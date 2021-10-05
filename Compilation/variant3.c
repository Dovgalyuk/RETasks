/* Как передаются параметры в функции? */
/* Как организован оператор ветвления? */
/* Как выполняется оператор цикла? */
/* Как происходят обращения к массивам? */
/* В каких регистрах или ячейках памяти хранятся переменные? */

/* ========================================================================== */

/* unsigned int fd2(unsigned int a, unsigned int b)  */
/* {  */
/*         return a / b;  */
/* } */

/* O0: */
/* 0000000000400496 <fd2>: */
/*   400496:	55                   	push   rbp */
/*   400497:	48 89 e5             	mov    rbp,rsp */
/*   40049a:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi */
/*   40049d:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi */
/*   4004a0:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4] */
/*   4004a3:	ba 00 00 00 00       	mov    edx,0x0 */
/*   4004a8:	f7 75 f8             	div    DWORD PTR [rbp-0x8] */
/*   4004ab:	5d                   	pop    rbp */
/*   4004ac:	c3                   	ret     */
/* 00000000004004ad <main>: */
/*   4004ad:	55                   	push   rbp */
/*   4004ae:	48 89 e5             	mov    rbp,rsp */
/*   4004b1:	be 03 00 00 00       	mov    esi,0x3 */
/*   4004b6:	bf 02 00 00 00       	mov    edi,0x2 */
/*   4004bb:	e8 d6 ff ff ff       	call   400496 <fd2> */
/*   4004c0:	b8 00 00 00 00       	mov    eax,0x0 */
/*   4004c5:	5d                   	pop    rbp */
/*   4004c6:	c3                   	ret     */
/*   4004c7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0] */
/*   4004ce:	00 00  */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистры edi, esi. 
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменные записываются в стек, по смещению в 4 байта(тип int) относительно 
 * регистра rbp. 
 */

/* O2: */
/* 00000000004004b0 <fd2>: */
/*   4004b0:	89 f8                	mov    eax,edi */
/*   4004b2:	31 d2                	xor    edx,edx */
/*   4004b4:	f7 f6                	div    esi */
/*   4004b6:	c3                   	ret     */
/*   4004b7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0] */
/*   4004be:	00 00  */
/* 00000000004003c0 <main>: */
/*   4003c0:	31 c0                	xor    eax,eax */
/*   4003c2:	c3                   	ret     */
/*   4003c3:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0] */
/*   4003ca:	00 00 00  */
/*   4003cd:	0f 1f 00             	nop    DWORD PTR [rax] */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистры edi, esi. 
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменные записываются на праямую в регистры общего назначения (a -> eax), 
 * для последующего деления.
 */

/* ========================================================================== */




/* ========================================================================== */

/* unsigned int fd3(unsigned int a)  */
/* {  */
/*         return a % 10;  */
/* } */

/* O0: */
/* 0000000000400496 <fd3>: */
/*   400496:	55                   	push   rbp */
/*   400497:	48 89 e5             	mov    rbp,rsp */
/*   40049a:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi */
/*   40049d:	8b 4d fc             	mov    ecx,DWORD PTR [rbp-0x4] */
/*   4004a0:	89 ca                	mov    edx,ecx */
/*   4004a2:	b8 cd cc cc cc       	mov    eax,0xcccccccd */
/*   4004a7:	48 0f af c2          	imul   rax,rdx */
/*   4004ab:	48 c1 e8 20          	shr    rax,0x20 */
/*   4004af:	89 c2                	mov    edx,eax */
/*   4004b1:	c1 ea 03             	shr    edx,0x3 */
/*   4004b4:	89 d0                	mov    eax,edx */
/*   4004b6:	c1 e0 02             	shl    eax,0x2 */
/*   4004b9:	01 d0                	add    eax,edx */
/*   4004bb:	01 c0                	add    eax,eax */
/*   4004bd:	29 c1                	sub    ecx,eax */
/*   4004bf:	89 ca                	mov    edx,ecx */
/*   4004c1:	89 d0                	mov    eax,edx */
/*   4004c3:	5d                   	pop    rbp */
/*   4004c4:	c3                   	ret     */
/* 00000000004004c5 <main>: */
/*   4004c5:	55                   	push   rbp */
/*   4004c6:	48 89 e5             	mov    rbp,rsp */
/*   4004c9:	bf 0a 00 00 00       	mov    edi,0xa */
/*   4004ce:	e8 c3 ff ff ff       	call   400496 <fd3> */
/*   4004d3:	b8 00 00 00 00       	mov    eax,0x0 */
/*   4004d8:	5d                   	pop    rbp */
/*   4004d9:	c3                   	ret     */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменные записываются в стек, по смещению в 4 байта(тип int) относительно 
 * регистра rbp. 
 */
 
