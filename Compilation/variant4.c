unsigned int f1(unsigned int a)
{
    return a / 10;
}

unsigned int f2(unsigned int a)
{
    return a / 16;
}

unsigned int f3(unsigned int a, unsigned int b)
{
    return a % b;
}

int f4(int a)
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

int f5(int a)
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

int f6(int a)
{
    int b = a == 50 ? 12 : 26;
    return b;
}
int f7(int a, int b, int c)
{
    if (a && c)
        return b;
    else
        return c;
}
int f8(int a, int b, int c)
{
    if (a || c == b)
        return b;
    else
        return a;
}

int *s[100];
int t[100];
void f9()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}

void g();

void f10(int a)
{
    while (a)
    {
        --a;
        g();
    }
}

void f11(int a)
{
L:
    if (a)
    {
        --a;
        g();
        goto L;
    }
}

void f12(int a)
{
    do
    {
        --a;
        g();
    }
    while (a);
}
