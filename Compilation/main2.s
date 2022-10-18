	.file	"main.c"
	.text
	.p2align 4
	.globl	f1
	.def	f1;	.scl	2;	.type	32;	.endef
	.seh_proc	f1
f1:
	.seh_endprologue
	movl	%ecx, %eax
	movl	%edx, %ecx
	xorl	%edx, %edx
	divl	%ecx
	ret
	.seh_endproc
	.p2align 4
	.globl	f2
	.def	f2;	.scl	2;	.type	32;	.endef
	.seh_proc	f2
f2:
	.seh_endprologue
	movl	$3435973837, %edx
	movl	%ecx, %eax
	imulq	%rdx, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %edx
	movl	%ecx, %eax
	addl	%edx, %edx
	subl	%edx, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	f3
	.def	f3;	.scl	2;	.type	32;	.endef
	.seh_proc	f3
f3:
	.seh_endprologue
	movl	%ecx, %eax
	andl	$15, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	f4
	.def	f4;	.scl	2;	.type	32;	.endef
	.seh_proc	f4
f4:
	.seh_endprologue
	xorl	%eax, %eax
	subl	$1, %ecx
	cmpl	$9, %ecx
	ja	.L5
	leaq	CSWTCH.6(%rip), %rax
	movl	(%rax,%rcx,4), %eax
.L5:
	ret
	.seh_endproc
	.p2align 4
	.globl	f5
	.def	f5;	.scl	2;	.type	32;	.endef
	.seh_proc	f5
f5:
	.seh_endprologue
	cmpl	$1000, %ecx
	je	.L11
	jg	.L10
	movl	$7, %eax
	cmpl	$6, %ecx
	je	.L8
	movl	$3, %eax
	cmpl	$10, %ecx
	jne	.L19
.L8:
	ret
	.p2align 4,,10
	.p2align 3
.L19:
	xorl	%eax, %eax
	cmpl	$1, %ecx
	sete	%al
	leal	(%rax,%rax,4), %eax
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	movl	$8, %eax
	cmpl	$6000, %ecx
	je	.L8
	xorl	%eax, %eax
	cmpl	$10000, %ecx
	sete	%al
	sall	$2, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L11:
	movl	$9, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	f6
	.def	f6;	.scl	2;	.type	32;	.endef
	.seh_proc	f6
f6:
	.seh_endprologue
	movl	$1, %eax
	cmpl	$1, %ecx
	sbbl	$-1, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	f7
	.def	f7;	.scl	2;	.type	32;	.endef
	.seh_proc	f7
f7:
	.seh_endprologue
	movl	$12, %edx
	movl	$26, %eax
	cmpl	$50, %ecx
	cmove	%edx, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	f8
	.def	f8;	.scl	2;	.type	32;	.endef
	.seh_proc	f8
f8:
	.seh_endprologue
	testl	%ecx, %ecx
	jne	.L30
	xorl	%eax, %eax
	cmpl	%edx, %r8d
	je	.L30
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	movl	%edx, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	f9
	.def	f9;	.scl	2;	.type	32;	.endef
	.seh_proc	f9
f9:
	.seh_endprologue
	leaq	t(%rip), %rax
	leaq	s(%rip), %rdx
	leaq	400(%rax), %rcx
	.p2align 4,,10
	.p2align 3
.L33:
	movq	%rax, (%rdx)
	addq	$4, %rax
	addq	$8, %rdx
	cmpq	%rcx, %rax
	jne	.L33
	ret
	.seh_endproc
	.p2align 4
	.globl	f10
	.def	f10;	.scl	2;	.type	32;	.endef
	.seh_proc	f10
f10:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, %ebx
	testl	%ecx, %ecx
	je	.L35
	.p2align 4,,10
	.p2align 3
.L37:
	subl	$1, %ebx
	call	g
	testl	%ebx, %ebx
	jne	.L37
.L35:
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.p2align 4
	.globl	f11
	.def	f11;	.scl	2;	.type	32;	.endef
	.seh_proc	f11
f11:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, %ebx
	testl	%ecx, %ecx
	je	.L42
	.p2align 4,,10
	.p2align 3
.L44:
	subl	$1, %ebx
	call	g
	testl	%ebx, %ebx
	jne	.L44
.L42:
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.p2align 4
	.globl	f12
	.def	f12;	.scl	2;	.type	32;	.endef
	.seh_proc	f12
f12:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, %ebx
	.p2align 4,,10
	.p2align 3
.L50:
	subl	$1, %ebx
	call	g
	testl	%ebx, %ebx
	jne	.L50
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 32
CSWTCH.6:
	.long	5
	.long	0
	.long	0
	.long	0
	.long	0
	.long	7
	.long	0
	.long	0
	.long	0
	.long	3
	.globl	t
	.bss
	.align 32
t:
	.space 400
	.globl	s
	.align 32
s:
	.space 800
	.ident	"GCC: (Rev1, Built by MSYS2 project) 12.2.0"
	.def	g;	.scl	2;	.type	32;	.endef
