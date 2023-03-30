# Bai tap 4: Kiem tra so doi xung
.data 
	user_input: .asciiz "Moi ban nhap so nguyen n: "
	output_yes: .asciiz "n la so doi xung"
	output_no: .asciiz "n khong la so doi xung"
.text
	main:
		li $v0, 4
		la $a0, user_input # in ra user_input
		syscall
		
		li $v0, 5 # nhap so n
		syscall
		move $t0, $v0 
		
		li $t1, 0 # luu so doi xung cua n
		move $t2, $t0 # luu bien phu

	start_loop:
		bnez $t2, calc_palindrome
		
		# so doi xung dang du so 0 phia sau
		div $t1, $t1, 10
		
		# neu so doi xung = n
		beq $t1, $t0, is_palindrome
		# neu khong
		j not_palindrome
		
	calc_palindrome:
		rem $t3, $t2, 10
		add $t1, $t1, $t3
		mul $t1, $t1, 10
		
		# n /= 10
		div $t2, $t2, 10
		
		j start_loop

	is_palindrome:
		li $v0, 4
		la $a0, output_yes
		syscall
		j exit
	
	not_palindrome:
		li $v0, 4
		la $a0, output_no
		syscall
		j exit
			
	exit: # thoat chuong trinh
		li $v0, 10 
		syscall
