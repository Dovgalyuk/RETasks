unsigned int fd(unsigned int a)
{
    return a / 10;
}

fd:                                     # @fd
        mov     DWORD PTR [RSP - 4], EDI передача аргументов
        mov     EAX, EDI
        mov     ECX, 3435973837
        imul    RCX, RAX
        shr     RCX, 35
        mov     EDX, ECX
        mov     ESI, 10
        mov     EAX, EDX
        mov     DWORD PTR [RSP - 8], ESI # 4-byte Spill
        mov     DWORD PTR [RSP - 12], EDI # 4-byte Spill
        ret
        
        переменные хранятся в [rsp-4],ecx,edx,esi,rax,rcx
        ветвлений и массивов нет
        деление на 10 орагнизованно через умножение на 3435973837 и сдвиг на 35 позиций
        перед тем как поместить что-то в переменные выделяетя место в памяти ,в стек помешается через [rsp -4] итд


=============================================

unsigned int fd1(unsigned int a)
{
    return a / 16;
}


 mov     DWORD PTR [RSP - 4], EDI
        mov     EDI, DWORD PTR [RSP - 4]
        shr     EDI, 4
        mov     EAX, EDI
        ret

        переменные в [rsp-4],edi,eax
        сначала выделяется память ,а хранится в еди
        деление происзодит через сдвиг на 4
        результат помещается в еах
===================================
unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}

fd2:                                    # @fd2
        mov     DWORD PTR [RSP - 4], EDI передача аргументов
        mov     DWORD PTR [RSP - 8], ESI передача аргументов
        mov     EAX, DWORD PTR [RSP - 4]
        xor     EDX, EDX
        div     ESI
        mov     DWORD PTR [RSP - 12], ESI # 4-byte Spill
        ret
        переменные в [rsp-4],[rsp-8],eax,edx
        для а,б выделяются места в стеке , затем в еах помещается значение ,потом проверяется будет ли делитель равен 0 и делят 
===============

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
    case 12:
        return 4;
    case 62:
        return 1;
    case 20:
        return 8;
    }
    return 0;
}

f:                                      # @f
        mov     DWORD PTR [RSP - 8], EDI передача аргементов
        mov     EAX, EDI
        cmp     EDI, 61 начало ветвления со сравнения с числом
        mov     DWORD PTR [RSP - 12], EAX # 4-byte Spill
        jg      .LBB0_10 сравнение
        jmp     .LBB0_9 переход по условию
.LBB0_9:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 19
        jg      .LBB0_12
        jmp     .LBB0_11
.LBB0_11:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 5
        jg      .LBB0_14
        jmp     .LBB0_13
.LBB0_13:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 1
        je      .LBB0_1
        jmp     .LBB0_7
.LBB0_14:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 6
        je      .LBB0_2
        jmp     .LBB0_15
.LBB0_15:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 10
        je      .LBB0_3
        jmp     .LBB0_16
.LBB0_16:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 12
        je      .LBB0_4
        jmp     .LBB0_7
.LBB0_12:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 20
        je      .LBB0_6
        jmp     .LBB0_7
.LBB0_10:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 62
        je      .LBB0_5
        jmp     .LBB0_7
.LBB0_1:                      ВАРИАНТЫ ВОЗВРАЩЕННЫХ ЗНАЧЕНИЯ
        mov     DWORD PTR [RSP - 4], 5 
        jmp     .LBB0_8
.LBB0_2:
        mov     DWORD PTR [RSP - 4], 7
        jmp     .LBB0_8
.LBB0_3:
        mov     DWORD PTR [RSP - 4], 3
        jmp     .LBB0_8
.LBB0_4:
        mov     DWORD PTR [RSP - 4], 4
        jmp     .LBB0_8
.LBB0_5:
        mov     DWORD PTR [RSP - 4], 1
        jmp     .LBB0_8
.LBB0_6:
        mov     DWORD PTR [RSP - 4], 8
        jmp     .LBB0_8
.LBB0_7:
        mov     DWORD PTR [RSP - 4], 0
.LBB0_8:
        mov     EAX, DWORD PTR [RSP - 4]
        ret

    переменные хранятся в [RSP - 4],еах,[RSP - 8],[RSP - 12],edi
    ветвление представлено операторами сравнения и перехода  jg, je, jmp 
    а так же метками .L{N} - N - номер метки
    нет массивов
    выделяются места в памяти, сначала для а и заме в зависимости от условий для числа которое нужно вывести

