%include "io.inc"
extern _getch

section .data
    input_prompt db "Moi ban nhap so nguyen n: ", 0
    out_perfect db "Day la so hoan thien", 10, 0
    out_notpf db "Day la so khong hoan thien", 10, 0
    fmt db "%d", 0
    
section .bss
    n resd 1
    
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    push input_prompt
    call _printf
    add esp, 4
    
    push n
    push fmt
    call _scanf
    add esp, 8
    
    mov ebx, 1 ; i = 1
    mov ecx, 0 ; sum =0
    
start_loop:
    cmp ebx, [n] ; if i = n
    je check_sum
    
    mov eax, [n]
    mov edx, 0
    div ebx
    
    cmp edx, 0 ; if (n%i == 0)
    je make_sum
    
    inc ebx
    jmp start_loop

make_sum:
    add ecx, ebx
    inc ebx
    jmp start_loop

check_sum:
    cmp ecx, [n]
    je is_perfect ; sum = n
    jmp not_perfect ; sum != n
    
is_perfect:
    push out_perfect
    call _printf
    add esp, 4
    jmp exit
    
not_perfect:
    push out_notpf
    call _printf
    add esp, 4
    jmp exit

exit:
    call _getch
    xor eax, eax
    ret