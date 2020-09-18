https://github.com/Dovgalyuk/RETasks/tree/master/Compilation

GCC: x86_64 8.1.0
-fno-asynchronous-unwind-tables -masm=intel -S

1) Как передаются параметры в функции?
2) Как организован оператор ветвления?
3) Как выполняется оператор цикла?
4) Как происходят обращения к массивам?
5) В каких регистрах или ячейках памяти хранятся переменные?


unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}

-O0	
	fd2:
		push	rbp
		mov	rbp, rsp
		mov	DWORD PTR 16[rbp], ecx
		mov	DWORD PTR 24[rbp], edx
		mov	eax, DWORD PTR 16[rbp]
		mov	edx, 0
		div	DWORD PTR 24[rbp]
		pop	rbp
		ret
		
1) Параметры передаются через регистры ecx, edx;
5) Обе переменные хранятся в памяти;
		

-O2	
	fd2:
		mov	r8d, edx
		mov	eax, ecx
		xor	edx, edx
		div	r8d
		ret

1) Через регистры ecx, edx;
5) В регистрах eax, r8d;
	
	
unsigned int fd3(unsigned int a)
{
    return a % 10;
}

-O0
	fd3:
		push	rbp
		mov	rbp, rsp
		mov	DWORD PTR 16[rbp], ecx
		mov	ecx, DWORD PTR 16[rbp]
		mov	edx, -858993459
		mov	eax, ecx
		mul	edx
		shr	edx, 3
		mov	eax, edx
		sal	eax, 2
		add	eax, edx
		add	eax, eax
		sub	ecx, eax
		mov	edx, ecx
		mov	eax, edx
		pop	rbp
		ret

1) Через регистр ecx;
5) В памяти;

		
-O2
	fd3:
		mov	eax, ecx
		mov	edx, -858993459
		mul	edx
		mov	eax, edx
		shr	eax, 3
		lea	eax, [rax+rax*4]
		add	eax, eax
		sub	ecx, eax
		mov	eax, ecx
		ret
		
1) Через регистр ecx;
5) В регистре ecx;
		
		
unsigned int fd4(unsigned int a)
{
    return a % 16;
}

-O0
	fd4:
		push	rbp
		mov	rbp, rsp
		mov	DWORD PTR 16[rbp], ecx
		mov	eax, DWORD PTR 16[rbp]
		and	eax, 15
		pop	rbp
		ret
		
1) Через регистр ecx;
5) В памяти;
		
-O2
	fd4:
		mov	eax, ecx
		and	eax, 15
		ret
		
1) Через регистр ecx;
5) В регистре eax;


int f1(int a)
{
    switch (a)
    {
    case 1:
        return 5;
    case 6:
        return 7;
    case 10:
        return 3;
    }
    return 0;
}

-O0
	f1:
		push	rbp
		mov	rbp, rsp
		mov	DWORD PTR 16[rbp], ecx
		cmp	DWORD PTR 16[rbp], 6
		je	.L2
		cmp	DWORD PTR 16[rbp], 10
		je	.L3
		cmp	DWORD PTR 16[rbp], 1
		jne	.L4
		mov	eax, 5
		jmp	.L5
	.L2:
		mov	eax, 7
		jmp	.L5
	.L3:
		mov	eax, 3
		jmp	.L5
	.L4:
		mov	eax, 0
	.L5:
		pop	rbp
		ret

1) Через регистр ecx;
2) Переменная при помощи команды cmp сравнивается с 3 условиями:
	если переменная равна 6 или 10
		то при помощи инструкции je выполняется  переход по метке
		(L2 или L3), а затем через jmp на блок завершения функции (L5)
	Если переменная не равна 1, 
		jne переходит по метке (L4) и без дополнительных интсрукций достигает
		блока завершения функции;
	Иначе в регистр eax записывается соответствющее значение и потом 
	через jmp переход на метку (L5);
5) Переменная хранится в памяти; 		

