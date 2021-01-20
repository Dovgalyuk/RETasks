unsigned int fd(unsigned int a)
{
    return a / 10;
}

fd:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     eax, DWORD PTR [rbp-4]
        mov     edx, eax
        mov     eax, 3435973837
        imul    rax, rdx
        shr     rax, 32
        shr     eax, 3
        pop     rbp
        ret

Переменные храняться в rbp,[rbp-4],eax,rax
Ветвлений и массивов нет
______________________________________________________________
unsigned int fd1(unsigned int a)
{
    return a / 16;
}

fd1:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     eax, DWORD PTR [rbp-4]
        shr     eax, 4
        pop     rbp
        ret

Переменные храняться в [rbp-4],eax
______________________________________________________________
unsigned int fd2(unsigned int a, unsigned int b)
{
    return a % b;
}

fd2:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi //Передача аргумента a
        mov     DWORD PTR [rbp-8], esi //Передача аргумента b
        mov     eax, DWORD PTR [rbp-4]
        mov     edx, 0
        div     DWORD PTR [rbp-8]
        mov     eax, edx
        pop     rbp
        ret
Переменные храняться в [rbp-4],[rbp-8],eax,edx
______________________________________________________________

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


f2:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi //Передача аргумента
        cmp     DWORD PTR [rbp-4], 10000 //Начало ветвления (Операция сравнения)
        je      .L8
        cmp     DWORD PTR [rbp-4], 10000
        jg      .L9
        cmp     DWORD PTR [rbp-4], 6000
        je      .L10
        cmp     DWORD PTR [rbp-4], 6000
        jg      .L9
        cmp     DWORD PTR [rbp-4], 1000
        je      .L11
        cmp     DWORD PTR [rbp-4], 1000
        jg      .L9
        cmp     DWORD PTR [rbp-4], 10
        je      .L12
        cmp     DWORD PTR [rbp-4], 10
        jg      .L9
        cmp     DWORD PTR [rbp-4], 1
        je      .L13
        cmp     DWORD PTR [rbp-4], 6
        je      .L14
        jmp     .L9
		//Возвращаемые значения
.L13:
        mov     eax, 5
        jmp     .L15
.L14:
        mov     eax, 7
        jmp     .L15
.L12:
        mov     eax, 3
        jmp     .L15
.L11:
        mov     eax, 9
        jmp     .L15
.L10:
        mov     eax, 8
        jmp     .L15
.L8:
        mov     eax, 4
        jmp     .L15
.L9:
        mov     eax, 0
.L15:
        pop     rbp
        ret

*Переменные хранятся в rbp,[rbp-4],eax.
*Ветвление представлено операторами сравнения и перехода je, jg, jmp, а так же метками .L{N} - N - номер метки
*Массивов нет
______________________________________________________________
int f3(int a)
{
    switch (a)
    {
    case 3:
        return 5;
    case 5:
        return 7;
    case 6:
        return 3;
    case 8:
        return 4;
    case 9:
        return 1;
    case 7:
        return 8;
    }
    return 0;
}

f3:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi //Получение аргумента
        mov     eax, DWORD PTR [rbp-4]
        sub     eax, 3
        cmp     eax, 6
        ja      .L17
        mov     eax, eax
        mov     rax, QWORD PTR .L19[0+rax*8] //Ветвления
        jmp     rax
.L19:
        .quad   .L24
        .quad   .L17
        .quad   .L23
        .quad   .L22
        .quad   .L21
        .quad   .L20
        .quad   .L18
	//Возвращаемые значения
.L24:
        mov     eax, 5
        jmp     .L25
.L23:
        mov     eax, 7
        jmp     .L25
.L22:
        mov     eax, 3
        jmp     .L25
.L20:
        mov     eax, 4
        jmp     .L25
.L18:
        mov     eax, 1
        jmp     .L25
.L21:
        mov     eax, 8
        jmp     .L25
.L17:
        mov     eax, 0
.L25:
        pop     rbp
        ret

*Переменные хранятся в rbp, [rbp-4], eax, rax.
*Ветвление представлено оператором обращения по значению, а так же метками .L{N} - N - номер метки
*Массивов нет

