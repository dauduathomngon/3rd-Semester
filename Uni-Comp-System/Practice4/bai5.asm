%include "io.inc"
extern _getch

section .data
    menu_prompt db 'Menu',10,'1. Nhap mang 1 chieu n phan tu so nguyen.',10,'2. Xuat mang.',10,'3. Liet ke cac so nguyen to.',10,'4. Tim gia tri lon nhat trong mang.',10,'5. Tinh trung binh mang.',10,'0. Thoat chuong trinh.',10,'Nhap so tuong ung de chon chuc nang: ',0
    size_in db 'Moi ban nhap size array (toi da 100): ', 0
    element_in db 'Nhap phan tu: ', 0
    element_out db 'Phan tu: ', 0
    fmt1 db '%d', 0
    fmt2 db '%d ', 0
    endl db '', 10, 0
    
section .bss
    arr resd 200
    size resd 1
    choice resd 1
    
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    jmp menu

menu:
    push menu_prompt
    call _printf
    add esp, 4
    
    push choice
    push fmt1
    call _scanf
    add esp, 8

    cmp dword[choice], 1
    je option1
    
    cmp dword[choice], 2
    je option2
    
    cmp dword[choice], 3
    je option3
    
    cmp dword[choice], 4
    je option4
    
    cmp dword[choice], 5
    je option5
    
    jmp exit
    
; option 1 -----------------
option1:
    push size_in
    call _printf
    add esp, 4
    
    push size
    push fmt1
    call _scanf
    add esp, 8
    
    cmp dword[size], 100 ; so luong > 100
    je exit 
    
    mov ebx, arr ; ebx = dia chi arr
    mov esi, 0 ; i = 0
    
    jmp arr_input
    
arr_input:
    cmp esi, [size] ; i = n
    je menu

    push element_in
    call _printf
    add esp, 4
    
    ; nhap a[i]
    push ebx
    push fmt1
    call _scanf
    add esp, 8
    
    ; tang chi so
    add ebx, 4
    inc esi
    jmp arr_input

; option 2 -----------------
option2:
    mov ebx, arr ; arr 
    mov esi, 0 ; idx
    
    jmp arr_output
    
arr_output:
    cmp esi, [size]
    je menu

    push element_out
    call _printf
    add esp, 4
    
    push dword[ebx]
    push fmt2
    call _printf
    add esp, 8
    
    push endl
    call _printf
    add esp, 4
    
    add ebx, 4
    inc esi
    jmp arr_output

; option 3 -----------------
option3:
    mov ecx, 0
    
arr_loop:
    cmp ecx, dword [size]
    jge menu

    lea eax, [arr+ecx*4]
    mov ebx, dword [eax] 
    push ecx
    push ebx
    call is_prime
    add esp, 4
    pop ecx

    cmp eax, 1
    jne not_prime

    push ecx
    push ebx 
    push fmt2
    call _printf
    add esp, 8
        
    push endl
    call _printf
    add esp, 4
    pop ecx

not_prime:
    inc ecx
    jmp arr_loop   
        
is_prime:
    push ebp
    mov ebp, esp

    mov ebx, dword [ebp+8] 

    cmp ebx, 2
    jl not_prime_result
    cmp ebx, 2
    je prime_result

    mov ecx, 2
    
is_prime_loop:
    cmp ecx, ebx
    jge prime_result

    xor edx, edx
    mov eax, ebx
    cdq
    idiv ecx
    cmp edx, 0
    je not_prime_result

    inc ecx
    jmp is_prime_loop

prime_result:
    mov eax, 1
    pop ebp
    ret

not_prime_result:
    xor eax, eax
    pop ebp
    ret

; option 4 -----------------
option4:
    mov eax, dword [arr]
    mov ecx, 1
    
find_max_loop:
    cmp ecx, dword [size]
    jge display_max

    cmp eax, dword [arr+ecx*4]
    jge not_greater

    mov eax, dword [arr+ecx*4]

not_greater:
    inc ecx
    jmp find_max_loop

display_max:
    push eax
    push fmt2
    call _printf
    add esp, 8
    
    push endl
    call _printf
    add esp, 4

    jmp menu

; option 5 -----------------
option5:
    push ebp
    mov ebp,esp
    push ebx
    push esi
 
    add esp,-32
    
    mov ebx, arr
    mov ecx, 0 ; sum = 0
    mov esi, 0 ; i = 0

sum_loop:
    add ecx, dword[ebx]
    
    add ebx, 4
    inc esi
    
    cmp esi, dword[size]
    jl sum_loop
    
calc_avg:
    mov eax, ecx 
    mov edx, 0   
    div dword[size]
    
    push eax
    push fmt2
    call _printf
    add esp, 8
    
    push endl
    call _printf
    add esp, 4
    
    add esp,32
    pop esi
    pop ebx
    pop ebp
    
    jmp menu

; exit ---------------------
exit:
   call _getch
   xor eax, eax
   ret