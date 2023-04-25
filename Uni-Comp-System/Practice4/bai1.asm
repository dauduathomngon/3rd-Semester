%include "io.inc"
extern _getch

section .data
    input_prompt db "Moi ban nhap so nguyen n: ", 0
    out_prime db "La so nguyen to", 0
    out_notprime db "Khong la so nguyen to", 0
    fmt db "%d", 0
    
section .bss
    n resd 1
    
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    push input_prompt ; xuat thong bao
    call _printf
    add esp, 4
    
    push n
    push fmt
    call _scanf
    add esp, 8
    
    mov edx, [n]
    
    cmp edx, 1
    je not_prime
    
    mov edx, 0
    mov ebx, 2 ; i = 2
    jmp start_loop
    
start_loop:
    cmp ebx, [n] ; i == n
    je is_prime
    
    mov eax, [n]
    mov edx, 0
    div ebx
    
    cmp edx, 0
    je not_prime
    
    inc ebx
    jmp start_loop

is_prime:
    push out_prime
    call _printf
    add esp, 4
    jmp exit

not_prime:
    push out_notprime
    call _printf
    add esp, 4
    jmp exit

exit:
    call _getch
    xor eax, eax
    ret