================================================

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
f2:                                     # @f2
        mov     DWORD PTR [RSP - 8], EDI
        mov     EAX, EDI
        cmp     EDI, 9999
        mov     DWORD PTR [RSP - 12], EAX # 4-byte Spill
        jg      .LBB0_10
        jmp     .LBB0_9
.LBB0_9:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 5999
        jg      .LBB0_12
        jmp     .LBB0_11
.LBB0_11:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 999
        jg      .LBB0_14
        jmp     .LBB0_13
.LBB0_13:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 1
        je      .LBB0_1
        jmp     .LBB0_15
.LBB0_15:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 6
        je      .LBB0_2
        jmp     .LBB0_16
.LBB0_16:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 10
        je      .LBB0_3
        jmp     .LBB0_7
.LBB0_14:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 1000
        je      .LBB0_4
        jmp     .LBB0_7
.LBB0_12:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 6000
        je      .LBB0_5
        jmp     .LBB0_7
.LBB0_10:
        mov     EAX, DWORD PTR [RSP - 12] # 4-byte Reload
        cmp     EAX, 10000
        je      .LBB0_6
        jmp     .LBB0_7
.LBB0_1:
        mov     DWORD PTR [RSP - 4], 5
        jmp     .LBB0_8
.LBB0_2:
        mov     DWORD PTR [RSP - 4], 7
        jmp     .LBB0_8
.LBB0_3:
        mov     DWORD PTR [RSP - 4], 3
        jmp     .LBB0_8
.LBB0_4:
        mov     DWORD PTR [RSP - 4], 9
        jmp     .LBB0_8
.LBB0_5:
        mov     DWORD PTR [RSP - 4], 8
        jmp     .LBB0_8
.LBB0_6:
        mov     DWORD PTR [RSP - 4], 4
        jmp     .LBB0_8
.LBB0_7:
        mov     DWORD PTR [RSP - 4], 0
.LBB0_8:
        mov     EAX, DWORD PTR [RSP - 4]
        ret
        переменные хранятся в [RSP - 4],еах,[RSP - 8],[RSP - 12],edi
    ветвление представлено операторами сравнения и перехода  jg, je, jmp 
    а так же метками .L{N} - N - номер метки
    нет массивов

==================================

int if1(int a)
{
    int b = a == 0 ? 1 : 2;
    return b;
}
  mov     EAX, 2
        mov     DWORD PTR [RSP - 4], EDI  объявление переменной
        cmp     DWORD PTR [RSP - 4], 0 сравнение с нулем
        sete    CL помещение 1 или 0 
        test    CL, CL логическое и
        mov     EDI, 1
        cmove   EDI, EAX
        mov     DWORD PTR [RSP - 8], EDI
        mov     EAX, DWORD PTR [RSP - 8]
        ret
        переменные хранятся в еах,edi
        выделяются места в памяти,затем сравнивается с 0 и в сл помещается 0 или 1 в зависимости от сравнения , в еди помещается 1
        после смув сравнивает и в память для вывода помещаются результаты
=================
int if2(int a)
{
    int b = a == 50 ? 12 : 26;
    return b;
}
if2:                                    # @if2
        mov     EAX, 26
        mov     DWORD PTR [RSP - 4], EDI
        cmp     DWORD PTR [RSP - 4], 50
        sete    CL
        test    CL, CL
        mov     EDI, 12
        cmove   EDI, EAX
        mov     DWORD PTR [RSP - 8], EDI
        mov     EAX, DWORD PTR [RSP - 8]
        ret
    
        переменные хранятся в еах,edi

===================
int if3(int a, int b, int c)
{
    if (a && c)
        return b;
    else
        return c;
}
if3:                                    # @if3
        mov     DWORD PTR [RSP - 8], EDI
        mov     DWORD PTR [RSP - 12], ESI
        mov     DWORD PTR [RSP - 16], EDX
        cmp     DWORD PTR [RSP - 8], 0
        je      .LBB0_3
        cmp     DWORD PTR [RSP - 16], 0
        je      .LBB0_3
        mov     EAX, DWORD PTR [RSP - 12]
        mov     DWORD PTR [RSP - 4], EAX
        jmp     .LBB0_4