/* O2: */
/* 00000000004004b0 <fd3>: */
/*   4004b0:	89 f8                	mov    eax,edi */
/*   4004b2:	ba cd cc cc cc       	mov    edx,0xcccccccd */
/*   4004b7:	48 0f af c2          	imul   rax,rdx */
/*   4004bb:	48 c1 e8 23          	shr    rax,0x23 */
/*   4004bf:	8d 14 80             	lea    edx,[rax+rax*4] */
/*   4004c2:	89 f8                	mov    eax,edi */
/*   4004c4:	01 d2                	add    edx,edx */
/*   4004c6:	29 d0                	sub    eax,edx */
/*   4004c8:	c3                   	ret     */
/*   4004c9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0] */
/* 00000000004003c0 <main>: */
/*   4003c0:	31 c0                	xor    eax,eax */
/*   4003c2:	c3                   	ret     */
/*   4003c3:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0] */
/*   4003ca:	00 00 00  */
/*   4003cd:	0f 1f 00             	nop    DWORD PTR [rax] */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменные записываются на праямую в регистры общего назначения (a -> eax). 
 */

/* ========================================================================== */




/* ========================================================================== */

/* unsigned int fd4(unsigned int a)  */
/* {  */
/*         return a % 16;  */
/* } */

/* O0: */
/* 0000000000400496 <fd4>: */
/*   400496:	55                   	push   rbp */
/*   400497:	48 89 e5             	mov    rbp,rsp */
/*   40049a:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi */
/*   40049d:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4] */
/*   4004a0:	83 e0 0f             	and    eax,0xf */
/*   4004a3:	5d                   	pop    rbp */
/*   4004a4:	c3                   	ret     */
/* 00000000004004a5 <main>: */
/*   4004a5:	55                   	push   rbp */
/*   4004a6:	48 89 e5             	mov    rbp,rsp */
/*   4004a9:	bf 0a 00 00 00       	mov    edi,0xa */
/*   4004ae:	e8 e3 ff ff ff       	call   400496 <fd4> */
/*   4004b3:	b8 00 00 00 00       	mov    eax,0x0 */
/*   4004b8:	5d                   	pop    rbp */
/*   4004b9:	c3                   	ret     */
/*   4004ba:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0] */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменные записываются в стек, по смещению в 4 байта(тип int) относительно 
 * регистра rbp. 
 */

/* O2: */
/* 00000000004004b0 <fd4>: */
/*   4004b0:	89 f8                	mov    eax,edi */
/*   4004b2:	83 e0 0f             	and    eax,0xf */
/*   4004b5:	c3                   	ret     */
/*   4004b6:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0] */
/*   4004bd:	00 00 00  */
/* 00000000004003c0 <main>: */
/*   4003c0:	31 c0                	xor    eax,eax */
/*   4003c2:	c3                   	ret     */
/*   4003c3:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0] */
/*   4003ca:	00 00 00  */
/*   4003cd:	0f 1f 00             	nop    DWORD PTR [rax] */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменные записываются на праямую в регистры общего назначения (a -> eax). 
 */

