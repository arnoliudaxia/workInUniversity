	.arch armv8-a
	.file	"main.c"
	.text
	.align	2
	.global	max
	.type	max, %function
max:
.LFB0:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, 12]
	str	w1, [sp, 8]
	ldr	w0, [sp, 12]
	ldr	w2, [sp, 8]
	ldr	w1, [sp, 8]
	cmp	w2, w0
	csel	w0, w1, w0, ge
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	max, .-max
	.align	2
	.global	min
	.type	min, %function
min:
.LFB1:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, 12]
	str	w1, [sp, 8]
	ldr	w0, [sp, 8]
	ldr	w2, [sp, 12]
	ldr	w1, [sp, 12]
	cmp	w2, w0
	csel	w0, w1, w0, le
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	min, .-min
	.global	str1
	.section	.rodata
	.align	3
.LC0:
	.string	"01234"
	.section	.data.rel.local,"aw"
	.align	3
	.type	str1, %object
	.size	str1, 8
str1:
	.xword	.LC0
	.global	str2
	.section	.rodata
	.align	3
.LC1:
	.string	"2345"
	.section	.data.rel.local
	.align	3
	.type	str2, %object
	.size	str2, 8
str2:
	.xword	.LC1
	.global	m
	.data
	.align	2
	.type	m, %object
	.size	m, 4
m:
	.word	5
	.global	n
	.align	2
	.type	n, %object
	.size	n, 4
n:
	.word	4
	.text
	.align	2
	.global	matchString
	.type	matchString, %function
matchString:
.LFB2:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	w0, [sp, 28]
	str	w1, [sp, 24]
	mov	w0, 1
	str	w0, [sp, 44]
	adrp	x0, m
	add	x0, x0, :lo12:m
	ldr	w1, [x0]
	ldr	w0, [sp, 28]
	sub	w0, w1, w0
	sub	w2, w0, #1
	adrp	x0, n
	add	x0, x0, :lo12:n
	ldr	w1, [x0]
	ldr	w0, [sp, 24]
	sub	w0, w1, w0
	sub	w0, w0, #1
	mov	w1, w0
	mov	w0, w2
	bl	min
	str	w0, [sp, 36]
	mov	w0, 1
	str	w0, [sp, 40]
	b	.L6
.L8:
	adrp	x0, str1
	add	x0, x0, :lo12:str1
	ldr	x1, [x0]
	ldr	w2, [sp, 28]
	ldr	w0, [sp, 40]
	add	w0, w2, w0
	sxtw	x0, w0
	add	x0, x1, x0
	ldrb	w1, [x0]
	adrp	x0, str2
	add	x0, x0, :lo12:str2
	ldr	x2, [x0]
	ldr	w3, [sp, 24]
	ldr	w0, [sp, 40]
	add	w0, w3, w0
	sxtw	x0, w0
	add	x0, x2, x0
	ldrb	w0, [x0]
	cmp	w1, w0
	bne	.L7
	ldr	w0, [sp, 44]
	add	w0, w0, 1
	str	w0, [sp, 44]
.L7:
	ldr	w0, [sp, 40]
	add	w0, w0, 1
	str	w0, [sp, 40]
.L6:
	ldr	w1, [sp, 40]
	ldr	w0, [sp, 36]
	cmp	w1, w0
	ble	.L8
	ldr	w0, [sp, 44]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	matchString, .-matchString
	.align	2
	.global	searchForOne
	.type	searchForOne, %function
searchForOne:
.LFB3:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	w0, [sp, 28]
	str	wzr, [sp, 44]
	str	wzr, [sp, 40]
	b	.L11
.L13:
	adrp	x0, str1
	add	x0, x0, :lo12:str1
	ldr	x1, [x0]
	ldrsw	x0, [sp, 28]
	add	x0, x1, x0
	ldrb	w1, [x0]
	adrp	x0, str2
	add	x0, x0, :lo12:str2
	ldr	x2, [x0]
	ldrsw	x0, [sp, 40]
	add	x0, x2, x0
	ldrb	w0, [x0]
	cmp	w1, w0
	bne	.L12
	ldr	w1, [sp, 40]
	ldr	w0, [sp, 28]
	bl	matchString
	ldr	w1, [sp, 44]
	bl	max
	str	w0, [sp, 44]
.L12:
	ldr	w0, [sp, 40]
	add	w0, w0, 1
	str	w0, [sp, 40]
.L11:
	adrp	x0, n
	add	x0, x0, :lo12:n
	ldr	w0, [x0]
	ldr	w1, [sp, 40]
	cmp	w1, w0
	blt	.L13
	ldr	w0, [sp, 44]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE3:
	.size	searchForOne, .-searchForOne
	.section	.rodata
	.align	3
.LC2:
	.string	"%d\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB4:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	wzr, [sp, 28]
	str	wzr, [sp, 24]
	b	.L16
.L17:
	ldr	w0, [sp, 24]
	bl	searchForOne
	mov	w1, w0
	ldr	w0, [sp, 28]
	bl	max
	str	w0, [sp, 28]
	ldr	w0, [sp, 24]
	add	w0, w0, 1
	str	w0, [sp, 24]
.L16:
	adrp	x0, m
	add	x0, x0, :lo12:m
	ldr	w0, [x0]
	ldr	w1, [sp, 24]
	cmp	w1, w0
	blt	.L17
	ldr	w1, [sp, 28]
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	printf
	mov	w0, 0
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
