section .bss
    var_a resd 1
    var_b resd 1
    var_resultado resd 1

section .text
    global _start

_start:
    mov eax, 10
    mov [var_a], eax
    mov eax, 20
    mov [var_b], eax
    mov eax, [var_a]
    add eax, [var_b]
    mov [var_resultado], eax
    mov eax, [var_resultado]
    call escribir_entero

    mov eax, 1               ; sys_exit
    xor ebx, ebx
    int 0x80

escribir_entero:
    sub esp, 12
    lea ecx, [esp + 11]
    mov byte [ecx], 10
    mov esi, eax
    test eax, eax
    jns .magnitud
    neg eax
.magnitud:
    mov ebx, 10
.digito:
    xor edx, edx
    div ebx
    add dl, '0'
    dec ecx
    mov [ecx], dl
    test eax, eax
    jnz .digito
    test esi, esi
    jns .imprimir
    dec ecx
    mov byte [ecx], '-'
.imprimir:
    lea edx, [esp + 12]
    sub edx, ecx
    mov eax, 4               ; sys_write
    mov ebx, 1
    int 0x80
    add esp, 12
    ret