/* ========================================================================== */




/* ========================================================================== */

/* int f1(int a)  */
/* { */
/*         switch (a) { */
/*                 case 1: */
/*                         return 5; */
/*                 case 6: */
/*                         return 7; */
/*                 case 10: */
/*                         return 3; */
/*         } */
/*         return 0; */
/* } */

/* O0: */
/* int f1(int a)  */
/* { */
/*   400496:	55                   	push   rbp */
/*   400497:	48 89 e5             	mov    rbp,rsp */
/*   40049a:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi */
/*         switch (a) { */
/*   40049d:	83 7d fc 0a          	cmp    DWORD PTR [rbp-0x4],0xa */
/*   4004a1:	74 22                	je     4004c5 <f1+0x2f> */
/*   4004a3:	83 7d fc 0a          	cmp    DWORD PTR [rbp-0x4],0xa */
/*   4004a7:	7f 23                	jg     4004cc <f1+0x36> */
/*   4004a9:	83 7d fc 01          	cmp    DWORD PTR [rbp-0x4],0x1 */
/*   4004ad:	74 08                	je     4004b7 <f1+0x21> */
/*   4004af:	83 7d fc 06          	cmp    DWORD PTR [rbp-0x4],0x6 */
/*   4004b3:	74 09                	je     4004be <f1+0x28> */
/*   4004b5:	eb 15                	jmp    4004cc <f1+0x36> */
/*                 case 1: */
/*                         return 5; */
/*   4004b7:	b8 05 00 00 00       	mov    eax,0x5 */
/*   4004bc:	eb 13                	jmp    4004d1 <f1+0x3b> */
/*                 case 6: */
/*                         return 7; */
/*   4004be:	b8 07 00 00 00       	mov    eax,0x7 */
/*   4004c3:	eb 0c                	jmp    4004d1 <f1+0x3b> */
/*                 case 10: */
/*                         return 3; */
/*   4004c5:	b8 03 00 00 00       	mov    eax,0x3 */
/*   4004ca:	eb 05                	jmp    4004d1 <f1+0x3b> */
/*         } */
/*         return 0; */
/*   4004cc:	b8 00 00 00 00       	mov    eax,0x0 */
/* } */
/*   4004d1:	5d                   	pop    rbp */
/*   4004d2:	c3                   	ret     */
/* 00000000004004d3 <main>: */
/*   4004d3:	55                   	push   rbp */
/*   4004d4:	48 89 e5             	mov    rbp,rsp */
/*   4004d7:	bf 0a 00 00 00       	mov    edi,0xa */
/*   4004dc:	e8 b5 ff ff ff       	call   400496 <f1> */
/*   4004e1:	b8 00 00 00 00       	mov    eax,0x0 */
/*   4004e6:	5d                   	pop    rbp */
/*   4004e7:	c3                   	ret     */
/*   4004e8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0] */
/*   4004ef:	00  */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как организован оператор ветвления? 
 * Через команду сравнения(cmp) и инструкции переходов(je, jg, jmp). После
 * перехода в регистр eax записывается возвращаемое значени, если не один 
 * case не сработал в eax записывается 0.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться на стеке по адресу [rbp-0x4]. Возвращаемое значение
 * в регистре eax.
 */