-O2
	f1:
		sub	ecx, 1
		xor	eax, eax
		cmp	ecx, 9
		ja	.L1
		lea	rax, CSWTCH.0[rip]
		mov	eax, DWORD PTR [rax+rcx*4]
	.L1:
		ret
		.section .rdata,"dr"
		.align 32
	CSWTCH.0:
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
		
1) Через регистр ecx;
2) Из переменной "a" вычитается 1(Sub). 
	xor обнуляет регистр в котором будет возврщаться результат выполнения.
	cmp проверяет "а" на равенство 9, если ("а"!=9 и "а">9), то ja переходит по
	метке L1 где завершается функция. Иначе lea помещает в регистр rax адрес начала
	созданного в памяти константного массива(возможно неправильно назвал, 4 бйтовую
	последовательность чисел), mov помещает в регистр eax одну из констант блока
	CSWTCH.0, смещение для которой вычисляется [адрес начала массива + 
	индекс(значение "а") * размер блока данных], возврат из функции.
5) "a" используется из регистра в котором приходит(ecx);
		
		
int f2(int a)
{
    switch (a)
    {
    case 1:
        return 5;
    case 6:
        return 7;
    case 10:
        return 3;
    case 1000:
        return 9;
    case 6000:
        return 8;
    case 10000:
        return 4;
    }
    return 0;
}

-O0
	f2:
		push	rbp
		mov	rbp, rsp
		mov	DWORD PTR 16[rbp], ecx
		cmp	DWORD PTR 16[rbp], 10
		je	.L2
		cmp	DWORD PTR 16[rbp], 10
		jg	.L3
		cmp	DWORD PTR 16[rbp], 1
		je	.L4
		cmp	DWORD PTR 16[rbp], 6
		je	.L5
		jmp	.L6
	.L3:
		cmp	DWORD PTR 16[rbp], 6000
		je	.L7
		cmp	DWORD PTR 16[rbp], 10000
		je	.L8
		cmp	DWORD PTR 16[rbp], 1000
		je	.L9
		jmp	.L6
	.L4:
		mov	eax, 5
		jmp	.L10
	.L5:
		mov	eax, 7
		jmp	.L10
	.L2:
		mov	eax, 3
		jmp	.L10
	.L9:
		mov	eax, 9
		jmp	.L10
	.L7:
		mov	eax, 8
		jmp	.L10
	.L8:
		mov	eax, 4
		jmp	.L10
	.L6:
		mov	eax, 0
	.L10:
		pop	rbp
		ret
		
1) Через регистр ecx;
2) Cmp сравнивает "а" и 10, если равно je переходит в L2, eax получает значение
	для возврата, конец функции.
	
	Cmp сравнивает "а" и 10, 10 меньше, продолжает выполнение со следующей интсрукции,
	где "а" последовательно сравнивается с 1 и 6, и в случае равенства je переходит
	для выполнения их блоков кода.
	Если "а" больше 10, jg переходит на блок кода L3, где "а" сравнивается
	с 6000, 10000, 1000 в случае равенства переходит для выполнения их блока кода.
	Если ни 1но равенство не выполнено при помощи jmp происходит переход на L6 
	для возврата 0;
	
5) В памяти;

		
-O2
	f2:
		cmp	ecx, 10
		je	.L4
		jle	.L14
		cmp	ecx, 6000
		mov	eax, 8
		je	.L1
		cmp	ecx, 10000
		mov	eax, 4
		je	.L1
		xor	eax, eax
		cmp	ecx, 1000
		sete	al
		lea	eax, [rax+rax*8]
		ret
		.p2align 4,,10
	.L4:
		mov	eax, 3
	.L1:
		ret
		.p2align 4,,10
	.L14:
		cmp	ecx, 1
		mov	eax, 5
		je	.L1
		cmp	ecx, 6
		mov	edx, 0
		mov	eax, 7
		cmovne	eax, edx
		ret	

