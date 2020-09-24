unsigned int fd(unsigned int a)
{
    return a / 10;
}


fd:                                     
        mov     DWORD PTR [RSP - 4], EDI
        mov     EAX, EDI
        mov     ECX, 3435973837    -передача аргументов в функцию
        imul    RCX, RAX
        shr     RCX, 35
        mov     EDX, ECX
        mov     ESI, 10
        mov     EAX, EDX
        mov     DWORD PTR [RSP - 8], ESI # 4-byte Spill
        mov     DWORD PTR [RSP - 12], EDI # 4-byte Spill
        ret
        
        переменные хранятся в EDI,EAX,ECX,RCX,ESI
======================================
unsigned int fd1(unsigned int a)
{
    return a / 16;
}

        mov     DWORD PTR [RSP - 4], EDI
        mov     EDI, DWORD PTR [RSP - 4]
        shr     EDI, 4
        mov     EAX, EDI
        ret
    переменные хранятся в EDI,EAX, [RSP-4]
========================================

unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}
        mov     DWORD PTR [RSP - 4], EDI
        mov     DWORD PTR [RSP - 8], ESI
        mov     EAX, DWORD PTR [RSP - 4]
        xor     EDX, EDX
        div     ESI
        mov     DWORD PTR [RSP - 12], ESI # 4-byte Spill
        ret

        переменные хранятся в EDI,ESI,EDX,EAX, [RSP-4], [RSP-8]
================================================
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
        mov     DWORD PTR [RSP - 8], EDI
        mov     EAX, EDI
        cmp     EDI, 61
        mov     DWORD PTR [RSP - 12], EAX # 4-byte Spill
        jg      .LBB0_10
        jmp     .LBB0_9
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

    переменные хранятся в eax,edi,[rsp-4],[rsp-12]
        ветвление представлено операторами сравнения и перехода  jg, je, jmp 
        а так же метками .L{N} - N - номер метки
======================================================

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
        
       аналогично вышеупомянутому

==================================================
int if1(int a)
{
    int b = a == 0 ? 1 : 2;
    return b;
}
int if2(int a)
{
    int b = a == 50 ? 12 : 26;
    return b;
}
int if3(int a, int b, int c)
{
    if (a && c)
        return b;
    else
        return c;
}
if1:                                    # @if1
        mov     EAX, 2
        mov     DWORD PTR [RSP - 4], EDI
        cmp     DWORD PTR [RSP - 4], 0
        sete    CL
        test    CL, CL
        mov     EDI, 1
        cmove   EDI, EAX
        mov     DWORD PTR [RSP - 8], EDI
        mov     EAX, DWORD PTR [RSP - 8]
        ret

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

if3:                                    # @if3
        mov     DWORD PTR [RSP - 8], EDI
        mov     DWORD PTR [RSP - 12], ESI
        mov     DWORD PTR [RSP - 16], EDX
        cmp     DWORD PTR [RSP - 8], 0
        je      .LBB2_3
        cmp     DWORD PTR [RSP - 16], 0
        je      .LBB2_3
        mov     EAX, DWORD PTR [RSP - 12]
        mov     DWORD PTR [RSP - 4], EAX
        jmp     .LBB2_4
.LBB2_3:
        mov     EAX, DWORD PTR [RSP - 16]
        mov     DWORD PTR [RSP - 4], EAX
.LBB2_4:
        mov     EAX, DWORD PTR [RSP - 4]
        ret
        
        переменные хранятся в eax,edi, [rsp-4],[rsp-8],[rsp-12],[rsp-16]
        ветвление представлено операторами jne, jmp,CL и сравнением
        а так же метками .L{N} - N - номер метки
        нет массивов

=====================================================

int *s[100];
int t[100];
void f2()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}
f2:                                     # @f2
        mov     DWORD PTR [RSP - 4], 0
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
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
        
         переменные хранятся в rcx,rsp, [rsp-4] eax
        {rax, rdx,  [s+rax*8] [t] }- массивы 
        цикл организован с помощью сравнений и переходов по меткам с операторами jmp и jne

=============================================================
void g();

void f1(int a)
{
    while (a)
    {
        --a;
        g();
    }
}

f1:                                     # @f1
        push    RBP
        mov     RBP, RSP
        sub     RSP, 16
        mov     DWORD PTR [RBP - 4], EDI
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
        переменные хранятся в rbp,rsp, [rbp-4], eax,edi
        оператор ветвления организован с помощью переходов по меткам и операторов je, jmp
        с помощью сравнения и переходов организован цикл

=====================================
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
f2:                                     # @f2
        push    RBP
        mov     RBP, RSP
        sub     RSP, 16
        mov     DWORD PTR [RBP - 4], EDI
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
        
        переменные хранятся в rbp,rsp, [rbp-4], eax,edi
        ветвление оргнизовано с помощью  меток и операторов je, jmp а так же с помощью этого организован цикл
==============================
void f3(int *p)
{
    for (int i = 0 ; i < 10 ; ++i)
    {
        ++*p;
        if (*p == 5) continue;
        ++*p;
    }
}

f3:                                     # @f3
        mov     QWORD PTR [RSP - 8], RDI
        mov     DWORD PTR [RSP - 12], 0
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
        cmp     DWORD PTR [RSP - 12], 10
        jge     .LBB1_6
        mov     RAX, QWORD PTR [RSP - 8]
        mov     ECX, DWORD PTR [RAX]
        add     ECX, 1
        mov     DWORD PTR [RAX], ECX
        mov     RAX, QWORD PTR [RSP - 8]
        cmp     DWORD PTR [RAX], 5
        jne     .LBB1_4
        jmp     .LBB1_5
.LBB1_4:                                #   in Loop: Header=BB1_1 Depth=1
        mov     RAX, QWORD PTR [RSP - 8]
        mov     ECX, DWORD PTR [RAX]
        add     ECX, 1
        mov     DWORD PTR [RAX], ECX
.LBB1_5:                                #   in Loop: Header=BB1_1 Depth=1
        mov     EAX, DWORD PTR [RSP - 12]
        add     EAX, 1
        mov     DWORD PTR [RSP - 12], EAX
        jmp     .LBB1_1
.LBB1_6:
        ret
        
        переменные хранятся в rdi,ecx,eax ...
        ветвление оргнизовано с помощью меток и операторов je, jmp, jne, операторов сравнения
        а так же с помощью этого организован цикл с условием
