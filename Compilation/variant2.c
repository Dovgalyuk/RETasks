========================================================\
unsigned int fd(unsigned int a)                    
{
    return a / 10;
}

fd:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi   - передача аргументов                                ONE
        mov     eax, DWORD PTR [rbp-4]
        mov     edx, eax
        mov     eax, 3435973837
        imul    rax, rdx
        shr     rax, 32
        shr     eax, 3
        pop     rbp
        ret

        переменные хранятся в rbp, rsp, eax, edx, [rbp-4]
        нет массивов и ветвления
                                                        |
========================================================/


========================================================\
unsigned int fd1(unsigned int a)
{
    return a / 16;
}

fd1:
        push    rbp
        mov     rbp, rsp                                                                      TWO
        mov     DWORD PTR [rbp-4], edi
        mov     eax, DWORD PTR [rbp-4]
        shr     eax, 4
        pop     rbp
        ret
        переменные хранятся в rbr,rsp, [rbp-4], eax
        нет массивов и ветвления
                                                        |
========================================================/

========================================================\
unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}

fd2:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi   передача аргументов                                  THREE
        mov     DWORD PTR [rbp-8], esi   передача аргументов
        mov     eax, DWORD PTR [rbp-4]
        mov     edx, 0
        div     DWORD PTR [rbp-8]
        pop     rbp
        ret

        переменные хранятся в rbr,rsp, [rbp-4] [rbp-8],eax,edx
        нет массивов и ветвления
                                                        |
========================================================/

========================================================\
int f(int a)
{
    switch (a)
    {
    case 1:
        return 5;
    case 6:
        return 7;
    case 10:
        return 3;
    case 12:                                                                                    FOUR
        return 4;
    case 62:
        return 1;
    case 20:
        return 8;
    }
    return 0;
}

f:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi - передача переменных
        cmp     DWORD PTR [rbp-4], 20   начало ветвлени
        jg      .L8
        cmp     DWORD PTR [rbp-4], 0
        jle     .L9
        cmp     DWORD PTR [rbp-4], 20
        ja      .L9
        mov     eax, DWORD PTR [rbp-4]
        mov     rax, QWORD PTR .L11[0+rax*8]
        jmp     rax
.L11:
        .quad   .L9
        .quad   .L15
        .quad   .L9
        .quad   .L9
        .quad   .L9
        .quad   .L9
        .quad   .L14
        .quad   .L9
        .quad   .L9
        .quad   .L9
        .quad   .L13
        .quad   .L9
        .quad   .L12
        .quad   .L9
        .quad   .L9
        .quad   .L9
        .quad   .L9
        .quad   .L9
        .quad   .L9
        .quad   .L9
        .quad   .L10
.L8:
        cmp     DWORD PTR [rbp-4], 62
        je      .L16
        jmp     .L9
.L15:
        mov     eax, 5
        jmp     .L17
.L14:
        mov     eax, 7
        jmp     .L17
.L13:
        mov     eax, 3
        jmp     .L17
.L12:
        mov     eax, 4
        jmp     .L17
.L16:
        mov     eax, 1
        jmp     .L17
.L10:
        mov     eax, 8
        jmp     .L17
.L9:
        mov     eax, 0
.L17:
        pop     rbp
        ret
        переменные хранятся в rbr,rsp, eax, .L11[0+rax*8], [rbp-4]
        ветвление представлено операторами сравнения и перехода ja, jg, jle, jmp 
        а так же метками .L{N} - N - номер метки
        нет массивов
                                                        |
========================================================/