1) Через ecx;
2) Cmp сравнивает "a" и 10,
	если равны je переводит выполнение к L4, где в eax помешается 3, конец функции.
	если "a" меньше 10, jle переходит к блоку L14, в котором
		cmp сравнивает "а" с 1, 
			помещает 5 в eax,
			если "a" равно 1, переходит в L1 для завершения функции;
		cmp сравнивает "а" с 6, устанавливает ZF=1 если равны
			mov помещает в edx 0,
			mov помещает в eax 7
			cmovne помещает содержимое edx в eax, если ZF=0
		Конец функции;
5) Остаётся в регистре ecx;
		
		
int if1(int a)
{
    int b = a == 0 ? 1 : 2;
    return b;
}

-O0
	if1:
		push	rbp
		mov	rbp, rsp
		sub	rsp, 16
		mov	DWORD PTR 16[rbp], ecx
		cmp	DWORD PTR 16[rbp], 0
		jne	.L2
		mov	eax, 1
		jmp	.L3
	.L2:
		mov	eax, 2
	.L3:
		mov	DWORD PTR -4[rbp], eax
		mov	eax, DWORD PTR -4[rbp]
		leave
		ret

1) Через регистр ecx;
2) При помощи оператора сравнения cmp
	првоеряется переменная "a" на равенстов 0, если не равна jne переходит на 
	метку L2 где в регистр eax помещается 2, иначе в eax помещается 1 и 
	jmp переходит по метке L3. 
5) Обе переменные хранятся в памяти;		
		
-O2
	if1:
		xor	eax, eax
		test	ecx, ecx
		setne	al
		add	eax, 1
		ret

1) Через ecx;
2) test проверяет на равенство переменной "а" - 0, если равен 0, то устанавливает ZF=1.
	Setne в регистре eax устанавливает младший байт равным 1, если ZF!=0;
	Прибавляет к содержимому регистра eax еденицу.
5) Возвращаемое значение в eax



int if2(int a)
{
    int b = a == 50 ? 12 : 26;
    return b;
}

-O0
	if2:
		push	rbp
		mov	rbp, rsp
		sub	rsp, 16
		mov	DWORD PTR 16[rbp], ecx
		cmp	DWORD PTR 16[rbp], 50
		jne	.L6
		mov	eax, 12
		jmp	.L7
	.L6:
		mov	eax, 26
	.L7:
		mov	DWORD PTR -4[rbp], eax
		mov	eax, DWORD PTR -4[rbp]
		leave
		ret
		
1) Через ecx;
2) Сравнение при помощи cmp переменной "а" и 50, если равны jne переходит на L6
	где в регистр eax помещается 26, затем содержимое регистра помещается
	в переменную "b", из переменной "b" в регистр eax для возврата значения из 
	функции. Иначе в регистр eax помешается значение 12, jmp переходит по метке 
	L7, где содержимое eax помещается в переменную "b", а затем из переменной 
	"b" снова в регистр eax для возврата значения из функции.
	
5) Обе в памяти;

-O2
	if2:
		cmp	ecx, 50
		mov	edx, 26
		mov	eax, 12
		cmovne	eax, edx
		ret
		
1) Через регистр edi;
2) Сравнивает при помощи cmp значение параметра функции с 50(Устанавливает 
	ZF флаг если равны),
	помещает в регистр edx - 26, в регистр eax 12.
	Инструкция cmovne проверяет флаг ZF, если он не установлен, помещает содержимое
	регистра edx в eax;
5) регистр eax


int if4(int a, int b, int c)
{
    if (a || c == b)
        return b;
    else
        return a;
}	

-O0
	if4:
		push	rbp
		mov	rbp, rsp
		mov	DWORD PTR 16[rbp], ecx
		mov	DWORD PTR 24[rbp], edx
		mov	DWORD PTR 32[rbp], r8d
		cmp	DWORD PTR 16[rbp], 0
		jne	.L10
		mov	eax, DWORD PTR 32[rbp]
		cmp	eax, DWORD PTR 24[rbp]
		jne	.L11
	.L10:
		mov	eax, DWORD PTR 24[rbp]
		jmp	.L12
	.L11:
		mov	eax, DWORD PTR 16[rbp]
	.L12:
		pop	rbp
		ret
		
