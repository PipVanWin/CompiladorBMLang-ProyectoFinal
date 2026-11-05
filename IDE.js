

let codigoFuente = "";
let archivoActual = "programa.bml";

const API_BASE = "http://localhost:3000/api";

let tokens = [];

let astActual = null;

let codigoC3D = "";
let codigoNASM = "";

let vm = {
    instrucciones: [],
    variables: {},
    stack: [],
    output: [],
    pc: 0,
    ejecutando: false,
    terminado: false
};


async function compilarEnBackend(codigo, modo) {

    try {

        const respuesta = await fetch(`${API_BASE}/compile`, {
            method: "POST",

            headers: {
                "Content-Type": "application/json"
            },

            body: JSON.stringify({
                code: codigo,
                mode: modo
            })
        });

        const resultado = await respuesta.json();

        if (!respuesta.ok || !resultado.success) {

            return {
                success: false,
                output: resultado.output || "",
                errors: resultado.errors || "",
                message: resultado.message || "Error al compilar."
            };

        }

        return {
            success: true,
            output: resultado.output,
            errors: resultado.errors
        };

    } catch (error) {

        console.error("Error de conexión:", error);

        return {
            success: false,
            output: "",
            errors: error.message,
            message: "No se pudo conectar con el backend de BMLang."
        };

    }

}





const editor = document.getElementById("codeEditor");

const lineNumbers = document.getElementById("lineNumbers");

const editorStats = document.getElementById("editorStats");

const c3dOutput = document.getElementById("c3dOutput");

const nasmOutput = document.getElementById("nasmOutput");

const consoleLog = document.getElementById("consoleLog");



document.addEventListener("DOMContentLoaded", () => {

    actualizarNumerosLinea();

    updateEditorStats();

    logConsole("BMLang IDE iniciado correctamente.", "success");

    logConsole("Entorno preparado para trabajar con BMLang.", "info");

});



function logConsole(mensaje, tipo = "info") {

    if (!consoleLog) return;

    const colores = {
        success: "text-emerald-400",
        error: "text-red-400",
        warning: "text-amber-400",
        info: "text-blue-400"
    };

    const iconos = {
        success: "✓",
        error: "✗",
        warning: "⚠",
        info: "ℹ"
    };

    const elemento = document.createElement("div");

    elemento.className = colores[tipo] || colores.info;

    const fecha = new Date().toLocaleTimeString();

    elemento.textContent =
        `[${fecha}] ${iconos[tipo] || "ℹ"} ${mensaje}`;

    consoleLog.appendChild(elemento);

    consoleLog.scrollTop = consoleLog.scrollHeight;

}


function clearConsole() {

    consoleLog.innerHTML = "";

    logConsole("Consola limpiada.", "success");

}




function updateEditorStats() {

    codigoFuente = editor.value;

    const lineas = codigoFuente.split("\n").length;

    const caracteres = codigoFuente.length;

    editorStats.textContent =
        `Líneas: ${lineas} | Caracteres: ${caracteres}`;

    actualizarNumerosLinea();

}


function actualizarNumerosLinea() {

    const cantidad = editor.value.split("\n").length;

    let numeros = "";

    for (let i = 1; i <= cantidad; i++) {

        numeros += i + "\n";

    }

    lineNumbers.textContent = numeros.trimEnd() || "1";

}




function newFile() {

    const confirmar = confirm(
        "¿Desea crear un nuevo archivo? Se perderán los cambios no guardados."
    );

    if (!confirmar) return;

    editor.value = "";

    archivoActual = "programa.bml";

    updateEditorStats();

    reiniciarResultados();

    logConsole("Nuevo archivo creado.", "success");

}


function reiniciarResultados() {

    c3dOutput.textContent =
        "#! Presione Generar C3D para compilar !#";

    nasmOutput.textContent =
        "#! Presione Generar NASM para compilar !#";

    document.getElementById("astOutput").textContent =
        "#! AST no generado !#";

    document.getElementById("tokenTableBody").innerHTML = `
        <tr>
            <td colspan="4" class="text-center text-slate-500 py-8">
                No hay tokens disponibles.
            </td>
        </tr>
    `;

    codigoC3D = "";

    codigoNASM = "";

    tokens = [];

    astActual = null;

    resetInterpreterVM();

}