========================================================\
int f2(int a)
{
    switch (a)
    {
    case 1:
        return 5;
    case 6:
        return 7;
    case 10:                                                                                FIVE
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
        mov     DWORD PTR [rbp-4], edi - объявление переменных
        cmp     DWORD PTR [rbp-4], 10000
        je      .L19
        cmp     DWORD PTR [rbp-4], 10000
        jg      .L20
        cmp     DWORD PTR [rbp-4], 6000
        je      .L21
        cmp     DWORD PTR [rbp-4], 6000
        jg      .L20
        cmp     DWORD PTR [rbp-4], 1000
        je      .L22
        cmp     DWORD PTR [rbp-4], 1000
        jg      .L20
        cmp     DWORD PTR [rbp-4], 10
        je      .L23
        cmp     DWORD PTR [rbp-4], 10
        jg      .L20
        cmp     DWORD PTR [rbp-4], 1
        je      .L24
        cmp     DWORD PTR [rbp-4], 6
        je      .L25
        jmp     .L20
.L24:
        mov     eax, 5
        jmp     .L26
.L25:
        mov     eax, 7
        jmp     .L26
.L23:
        mov     eax, 3
        jmp     .L26
.L22:
        mov     eax, 9
        jmp     .L26
.L21:
        mov     eax, 8
        jmp     .L26
.L19:
        mov     eax, 4
        jmp     .L26
.L20:
        mov     eax, 0
.L26:
        pop     rbp
        ret
        переменные хранятся в rbr,rsp, [rb[-4], eax
        ветвление представлено операторами сравнения и перехода ja, jg, je, jle, jmp 
        а так же метками .L{N} - N - номер метки
        нет массивов
                                                        |
========================================================/


========================================================\
int if1(int a)
{
    int b = a == 0 ? 1 : 2;
    return b;
}

if1:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-20], edi - объявление переменных
        cmp     DWORD PTR [rbp-20], 0
        jne     .L28
        mov     eax, 1
        jmp     .L29                                                                                SIX
.L28:
        mov     eax, 2
.L29:
        mov     DWORD PTR [rbp-4], eax
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret

        переменные хранятся в rbr,rsp [rbp-20],eax,[rbp-4]
        ветвление представлено операторами jne, jmp и сравнением
        а так же метками .L{N} - N - номер метки
        нет массивов

                                                        |
========================================================/

========================================================\
int if2(int a)
{
    int b = a == 50 ? 12 : 26;
    return b;
}

if2:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-20], edi - объявление переменных
        cmp     DWORD PTR [rbp-20], 50
        jne     .L32
        mov     eax, 12
        jmp     .L33                                                                                 SEVEN
.L32:
        mov     eax, 26
.L33:
        mov     DWORD PTR [rbp-4], eax
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret

        переменные хранятся в rbr,rsp
        ветвление представлено операторами jne, jmp и сравнением
        а так же метками .L{N} - N - номер метки
                                                        |
========================================================/

========================================================\
int if3(int a, int b, int c)
{
    if (a && c)
        return b;
    else
        return c;
}

if3:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi  - \
        mov     DWORD PTR [rbp-8], esi  - объявление переменных
        mov     DWORD PTR [rbp-12], edx - /
        cmp     DWORD PTR [rbp-4], 0                                                                   EIGHT
        je      .L36
        cmp     DWORD PTR [rbp-12], 0
        je      .L36
        mov     eax, DWORD PTR [rbp-8]
        jmp     .L37
.L36:
        mov     eax, DWORD PTR [rbp-12]
.L37:
        pop     rbp
        ret
        переменные хранятся в rbr,rsp, [rbp - 4, -8, -12] , eax
        ветвление представлено операторами je, jmp и сравнением
        а так же метками .L{N} - N - номер метки

                                                        |
========================================================/

========================================================\
int *s[100];
int t[100];
void func2()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}

func2:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], 0
        jmp     .L39
.L40:
        mov     eax, DWORD PTR [rbp-4]
        cdqe                                                                                            NINE
        sal     rax, 2
        lea     rdx, t[rax]
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        mov     QWORD PTR s[0+rax*8], rdx
        add     DWORD PTR [rbp-4], 1
.L39:
        cmp     DWORD PTR [rbp-4], 100
        jne     .L40
        nop
        nop
        pop     rbp
        ret
        переменные хранятся в rbr,rsp, [rbp-4] eax
        {rax, rdx,  s[0+rax*8] t[rax] }- массивы 
        цикл организован с помощью сравнений и переходов по меткам с операторами jmp и jne
                                                        |
========================================================/


========================================================\
void g();

void f1(int a)
{
    while (a)
    {
        --a;
        g();
    }
}

f1:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi  - объявление переменных                                                  TEN
        jmp     .L42
.L43:
        sub     DWORD PTR [rbp-4], 1
        mov     eax, 0
        call    g
.L42:
        cmp     DWORD PTR [rbp-4], 0
        jne     .L43
        nop
        nop
        leave
        ret
        переменные хранятся в rbr,rsp, [rbp-4], eax
        оператор ветвления организован с помощью переходов по меткам и операторов je, jmp
        с помощью сравнения и переходов организован цикл
                                                        |
========================================================/

========================================================\
void ff2(int a)
{
L:
    if (a)
    {
        --a;
        g();
        goto L;
    }
}

ff2:
        push    rbp
        mov     rbp, rsp                                                                                    ELEVEN
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi - передача переменных
.L45:
        cmp     DWORD PTR [rbp-4], 0
        je      .L47
        sub     DWORD PTR [rbp-4], 1
        mov     eax, 0
        call    g
        jmp     .L45
.L47:
        nop
        leave
        ret
        переменные хранятся в rbr,rsp, [rbp-4], eax
        осуществляется вызов g но ничего не делает, ветвление оргнизовано с помощью 
        меток и операторов je, jmp а так же с помощью этого организован цикл
                                                        |
========================================================/

========================================================\
void f3(int *p)
{
    for (int i = 0 ; i < 10 ; ++i)
    {
        ++*p;
        if (*p == 5) continue;
        ++*p;
    }
}

f3:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-24], rdi
        mov     DWORD PTR [rbp-4], 0
        jmp     .L49
.L52:                                                                                                       TWELVE
        mov     rax, QWORD PTR [rbp-24]
        mov     eax, DWORD PTR [rax]
        lea     edx, [rax+1]
        mov     rax, QWORD PTR [rbp-24]
        mov     DWORD PTR [rax], edx
        mov     rax, QWORD PTR [rbp-24]
        mov     eax, DWORD PTR [rax]
        cmp     eax, 5
        je      .L53
        mov     rax, QWORD PTR [rbp-24]
        mov     eax, DWORD PTR [rax]
        lea     edx, [rax+1]
        mov     rax, QWORD PTR [rbp-24]
        mov     DWORD PTR [rax], edx
        jmp     .L51
.L53:
        nop
.L51:
        add     DWORD PTR [rbp-4], 1
.L49:
        cmp     DWORD PTR [rbp-4], 9
        jle     .L52
        nop
        nop
        pop     rbp
        ret
        переменные хранятся в rbr,rsp
        ветвление оргнизовано с помощью меток и операторов je, jmp, jle, операторов сравнения
        а так же с помощью этого организован цикл с условием

                                                        |
========================================================/