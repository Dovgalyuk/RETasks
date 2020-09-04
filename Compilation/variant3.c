unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}

unsigned int fd3(unsigned int a)
{
    return a % 10;
}

unsigned int fd4(unsigned int a)
{
    return a % 16;
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
int if4(int a, int b, int c)
{
    if (a || c == b)
        return b;
    else
        return a;
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

void f4(int a)
{
    do
    {
        --a;
        g();
    }
    while (a);
}
