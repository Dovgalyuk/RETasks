	.file	"variant4.c"
	.text
	.globl	_Z2fdj
	.def	_Z2fdj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2fdj
_Z2fdj: #параметры функций передаются через стек 
#Перед вызовом процедуры параметры необходимо поместить в стек с помощью команды pushq.
#Если бы параметров было больше одного, они могли бы передаваться или в прямом, или в обратном порядке
#переменные хранятся в регистрах eax, edx, ecx ... У остальных функций переменные храняться также
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	movl	%eax, %edx
	movl	$3435973837, %eax
	imulq	%rdx, %rax
	shrq	$32, %rax
	shrl	$3, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3fd1j
	.def	_Z3fd1j;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3fd1j
_Z3fd1j:#переменные хранятся в регистрах eax ecx
.LFB1:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	shrl	$4, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3fd2jj
	.def	_Z3fd2jj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3fd2jj
_Z3fd2jj:#переменные хранятся в регистрах eax, edx, ecx 
.LFB2:
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
	movl	%edx, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z2f2i
	.def	_Z2f2i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f2i
_Z2f2i:
.LFB3: #ветвление организовано с помощью команды условного перехода
#сначала выполняются такие команды, как CMP, AND или SUB, влияющие на флаги состояния процессора. 
#Затем выполняется команда условного перехода, которая анализирует значение нужных флагов, 
#и в случае если они установлены, выполняют переход по указанному адресу
#переменные хранятся в регистрах eax, ecx 
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$10000, 16(%rbp)
	je	.L8
	cmpl	$10000, 16(%rbp)
	jg	.L9
	cmpl	$6000, 16(%rbp)
	je	.L10
	cmpl	$6000, 16(%rbp)
	jg	.L9
	cmpl	$1000, 16(%rbp)
	je	.L11
	cmpl	$1000, 16(%rbp)
	jg	.L9
	cmpl	$10, 16(%rbp)
	je	.L12
	cmpl	$10, 16(%rbp)
	jg	.L9
	cmpl	$1, 16(%rbp)
	je	.L13
	cmpl	$6, 16(%rbp)
	je	.L14
	jmp	.L9
.L13: #ветвление организовано с помощью команды безусловного перехода: указывается метка команды, на которую надо перейти
	movl	$5, %eax
	jmp	.L15
.L14:
	movl	$7, %eax
	jmp	.L15
.L12:
	movl	$3, %eax
	jmp	.L15
.L11:
	movl	$9, %eax
	jmp	.L15
.L10:
	movl	$8, %eax
	jmp	.L15
.L8:
	movl	$4, %eax
	jmp	.L15
.L9:
	movl	$0, %eax
.L15:
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z2f3i
	.def	_Z2f3i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f3i
_Z2f3i:#переменные хранятся в регистрах eax, ecx
.LFB4:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	subl	$3, %eax
	cmpl	$6, %eax
	ja	.L17
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L19(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L19(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L19:
	.long	.L24-.L19
	.long	.L17-.L19
	.long	.L23-.L19
	.long	.L22-.L19
	.long	.L21-.L19
	.long	.L20-.L19
	.long	.L18-.L19
	.text
.L24:
	movl	$5, %eax
	jmp	.L25
.L23:
	movl	$7, %eax
	jmp	.L25
.L22:
	movl	$3, %eax
	jmp	.L25
.L20:
	movl	$4, %eax
	jmp	.L25
.L18:
	movl	$1, %eax
	jmp	.L25
.L21:
	movl	$8, %eax
	jmp	.L25
.L17:
	movl	$0, %eax
.L25:
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3if2i
	.def	_Z3if2i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3if2i
_Z3if2i:#переменные хранятся в регистрах eax, ecx
.LFB5:
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
	.globl	_Z3if3iii
	.def	_Z3if3iii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3if3iii
_Z3if3iii:#переменные хранятся в регистрах eax, edx, ecx
.LFB6:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	cmpl	$0, 16(%rbp)
	je	.L31
	cmpl	$0, 32(%rbp)
	je	.L31
	movl	24(%rbp), %eax
	jmp	.L32
.L31:
	movl	32(%rbp), %eax
.L32:
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3if4iii
	.def	_Z3if4iii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3if4iii
_Z3if4iii:#переменные хранятся в регистрах eax, edx, ecx
.LFB7:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	cmpl	$0, 16(%rbp)
	jne	.L34
	movl	32(%rbp), %eax
	cmpl	24(%rbp), %eax
	jne	.L35
.L34:
	movl	24(%rbp), %eax
	jmp	.L36
.L35:
	movl	16(%rbp), %eax
.L36:
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
	.globl	_Z2f2v
	.def	_Z2f2v;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f2v
_Z2f2v:#переменные хранятся в регистрах eax
.LFB8:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	$0, -4(%rbp)
	jmp	.L38
.L39:
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
.L38:
	cmpl	$100, -4(%rbp)
	jne	.L39
	nop
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z2f1i
	.def	_Z2f1i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f1i
_Z2f1i:
.LFB9: #цикл выполняется с помощью меток (.L42:, .L41:) 
#организация цикла с помощью команд условного перехода и регистра ecx
#помещается в регистр ecx количество повторений
#первая команда тела цикла отмечается меткой
#после выполнения тела цикла уменьшается содержимое регистра ecx на 1
#выполняется сравнение содержимого регистра ecx с нулем
#в случае, если ecx≠ 0, осуществляется переход на метку, иначе выполняется следующая за телом цикла команда
#переменные хранятся в регистрах ecx
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	jmp	.L41
.L42:
	subl	$1, 16(%rbp)
	call	_Z1gv
.L41:
	cmpl	$0, 16(%rbp)
	jne	.L42
	nop
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3f22i
	.def	_Z3f22i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3f22i
_Z3f22i:#переменные хранятся в регистрах ecx
.LFB10:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
.L44:
	cmpl	$0, 16(%rbp)
	je	.L46
	subl	$1, 16(%rbp)
	call	_Z1gv
	jmp	.L44
.L46:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z2f4i
	.def	_Z2f4i;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f4i
_Z2f4i:#переменные хранятся в регистрах ecx ...
.LFB11:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
.L48:
	subl	$1, 16(%rbp)
	call	_Z1gv
	cmpl	$0, 16(%rbp)
	jne	.L48
	nop
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 11.2.0"
	.def	_Z1gv;	.scl	2;	.type	32;	.endef