/* O2: */
/* f1: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	sub	edi, 1 */
/* 	xor	eax, eax */
/* 	cmp	edi, 9 */
/* 	ja	.L1 */
/* 	mov	eax, DWORD PTR CSWTCH.1[0+rdi*4] */
/* .L1: */
/* 	ret */
/* 	.cfi_endproc */
/* .LFE0: */
/* 	.size	f1, .-f1 */
/* 	.section	.text.startup,"ax",@progbits */
/* 	.p2align 4 */
/* 	.globl	main */
/* 	.type	main, @function */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	xor	eax, eax */
/* 	ret */
/* 	.cfi_endproc */
/* .LFE1: */
/* 	.size	main, .-main */
/* 	.section	.rodata */
/* 	.align 32 */
/* 	.type	CSWTCH.1, @object */
/* 	.size	CSWTCH.1, 40 */
/* CSWTCH.1: */
/* 	.long	5 */
/* 	.long	0 */
/* 	.long	0 */
/* 	.long	0 */
/* 	.long	0 */
/* 	.long	7 */
/* 	.long	0 */
/* 	.long	0 */
/* 	.long	0 */
/* 	.long	3 */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как организован оператор ветвления? 
 * От первоначального значения a отнимается 1. Если результат больше 9 - 
 * происходит возврат из функции. Если нет в eax помещается нужное значение. 
 * Оно берётся из таблицы переходов(CSWTCH.1) в разделе .rodata 
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться в edi. Возвращаемые значени в таблице 
 * преходов(CSWTCH.1)
 */

/* ========================================================================== */




/* ========================================================================== */

/* int f2(int a)  */
/* { */
/*         switch (a) { */
/*                 case 1: */
/*                         return 5; */
/*                 case 6: */
/*                         return 7; */
/*                 case 10: */
/*                         return 3; */
/*                 case 1000: */
/*                         return 9; */
/*                 case 6000: */
/*                         return 8; */
/*                 case 10000: */
/*                         return 4; */
/*         } */
/*         return 0; */
/* } */

/* O0: */
/* f2: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	DWORD PTR [rbp-4], edi */
/* 	cmp	DWORD PTR [rbp-4], 10000 */
/* 	je	.L2 */
/* 	cmp	DWORD PTR [rbp-4], 10000 */
/* 	jg	.L3 */
/* 	cmp	DWORD PTR [rbp-4], 6000 */
/* 	je	.L4 */
/* 	cmp	DWORD PTR [rbp-4], 6000 */
/* 	jg	.L3 */
/* 	cmp	DWORD PTR [rbp-4], 1000 */
/* 	je	.L5 */
/* 	cmp	DWORD PTR [rbp-4], 1000 */
/* 	jg	.L3 */
/* 	cmp	DWORD PTR [rbp-4], 10 */
/* 	je	.L6 */
/* 	cmp	DWORD PTR [rbp-4], 10 */
/* 	jg	.L3 */
/* 	cmp	DWORD PTR [rbp-4], 1 */
/* 	je	.L7 */
/* 	cmp	DWORD PTR [rbp-4], 6 */
/* 	je	.L8 */
/* 	jmp	.L3 */
/* .L7: */
/* 	mov	eax, 5 */
/* 	jmp	.L9 */
/* .L8: */
/* 	mov	eax, 7 */
/* 	jmp	.L9 */
/* .L6: */
/* 	mov	eax, 3 */
/* 	jmp	.L9 */
/* .L5: */
/* 	mov	eax, 9 */
/* 	jmp	.L9 */
/* .L4: */
/* 	mov	eax, 8 */
/* 	jmp	.L9 */
/* .L2: */
/* 	mov	eax, 4 */
/* 	jmp	.L9 */
/* .L3: */
/* 	mov	eax, 0 */
/* .L9: */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* .LFE0: */
/* 	.size	f2, .-f2 */
/* 	.globl	main */
/* 	.type	main, @function */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	edi, 10 */
/* 	call	f2 */
/* 	mov	eax, 0 */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */


/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как организован оператор ветвления? 
 * Через команду сравнения(cmp) и инструкции переходов(je, jg, jmp). После
 * перехода в регистр eax записывается возвращаемое значени, если не один 
 * case не сработал в eax записывается 0.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться на стеке по адресу [rbp-0x4]. Возвращаемое значение
 * в регистре eax.
 */

