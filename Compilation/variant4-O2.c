Главное отличие оптимизированной версии от не оптимизированной 
это отстутсивие помещения элеентов в DWORD PTR[] с выделенением памяти
Так же некоторые операции преобразовались

unsigned int fd(unsigned int a)
{
    return a / 10;
}

fd:
        mov     eax, edi
        mov     edi, 3435973837
        imul    rax, rdi
        shr     rax, 35
        ret
Переменные храняться в edi, eax,rax
Ветвлений и массивов нет
______________________________________________________________
unsigned int fd1(unsigned int a)
{
    return a / 16;
}

fd1:
        mov     eax, edi
        shr     eax, 4
        ret
Переменные храняться в eax
______________________________________________________________
unsigned int fd2(unsigned int a, unsigned int b)
{
    return a % b;
}

fd2:
        mov     eax, edi
        xor     edx, edx
        div     esi
        mov     eax, edx
        ret
Переменные храняться в eax,edx
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
        cmp     edi, 1000
        je      .L8
        jg      .L7
        mov     eax, 7
        cmp     edi, 6
        je      .L5
        mov     eax, 3
        cmp     edi, 10
        jne     .L17
.L5:
        ret
.L17:
        xor     eax, eax
        cmp     edi, 1
        sete    al
        lea     eax, [rax+rax*4]
        ret
.L7:
        mov     eax, 8
        cmp     edi, 6000
        je      .L5
        xor     eax, eax
        cmp     edi, 10000
        sete    al
        sal     eax, 2
        ret
.L8:
        mov     eax, 9
        ret

*Переменные хранятся в eax,edi.
*Ветвление образуется с помощью cmp,jg,je,jne и перехода по меткам .L[N]
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
        sub     edi, 3
        xor     eax, eax
        cmp     edi, 6
        ja      .L18
        mov     eax, DWORD PTR CSWTCH.6[0+rdi*4]
.L18:
        ret


*Переменные хранятся в eax, edi.
______________________________________________________________

int if2(int a)
{
    int b = a == 50 ? 12 : 26;
    return b;
}

if2:
        cmp     edi, 50
        mov     edx, 26
        mov     eax, 12
        cmovne  eax, edx
        ret

Переменные храняться в edi,eax, edx
Условие организованно, с помощью cmovne
______________________________________________________________int if3(int a, int b, int c)
{
    if (a && c)
        return b;
    else
        return c;
}

if3:
        mov     eax, esi
        test    edi, edi
        je      .L27
        test    edx, edx
        je      .L27
        ret
.L27:
        mov     eax, edx
        ret

Переменные храняться в eax,edi,edx
Условие организованно, с помощью вычитания je, test

______________________________________________________________
int if4(int a, int b, int c)
{
    if (a || c == b)
        return b;
    else
        return a;
}

if4:
        test    edi, edi
        jne     .L35
        xor     eax, eax
        cmp     edx, esi
        je      .L35
        ret
.L35:
        mov     eax, esi
        ret

Переменные храняться в eax,edi,edx
Условие организованно, с помощью вычитания cmp, je, jne

______________________________________________________________
void f2_1()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}

f2_1:
        mov     eax, OFFSET FLAT:t
        mov     edx, OFFSET FLAT:s
.L38:
        mov     QWORD PTR [rdx], rax
        add     rax, 4
        add     rdx, 8
        cmp     rax, OFFSET FLAT:t+400
        jne     .L38
        ret

Переменные хранятся eax,edx
[rdx],t- массивы 
Цикл организован с помощью jne,cmp ______________________________________________________________
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
        test    edi, edi
        je      .L48
        push    rbx
        mov     ebx, edi
.L42:
        sub     ebx, 1
        xor     eax, eax
        call    g
        test    ebx, ebx
        jne     .L42
        pop     rbx
        ret
.L48:
        ret
f2_2:
        test    edi, edi
        je      .L59
        push    rbx
        mov     ebx, edi
.L53:
        sub     ebx, 1
        xor     eax, eax
        call    g
        test    ebx, ebx
        jne     .L53
        pop     rbx
        ret
.L59:
        ret
f4:
        push    rbx
        mov     ebx, edi
.L63:
        sub     ebx, 1
        xor     eax, eax
        call    g
        test    ebx, ebx
        jne     .L63
        pop     rbx
        ret
CSWTCH.6:
        .long   5
        .long   0
        .long   7
        .long   3
        .long   8
        .long   4
        .long   1
t:
        .zero   400
s:
        .zero   800

Переменные хранятся в ebx,eax
Ветвление организованно с помощью jne и test
______________________________________________________________