function openFile(event) {

    const archivo = event.target.files[0];

    if (!archivo) return;

    const extension = archivo.name.split(".").pop().toLowerCase();

    if (!["bml", "txt"].includes(extension)) {

        logConsole("Formato de archivo no permitido.", "error");

        return;

    }

    const lector = new FileReader();

    lector.onload = function (e) {

        editor.value = e.target.result;

        archivoActual = archivo.name;

        updateEditorStats();

        reiniciarResultados();

        logConsole(
            `Archivo ${archivo.name} abierto correctamente.`,
            "success"
        );

    };

    lector.onerror = function () {

        logConsole("No fue posible leer el archivo.", "error");

    };

    lector.readAsText(archivo);

    event.target.value = "";

}




function saveFile() {

    const contenido = editor.value;

    const blob = new Blob(
        [contenido],
        { type: "text/plain;charset=utf-8" }
    );

    const url = URL.createObjectURL(blob);

    const enlace = document.createElement("a");

    enlace.href = url;

    enlace.download = archivoActual;

    enlace.click();

    URL.revokeObjectURL(url);

    logConsole(
        `Archivo ${archivoActual} guardado correctamente.`,
        "success"
    );

}



function loadSampleCode(ejemplo) {

    const ejemplos = {

        ex1: `#! Ejemplo 1: Operaciones Básicas e I/O !#

MAIN {

    DEC $a, $b, $resultado;

    $a => 10;
    $b => 5;

    $resultado => $a + $b;

    WRITE $resultado;

}`,

        ex2: `#! Ejemplo 2: Condicional IF ELSE !#

MAIN {

    DEC $edad;

    $edad => 20;

    IF ($edad >= 18) {

        WRITE $edad;

    } ELSE {

        WRITE $edad;

    }

}`,

        ex3: `#! Ejemplo 3: Ciclo FOR !#

MAIN {

    DEC $i, $suma;

    $suma => 0;

    FOR ($i => 1; $i <= 5; $i => $i + 1) {

        $suma => $suma + $i;

    }

    WRITE $suma;

}`,

        ex4: `#! Ejemplo 4: Ciclo WHILE !#

MAIN {

    DEC $base, $exponente, $resultado;

    $base => 2;
    $exponente => 3;
    $resultado => 1;

    WHILE ($exponente > 0) {

        $resultado => $resultado * $base;

        $exponente => $exponente - 1;

    }

    WRITE $resultado;

}`

    };

    if (!ejemplos[ejemplo]) return;

    editor.value = ejemplos[ejemplo];

    archivoActual = ejemplo + ".bml";

    updateEditorStats();

    reiniciarResultados();

    logConsole(
        `Ejemplo ${ejemplo} cargado correctamente.`,
        "success"
    );

}




function switchTab(tabId) {

    const pestañas = document.querySelectorAll(".tab-content");

    const botones = document.querySelectorAll(".tab-btn");

    pestañas.forEach(tab => {

        tab.classList.add("hidden");

        tab.classList.remove("flex");

    });

    botones.forEach(boton => {

        boton.classList.remove(
            "active",
            "border-amber-500",
            "text-amber-400",
            "bg-slate-800/50"
        );

        boton.classList.add(
            "border-transparent",
            "text-slate-400"
        );

    });

    const contenido = document.getElementById(tabId);

    const boton = document.getElementById("btn-" + tabId);

    if (contenido) {

        contenido.classList.remove("hidden");

        contenido.classList.add("flex");

    }

    if (boton) {

        boton.classList.add(
            "active",
            "border-amber-500",
            "text-amber-400",
            "bg-slate-800/50"
        );

        boton.classList.remove(
            "border-transparent",
            "text-slate-400"
        );

    }

}




function toggleModal(mostrar) {

    const modal = document.getElementById("integrantesModal");

    modal.classList.toggle("hidden", !mostrar);

}