1) Через регистры ecx, edx, r8d;
2) Оператор cmp проверяет равенство переменной а - 0, в случае не совпадения
	jne переходит по метке L10 для заполнения регистра с возвращаемыми данными,
	переменной "b" и далее через jmp в конец функции по метке L12.
	Если "а" оказалась равно 0, то помещает переменную "с" в регистр eax и
	сравнивает его с переменной "b", если не равны оператор jne переходит а метку
	L11 где в регистр возврата заносится переменная "а", иначе в eax заносится
	переменная "b", jmp в конец функции по L12
5) Все хранятся в памяти;
		
-O2
	if4:
		test	ecx, ecx
		jne	.L12
		xor	eax, eax
		cmp	r8d, edx
		je	.L12
		ret
		.p2align 4,,10
	.L12:
		mov	eax, edx
		ret
		
1) Через регистры ecx, edx, r8d;
2) test проверяет переменную "а" на равенство 0(Через "И" самой себя), если "а" 
	оказалась не равной 0, jne переходит по метке L12, где в регистр возврата eax,
	из регистра edx помещается переменная "b", иначе обнуляет регистр возврата, 
	cmp проверяет на равенство переменные "b" и "с", если равны переход в L12, 
	инчае завершение функции
3) ecx, edx, r8d;


int *s[100];
int t[100];
void f2()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}

-O0
	f2:
		push	rbp
		mov	rbp, rsp
		sub	rsp, 16
		mov	DWORD PTR -4[rbp], 0
		jmp	.L2
	.L3:
		mov	eax, DWORD PTR -4[rbp]
		cdqe
		lea	rdx, 0[0+rax*4]
		lea	rax, t[rip]
		lea	rcx, [rdx+rax]
		lea	rax, s[rip]
		mov	edx, DWORD PTR -4[rbp]
		movsx	rdx, edx
		mov	QWORD PTR [rax+rdx*8], rcx
		add	DWORD PTR -4[rbp], 1
	.L2:
		cmp	DWORD PTR -4[rbp], 100
		jne	.L3
		nop
		leave
		ret
		
3) Инициализация счётчика цикла, затем переход к проверке условия завешения цикла
	в блок L2 оператором jmp, если счётчик не равен 100, оператор jne переводит 
	выполнение в начало тела цикла L3, иначе функция завершается.
4) По адрес начала массиа + индекс*тип(4 для int, 8 для int&)
	абсолютный адрес вычисляется lea;
5) Счётчик цикла, массивы в памяти; 

-O2
	f2:
		lea	rax, t[rip]
		lea	rdx, s[rip]
		lea	rcx, 400+t[rip]
		.p2align 4,,10
	.L2:
		mov	QWORD PTR [rdx], rax
		add	rax, 4
		add	rdx, 8
		cmp	rax, rcx
		jne	.L2
		ret

3) В регистры eax, edx помещаются адреса нначала массивов t, s
	в регистр rcx адрес конца массива t.
	Инкремент счетчика командой add(которая add	rax, 4),
	проверка условия выхода из цикла - cmp, сравнивает адрес текущего элемента
	массива t с адресом конца массива;
4) Через регистры rax, rdx и их инкремент на размер соответствующего типа;
5) Счетчик в rax(он же адрес элемента массива t, счетчик из кода СИ не 
	используется), массивы в памяти;
		
		
void g();
void f1(int a)
{
    while (a)
    {
        --a;
        g();
    }
}

-O0
	f1:
		push	rbp
		mov	rbp, rsp
		sub	rsp, 32
		mov	DWORD PTR 16[rbp], ecx
		jmp	.L2
	.L3:
		sub	DWORD PTR 16[rbp], 1
		call	g
	.L2:
		cmp	DWORD PTR 16[rbp], 0
		jne	.L3
		nop
		leave
		ret
		