.LBB0_3:
        mov     EAX, DWORD PTR [RSP - 16]
        mov     DWORD PTR [RSP - 4], EAX
.LBB0_4:
        mov     EAX, DWORD PTR [RSP - 4]
        ret
         переменные хранятся в  еах,edi,esi,edx
         ветвления при сравнении организованны с помощью je,ccmp,jmp в
         метки .L{N} - N - номер метки


=========================

int *s[100];
int t[100];
void f2()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}
f2:                                     # @f2
        mov     DWORD PTR [RSP - 4], 0
.LBB0_1:                                
        cmp     DWORD PTR [RSP - 4], 100
        je      .LBB0_4
        lea     RAX, QWORD PTR [t]
        movsxd  RCX, DWORD PTR [RSP - 4]
        shl     RCX, 2
        add     RCX, RAX
        movsxd  RAX, DWORD PTR [RSP - 4]
        mov     QWORD PTR [8*RAX + s], RCX
        mov     EAX, DWORD PTR [RSP - 4]
        add     EAX, 1
        mov     DWORD PTR [RSP - 4], EAX
        jmp     .LBB0_1
.LBB0_4:
        ret
        переменные хранятся в ,rcx, [rbp-4] eax
        rax, [s+rax*8] [t] - массивы 
        цикл организован с помощью сравнений и переходов по меткам с операторами jmp и je,lea работает как приемник-> источник
        на каждом шаге цикла происходит сравнение 100 со счетчиком ,елли равноЮто конец ,если нет ,то значение счетчика в еах увеличивают на 1 ,а перед этим выделяют в места в 
        памяти для помещения туда значений 
===============================
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

void f3(int *p)
{
    for (int i = 0 ; i < 10 ; ++i)
    {
        ++*p;
        if (*p == 5) continue;
        ++*p;
    }
}

f1:                                     # @f1
        push    RBP
        mov     RBP, RSP
        sub     RSP, 16
        mov     DWORD PTR [RBP - 4], EDI передача аргументов
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
        cmp     DWORD PTR [RBP - 4], 0
        je      .LBB0_3
        mov     EAX, DWORD PTR [RBP - 4]
        add     EAX, 4294967295
        mov     DWORD PTR [RBP - 4], EAX
        mov     AL, 0
        call    g
        jmp     .LBB0_1
.LBB0_3:
        add     RSP, 16
        pop     RBP
        ret

f2:                                     # @f2
        push    RBP
        mov     RBP, RSP
        sub     RSP, 16
        mov     DWORD PTR [RBP - 4], EDI
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
        cmp     DWORD PTR [RBP - 4], 0
        je      .LBB1_3
        mov     EAX, DWORD PTR [RBP - 4]
        add     EAX, 4294967295
        mov     DWORD PTR [RBP - 4], EAX
        mov     AL, 0
        call    g
        jmp     .LBB1_1
.LBB1_3:
        add     RSP, 16
        pop     RBP
        ret

f3:                                     # @f3
        mov     QWORD PTR [RSP - 8], RDI
        mov     DWORD PTR [RSP - 12], 0
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
        cmp     DWORD PTR [RSP - 12], 10
        jge     .LBB2_6
        mov     RAX, QWORD PTR [RSP - 8]
        mov     ECX, DWORD PTR [RAX]
        add     ECX, 1
        mov     DWORD PTR [RAX], ECX
        mov     RAX, QWORD PTR [RSP - 8]
        cmp     DWORD PTR [RAX], 5
        jne     .LBB2_4
        jmp     .LBB2_5
.LBB2_4:                                #   in Loop: Header=BB2_1 Depth=1
        mov     RAX, QWORD PTR [RSP - 8]
        mov     ECX, DWORD PTR [RAX]
        add     ECX, 1
        mov     DWORD PTR [RAX], ECX
.LBB2_5:                                #   in Loop: Header=BB2_1 Depth=1
        mov     EAX, DWORD PTR [RSP - 12]
        add     EAX, 1
        mov     DWORD PTR [RSP - 12], EAX
        jmp     .LBB2_1
.LBB2_6:
        ret
        
        переменные хранятся в [RBP - 4],еах,rsp,al,ecx
        ветвление организованно с помощью jmp,jne,jge,je и перехода по меткам 