/* O2: */
/* f2: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	cmp	edi, 1000 */
/* 	je	.L4 */
/* 	jg	.L3 */
/* 	mov	eax, 7 */
/* 	cmp	edi, 6 */
/* 	je	.L1 */
/* 	mov	eax, 3 */
/* 	cmp	edi, 10 */
/* 	jne	.L14 */
/* .L1: */
/* 	ret */
/* 	.p2align 4,,10 */
/* 	.p2align 3 */
/* .L14: */
/* 	xor	eax, eax */
/* 	cmp	edi, 1 */
/* 	sete	al */
/* 	lea	eax, [rax+rax*4] */
/* 	ret */
/* 	.p2align 4,,10 */
/* 	.p2align 3 */
/* .L3: */
/* 	mov	eax, 8 */
/* 	cmp	edi, 6000 */
/* 	je	.L1 */
/* 	xor	eax, eax */
/* 	cmp	edi, 10000 */
/* 	sete	al */
/* 	sal	eax, 2 */
/* 	ret */
/* 	.p2align 4,,10 */
/* 	.p2align 3 */
/* .L4: */
/* 	mov	eax, 9 */
/* 	ret */
/* 	.cfi_endproc */
/* .LFE0: */
/* 	.size	f2, .-f2 */
/* 	.section	.text.startup,"ax",@progbits */
/* 	.p2align 4 */
/* 	.globl	main */
/* 	.type	main, @function */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	xor	eax, eax */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как организован оператор ветвления? 
 * С помощью инструкций cmp, je, jg, jne, sete, sal. И не сложной арефметики 
 * указателей. 
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться в edi. Далее всё сравнение идёт через константы.
 * Возвращаемое значени записывается в eax.
 */

/* ========================================================================== */




/* ========================================================================== */

/* int if1(int a)  */
/* { */
/*         int b = a == 0 ? 1 : 2; */
/*         return b; */
/* } */

/* O0: */
/* if1: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	DWORD PTR [rbp-20], edi */
/* 	cmp	DWORD PTR [rbp-20], 0 */
/* 	jne	.L2 */
/* 	mov	eax, 1 */
/* 	jmp	.L3 */
/* .L2: */
/* 	mov	eax, 2 */
/* .L3: */
/* 	mov	DWORD PTR [rbp-4], eax */
/* 	mov	eax, DWORD PTR [rbp-4] */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* .LFE0: */
/* 	.size	if1, .-if1 */
/* 	.globl	main */
/* 	.type	main, @function */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	edi, 10 */
/* 	call	if1 */
/* 	mov	eax, 0 */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как организован оператор ветвления? 
 * С помощью инструкций cmp, jne, и перехода на заданные метки.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться на стеке по адресу [rbp-20]. Возвращаемое значение
 * в регистре eax.
 */

/* O2: */
/* if1: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	cmp	edi, 1 */
/* 	mov	eax, 1 */
/* 	sbb	eax, -1 */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	xor	eax, eax */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как организован оператор ветвления? 
 * Как такогого оператора ветвления нет. Есть cmp который сравнивает 
 * переданное значени в функцию с 1, флаг CF устанавливает взависимости 
 * от этого сравнения. А затема используется инструкция sbb, которая отнимает 
 * флаг CF от результата вычитания eax c -1. В зависимости от этого 
 * возвращается 1 или 2.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться в регистре edi. Возвращаемое значение
 * в регистре eax.
 */

/* ========================================================================== */




/* ========================================================================== */

/* int if2(int a)  */
/* { */
/*         int b = a == 50 ? 12 : 26; */
/*         return b; */
/* } */

/* O0: */
/* if2: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	DWORD PTR [rbp-20], edi */
/* 	cmp	DWORD PTR [rbp-20], 50 */
/* 	jne	.L2 */
/* 	mov	eax, 12 */
/* 	jmp	.L3 */
/* .L2: */
/* 	mov	eax, 26 */
/* .L3: */
/* 	mov	DWORD PTR [rbp-4], eax */
/* 	mov	eax, DWORD PTR [rbp-4] */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* .LFE0: */
/* 	.size	if2, .-if2 */
/* 	.globl	main */
/* 	.type	main, @function */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	edi, 10 */
/* 	call	if2 */
/* 	mov	eax, 0 */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как организован оператор ветвления? 
 * С помощью инструкций cmp, jne, jmp, для перехода на заданные метки.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться на стеке по адресу [rbp-20]. Возвращаемое значение
 * в регистре eax.
 */

