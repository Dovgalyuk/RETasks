	.file	"main.c"
	.text
	.globl	f1
	.def	f1;	.scl	2;	.type	32;	.endef
	.seh_proc	f1
f1:
# Чтобы передать параметры функции используют стек и перед тем чтобы вызвать параметры используется команда pushq для помещения в этот стек.
# ecx,edx и eax это регисторы где хранятся переменные.
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %eax
	movl	$0, %edx
	divl	24(%rbp)
	popq	%rbp
	ret
	.seh_endproc
	.globl	f2
	.def	f2;	.scl	2;	.type	32;	.endef
	.seh_proc	f2
f2:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %ecx
	movl	%ecx, %edx
	movl	$3435973837, %eax
	imulq	%rdx, %rax
	shrq	$32, %rax
	movl	%eax, %edx
	shrl	$3, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	f3
	.def	f3;	.scl	2;	.type	32;	.endef
	.seh_proc	f3
f3:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	andl	$15, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	f4
	.def	f4;	.scl	2;	.type	32;	.endef
	.seh_proc	f4
f4:
# Здесь организовано ветвление на основе условного перехода, где в первую очередь выполняются такие команды как CMP, SUB или AND.
# Эти команды работают с флагами процессора и после них идет условный переход по нужным местам.
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$10, 16(%rbp)
	je	.L8
	cmpl	$10, 16(%rbp)
	jg	.L9
	cmpl	$1, 16(%rbp)
	je	.L10
	cmpl	$6, 16(%rbp)
	je	.L11
	jmp	.L9
.L10:
# Метка куда идет переход
	movl	$5, %eax
	jmp	.L12
.L11:
	movl	$7, %eax
	jmp	.L12
.L8:
	movl	$3, %eax
	jmp	.L12
.L9:
	movl	$0, %eax
.L12:
	popq	%rbp
	ret
	.seh_endproc
	.globl	f5
	.def	f5;	.scl	2;	.type	32;	.endef
	.seh_proc	f5
f5:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$10000, 16(%rbp)
	je	.L14
	cmpl	$10000, 16(%rbp)
	jg	.L15
	cmpl	$6000, 16(%rbp)
	je	.L16
	cmpl	$6000, 16(%rbp)
	jg	.L15
	cmpl	$1000, 16(%rbp)
	je	.L17
	cmpl	$1000, 16(%rbp)
	jg	.L15
	cmpl	$10, 16(%rbp)
	je	.L18
	cmpl	$10, 16(%rbp)
	jg	.L15
	cmpl	$1, 16(%rbp)
	je	.L19
	cmpl	$6, 16(%rbp)
	je	.L20
	jmp	.L15
.L19:
	movl	$5, %eax
	jmp	.L21
.L20:
	movl	$7, %eax
	jmp	.L21
.L18:
	movl	$3, %eax
	jmp	.L21
.L17:
	movl	$9, %eax
	jmp	.L21
.L16:
	movl	$8, %eax
	jmp	.L21
.L14:
	movl	$4, %eax
	jmp	.L21
.L15:
	movl	$0, %eax
.L21:
	popq	%rbp
	ret
	.seh_endproc
	.globl	f6
	.def	f6;	.scl	2;	.type	32;	.endef
	.seh_proc	f6
f6:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$0, 16(%rbp)
	jne	.L23
	movl	$1, %eax
	jmp	.L24
.L23:
	movl	$2, %eax
.L24:
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	f7
	.def	f7;	.scl	2;	.type	32;	.endef
	.seh_proc	f7
f7:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$50, 16(%rbp)
	jne	.L27
	movl	$12, %eax
	jmp	.L28
.L27:
	movl	$26, %eax
.L28:
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	f8
	.def	f8;	.scl	2;	.type	32;	.endef
	.seh_proc	f8
f8:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	cmpl	$0, 16(%rbp)
	jne	.L31
	movl	32(%rbp), %eax
	cmpl	24(%rbp), %eax
	jne	.L32
.L31:
	movl	24(%rbp), %eax
	jmp	.L33
.L32:
	movl	16(%rbp), %eax
.L33:
	popq	%rbp
	ret
	.seh_endproc
	.globl	s
	.bss
	.align 32
s:
	.space 800
	.globl	t
	.align 32
t:
	.space 400
	.text
	.globl	f9
	.def	f9;	.scl	2;	.type	32;	.endef
	.seh_proc	f9
f9:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	$0, -4(%rbp)
	jmp	.L35
.L36:
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
.L35:
	cmpl	$100, -4(%rbp)
	jne	.L36
	nop
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	f10
	.def	f10;	.scl	2;	.type	32;	.endef
	.seh_proc	f10
f10:
# Для начала используется условный переход и регистр ecx, где выставляется количество циклов.
# Далее указывается метка .L38:, в которой и выполняется цикл по уменьшению регистра ecx 
# Далее идет сравнение цикла и если ecx не равняется нулю то идем дальше к метке, в другом случае идет выполнение тела цикла 
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	jmp	.L38
.L39:
	subl	$1, 16(%rbp)
	call	g
.L38:
	cmpl	$0, 16(%rbp)
	jne	.L39
	nop
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	f11
	.def	f11;	.scl	2;	.type	32;	.endef
	.seh_proc	f11
f11:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
.L41:
	cmpl	$0, 16(%rbp)
	je	.L43
	subl	$1, 16(%rbp)
	call	g
	jmp	.L41
.L43:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	f12
	.def	f12;	.scl	2;	.type	32;	.endef
	.seh_proc	f12
f12:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
.L45:
	subl	$1, 16(%rbp)
	call	g
	cmpl	$0, 16(%rbp)
	jne	.L45
	nop
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev1, Built by MSYS2 project) 12.2.0"
	.def	g;	.scl	2;	.type	32;	.endef
