%include "io.inc"
extern _getch

section .data
    input_prompt db "Moi ban nhap so nguyen n: ", 0
    out_sym db "Day la so doi xung", 0
    out_notsym db "Day khong la so doi xung", 0
    fmt db "%d", 0
    
section .bss
    n resd 1
    
section .text
global CMAIN
CMAIN:
    push input_prompt
    call _printf
    add esp, 4
    
    push n
    push fmt
    call _scanf
    add esp, 8
    
    mov eax, [n] ; luu bien phu
    mov ebx, 0 ; so doi xung n
    mov ecx, 10 ; i = 10

start_loop:
    cmp eax, 0
    jne calc_palindrome
    
    cmp ebx, [n]
    je is_palindrome
    jmp not_palindrome
    
calc_palindrome:
    mov edx, 0
    div ecx
    
    imul ebx, ebx, 10
    add ebx, edx
    
    jmp start_loop

is_palindrome:
    push out_sym
    call _printf
    add esp, 4
    jmp exit

not_palindrome:
    push out_notsym
    call _printf
    add esp, 4
    jmp exit

exit:
    call _getch
    xor eax, eax
    ret