/* O2: */
/* if2: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	cmp	edi, 50 */
/* 	mov	edx, 26 */
/* 	mov	eax, 12 */
/* 	cmovne	eax, edx */
/* 	ret */
/* 	.cfi_endproc */
/* .LFE0: */
/* 	.size	if2, .-if2 */
/* 	.section	.text.startup,"ax",@progbits */
/* 	.p2align 4 */
/* 	.globl	main */
/* 	.type	main, @function */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	xor	eax, eax */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как организован оператор ветвления? 
 * Через инструкцию cmp и cmovne.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться в регистре edi. Возвращаемое значение
 * в регистре eax. Константы для сравнения в регистрах edx, eax.
 */

/* ========================================================================== */




/* ========================================================================== */

/* int if4(int a, int b, int c)  */
/* { */
/*         if (a || c == b) */
/*                 return b; */
/*         else */
/*                 return a; */
/* } */

/* O0: */
/* if4: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	DWORD PTR [rbp-4], edi */
/* 	mov	DWORD PTR [rbp-8], esi */
/* 	mov	DWORD PTR [rbp-12], edx */
/* 	cmp	DWORD PTR [rbp-4], 0 */
/* 	jne	.L2 */
/* 	mov	eax, DWORD PTR [rbp-12] */
/* 	cmp	eax, DWORD PTR [rbp-8] */
/* 	jne	.L3 */
/* .L2: */
/* 	mov	eax, DWORD PTR [rbp-8] */
/* 	jmp	.L4 */
/* .L3: */
/* 	mov	eax, DWORD PTR [rbp-4] */
/* .L4: */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	edx, 3 */
/* 	mov	esi, 3 */
/* 	mov	edi, 10 */
/* 	call	if4 */
/* 	mov	eax, 0 */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi(a), esi(b), edx(c). 
 *
 * Как организован оператор ветвления? 
 * С помощью инструкций cmp, jne, jmp, для перехода на заданные метки.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменнае храниться на стеке по адресам a->[rbp-20], b->[rbp-8], 
 * c->[rbp-12]. Возвращаемое значение в регистре eax.
 */

/* O2: */
/* if4: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	test	edi, edi */
/* 	jne	.L5 */
/* 	xor	eax, eax */
/* 	cmp	edx, esi */
/* 	je	.L5 */
/* 	ret */
/* 	.p2align 4,,10 */
/* 	.p2align 3 */
/* .L5: */
/* 	mov	eax, esi */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	xor	eax, eax */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi(a), esi(b), edx(c). 
 *
 * Как организован оператор ветвления? 
 * С помощью инструкций test, cmp, jne, je, для перехода на заданные метки.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменнае храниться в регистрах. Возвращаемое значение в регистре eax.
 */

/* ========================================================================== */




/* ========================================================================== */

/* int *s[100]; */
/* int t[100]; */
/* void f2()  */
/* { */
/*         for (int i = 0; i != 100; ++i) s[i] = &t[i]; */
/* } */