1) Через ecx;
3) Начинается цикл с перехода к L2;
	Состоит из двух частей .L3, .L2
	В L3 идет декремент счетчика(при помощи sub), + остальное тело цикла
	В L2 cmp проверяет биты переменной и 0 на равентсво, если не равны, 
	идет переход к началу цикла.
	
5) В памяти;

-O2
	f1:
		test	ecx, ecx
		je	.L9
		push	rbx
		mov	ebx, ecx
		sub	rsp, 32
		.p2align 4,,10
	.L3:
		call	g
		sub	ebx, 1
		test	ebx, ebx
		jne	.L3
		add	rsp, 32
		pop	rbx
		ret
		.p2align 4,,10
	.L9:
		ret

1) Через ecx;
3) В начале функции идет проверка параметра на равенство 0, если 0, то  
	функция завершается.
	
	Sub(sub	ebx, 1) производит декремент переменной,
	test выполняет битовое И для переменной с самой собой, что приведет к 
	установлению флага ZF=1 только в том случае если все биты переменной нули
	jne возвращает к началу цикла если ZF=0
5) В регистре ebx;
(
	Если вместо void g(), написать void g(){},
	-O2 сократит код до
		g:
			ret
		f1:
			ret
)

void g();
void f2(int a)
{
L:
    if (a)
    {
        --a;
        g();
        goto L;
    }
}

-O0
	f2:
		push	rbp
		mov	rbp, rsp
		sub	rsp, 32
		mov	DWORD PTR 16[rbp], ecx
	.L2:
		cmp	DWORD PTR 16[rbp], 0
		je	.L4
		sub	DWORD PTR 16[rbp], 1
		call	g
		jmp	.L2
	.L4:
		nop
		leave
		ret
		
1) Регистром ecx;
3) Оператор сравнения cmp проверяет стоит ли начинать очередной/первый виток цикла,
	опертор je завершает выполнение функции(переходит по метке L4 и предотвращает
	очередную итерацию цикла), послевыполнения тела цикла, jmp .L2 переводит в начало
5) В памяти;

-O2
	f2:
		test	ecx, ecx
		je	.L9
		push	rbx
		mov	ebx, ecx
		sub	rsp, 32
		.p2align 4,,10
	.L3:
		call	g
		sub	ebx, 1
		test	ebx, ebx
		jne	.L3
		add	rsp, 32
		pop	rbx
		ret
		.p2align 4,,10
	.L9:
		ret
		
1) Регистром ecx;
3) Входной параметр проверяется на равенство 0, если истина, то функция завершается
	(test проверяет, je .L9 переводит в конец)
	Основной цикл реализован при помощи sub - декремент переменной,
	test - проверяет нужно ли начинать итерацию цикла, jne переводит в начало цикла
5) В регистре ebx;
		

void g();		
void f4(int a)
{
    do
    {
        --a;
        g();
    }
    while (a);
}

-O0
	f4:
		push	rbp
		mov	rbp, rsp
		sub	rsp, 32
		mov	DWORD PTR 16[rbp], ecx
	.L2:
		sub	DWORD PTR 16[rbp], 1
		call	g
		cmp	DWORD PTR 16[rbp], 0
		jne	.L2
		nop
		leave
		ret

1) Регистром ecx;
3) Реализован оператором сравнения cmp
	который проверяет переменную на условие завершение цикла
	и jne который делает переход в начало цикла если условие не выполнено,
	переменная счетчик хранится в памяти, уменьшается оператором sub
5) Хранится в памяти;

-O2
	f4:
		push	rbx
		mov	ebx, ecx
		sub	rsp, 32
		.p2align 4,,10
	.L2:
		call	g
		sub	ebx, 1
		test	ebx, ebx
		jne	.L2
		add	rsp, 32
		pop	rbx
		ret
		
1) Регистром ecx;
3) Счетчик хранится в регистре ebx, декремент счетчика оператором sub,
	Проверка условия окончания цикла оператором test и флагом ZF,
	переход в начало итерации или выход из цикла оператором jne
5) В регистре ebx;
