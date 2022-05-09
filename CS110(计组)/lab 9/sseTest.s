	.file	"sseTest.c"
	.text
	.section	.rodata
.LC5:
	.string	"|%g %g| * |%g %g| = |%g %g|\n"
.LC6:
	.string	"|%g %g|   |%g %g|   |%g %g|\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB503:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$464, %rsp
	movl	%edi, -452(%rbp)
	movq	%rsi, -464(%rbp)
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -384(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -376(%rbp)
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -368(%rbp)
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -360(%rbp)
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -416(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -408(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -400(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -392(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -448(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -440(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -432(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -424(%rbp)
	leaq	-448(%rbp), %rax
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rax
	movupd	(%rax), %xmm0
	movaps	%xmm0, -16(%rbp)
	leaq	-448(%rbp), %rax
	addq	$16, %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movupd	(%rax), %xmm0
	movaps	%xmm0, -32(%rbp)
	movl	$789, -40(%rbp)
	movl	$0, -36(%rbp)
	jmp	.L4
.L14:
	movl	-36(%rbp), %eax
	addl	%eax, %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	-384(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rax
	movupd	(%rax), %xmm0
	movaps	%xmm0, -64(%rbp)
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	-416(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -280(%rbp)
	movq	-280(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -288(%rbp)
	movsd	-288(%rbp), %xmm0
	unpcklpd	%xmm0, %xmm0
	movaps	%xmm0, -80(%rbp)
	movl	-36(%rbp), %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,8), %rdx
	leaq	-416(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -264(%rbp)
	movq	-264(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -272(%rbp)
	movsd	-272(%rbp), %xmm0
	unpcklpd	%xmm0, %xmm0
	movaps	%xmm0, -96(%rbp)
	movapd	-64(%rbp), %xmm0
	movaps	%xmm0, -240(%rbp)
	movapd	-80(%rbp), %xmm0
	movaps	%xmm0, -256(%rbp)
	movapd	-240(%rbp), %xmm0
	mulpd	-256(%rbp), %xmm0
	movapd	-16(%rbp), %xmm1
	movaps	%xmm1, -208(%rbp)
	movaps	%xmm0, -224(%rbp)
	movapd	-208(%rbp), %xmm0
	addpd	-224(%rbp), %xmm0
	movaps	%xmm0, -16(%rbp)
	movapd	-64(%rbp), %xmm0
	movaps	%xmm0, -176(%rbp)
	movapd	-96(%rbp), %xmm0
	movaps	%xmm0, -192(%rbp)
	movapd	-176(%rbp), %xmm0
	mulpd	-192(%rbp), %xmm0
	movapd	-32(%rbp), %xmm1
	movaps	%xmm1, -144(%rbp)
	movaps	%xmm0, -160(%rbp)
	movapd	-144(%rbp), %xmm0
	addpd	-160(%rbp), %xmm0
	movaps	%xmm0, -32(%rbp)
	addl	$1, -36(%rbp)
.L4:
	cmpl	$1, -36(%rbp)
	jle	.L14
	movl	$987, -100(%rbp)
	leaq	-448(%rbp), %rax
	movq	%rax, -328(%rbp)
	movapd	-16(%rbp), %xmm0
	movaps	%xmm0, -352(%rbp)
	movapd	-352(%rbp), %xmm0
	movq	-328(%rbp), %rax
	movups	%xmm0, (%rax)
	leaq	-448(%rbp), %rax
	addq	$16, %rax
	movq	%rax, -304(%rbp)
	movapd	-32(%rbp), %xmm0
	movaps	%xmm0, -320(%rbp)
	movapd	-320(%rbp), %xmm0
	movq	-304(%rbp), %rax
	movups	%xmm0, (%rax)
	movsd	-432(%rbp), %xmm5
	movsd	-448(%rbp), %xmm4
	movsd	-400(%rbp), %xmm3
	movsd	-416(%rbp), %xmm2
	movsd	-368(%rbp), %xmm1
	movsd	-384(%rbp), %xmm0
	movl	$.LC5, %edi
	movl	$6, %eax
	call	printf
	movsd	-424(%rbp), %xmm5
	movsd	-440(%rbp), %xmm4
	movsd	-392(%rbp), %xmm3
	movsd	-408(%rbp), %xmm2
	movsd	-360(%rbp), %xmm1
	movsd	-376(%rbp), %xmm0
	movl	$.LC6, %edi
	movl	$6, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE503:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.align 8
.LC2:
	.long	0
	.long	1074266112
	.align 8
.LC3:
	.long	0
	.long	1074790400
	.ident	"GCC: (Uos 8.3.0.3-3+rebuild) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