/* O0: */
/* s: */
/* 	.zero	800 */
/* 	.globl	t */
/* 	.align 32 */
/* 	.type	t, @object */
/* 	.size	t, 400 */
/* t: */
/* 	.zero	400 */
/* 	.text */
/* 	.globl	f2 */
/* 	.type	f2, @function */
/* f2: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	DWORD PTR [rbp-4], 0 */
/* 	jmp	.L2 */
/* .L3: */
/* 	mov	eax, DWORD PTR [rbp-4] */
/* 	cdqe */
/* 	sal	rax, 2 */
/* 	lea	rdx, t[rax] */
/* 	mov	eax, DWORD PTR [rbp-4] */
/* 	cdqe */
/* 	mov	QWORD PTR s[0+rax*8], rdx */
/* 	add	DWORD PTR [rbp-4], 1 */
/* .L2: */
/* 	cmp	DWORD PTR [rbp-4], 100 */
/* 	jne	.L3 */
/* 	nop */
/* 	nop */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	eax, 0 */
/* 	call	f2 */
/* 	mov	eax, 0 */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */

/* Как выполняется оператор цикла? 
 * C помощью инструкции jmp(переход к условию цикла) и cmp(проверка условия), 
 * jne(переход к телу цикла). 
 * 
 * Как происходят обращения к массивам? 
 * Обращение происходит по указателю (QWORD PTR s[0+rax*8]).
 * 
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная i храниться на стеке по адреcу [rbp-4]. Элементы массивов
 * храняться в регистрах rdx(массив t).
 */

/* O2: */
/* f2: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	mov	eax, OFFSET FLAT:t */
/* 	mov	edx, OFFSET FLAT:s */
/* 	.p2align 4,,10 */
/* 	.p2align 3 */
/* .L2: */
/* 	mov	QWORD PTR [rdx], rax */
/* 	add	rax, 4 */
/* 	add	rdx, 8 */
/* 	cmp	rax, OFFSET FLAT:t+400 */
/* 	jne	.L2 */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	mov	eax, OFFSET FLAT:t */
/* 	mov	edx, OFFSET FLAT:s */
/* 	.p2align 4,,10 */
/* 	.p2align 3 */
/* .L6: */
/* 	mov	QWORD PTR [rdx], rax */
/* 	add	rax, 4 */
/* 	add	rdx, 8 */
/* 	cmp	rax, OFFSET FLAT:t+400 */
/* 	jne	.L6 */
/* 	xor	eax, eax */
/* 	ret */
/* 	.cfi_endproc */
/* t: */
/* 	.zero	400 */
/* 	.globl	s */
/* 	.align 32 */
/* 	.type	s, @object */
/* 	.size	s, 800 */
/* s: */
/* 	.zero	800 */

/* Как выполняется оператор цикла? 
 * C помощью инструкции cmp(проверка условия), jne(переход к телу цикла). 
 * Для проверки испоьзуется адрес массива и смещение в 400 байт, это 100 
 * элементов типа int.
 * 
 * Как происходят обращения к массивам? 
 * Обращение происходит по указателю. В регистр eax записывается начальный 
 * адрес массива t, в регистр edx начальный адрес массива s. Для обращения 
 * к элементу используется сложение с базовым адресом массивов. 
 * 
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * см. выше
 */

/* ========================================================================== */




/* ========================================================================== */
/* void g(){} */
/* ========================================================================== */




/* ========================================================================== */

/* void f1(int a)  */
/* { */
/*         while (a) { */
/*                 --a; */
/*                 g(); */
/*         } */
/* } */

/* O0: */
/* g: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	nop */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* f1: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	sub	rsp, 8 */
/* 	mov	DWORD PTR [rbp-4], edi */
/* 	jmp	.L3 */
/* .L4: */
/* 	sub	DWORD PTR [rbp-4], 1 */
/* 	mov	eax, 0 */
/* 	call	g */
/* .L3: */
/* 	cmp	DWORD PTR [rbp-4], 0 */
/* 	jne	.L4 */
/* 	nop */
/* 	nop */
/* 	leave */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB2: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	edi, 10 */
/* 	call	f1 */
/* 	mov	eax, 0 */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Параметры передаються через регистр edi. 
 *
 * Как выполняется оператор цикла? 
 * С помощью инструкций test, cmp, jne, je, для перехода на заданные метки.
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Переменная а храниться в регистре edi. Возвращаемое значение
 * в регистре eax. 
 */