______________________________________________________________

int if2(int a)
{
    int b = a == 50 ? 12 : 26;
    return b;
}

if2:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-20], edi //Получение аргумента
        cmp     DWORD PTR [rbp-20], 50 //Вычитание (проверка условия)
        jne     .L27
        mov     eax, 12
        jmp     .L28
.L27:
        mov     eax, 26
.L28:
        mov     DWORD PTR [rbp-4], eax
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret

Переменные храняться в [rbp-20], eax, [rbp-4]
Условие организованно, с помощью вычитания cmp которое выставляет флаг в 1 в случае если результат вычитания равен 0
______________________________________________________________int if3(int a, int b, int c)
{
    if (a && c)
        return b;
    else
        return c;
}

if3:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi //Получение аргумента a
        mov     DWORD PTR [rbp-8], esi //Получение аргумента b
        mov     DWORD PTR [rbp-12], edx//Получение аргумента c
        cmp     DWORD PTR [rbp-4], 0
        je      .L31
        cmp     DWORD PTR [rbp-12], 0
        je      .L31
        mov     eax, DWORD PTR [rbp-8]
        jmp     .L32
.L31:
        mov     eax, DWORD PTR [rbp-12]
.L32:
        pop     rbp
        ret
Переменные храняться в [rbp-4],[rbp-8],[rbp-12], eax
Условие организованно, с помощью вычитания cmp, je, jmp

______________________________________________________________
int if4(int a, int b, int c)
{
    if (a || c == b)
        return b;
    else
        return a;
}

if4:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi //Получение аргумента a
        mov     DWORD PTR [rbp-8], esi //Получение аргумента b
        mov     DWORD PTR [rbp-12], edx//Получение аргумента c
        cmp     DWORD PTR [rbp-4], 0
        jne     .L34
        mov     eax, DWORD PTR [rbp-12]
        cmp     eax, DWORD PTR [rbp-8]
        jne     .L35
.L34:							//Условие верно
        mov     eax, DWORD PTR [rbp-8]
        jmp     .L36
.L35:							//Условие ложно
        mov     eax, DWORD PTR [rbp-4]
.L36:
        pop     rbp
        ret
Переменные храняться в [rbp-4],[rbp-8],[rbp-12], eax
Условие организованно, с помощью вычитания cmp, je, jmp

______________________________________________________________
void f2_1()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}

f2_1:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], 0
        jmp     .L38
.L39:
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        sal     rax, 2
        lea     rdx, t[rax]
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        mov     QWORD PTR s[0+rax*8], rdx
        add     DWORD PTR [rbp-4], 1
.L38:
        cmp     DWORD PTR [rbp-4], 100
        jne     .L39
        nop
        nop
        pop     rbp
        ret

Переменные хранятся в[rbp-4], eax
rdx, s[0+rax*8] t[rax] - массивы 
Цикл организован с помощью сравнений и переходов по меткам с операторами jmp и jne,lea работает как приемник-> источник
______________________________________________________________
void g();

void f1(int a)
{
    while (a)
    {
        --a;
        g();
    }
}


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

void f4(int a)
{
    do
    {
        --a;
        g();
    }
    while (a);
}

f1:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi //Получение аргумента 
        jmp     .L41
.L42:
        sub     DWORD PTR [rbp-4], 1
        mov     eax, 0
        call    g
.L41:
        cmp     DWORD PTR [rbp-4], 0
        jne     .L42
        nop
        nop
        leave
        ret
f2_2:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi //Получение аргумента 
.L44:
        cmp     DWORD PTR [rbp-4], 0
        je      .L46
        sub     DWORD PTR [rbp-4], 1
        mov     eax, 0
        call    g
        jmp     .L44
.L46:
        nop
        leave
        ret
f4:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi //Получение аргумента 
.L48:
        sub     DWORD PTR [rbp-4], 1
        mov     eax, 0
        call    g
        cmp     DWORD PTR [rbp-4], 0
        jne     .L48
        nop
        nop
        leave
        ret

Переменные хранятся в [rbp - 4],еах 
Ветвление организованно с помощью jmp, jne, je и перехода по меткам 
______________________________________________________________
