unsigned int fd(unsigned int a)
{
    return a / 10;
}

unsigned int fd1(unsigned int a)
{
    return a / 16;
}

unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}

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

int *s[100];
int t[100];
void f2()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}

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
/*
1. Параметры передаются в функции при помощи оператора mov для перемещения. Здесь выделяется место из памяти при помощи DWORD PTR,после чего начинаются вычисления программы
    mov     DWORD PTR [RSP - 4], EDI
    mov     DWORD PTR [RSP - 8], ESI
    
2. Ветвление организуется при помощи использования cmp для сравнения с 0 ,а затем при помощи je, jle перемещаетсяв часть ассемблерного кода удовлетворяющего условию if 

3. циклы организуюся двумя способами: либо при помощи сравнений ,как в ветвлении, либо при помощи специального оператора LOOP, который будет возвращаться к метке и проходить ее,
    пока операторы сраврения не будут true
4. При заполнении массива организуется цикл в котором сперва всегда сравнивают инкрементирующуюся переменную с размером масси,в конце к ней добавляется шаг.
    Изначально под массив выделяется область памяти ,в которую последовательно будут записаны элементы. Во время цикла переменные помещаются в память при помощи MOV. 
    Если все элементы массива заполнены, то выполняется jmp на выход из программы 
5.Переменные помещаются в регистры. такими регистрами могут быть EAX EBX EDX итд.
*/
