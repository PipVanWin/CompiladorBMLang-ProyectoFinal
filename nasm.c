#include <stdio.h>
#include "nasm.h"

static int ultimaEtiqueta;
static int usaLectura;
static int usaEscritura;
static int usaPotencia;
static int usaDivision;

/* Quita el signo $ del nombre de la variable */
static char *nombreSinDolar(Nodo *variable) {
    return variable->nombre + 1;  /* Empieza después del signo $. */
}

static void reservarVariables(Nodo *nodo) {
    for (; nodo != NULL; nodo = nodo->sig) {
        switch (nodo->tipo) {
            case N_DECLARACION:
                /* reserva bytes por variable */
                for (Nodo *variable = nodo->a; variable; variable = variable->sig) {
                    printf("    var_%s resd 1\n", nombreSinDolar(variable));
                }
                break;
            case N_IF:
                reservarVariables(nodo->b);
                reservarVariables(nodo->c);
                break;
            case N_WHILE:
                reservarVariables(nodo->b);
                break;
            case N_FOR:
                reservarVariables(nodo->d);
                break;
            default:
                break;
        }
    }
}


static int esNumeroOVariable(Nodo *valor) {
    return valor->tipo == N_NUMERO || valor->tipo == N_VARIABLE;
}

/* escribe una instrucción  */
static void escribirInstruccion(char *instruccion, char *registro, Nodo *valor) {
    if (valor->tipo == N_NUMERO) {
        printf("    %s %s, %d\n", instruccion, registro, valor->valor);
    } else {
        printf("    %s %s, [var_%s]\n", instruccion, registro,
               nombreSinDolar(valor));
    }
}

static void generarExpresion(Nodo *nodo);

/* carga la info de ambos lados */
static void cargarDosValores(Nodo *izquierda, Nodo *derecha) {
    generarExpresion(izquierda);
    if (esNumeroOVariable(derecha)) {
        escribirInstruccion("mov", "ecx", derecha);
    } else {
        printf("    push eax\n");
        generarExpresion(derecha);
        printf("    mov ecx, eax\n    pop eax\n");
    }
}

static void generarExpresion(Nodo *nodo) {
    switch (nodo->tipo) {
        case N_NUMERO:
        case N_VARIABLE:
            escribirInstruccion("mov", "eax", nodo);
            break;
        case N_NEGACION:
            generarExpresion(nodo->a);
            printf("    neg eax\n");
            break;
        case N_OPBIN: {
            /* yraduce una operacion  */
            Nodo *izquierda = nodo->a;
            Nodo *derecha = nodo->b;
            char operador = nodo->op;
            char *instruccion = NULL;
            switch (operador) {
                case '+':
                    instruccion = "add";
                    break;
                case '-':
                    instruccion = "sub";
                    break;
                case '*':
                    instruccion = "imul";
                    break;
            }

            /* numero o variable*/
            if (instruccion && esNumeroOVariable(derecha)) {
                generarExpresion(izquierda);
                escribirInstruccion(instruccion, "eax", derecha);
                break;
            }
            cargarDosValores(izquierda, derecha);
            if (instruccion) {
                printf("    %s eax, ecx\n", instruccion);
            } else if (operador == '/') {
                /* Prepara edx:eax para dividir con signo */
                ultimaEtiqueta = ultimaEtiqueta + 1;
                int etiquetaDivision = ultimaEtiqueta;
                usaDivision = 1;
                printf("    test ecx, ecx\n    jz error_ejecucion\n"
                       "    cmp ecx, -1\n"
                       "    jne L%d\n"
                       "    cmp eax, 0x80000000\n"
                       "    je error_ejecucion\n"
                       "L%d:\n    cdq\n    idiv ecx\n", etiquetaDivision, etiquetaDivision);
            } else {
                usaPotencia = 1;
                printf("    call potencia\n");
            }
            break;
        }
        default:
            break;
    }
}