async function copyToClipboard(elementId) {

    const elemento = document.getElementById(elementId);

    if (!elemento) return;

    try {

        await navigator.clipboard.writeText(elemento.textContent);

        logConsole("Contenido copiado al portapapeles.", "success");

    } catch (error) {

        logConsole("No fue posible copiar el contenido.", "error");

    }

}


/* =========================================================
   13. ANALIZADOR LÉXICO BÁSICO
========================================================= */

/*
   IMPORTANTE:

   Este analizador es una implementación preliminar
   en JavaScript para visualizar tokens.

   El analizador léxico oficial del proyecto es BMLang.l,
   desarrollado con Flex.
*/

function analizarLexico(codigo) {

    const reglas = [

        ["COMENTARIO", /^#![^\n]*!#/],

        ["MAIN", /^MAIN\b/],
        ["DEC", /^DEC\b/],
        ["READ", /^READ\b/],
        ["WRITE", /^WRITE\b/],
        ["IF", /^IF\b/],
        ["ELSE", /^ELSE\b/],
        ["WHILE", /^WHILE\b/],
        ["FOR", /^FOR\b/],

        ["ASIGNACION", /^=>/],

        ["MENORIGUAL", /^<=/],
        ["MAYORIGUAL", /^>=/],
        ["IGUAL", /^==/],
        ["DIFERENTE", /^<>/],

        ["AND", /^&&/],
        ["OR", /^\|\|/],

        ["MENOR", /^</],
        ["MAYOR", /^>/],

        ["MAS", /^\+/],
        ["MENOS", /^-/],
        ["POR", /^\*/],
        ["DIVIDIR", /^\//],
        ["POTENCIA", /^:/],

        ["PARENTESIS_ABRIR", /^\(/],
        ["PARENTESIS_CERRAR", /^\)/],

        ["LLAVE_ABRIR", /^\{/],
        ["LLAVE_CERRAR", /^\}/],

        ["COMA", /^,/],
        ["PUNTOYCOMA", /^;/],

        ["IDENTIFICADOR", /^\$[a-zA-Z][a-zA-Z0-9]*/],

        ["NUMERO", /^[0-9]+/],

        ["ESPACIO", /^[ \t\r]+/],

        ["SALTO_LINEA", /^\n/]

    ];

    const resultado = [];

    let posicion = 0;

    let linea = 1;

    while (posicion < codigo.length) {

        const fragmento = codigo.slice(posicion);

        let encontrado = false;

        for (const [tipo, regex] of reglas) {

            const coincidencia = fragmento.match(regex);

            if (!coincidencia) continue;

            const lexema = coincidencia[0];

            encontrado = true;

            if (tipo === "SALTO_LINEA") {

                linea++;

            } else if (
                tipo !== "ESPACIO" &&
                tipo !== "COMENTARIO"
            ) {

                resultado.push({

                    lexema,

                    tipo,

                    linea

                });

            }

            posicion += lexema.length;

            break;

        }

        if (!encontrado) {

            resultado.push({

                lexema: fragmento[0],

                tipo: "INVALIDO",

                linea

            });

            posicion++;

        }

    }

    return resultado;

}




function mostrarTokens(lista) {

    const tabla = document.getElementById("tokenTableBody");

    tabla.innerHTML = "";

    if (lista.length === 0) {

        tabla.innerHTML = `
            <tr>
                <td colspan="4" class="text-center text-slate-500 py-8">
                    No se encontraron tokens.
                </td>
            </tr>
        `;

        return;

    }

    lista.forEach((token, indice) => {

        const fila = document.createElement("tr");

        const valores = [
            indice + 1,
            token.lexema,
            token.tipo,
            token.linea
        ];

        valores.forEach(valor => {

            const celda = document.createElement("td");

            celda.textContent = valor;

            fila.appendChild(celda);

        });

        if (token.tipo === "INVALIDO") {

            fila.classList.add("bg-red-950/30");

        }

        tabla.appendChild(fila);

    });

}




function validarEstructura(codigo) {

    const errores = [];

    if (!codigo.trim()) {

        errores.push("El código fuente está vacío.");

        return errores;

    }

    if (!/\bMAIN\s*\{/.test(codigo)) {

        errores.push("No se encontró MAIN {.");

    }

    let llaves = 0;

    let parentesis = 0;

    for (const caracter of codigo) {

        if (caracter === "{") llaves++;

        if (caracter === "}") llaves--;

        if (caracter === "(") parentesis++;

        if (caracter === ")") parentesis--;

        if (llaves < 0) {

            errores.push("Existe una llave de cierre sin apertura.");

            break;

        }

        if (parentesis < 0) {

            errores.push("Existe un paréntesis de cierre sin apertura.");

            break;

        }

    }

    if (llaves !== 0) {

        errores.push("Las llaves no están balanceadas.");

    }

    if (parentesis !== 0) {

        errores.push("Los paréntesis no están balanceados.");

    }

    return errores;

}




async function generarAST() {

    const codigo = editor.value;

    if (!codigo.trim()) {

        logConsole("No hay código fuente para analizar.", "error");

        switchTab("consoleTab");

        return;
    }

    logConsole("Generando AST mediante el compilador real...", "info");

    const astOutput = document.getElementById("astOutput");

    astOutput.textContent = "Generando árbol sintáctico...";

    switchTab("astTab");

    const resultado = await compilarEnBackend(codigo, "ast");

    if (!resultado.success) {

        astOutput.textContent =
            resultado.output || resultado.errors || resultado.message;

        logConsole("Error al generar el AST.", "error");

        return;
    }

    astActual = resultado.output;

    astOutput.textContent = resultado.output;

    logConsole("AST generado correctamente mediante Bison y ast.c.", "success");

}



async function compilePipeline(tipo) {

    const codigo = editor.value;

    if (!codigo.trim()) {

        logConsole("No hay código fuente para compilar.", "error");

        switchTab("consoleTab");

        return;
    }

   
    if (tipo === "c3d") {

        logConsole("Generando código de tres direcciones...", "info");

        c3dOutput.textContent = "Generando C3D...";

        switchTab("c3dTab");

        const resultado = await compilarEnBackend(codigo, "tac");

        if (!resultado.success) {

            c3dOutput.textContent =
                resultado.output || resultado.errors || resultado.message;

            logConsole("Error durante la generación de C3D.", "error");

            return;
        }

        codigoC3D = resultado.output;

        c3dOutput.textContent = resultado.output;

        logConsole("Código de tres direcciones generado correctamente.", "success");

        return;
    }

    
if (tipo === "nasm") {

    logConsole("Generando código ensamblador NASM...", "info");

    nasmOutput.textContent = "Generando código NASM...";

    switchTab("nasmTab");

    const resultado = await compilarEnBackend(codigo, "nasm");

    if (!resultado.success) {

        nasmOutput.textContent =
            resultado.output ||
            resultado.errors ||
            resultado.message;

        logConsole("Error durante la generación de NASM.", "error");

        return;
    }

    codigoNASM = resultado.output;

    nasmOutput.textContent = codigoNASM;

    logConsole("Código NASM generado correctamente.", "success");

    return;
}
    if (tipo === "run") {

    logConsole("Compilando y ejecutando programa...", "info");

    switchTab("consoleTab");

    try {

        const respuesta = await fetch(`${API_BASE}/run`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({
                code: codigo
            })
        });

        const resultado = await respuesta.json();

        if (!resultado.success) {

            logConsole(
                resultado.errors ||
                resultado.message ||
                "Error durante la ejecución.",
                "error"
            );

            if (resultado.output) {
                logConsole(resultado.output, "info");
            }

            return;
        }

       
        if (resultado.output) {

            logConsole(
                resultado.output,
                "success"
            );

        } else {

            logConsole(
                "El programa terminó correctamente, pero no produjo salida.",
                "info"
            );
        }

        
        if (resultado.errors) {
            logConsole(resultado.errors, "warning");
        }

        logConsole(
            "Ejecución finalizada correctamente.",
            "success"
        );

    } catch (error) {

        console.error(error);

        logConsole(
            "No se pudo conectar con el backend.",
            "error"
        );
    }

    return;
}


   
   if (tipo === "build") {

    logConsole("Iniciando compilación del ejecutable...", "info");

    switchTab("consoleTab");

    try {

        
        const respuesta = await fetch(`${API_BASE}/build`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({
                code: codigo
            })
        });

        
        if (!respuesta.ok) {

            const error = await respuesta.json();

            logConsole(
                error.errors || error.message || "Error al generar el ejecutable.",
                "error"
            );

            return;
        }

        
        const archivo = await respuesta.blob();

       
        const url = window.URL.createObjectURL(archivo);

        
        const enlace = document.createElement("a");

        enlace.href = url;
        enlace.download = "programa";

        document.body.appendChild(enlace);

        enlace.click();

        
        enlace.remove();

        window.URL.revokeObjectURL(url);

        logConsole(
            "Ejecutable generado y descargado correctamente.",
            "success"
        );

    } catch (error) {

        console.error(error);

        logConsole(
            "No se pudo conectar con el backend para generar el ejecutable.",
            "error"
        );
    }

    return;
}

}



function prepararVM() {

    if (!codigoC3D.trim()) {

        logConsole(
            "Primero debe generarse el código C3D real.",
            "warning"
        );

        return false;

    }

    vm.instrucciones = codigoC3D
        .split("\n")
        .map(linea => linea.trim())
        .filter(linea => linea && !linea.startsWith("#!"));

    vm.variables = {};

    vm.stack = [];

    vm.output = [];

    vm.pc = 0;

    vm.ejecutando = false;

    vm.terminado = false;

    actualizarVM();

    return true;

}


function resetInterpreterVM() {

    vm = {

        instrucciones: [],

        variables: {},

        stack: [],

        output: [],

        pc: 0,

        ejecutando: false,

        terminado: false

    };

    actualizarVM();

    const estado = document.getElementById("vmStatus");

    if (estado) {

        estado.textContent = "Estado: Detenido";

    }

}


function ejecutarInstruccion(instruccion) {

    const printMatch = instruccion.match(
        /^(?:PRINT|WRITE)\s+(.+)$/i
    );

    if (printMatch) {

        const valor = evaluarExpresion(printMatch[1]);

        vm.output.push(String(valor));

        return;

    }

    const asignacion = instruccion.match(
        /^([a-zA-Z_$][a-zA-Z0-9_$]*)\s*=\s*(.+)$/
    );

    if (!asignacion) {

        throw new Error(
            `Instrucción no reconocida: ${instruccion}`
        );

    }

    const variable = asignacion[1];

    const expresion = asignacion[2];

    vm.variables[variable] = evaluarExpresion(expresion);

    vm.stack.push({

        variable,

        valor: vm.variables[variable]

    });

}


function evaluarExpresion(expresion) {

    const texto = expresion.trim();

    if (/^-?\d+$/.test(texto)) {

        return Number(texto);

    }

    if (
        Object.prototype.hasOwnProperty.call(
            vm.variables,
            texto
        )
    ) {

        return vm.variables[texto];

    }

    const operacion = texto.match(
        /^([a-zA-Z_$][a-zA-Z0-9_$]*|-?\d+)\s*([+\-*/])\s*([a-zA-Z_$][a-zA-Z0-9_$]*|-?\d+)$/
    );

    if (operacion) {

        const obtener = valor => {

            if (/^-?\d+$/.test(valor)) {

                return Number(valor);

            }

            if (
                Object.prototype.hasOwnProperty.call(
                    vm.variables,
                    valor
                )
            ) {

                return vm.variables[valor];

            }

            throw new Error(
                `Variable no definida: ${valor}`
            );

        };

        const a = obtener(operacion[1]);

        const b = obtener(operacion[3]);

        switch (operacion[2]) {

            case "+": return a + b;

            case "-": return a - b;

            case "*": return a * b;

            case "/":

                if (b === 0) {

                    throw new Error("División entre cero.");

                }

                return a / b;

        }

    }

    throw new Error(
        `Expresión no soportada: ${texto}`
    );

}




function stepInterpreter() {

    if (vm.instrucciones.length === 0) {

        if (!prepararVM()) return;

    }

    if (vm.terminado) {

        return;

    }

    if (vm.pc >= vm.instrucciones.length) {

        finalizarVM();

        return;

    }

    try {

        const instruccion = vm.instrucciones[vm.pc];

        ejecutarInstruccion(instruccion);

        vm.pc++;

        actualizarVM();

        if (vm.pc >= vm.instrucciones.length) {

            finalizarVM();

        } else {

            document.getElementById("vmStatus").textContent =
                "Estado: Ejecutando";

        }

    } catch (error) {

        logConsole(error.message, "error");

        document.getElementById("vmStatus").textContent =
            "Estado: Error";

        vm.terminado = true;

    }

}




function runInterpreter() {

    if (vm.instrucciones.length === 0) {

        if (!prepararVM()) return;

    }

    if (vm.terminado) {

        resetInterpreterVM();

        if (!prepararVM()) return;

    }

    let pasos = 0;

    const limite = 10000;

    try {

        while (
            vm.pc < vm.instrucciones.length &&
            pasos < limite
        ) {

            const instruccion = vm.instrucciones[vm.pc];

            ejecutarInstruccion(instruccion);

            vm.pc++;

            pasos++;

        }

        if (pasos >= limite) {

            throw new Error(
                "Se alcanzó el límite de instrucciones."
            );

        }

        finalizarVM();

    } catch (error) {

        document.getElementById("vmStatus").textContent =
            "Estado: Error";

        logConsole(error.message, "error");

        vm.terminado = true;

    }

}




function actualizarVM() {

    const variables = document.getElementById("vmVariables");

    const stack = document.getElementById("vmStack");

    const pc = document.getElementById("vmPC");

    const salida = document.getElementById("vmOutput");

    if (!variables) return;

    variables.innerHTML = "";

    const entradas = Object.entries(vm.variables);

    if (entradas.length === 0) {

        variables.innerHTML = `
            <div class="text-slate-500 italic">
                No hay variables registradas.
            </div>
        `;

    } else {

        entradas.forEach(([nombre, valor]) => {

            const fila = document.createElement("div");

            fila.className =
                "flex justify-between bg-slate-950 p-2 rounded border border-slate-800";

            const nombreElemento = document.createElement("span");

            nombreElemento.className = "text-blue-400";

            nombreElemento.textContent = nombre;

            const valorElemento = document.createElement("span");

            valorElemento.className = "text-emerald-400";

            valorElemento.textContent = valor;

            fila.append(nombreElemento, valorElemento);

            variables.appendChild(fila);

        });

    }

    if (stack) {

        stack.innerHTML = "";

        if (vm.stack.length === 0) {

            stack.innerHTML = `
                <div class="text-slate-500 text-center py-4 italic">
                    [ Pila vacía ]
                </div>
            `;

        } else {

            vm.stack.forEach(elemento => {

                const fila = document.createElement("div");

                fila.className =
                    "bg-slate-900 border border-slate-800 rounded p-2 flex justify-between";

                fila.textContent =
                    `${elemento.variable} = ${elemento.valor}`;

                stack.appendChild(fila);

            });

        }

    }

    if (pc) {

        pc.textContent = `PC: ${vm.pc}`;

    }

    if (salida) {

        salida.textContent =
            vm.output.length > 0
                ? vm.output.join("\n")
                : "> _";

    }

}




function finalizarVM() {

    vm.terminado = true;

    vm.ejecutando = false;

    actualizarVM();

    document.getElementById("vmStatus").textContent =
        "Estado: Finalizado";

    logConsole(
        "Ejecución de la máquina virtual finalizada.",
        "success"
    );

}



editor.addEventListener("scroll", () => {

    lineNumbers.scrollTop = editor.scrollTop;

});




editor.addEventListener("keydown", event => {

    if (event.key === "Tab") {

        event.preventDefault();

        const inicio = editor.selectionStart;

        const fin = editor.selectionEnd;

        editor.setRangeText(
            "    ",
            inicio,
            fin,
            "end"
        );

        updateEditorStats();

    }

    if (
        event.ctrlKey &&
        event.key.toLowerCase() === "s"
    ) {

        event.preventDefault();

        saveFile();

    }

    if (
        event.ctrlKey &&
        event.key.toLowerCase() === "n"
    ) {

        event.preventDefault();

        newFile();

    }

});


