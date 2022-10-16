	.file	"variant5.c"
	.text
	.p2align 4
	.globl	f1
	.type	f1, @function
f1:
.LFB0:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	xorl	%edx, %edx
	divl	%esi
	ret
	.cfi_endproc
.LFE0:
	.size	f1, .-f1
	.p2align 4
	.globl	f2
	.type	f2, @function
f2:
.LFB1:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	movl	$3435973837, %edx
	imulq	%rdx, %rax
	shrq	$35, %rax
	ret
	.cfi_endproc
.LFE1:
	.size	f2, .-f2
	.p2align 4
	.globl	f3
	.type	f3, @function
f3:
.LFB2:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	andl	$15, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	f3, .-f3
	.p2align 4
	.globl	f4
	.type	f4, @function
f4:
.LFB3:
	.cfi_startproc
	endbr64
	cmpl	$20, %edi
	jg	.L6
	xorl	%eax, %eax
	testl	%edi, %edi
	jle	.L5
	cmpl	$20, %edi
	ja	.L8
	leaq	.L10(%rip), %rdx
	movl	%edi, %edi
	movslq	(%rdx,%rdi,4), %rax
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L10:
	.long	.L8-.L10
	.long	.L15-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L13-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L12-.L10
	.long	.L8-.L10
	.long	.L11-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L9-.L10
	.text
	.p2align 4,,10
	.p2align 3
.L8:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L15:
	movl	$5, %eax
.L5:
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	xorl	%eax, %eax
	cmpl	$62, %edi
	sete	%al
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	movl	$8, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	movl	$3, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L11:
	movl	$4, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L13:
	movl	$7, %eax
	ret
	.cfi_endproc
.LFE3:
	.size	f4, .-f4
	.p2align 4
	.globl	f5
	.type	f5, @function
f5:
.LFB4:
	.cfi_startproc
	endbr64
	subl	$3, %edi
	xorl	%eax, %eax
	cmpl	$6, %edi
	ja	.L17
	leaq	CSWTCH.6(%rip), %rax
	movl	(%rax,%rdi,4), %eax
.L17:
	ret
	.cfi_endproc
.LFE4:
	.size	f5, .-f5
	.p2align 4
	.globl	f6
	.type	f6, @function
f6:
.LFB5:
	.cfi_startproc
	endbr64
	cmpl	$1, %edi
	movl	$1, %eax
	sbbl	$-1, %eax
	ret
	.cfi_endproc
.LFE5:
	.size	f6, .-f6
	.p2align 4
	.globl	f7
	.type	f7, @function
f7:
.LFB6:
	.cfi_startproc
	endbr64
	movl	%esi, %eax
	testl	%edi, %edi
	je	.L26
	testl	%edx, %edx
	je	.L26
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	movl	%edx, %eax
	ret
	.cfi_endproc
.LFE6:
	.size	f7, .-f7
	.p2align 4
	.globl	f8
	.type	f8, @function
f8:
.LFB7:
	.cfi_startproc
	endbr64
	testl	%edi, %edi
	jne	.L34
	xorl	%eax, %eax
	cmpl	%esi, %edx
	je	.L34
	ret
	.p2align 4,,10
	.p2align 3
.L34:
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE7:
	.size	f8, .-f8
	.p2align 4
	.globl	f9
	.type	f9, @function
f9:
.LFB8:
	.cfi_startproc
	endbr64
	leaq	t(%rip), %rax
	leaq	s(%rip), %rdx
	leaq	400(%rax), %rcx
	.p2align 4,,10
	.p2align 3
.L37:
	movq	%rax, (%rdx)
	addq	$4, %rax
	addq	$8, %rdx
	cmpq	%rcx, %rax
	jne	.L37
	ret
	.cfi_endproc
.LFE8:
	.size	f9, .-f9
	.p2align 4
	.globl	g
	.type	g, @function
g:
.LFB9:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE9:
	.size	g, .-g
	.p2align 4
	.globl	f10
	.type	f10, @function
f10:
.LFB10:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE10:
	.size	f10, .-f10
	.p2align 4
	.globl	f11
	.type	f11, @function
f11:
.LFB15:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE15:
	.size	f11, .-f11
	.p2align 4
	.globl	f12
	.type	f12, @function
f12:
.LFB12:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	movl	$10, %edx
	movl	$5, %esi
	.p2align 4,,10
	.p2align 3
.L44:
	leal	2(%rax), %ecx
	cmpl	$4, %eax
	movl	%ecx, %eax
	cmove	%esi, %eax
	subl	$1, %edx
	jne	.L44
	movl	%eax, (%rdi)
	ret
	.cfi_endproc
.LFE12:
	.size	f12, .-f12
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	endbr64
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.section	.rodata
	.align 16
	.type	CSWTCH.6, @object
	.size	CSWTCH.6, 28
CSWTCH.6:
	.long	5
	.long	0
	.long	7
	.long	3
	.long	8
	.long	4
	.long	1
	.globl	t
	.bss
	.align 32
	.type	t, @object
	.size	t, 400
t:
	.zero	400
	.globl	s
	.align 32
	.type	s, @object
	.size	s, 800
s:
	.zero	800
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