/* Compara valores */
static void generarSaltoCondicional(Nodo *nodo,
                                    int saltarSiVerdadera, int destino) {
    if (nodo->tipo == N_COMPARACION) {

        static char *saltoSiVerdadera[] = {"jl",  "jg",  "jle", "jge", "je",  "jne"};
        static char *saltoSiFalsa[]     = {"jge", "jle", "jg",  "jl",  "jne", "je"};
        if (esNumeroOVariable(nodo->b)) {
            generarExpresion(nodo->a);
            escribirInstruccion("cmp", "eax", nodo->b);
        } else {
            cargarDosValores(nodo->a, nodo->b);
            printf("    cmp eax, ecx\n");
        }
        char *salto;
        if (saltarSiVerdadera) {
            salto = saltoSiVerdadera[nodo->op];
        } else {
            salto = saltoSiFalsa[nodo->op];
        }
        printf("    %s L%d\n", salto, destino);
        return;
    }


    int bastaConUnLado = (nodo->tipo == N_OR && saltarSiVerdadera)
                      || (nodo->tipo == N_AND && !saltarSiVerdadera);
    if (bastaConUnLado) {
        generarSaltoCondicional(nodo->a, saltarSiVerdadera, destino);
        generarSaltoCondicional(nodo->b, saltarSiVerdadera, destino);
        return;
    }

    /* Omite el lado derecho  */
    ultimaEtiqueta = ultimaEtiqueta + 1;
    int evaluacionTerminada = ultimaEtiqueta;
    generarSaltoCondicional(nodo->a, !saltarSiVerdadera, evaluacionTerminada);
    generarSaltoCondicional(nodo->b, saltarSiVerdadera, destino);
    printf("L%d:\n", evaluacionTerminada);
}

/* Traduce isntrucciones */
static void generarSentencias(Nodo *nodo) {
    for (; nodo != NULL; nodo = nodo->sig) {
        switch (nodo->tipo) {
            case N_DECLARACION:
                break;  /* la variable ya tiene espacio reservado en .bss */
            case N_ASIGNACION:
                generarExpresion(nodo->b);
                printf("    mov [var_%s], eax\n", nombreSinDolar(nodo->a));
                break;
            case N_READ:
                usaLectura = 1;
                printf("    call leer_entero\n"
                       "    mov [var_%s], eax\n", nombreSinDolar(nodo->a));
                break;
            case N_WRITE:
                usaEscritura = 1;
                printf("    mov eax, [var_%s]\n"
                       "    call escribir_entero\n", nombreSinDolar(nodo->a));
                break;
            case N_IF: {
                ultimaEtiqueta = ultimaEtiqueta + 1;
                int etiquetaFalsa = ultimaEtiqueta;
                /* if a es la condición, b es el bloque if y c es else */
                generarSaltoCondicional(nodo->a, 0, etiquetaFalsa);
                generarSentencias(nodo->b);
                if (nodo->c != NULL) {
                    ultimaEtiqueta = ultimaEtiqueta + 1;
                    int fin = ultimaEtiqueta;
                    printf("    jmp L%d\nL%d:\n", fin, etiquetaFalsa);
                    generarSentencias(nodo->c);
                    printf("L%d:\n", fin);
                } else {
                    printf("L%d:\n", etiquetaFalsa);
                }
                break;
            }
            case N_WHILE:
            case N_FOR: {
                Nodo *condicionDelCiclo = nodo->a;
                Nodo *instruccionesDelCiclo = nodo->b;
                if (nodo->tipo == N_FOR) {
                    generarSentencias(nodo->a);
                    condicionDelCiclo = nodo->b;
                    instruccionesDelCiclo = nodo->d;
                }
                ultimaEtiqueta = ultimaEtiqueta + 1;
                int inicio = ultimaEtiqueta;
                ultimaEtiqueta = ultimaEtiqueta + 1;
                int fin = ultimaEtiqueta;
                printf("L%d:\n", inicio);
                /* condicion falsa */
                generarSaltoCondicional(condicionDelCiclo, 0, fin);
                generarSentencias(instruccionesDelCiclo);
                if (nodo->tipo == N_FOR) {
                    generarSentencias(nodo->c);
                }
                printf("    jmp L%d\nL%d:\n", inicio, fin);
                break;
            }
            default:
                break;
        }
    }
}



/* eax y exc */
static void emitirPotencia(void) {
    printf("\npotencia:\n"
           "    test ecx, ecx\n"
           "    js .negativo\n"
           "    mov edx, eax\n"
           "    mov eax, 1\n"
           ".bucle:\n"
           "    test ecx, ecx\n"
           "    jz .fin\n"
           "    test ecx, 1\n"
           "    jz .cuadrado\n"
           "    imul eax, edx\n"
           ".cuadrado:\n"
           "    imul edx, edx\n"
           "    shr ecx, 1\n"
           "    jmp .bucle\n"
           ".negativo:\n"
           "    test eax, eax\n"
           "    jz error_ejecucion\n"
           "    cmp eax, 1\n"
           "    je .fin\n"
           "    cmp eax, -1\n"
           "    jne .cero\n"
           "    test ecx, 1\n"
           "    jnz .fin\n"
           "    mov eax, 1\n"
           "    ret\n"
           ".cero:\n"
           "    xor eax, eax\n"
           ".fin:\n"
           "    ret\n");
}

