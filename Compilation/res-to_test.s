	.file	"variant5.c"
	.text
	.globl	f1
	.type	f1, @function
f1:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	$0, %edx
	divl	-8(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	f1, .-f1
	.globl	f2
	.type	f2, @function
f2:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	movl	$3435973837, %eax
	imulq	%rdx, %rax
	shrq	$32, %rax
	shrl	$3, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	f2, .-f2
	.globl	f3
	.type	f3, @function
f3:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	andl	$15, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	f3, .-f3
	.globl	f4
	.type	f4, @function
f4:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$20, -4(%rbp)
	jg	.L8
	cmpl	$0, -4(%rbp)
	jle	.L9
	cmpl	$20, -4(%rbp)
	ja	.L9
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L11(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L11(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L11:
	.long	.L9-.L11
	.long	.L15-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L14-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L13-.L11
	.long	.L9-.L11
	.long	.L12-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L9-.L11
	.long	.L10-.L11
	.text
.L8:
	cmpl	$62, -4(%rbp)
	je	.L16
	jmp	.L9
.L15:
	movl	$5, %eax
	jmp	.L17
.L14:
	movl	$7, %eax
	jmp	.L17
.L13:
	movl	$3, %eax
	jmp	.L17
.L12:
	movl	$4, %eax
	jmp	.L17
.L16:
	movl	$1, %eax
	jmp	.L17
.L10:
	movl	$8, %eax
	jmp	.L17
.L9:
	movl	$0, %eax
.L17:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	f4, .-f4
	.globl	f5
	.type	f5, @function
f5:
.LFB4:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	subl	$3, %eax
	cmpl	$6, %eax
	ja	.L19
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L21(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L21(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L21:
	.long	.L26-.L21
	.long	.L19-.L21
	.long	.L25-.L21
	.long	.L24-.L21
	.long	.L23-.L21
	.long	.L22-.L21
	.long	.L20-.L21
	.text
.L26:
	movl	$5, %eax
	jmp	.L27
.L25:
	movl	$7, %eax
	jmp	.L27
.L24:
	movl	$3, %eax
	jmp	.L27
.L22:
	movl	$4, %eax
	jmp	.L27
.L20:
	movl	$1, %eax
	jmp	.L27
.L23:
	movl	$8, %eax
	jmp	.L27
.L19:
	movl	$0, %eax
.L27:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	f5, .-f5
	.globl	f6
	.type	f6, @function
f6:
.LFB5:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L29
	movl	$1, %eax
	jmp	.L30
.L29:
	movl	$2, %eax
.L30:
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	f6, .-f6
	.globl	f7
	.type	f7, @function
f7:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L33
	cmpl	$0, -12(%rbp)
	je	.L33
	movl	-8(%rbp), %eax
	jmp	.L34
.L33:
	movl	-12(%rbp), %eax
.L34:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	f7, .-f7
	.globl	f8
	.type	f8, @function
f8:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L36
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jne	.L37
.L36:
	movl	-8(%rbp), %eax
	jmp	.L38
.L37:
	movl	-4(%rbp), %eax
.L38:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	f8, .-f8
	.globl	s
	.bss
	.align 32
	.type	s, @object
	.size	s, 800
s:
	.zero	800
	.globl	t
	.align 32
	.type	t, @object
	.size	t, 400
t:
	.zero	400
	.text
	.globl	f9
	.type	f9, @function
f9:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, -4(%rbp)
	jmp	.L40
.L41:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	t(%rip), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	s(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	addl	$1, -4(%rbp)
.L40:
	cmpl	$100, -4(%rbp)
	jne	.L41
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	f9, .-f9
	.globl	g
	.type	g, @function
g:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	g, .-g
	.globl	f10
	.type	f10, @function
f10:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	movl	%edi, -4(%rbp)
	jmp	.L44
.L45:
	subl	$1, -4(%rbp)
	movl	$0, %eax
	call	g
.L44:
	cmpl	$0, -4(%rbp)
	jne	.L45
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	f10, .-f10
	.globl	f11
	.type	f11, @function
f11:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	movl	%edi, -4(%rbp)
.L47:
	cmpl	$0, -4(%rbp)
	je	.L49
	subl	$1, -4(%rbp)
	movl	$0, %eax
	call	g
	jmp	.L47
.L49:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	f11, .-f11
	.globl	f12
	.type	f12, @function
f12:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L51
.L54:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$5, %eax
	je	.L55
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L53
.L55:
	nop
.L53:
	addl	$1, -4(%rbp)
.L51:
	cmpl	$9, -4(%rbp)
	jle	.L54
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	f12, .-f12
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.1.0-1ubuntu1~20.04) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