/* O2: */
/* g: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	ret */
/* 	.cfi_endproc */
/* f1: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB2: */
/* 	.cfi_startproc */
/* 	xor	eax, eax */
/* 	ret */
/* 	.cfi_endproc */

/* Как передаются параметры в функции? 
 * Не передаются.
 *
 * Как выполняется оператор цикла? 
 * Реализации цикла нет
 *
 * В каких регистрах или ячейках памяти хранятся переменные? 
 * Так как в цикле происходит уменьшение значения переменной a,
 * которая была передана по значению, а не по указателю, то становиться 
 * ясно что смысла в таком цикле нет, поэтому оптимизатор его не создаёт. 
 */

/* ========================================================================== */




/* ========================================================================== */

/* void f2(int a)  */
/* { */
/* L: */
/*         if (a) { */
/*                 --a; */
/*                 g(); */
/*                 goto L; */
/*         } */
/* } */

/* O0: */
/* g: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	nop */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* f2: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	sub	rsp, 8 */
/* 	mov	DWORD PTR [rbp-4], edi */
/* .L3: */
/* 	cmp	DWORD PTR [rbp-4], 0 */
/* 	je	.L5 */
/* 	sub	DWORD PTR [rbp-4], 1 */
/* 	mov	eax, 0 */
/* 	call	g */
/* 	jmp	.L3 */
/* .L5: */
/* 	nop */
/* 	leave */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB2: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	edi, 10 */
/* 	call	f2 */
/* 	mov	eax, 0 */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */

/* O2: */
/* g: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	ret */
/* 	.cfi_endproc */
/* f2: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB2: */
/* 	.cfi_startproc */
/* 	xor	eax, eax */
/* 	ret */
/* 	.cfi_endproc */

/* Всё аналогично предыдущей функции */

/* ========================================================================== */




/* ========================================================================== */

/* void f4(int a)  */
/* { */
/*         do { */
/*                 --a; */
/*                 g(); */
/*         } while (a); */
/* } */

/* O0: */
/* g: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	nop */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* f4: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	sub	rsp, 8 */
/* 	mov	DWORD PTR [rbp-4], edi */
/* .L3: */
/* 	sub	DWORD PTR [rbp-4], 1 */
/* 	mov	eax, 0 */
/* 	call	g */
/* 	cmp	DWORD PTR [rbp-4], 0 */
/* 	jne	.L3 */
/* 	nop */
/* 	nop */
/* 	leave */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB2: */
/* 	.cfi_startproc */
/* 	push	rbp */
/* 	.cfi_def_cfa_offset 16 */
/* 	.cfi_offset 6, -16 */
/* 	mov	rbp, rsp */
/* 	.cfi_def_cfa_register 6 */
/* 	mov	edi, 10 */
/* 	call	f4 */
/* 	mov	eax, 0 */
/* 	pop	rbp */
/* 	.cfi_def_cfa 7, 8 */
/* 	ret */
/* 	.cfi_endproc */

/* 02: */
/* g: */
/* .LFB0: */
/* 	.cfi_startproc */
/* 	ret */
/* 	.cfi_endproc */
/* f4: */
/* .LFB1: */
/* 	.cfi_startproc */
/* 	ret */
/* 	.cfi_endproc */
/* main: */
/* .LFB2: */
/* 	.cfi_startproc */
/* 	xor	eax, eax */
/* 	ret */
/* 	2: */

/* Всё аналогично предыдущей функции */

/* ========================================================================== */

int main() 
{
        /* fd2(10, 2); */
        /* fd3(10); */
        /* fd4(10); */
        /* f1(10); */
        /* f2(10); */
        /* if1(10); */
        /* if2(10); */
        /* if4(10, 7, 3); */
        /* f2(); */
        /* f1(10); */
        /* f2(10); */
        /* f4(10); */

        return 0;
}