/* lee un entero y lo devuelve en eax */
static void emitirLectura(void) {
    printf("\nleer_entero:\n"
           "    xor esi, esi             ; acumulador\n"
           "    xor edi, edi             ; signo negativo\n"
           ".espacios:\n"
           "    call leer_byte\n"
           "    cmp edx, -1\n"
           "    je error_ejecucion\n"
           "    cmp edx, 32\n"
           "    je .espacios\n"
           "    cmp edx, 9\n"
           "    jb .signo\n"
           "    cmp edx, 13\n"
           "    jbe .espacios\n"
           ".signo:\n"
           "    cmp edx, 43\n"
           "    je .siguiente\n"
           "    cmp edx, 45\n"
           "    jne .digito\n"
           "    mov edi, 1\n"
           ".siguiente:\n"
           "    call leer_byte\n"
           ".digito:\n"
           "    sub edx, 48\n"
           "    cmp edx, 9\n"
           "    ja error_ejecucion\n"
           "    imul esi, esi, 10\n"
           "    jo error_ejecucion\n"
           "    sub esi, edx\n"
           "    jo error_ejecucion\n"
           "    call leer_byte\n"
           "    cmp edx, -1\n"
           "    je .fin\n"
           "    cmp edx, 32\n"
           "    je .fin\n"
           "    cmp edx, 9\n"
           "    jb error_ejecucion\n"
           "    cmp edx, 13\n"
           "    ja .digito\n"
           ".fin:\n"
           "    mov eax, esi\n"
           "    test edi, edi\n"
           "    jnz .retorno\n"
           "    neg eax\n"
           "    jo error_ejecucion\n"
           ".retorno:\n"
           "    ret\n"
           "\n"
           "leer_byte:\n"
           "    push dword 0\n"
           "    mov ecx, esp\n"
           "    mov eax, 3               ; sys_read\n"
           "    xor ebx, ebx\n"
           "    mov edx, 1\n"
           "    int 0x80\n"
           "    pop edx\n"
           "    cmp eax, 1\n"
           "    je .fin\n"
           "    test eax, eax\n"
           "    js error_ejecucion\n"
           "    mov edx, -1\n"
           ".fin:\n"
           "    ret\n");
}

/* muestra el entero de eax  */
static void emitirEscritura(void) {
    printf("\nescribir_entero:\n"
           "    sub esp, 12\n"
           "    lea ecx, [esp + 11]\n"
           "    mov byte [ecx], 10\n"
           "    mov esi, eax\n"
           "    test eax, eax\n"
           "    jns .magnitud\n"
           "    neg eax\n"
           ".magnitud:\n"
           "    mov ebx, 10\n"
           ".digito:\n"
           "    xor edx, edx\n"
           "    div ebx\n"
           "    add dl, '0'\n"
           "    dec ecx\n"
           "    mov [ecx], dl\n"
           "    test eax, eax\n"
           "    jnz .digito\n"
           "    test esi, esi\n"
           "    jns .imprimir\n"
           "    dec ecx\n"
           "    mov byte [ecx], '-'\n"
           ".imprimir:\n"
           "    lea edx, [esp + 12]\n"
           "    sub edx, ecx\n"
           "    mov eax, 4               ; sys_write\n"
           "    mov ebx, 1\n"
           "    int 0x80\n"
           "    add esp, 12\n"
           "    ret\n");
}

/* escribe las variables y las rutinas que se usan. */
int generarNASM(Nodo *programa) {
    ultimaEtiqueta = 0;
    usaLectura = 0;
    usaEscritura = 0;
    usaPotencia = 0;
    usaDivision = 0;

    printf("section .bss\n");
    reservarVariables(programa->a);
    printf("\nsection .text\n    global _start\n\n_start:\n");
    generarSentencias(programa->a);
    printf("\n    mov eax, 1               ; sys_exit\n"
           "    xor ebx, ebx\n"
           "    int 0x80\n");
    if (usaPotencia) {
        emitirPotencia();
    }
    if (usaLectura) {
        emitirLectura();
    }
    if (usaEscritura) {
        emitirEscritura();
    }
    if (usaPotencia || usaLectura || usaDivision) {
        printf("\nerror_ejecucion:\n    mov eax, 4\n    mov ebx, 2\n"
               "    mov ecx, mensaje_error\n"
               "    mov edx, largo_error\n"
               "    int 0x80\n"
               "    mov eax, 1\n"
               "    mov ebx, 2\n"
               "    int 0x80\n"
               "\n"
               "section .rodata\n"
               "    mensaje_error db 'Error de ejecucion BMLang', 10\n"
               "    largo_error equ $ - mensaje_error\n");
    }
    /* enva lo que todavia queda pendiente de escribir */
    int resultadoEscritura = fflush(stdout);
    if (resultadoEscritura == EOF) {
        return 1;
    }

    /* Revisa si falló algún printf anterior. */
    int huboError = ferror(stdout);
    if (huboError != 0) {
        return 1;
    }

    return 0;
}
