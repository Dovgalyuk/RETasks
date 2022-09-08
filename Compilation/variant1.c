unsigned int f1(unsigned int a)
{
    return a / 10;
}

unsigned int f2(unsigned int a, unsigned int b)
{
    return a / b;
}

unsigned int f3(unsigned int a)
{
    return a % 16;
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
    case 12:
        return 4;
    case 62:
        return 1;
    case 20:
        return 8;
    }
    return 0;
}

int f5(int a)
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


void g();

void f6(int a)
{
    while (a)
    {
        --a;
        g();
    }
}

void f7(int a)
{
L:
    if (a)
    {
        --a;
        g();
        goto L;
    }
}

void f8(int *p)
{
    for (int i = 0 ; i < 10 ; ++i)
        *p++ = 0;
}

int *s[100];
int t[100];
void f9()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}


void f10(int *p)
{
    for (int i = 0 ; i < 10 ; ++i)
    {
        ++*p;
        if (*p == 5) continue;
        ++*p;
    }
}

void f11(int a)
{
    do
    {
        --a;
        g();
    }
    while (a);
}

int f12(int a, int b, int c)
{
    if (a || c == b)
        return b;
    else
        return a;
}
