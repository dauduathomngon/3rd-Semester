# Bai tap 1: Kiem tra so nguyen to
.data 
	user_input: .asciiz "Moi ban nhap so nguyen n: "
	output_yes: .asciiz "n la so nguyen to"
	output_no: .asciiz "n khong la so nguyen to"
.text
	main:
		li $v0, 4
		la $a0, user_input # in ra user_input
		syscall
		
		li $v0, 5 # nhap so n
		syscall
		move $t0, $v0 
		
		beq $t0, 0, not_prime # neu n = 0
		beq $t0, 1, not_prime # neu n = 1
		
		li $t1, 2 # i = 2
		
		start_loop:
			slt $t2, $t1, $t0 # i <= n
			beqz $t2, is_prime
		
			div $t0, $t1
			mfhi $t3
			beqz $t3, not_prime # neu phan du la 0 thi khong la so nguyen to
			addi $t1, $t1, 1
		
			j start_loop 
		
		is_prime:
			li $v0, 4
			la $a0, output_yes
			syscall
			j exit
	
		not_prime:
			li $v0, 4
			la $a0, output_no
			syscall
			j exit

		exit: # thoat chuong trinh
			li $v0, 10 
			syscall
