unsigned int fd(unsigned int a)
{
    return a / 10;
}

unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}

unsigned int fd4(unsigned int a)
{
    return a % 16;
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

void f1(int *p)
{
    for (int i = 0 ; i < 10 ; ++i)
        *p++ = 0;
}

int *s[100];
int t[100];
void f2()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
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

void f4(int a)
{
    do
    {
        --a;
        g();
    }
    while (a);
}

int if1(int a)
{
    int b = a == 0 ? 1 : 2;
    return b;
}

int if4(int a, int b, int c)
{
    if (a || c == b)
        return b;
    else
        return a;
}
