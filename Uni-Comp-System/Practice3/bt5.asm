# Bai 5
.data
	my_array: .word 0:100
	menu_prompt: .asciiz "\nMenu \n1. Nhap mang 1 chieu n phan tu so nguyen.\n2. Xuat mang.\n3. Liet ke cac so nguyen to.\n4. Tim gia tri lon nhat trong mang.\n5. Tinh trung binh mang.\n0. Thoat chuong trinh.\n Nhap so tuong ung de chon chuc nang: "
	endl: .asciiz "\n"
	size_in: .asciiz "Moi ban nhap size array (toi da 100): "
	element_in: .asciiz "Nhap phan tu: "
	element_out: .asciiz "Phan tu: "
	prime_out: .asciiz "So nguyen to: "
	max_out: .asciiz "Gia tri lon nhat: "
	avg_out: .asciiz "Gia tri trung binh: "
.text
	main:
		j while_menu
	
	while_menu:
		li $v0, 4
		la $a0, menu_prompt
		syscall
		
		li $v0, 5
		syscall
		move $t0, $v0
		
		beq $t0, 0, exit
		beq $t0, 1, option1
		beq $t0, 2, option2
		beq $t0, 3, option3
		beq $t0, 4, option4
		beq $t0, 5, option5
		
		j while_menu
	
	# cau 1 --------------------- (dung $t1, $t2)
	option1:
		li $v0, 4
		la $a0, size_in
		syscall
		
		li $v0, 5
		syscall
		move $t0, $v0
		
		bgt $t0, 100, exit # neu so luong phan tu lon hon 100'
		
		move $t7, $t0 # $t7 luu size array
			
		li $t1, 0 # luu so luong vao t1
		li $t2, 0 # index array
		
		j ArrInput
	
	ArrInput: # nhap array
		beq $t1, $t7, while_menu
		
		li $v0, 4
		la $a0, element_in
		syscall
		
		li $v0, 5
		syscall
		
		sw $v0, my_array($t2) # dua phan tu vua nhap vao array
		addi $t2, $t2, 4
		
		addi $t1, $t1, 1
		
		j ArrInput
	# -------------------------------------
	
	# cau 2 ------------------------------- (dung $t3, $t4)
	option2:
		li $t3, 0 # array index
		li $t4, 1 # array size
		
		j ArrOutput
	
	ArrOutput: # xuat array
		bgt $t4, $t7, while_menu
		
		li $v0, 4
		la $a0, element_out
		syscall
		
		lw $a0, my_array($t3)

		li $v0, 1
		syscall
		
		li $v0, 4 # in dong moi
		la $a0, endl
		syscall

		addi $t3, $t3, 4
		addi $t4, $t4, 1
				
		j ArrOutput
	# -----------------------------------------
	
	# cau 3 ----------------------------------- (dung $t1, $t2, $t3, $t4, $t5)
	option3:	
		li $t1, 0 # array index
		li $t2, 0 # array size
		
		j PrimeLoop
	
	PrimeLoop:
		beq $t2, $t7, while_menu
		
		li $t3, 2 # i = 2
		
		lw $t4, my_array($t1) # phan tu tai index $t1
		addi $t1, $t1, 4
		
		beq $t4, 0, NotPrime
		beq $t4, 1, NotPrime
		
		j CheckPrime
		
	CheckPrime:
		beq $t3, $t4, IsPrime
		
		div $t4, $t3
		mfhi $t5
		beqz $t5, NotPrime
		addi $t3, $t3, 1
		
		j CheckPrime
	
	IsPrime:
		li $v0, 4
		la $a0, prime_out
		syscall
		
		li $v0, 1
		move $a0, $t4
		syscall
		
		li $v0, 4
		la $a0, endl
		syscall
		
		addi $t2, $t2, 1
		
		j PrimeLoop
	
	NotPrime:
		addi $t2, $t2, 1
	
		j PrimeLoop
	
	# -----------------------------------------
	
	# cau 4 -----------------------------------
	option4:
		li $t1, 0 # array index
		li $t2, 0 # array size
		li $t3, 0 # max
		
		j FindMax
		
	FindMax:
		beq $t2, $t7, MaxPrint
		
		lw $t4, my_array($t1)
		addi $t1, $t1, 4
		
		bge $t4, $t3, SetMax
		
		addi $t2, $t2, 1
		j FindMax
	
	SetMax:
		move $t3, $t4
		
		addi $t2, $t2, 1
		j FindMax
		
	MaxPrint:
		li $v0, 4
		la $a0, max_out
		syscall
		
		li $v0, 1
		move $a0, $t3
		syscall
		
		j while_menu
	
	# -----------------------------------------
	
	# cau 5 -----------------------------------
	option5:
		li $t1, 0 # array index
		li $t2, 0 # array size
		li $t3, 0 # tong
		
		j FindSum
		
	FindSum:
		beq $t2, $t7, GetAvg
		
		lw $t4, my_array($t1)
		addi $t1, $t1, 4
		
		add $t3, $t3, $t4
		
		addi $t2, $t2, 1
		
		j FindSum
		
	GetAvg:
		div $t3, $t7 
		mflo $t4
		
		li $v0, 4
		la $a0, avg_out
		syscall
		
		li $v0, 1
		move $a0, $t4
		syscall
		
		j while_menu
	
	# -----------------------------------------
	
	exit: # thoat chuong trinh
		li $v0, 10
		syscall
