.data
test_input: .word 3 6 7 8

.text
main:
	add t0, x0, x0
	addi t1, x0, 4
	la t2, test_input
main_loop:
	beq t0, t1, main_exit
	slli t3, t0, 2
	add t4, t2, t3
	lw a0, 0(t4) # a0 is 参数

	addi sp, sp, -20
	sw t0, 0(sp)
	sw t1, 4(sp)
	sw t2, 8(sp)
	sw t3, 12(sp)
	sw t4, 16(sp)
	# t0-t4预留

	jal ra, factorial

	lw t0, 0(sp)
	lw t1, 4(sp)
	lw t2, 8(sp)
	lw t3, 12(sp)
	lw t4, 16(sp)
	addi sp, sp, 20

	addi a1, a0, 0
	addi a0, x0, 1
	ecall # Print Result
	addi a1, x0, ' '
	addi a0, x0, 11
	ecall
	
	addi t0, t0, 1
	jal x0, main_loop
main_exit:  
	addi a0, x0, 10
	ecall # Exit

factorial:
	# for(int i=a0-1;i>1;i--)
	# {
	# a0*=i;
	# }
	# return a0;
	addi sp, sp, -4
	sw a1,0(sp)

		li t1,1

		mv t0,a0
		addi t0,t0,-1

		again:
		mv a1,t0
		
			addi sp, sp, -4
			sw ra,0(sp)
			jal Muti
			lw ra,0(sp)
			addi sp, sp, 4

		addi t0,t0,-1 
		bne  t0,t1,again

	lw a1,0(sp)
	addi sp, sp, 4
	ret

Muti:
	#a0=a0*a1
	mv t3,a0
	agMuti:
	add a0,a0,t3
	addi a1,a1,-1
	bne a1,t1,agMuti
	ret

	