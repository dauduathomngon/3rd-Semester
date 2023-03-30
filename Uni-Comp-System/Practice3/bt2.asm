# Bai tap 2: Kiem tra so nguyen hoan thien
.data 
	user_input: .asciiz "Moi ban nhap so nguyen n: "
	output_yes: .asciiz "n la so nguyen hoan thien"
	output_no: .asciiz "n khong la so nguyen hoan thien"
.text
	main:
		li $v0, 4
		la $a0, user_input # in ra user_input
		syscall
		
		li $v0, 5 # nhap so n
		syscall
		move $t0, $v0 
		
		beq $t0, 1, not_perfect # if n = 1
		
		li $t1, 1 # sum = 1
		li $t2, 2 # i = 2
		
	start_loop: # vong lap
		slt $t3, $t2, $t0 # i < n
		beqz $t3, check_sum
		
		# neu n % i == 0
		div $t0, $t2
		mfhi $t4
		beqz $t4, make_sum
		
		# i++
		addi $t2, $t2, 1
		j start_loop
		
	make_sum: # tinh tong tat ca cac uoc so
		add $t1, $t1, $t2
		addi $t2, $t2, 1
		j start_loop
		
	check_sum:
		beq $t1, $t0, is_perfect # neu sum = n
		j not_perfect # neu sum != n
		
	not_perfect:
		li $v0, 4
		la $a0, output_no
		syscall
		j exit
	
	is_perfect:
		li $v0, 4
		la $a0, output_yes
		syscall
		j exit
		
	exit: # thoat chuong trinh
		li $v0, 10 
		syscall
