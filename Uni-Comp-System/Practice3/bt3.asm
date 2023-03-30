# Bai tap 3: Kiem tra so chinh phuong
.data 
	user_input: .asciiz "Moi ban nhap so nguyen n: "
	output_yes: .asciiz "n la so chinh phuong"
	output_no: .asciiz "n khong la so chinh phuong"
.text
	main:
		li $v0, 4
		la $a0, user_input # in ra user_input
		syscall
		
		li $v0, 5 # nhap so n
		syscall
		move $t0, $v0 
		
		li $t1, 1 # i = 1
		
	start_loop:
		slt $t2, $t1, $t0 # i < n
		beqz $t2, not_square
		
		# i * i
		mult $t1, $t1
		mflo $t3
		
		# neu i*i = n
		beq $t3, $t0, is_square
		
		# i++
		addi $t1, $t1, 1
		j start_loop
		
	is_square:
		li $v0, 4
		la $a0, output_yes
		syscall
		j exit
	
	not_square:
		li $v0, 4
		la $a0, output_no
		syscall
		j exit
			
	exit: # thoat chuong trinh
		li $v0, 10 
		syscall
