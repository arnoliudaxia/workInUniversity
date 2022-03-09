	.text

main:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
	lui	a5,%hi(str1)
	lw	a5,%lo(str1)(a5)
	mv	a0,a5
	call	strlen
	mv	a5,a0
	mv	a4,a5
	lui	a5,%hi(m)
	sw	a4,%lo(m)(a5)
	lui	a5,%hi(str2)
	lw	a5,%lo(str2)(a5)
	mv	a0,a5
	call	strlen
	mv	a5,a0
	mv	a4,a5
	lui	a5,%hi(n)
	sw	a4,%lo(n)(a5)
	sw	zero,-20(s0)
	sw	zero,-24(s0)
	j	.L22
max:
	addi	sp,sp,-32
	sw	s0,28(sp)
	addi	s0,sp,32
	sw	a0,-20(s0)
	sw	a1,-24(s0)
	lw	a4,-20(s0)
	lw	a5,-24(s0)
	bge	a5,a4,.L3
	mv	a5,a4
.L3:
	mv	a0,a5
	lw	s0,28(sp)
	addi	sp,sp,32
	jr	ra
min:
	addi	sp,sp,-32
	sw	s0,28(sp)
	addi	s0,sp,32
	sw	a0,-20(s0)
	sw	a1,-24(s0)
	lw	a4,-24(s0)
	lw	a5,-20(s0)
	ble	a5,a4,.L6
	mv	a5,a4
.L6:
	mv	a0,a5
	lw	s0,28(sp)
	addi	sp,sp,32
	jr	ra


str1:
	.word	.LC0
	.globl	str2
	.section	.rodata
	.align	2



n:
	.word	4
	.text
	.align	1
	.globl	matchString
	.type	matchString, @function
matchString:
	addi	sp,sp,-48
	sw	ra,44(sp)
	sw	s0,40(sp)
	addi	s0,sp,48
	sw	a0,-36(s0)
	sw	a1,-40(s0)
	li	a5,1
	sw	a5,-20(s0)
	lui	a5,%hi(m)
	lw	a4,%lo(m)(a5)
	lw	a5,-36(s0)
	sub	a5,a4,a5
	addi	a3,a5,-1
	lui	a5,%hi(n)
	lw	a4,%lo(n)(a5)
	lw	a5,-40(s0)
	sub	a5,a4,a5
	addi	a5,a5,-1
	mv	a1,a5
	mv	a0,a3
	call	min
	sw	a0,-28(s0)
	li	a5,1
	sw	a5,-24(s0)
.L8:
	lui	a5,%hi(str1)
	lw	a5,%lo(str1)(a5)
	lw	a3,-36(s0)
	lw	a4,-24(s0)
	add	a4,a3,a4
	add	a5,a5,a4
	lbu	a5,0(a5)
	sb	a5,-29(s0)
	lui	a5,%hi(str2)
	lw	a5,%lo(str2)(a5)
	lw	a3,-40(s0)
	lw	a4,-24(s0)
	add	a4,a3,a4
	add	a5,a5,a4
	lbu	a5,0(a5)
	sb	a5,-30(s0)
	lbu	a4,-29(s0)
	lbu	a5,-30(s0)
	bne	a4,a5,.L12
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
	lw	a4,-24(s0)
	lw	a5,-28(s0)
	bgt	a4,a5,.L13
	j	.L8
.L12:
	nop
	j	.L10
.L13:
	nop
.L10:
	lw	a5,-20(s0)
	mv	a0,a5
	lw	ra,44(sp)
	lw	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	matchString, .-matchString
	.align	1
	.globl	searchForOne
	.type	searchForOne, @function
searchForOne:
	addi	sp,sp,-48
	sw	ra,44(sp)
	sw	s0,40(sp)
	addi	s0,sp,48
	sw	a0,-36(s0)
	sw	zero,-20(s0)
	lui	a5,%hi(str1)
	lw	a4,%lo(str1)(a5)
	lw	a5,-36(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	sb	a5,-25(s0)
	sw	zero,-24(s0)
.L15:
	lui	a5,%hi(str2)
	lw	a4,%lo(str2)(a5)
	lw	a5,-24(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	sb	a5,-26(s0)
	lbu	a4,-25(s0)
	lbu	a5,-26(s0)
	bne	a4,a5,.L20
	lw	a1,-24(s0)
	lw	a0,-36(s0)
	call	matchString
	mv	a5,a0
	lw	a1,-20(s0)
	mv	a0,a5
	call	max
	sw	a0,-20(s0)
	j	.L17
.L20:
	nop
.L17:
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
	lui	a5,%hi(n)
	lw	a5,%lo(n)(a5)
	lw	a4,-24(s0)
	bge	a4,a5,.L18
	j	.L15
.L18:
	lw	a5,-20(s0)
	mv	a0,a5
	lw	ra,44(sp)
	lw	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	searchForOne, .-searchForOne
	.section	.rodata
	.align	2

.L23:
	lw	a0,-24(s0)
	call	searchForOne
	mv	a5,a0
	mv	a1,a5
	lw	a0,-20(s0)
	call	max
	sw	a0,-20(s0)
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
.L22:
	lui	a5,%hi(m)
	lw	a5,%lo(m)(a5)
	lw	a4,-24(s0)
	blt	a4,a5,.L23
	lw	a1,-20(s0)
	lui	a5,%hi(.LC2)
	addi	a0,a5,%lo(.LC2)
	call	printf
	li	a5,0
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (GNU) 10.1.0"
