%include "io.inc"
extern _getch

section .data
    input_prompt db "Moi ban nhap so nguyen n: ", 0
    out_square db "Day la so chinh phuong", 10, 0
    out_notsqr db "Day khong la so chinh phuong", 10, 0
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
    
    mov ebx, 1 ; i = 1

start_loop:
    cmp ebx, [n] ; i == n
    je not_square
    
    ; i * i
    mov eax, ebx
    mul eax
    
    cmp eax, [n] ; i*i = n
    je is_square
    
    mov eax, 0
    inc ebx
    jmp start_loop
    
is_square:
    push out_square
    call _printf
    add esp, 4
    jmp exit

not_square:
    push out_notsqr
    call _printf
    add esp, 4
    jmp exit

exit:
    call _getch
    xor eax, eax
    ret