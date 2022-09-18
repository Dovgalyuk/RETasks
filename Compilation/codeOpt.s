	.file	"variant4.c"
	.text
	.p2align 4
	.globl	_Z2fdj
	.def	_Z2fdj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2fdj
_Z2fdj:
.LFB0:
	.seh_endprologue
	movl	$3435973837, %edx
	movl	%ecx, %eax
	imulq	%rdx, %rax
	shrq	$35, %rax
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z3fd1j
	.def	_Z3fd1j;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3fd1j
_Z3fd1j:
.LFB1:
	.seh_endprologue
	movl	%ecx, %eax
	shrl	$4, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z3fd2jj
	.def	_Z3fd2jj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3fd2jj
_Z3fd2jj:
.LFB2:
	.seh_endprologue
	movl	%edx, %r9d
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%r9d
	movl	%edx, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z2f2i
	.def	_Z2f2i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f2i
_Z2f2i:
.LFB3:
	.seh_endprologue
	cmpl	$1000, %ecx
	je	.L8
	jg	.L7
	cmpl	$6, %ecx
	movl	$7, %eax
	je	.L5
	cmpl	$10, %ecx
	movl	$3, %eax
	jne	.L16
.L5:
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	xorl	%eax, %eax
	cmpl	$1, %ecx
	sete	%al
	leal	(%rax,%rax,4), %eax
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	cmpl	$6000, %ecx
	movl	$8, %eax
	je	.L5
	xorl	%eax, %eax
	cmpl	$10000, %ecx
	sete	%al
	sall	$2, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	movl	$9, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z2f3i
	.def	_Z2f3i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f3i
_Z2f3i:
.LFB4:
	.seh_endprologue
	xorl	%eax, %eax
	subl	$3, %ecx
	cmpl	$6, %ecx
	ja	.L17
	leaq	CSWTCH.6(%rip), %rax
	movl	(%rax,%rcx,4), %eax
.L17:
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z3if2i
	.def	_Z3if2i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3if2i
_Z3if2i:
.LFB5:
	.seh_endprologue
	movl	$26, %edx
	movl	$12, %eax
	cmpl	$50, %ecx
	cmovne	%edx, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z3if3iii
	.def	_Z3if3iii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3if3iii
_Z3if3iii:
.LFB6:
	.seh_endprologue
	testl	%ecx, %ecx
	movl	%edx, %eax
	je	.L26
	testl	%r8d, %r8d
	je	.L26
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	movl	%r8d, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z3if4iii
	.def	_Z3if4iii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3if4iii
_Z3if4iii:
.LFB7:
	.seh_endprologue
	testl	%ecx, %ecx
	jne	.L34
	xorl	%eax, %eax
	cmpl	%edx, %r8d
	je	.L34
	ret
	.p2align 4,,10
	.p2align 3
.L34:
	movl	%edx, %eax
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z2f2v
	.def	_Z2f2v;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f2v
_Z2f2v:
.LFB8:
	.seh_endprologue
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
	.seh_endproc
	.p2align 4
	.globl	_Z2f1i
	.def	_Z2f1i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f1i
_Z2f1i:
.LFB9:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	testl	%ecx, %ecx
	movl	%ecx, %ebx
	je	.L39
	.p2align 4,,10
	.p2align 3
.L41:
	call	_Z1gv
	subl	$1, %ebx
	testl	%ebx, %ebx
	jne	.L41
.L39:
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z3f22i
	.def	_Z3f22i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3f22i
_Z3f22i:
.LFB10:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	testl	%ecx, %ecx
	movl	%ecx, %ebx
	je	.L46
	.p2align 4,,10
	.p2align 3
.L48:
	call	_Z1gv
	subl	$1, %ebx
	testl	%ebx, %ebx
	jne	.L48
.L46:
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z2f4i
	.def	_Z2f4i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f4i
_Z2f4i:
.LFB11:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, %ebx
	.p2align 4,,10
	.p2align 3
.L54:
	call	_Z1gv
	subl	$1, %ebx
	testl	%ebx, %ebx
	jne	.L54
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 16
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
t:
	.space 400
	.globl	s
	.align 32
s:
	.space 800
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 11.2.0"
	.def	_Z1gv;	.scl	2;	.type	32;	.endef
