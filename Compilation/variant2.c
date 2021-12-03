// Кожевников А.В. гр. 1093
/*
Вопросы:

   1. Как передаются параметры в функции?
   2. Как организован оператор ветвления?
   3. Как выполняется оператор цикла?
   4. Как происходят обращения к массивам?
   5. В каких регистрах или ячейках памяти хранятся переменные?
*/

/*

Краткое резюме по "gcc -O2":

В основном при использовании оптимизации мы получаем:

    1. Переменные используются без взаимодействия со стеком.
    2. Используется меньше регистров.
    3. Некоторые операции заменяются на более оптимальные.

*/

unsigned int fd(unsigned int a)
{
    return a / 10;
}

// fd: (Без оптимизации)          

// endbr64
// push    rbp
// mov     rbp, rsp
// mov     [rbp-4], edi // Помещаем переданный параметр на стек
// mov     eax, [rbp-4]
// mov     edx, eax
// mov     eax, 0CCCCCCCDh
// imul    rax, rdx
// shr     rax, 20h
// shr     eax, 3
// pop     rbp
// retn

/*
    1. Параметр передается через регистр edi.
    5. Переменные записываются в стек со смещением в 4 байта [rbp-4]
*/

//////////////////////////////////////////////////////////////////////////////////

// fd: (С оптимизацией "gcc -O2")   

// endbr64
// mov     eax, edi
// mov     edi, 0CCCCCCCDh
// imul    rax, rdi
// shr     rax, 23h
// retn

/*
    1. Параметр передается через регистр edi.
    5. Переменная записывается на прямую в регистр eax.
*/



unsigned int fd1(unsigned int a)
{
    return a / 16;
}

// fd1: (Без оптимизации)

// endbr64
// push    rbp
// mov     rbp, rsp
// mov     [rbp-4], edi
// mov     eax, [rbp-4]
// shr     eax, 4
// pop     rbp
// retn

/*
    1. Параметр передается через регистр edi.
    5. Переменные записываются в стек со смещением в 4 байта [rbp-4]
*/

//////////////////////////////////////////////////////////////////////////////////

// fd1: (С оптимизацией "gcc -O2") 

// endbr64
// mov     eax, edi
// shr     eax, 4
// retn

/*
    1. Параметр передается через регистр edi.
    5. Переменная записывается на прямую в регистр eax.
*/

unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}

// fd2: (Без оптимизации)

// endbr64
// push    rbp
// mov     rbp, rsp
// mov     [rbp-4], edi
// mov     [rbp-8], esi
// mov     eax, [rbp-4]
// mov     edx, 0
// div     dword ptr [rbp-8]
// pop     rbp
// retn

/*
    1. Параметры передаются через регистр edi, esi.
    5. Переменные записываются в стек со смещением в 4 байта (edi в [rbp-4], esi в [rbp-8])
*/

//////////////////////////////////////////////////////////////////////////////////

// fd2: (С оптимизацией "gcc -O2") 

// endbr64
// mov     eax, edi
// xor     edx, edx
// div     esi
// retn

/*
    1. Параметры передаются через регистр edi, esi.
    5. Переменные записываются в регистры eax, esi.
*/

//////////////////////////////////////////////////////////////////////////////////

// Главное отличие третьего от первого и второго в том, 
// что деление происходит через div (что менее эффективно), так как b заранее не известно.

//////////////////////////////////////////////////////////////////////////////////

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

// f: (Без оптимизации)

// endbr64
// push    rbp
// mov     rbp, rsp
// mov     [rbp-4], edi
// cmp     dword ptr [rbp-4], 14h
// jg      short loc_116A
// cmp     dword ptr [rbp-4], 0
// jle     short loc_119C
// cmp     dword ptr [rbp-4], 14h
// ja      short loc_119C
// mov     eax, [rbp-4]
// lea     rdx, ds:0[rax*4]
// lea     rax, unk_2004
// mov     eax, [rdx+rax]
// cdqe
// lea     rdx, unk_2004
// add     rax, rdx
// db      3Eh
// jmp     rax


// loc_116A:                              
// cmp     dword ptr [rbp-4], 3Eh ; '>'
// jz      short loc_118E
// jmp     short loc_119C

// mov     eax, 5
// jmp     short loc_11A1

// mov     eax, 7
// jmp     short loc_11A1

// mov     eax, 3
// jmp     short loc_11A1

// mov     eax, 4
// jmp     short loc_11A1


// loc_118E:                               
// mov     eax, 1
// jmp     short loc_11A1

// mov     eax, 8
// jmp     short loc_11A1


// loc_119C:                               
//                                         
// mov     eax, 0

// loc_11A1:                               
//                                        
// pop     rbp
// retn

/*
    1. Параметры передаются через регистр edi.
    2.1 При помощи cmp (сравнение), переходом без условия (jmp) и переходами с условием (jz, ja, jle,jg).
    2.2 Через вычисление метки:
    2.2.1 Ищем смещение с помощью добавления к unk_2004 параметра *4. После этого добавляем к адресу массива полученное смещение, тем самым переходя к искомому участку кода.
    5. Переменная записывается в стек со смещением в 4 байта [rbp-4]
*/

//////////////////////////////////////////////////////////////////////////////////

// f: (С оптимизацией "gcc -O2") 

// endbr64
// cmp     edi, 14h
// jg      short loc_1180
// xor     eax, eax
// test    edi, edi
// jle     short locret_1172
// cmp     edi, 14h
// ja      short loc_1173
// lea     rdx, unk_2004
// mov     edi, edi
// movsxd  rax, dword ptr [rdx+rdi*4]
// add     rax, rdx
// db      3Eh
// jmp     rax

// mov     eax, 7
// retn

// mov     eax, 5

// locret_1172:                            
// retn


// loc_1173:                               
// xor     eax, eax
// retn

// loc_1180:                               
// xor     eax, eax
// cmp     edi, 3Eh ; '>'
// setz    al
// retn
// f               endp

// mov     eax, 8
// retn

// mov     eax, 3
// retn

// mov     eax, 4
// retn

/*  
    1. Параметры передаются через регистр edi.
    2. При помощи cmp (сравнение), переходом без условия (jmp) и переходами с условием (jz, ja, jle,jg).
    2.2 Через вычисление метки:
    2.2.1 Ищем смещение с помощью добавления к unk_2004 параметра *4. После этого добавляем к адресу массива полученное смещение, тем самым переходя к искомому участку кода.
    5. Переменная записывается напрямую в регистр eax.

    Так же некоторые операции были заменены на более оптимальные.
*/

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

// f2: (Без оптимизации) 

// push    rbp
// mov     rbp, rsp
// mov     [rbp-4], edi
// cmp     dword ptr [rbp-4], 2710h
// jz      short loc_11A7
// cmp     dword ptr [rbp-4], 2710h
// jg      short loc_11AE
// cmp     dword ptr [rbp-4], 1770h
// jz      short loc_11A0
// cmp     dword ptr [rbp-4], 1770h
// jg      short loc_11AE
// cmp     dword ptr [rbp-4], 3E8h
// jz      short loc_1199
// cmp     dword ptr [rbp-4], 3E8h
// jg      short loc_11AE
// cmp     dword ptr [rbp-4], 0Ah
// jz      short loc_1192
// cmp     dword ptr [rbp-4], 0Ah
// jg      short loc_11AE
// cmp     dword ptr [rbp-4], 1
// jz      short loc_1184
// cmp     dword ptr [rbp-4], 6
// jz      short loc_118B
// jmp     short loc_11AE


// loc_1184:                              
// mov     eax, 5
// jmp     short loc_11B3


// loc_118B:                               
// mov     eax, 7
// jmp     short loc_11B3


// loc_1192:                               
// mov     eax, 3
// jmp     short loc_11B3


// loc_1199:                               
// mov     eax, 9
// jmp     short loc_11B3


// loc_11A0:                               
// mov     eax, 8
// jmp     short loc_11B3


// loc_11A7:                               
// mov     eax, 4
// jmp     short loc_11B3


// loc_11AE:                               
//                                         
// mov     eax, 0

// loc_11B3:                               
//                                         
// pop     rbp
// retn

/*

Так же как и в пердыдущем, только без использования перехода к меткам с помощью массива. 

*/
//////////////////////////////////////////////////////////////////////////////////

// f2: (С оптимизацией "gcc -O2") 
// endbr64
// cmp     edi, 3E8h
// jz      short loc_1198
// jg      short loc_1178
// mov     eax, 7
// cmp     edi, 6
// jz      short locret_1162
// mov     eax, 3
// cmp     edi, 0Ah
// jnz     short loc_1168

// locret_1162:                            
//                                         
// retn

// align 8

// loc_1168:                               
// xor     eax, eax
// cmp     edi, 1
// setz    al
// lea     eax, [rax+rax*4] // если edi == 1, то return(1+1*4) иначе return(0+0*4)
// retn

// align 8

// loc_1178:                               
// mov     eax, 8
// cmp     edi, 1770h
// jz      short locret_1162
// xor     eax, eax
// cmp     edi, 2710h
// setz    al
// shl     eax, 2
// retn

// align 8

// loc_1198:                               
// mov     eax, 9
// retn

/*

Так же как и в пердыдущем, только без использования перехода к меткам с помощью массива. 

*/

int if1(int a)
{
    int b = a == 0 ? 1 : 2;
    return b;
}

// if1: (Без оптимизации)

// endbr64
// push    rbp
// mov     rbp, rsp
// mov     [rbp-14h], edi
// cmp     dword ptr [rbp-14h], 0
// jnz     short loc_1141
// mov     eax, 1
// jmp     short loc_1146


// loc_1141:                               
// mov     eax, 2

// loc_1146:                               
// mov     [rbp-4], eax
// mov     eax, [rbp-4]
// pop     rbp
// retn

/*
    1. Параметры передаются через регистр edi.
    2.1 При помощи cmp (сравнение), переходом без условия (jmp) и переходом с условием jnz.
    5. Переменная записывается в стек со смещением в 14 байт [rbp-14]
*/

//////////////////////////////////////////////////////////////////////////////////

// if1: (С оптимизацией "gcc -O2") 

// endbr64
// xor     eax, eax
// test    edi, edi
// setnz   al
// add     eax, 1
// retn

/*  
    1. Параметры передаются через регистр edi.
    2. При помощи setnz организуются переходы.
    5. Переменная записывается напрямую в регистр eax.

    Так же некоторые операции были заменены на более оптимальные.
*/

int if2(int a)
{
    int b = a == 50 ? 12 : 26;
    return b;
}

// if2: (Без оптимизации)

// endbr64
// push    rbp
// mov     rbp, rsp
// mov     [rbp-14h], edi
// cmp     dword ptr [rbp-14h], 32h ; '2'
// jnz     short loc_1141
// mov     eax, 0Ch
// jmp     short loc_1146


// loc_1141:                               
// mov     eax, 1Ah

// loc_1146:                               
// mov     [rbp-4], eax
// mov     eax, [rbp-4]
// pop     rbp
// retn

/*
    1. Параметры передаются через регистр edi.
    2 При помощи cmp (сравнение), переходом без условия (jmp) и переходом с условием jnz.
    5. Переменная записывается в стек со смещением в 14 байт [rbp-14]
*/

//////////////////////////////////////////////////////////////////////////////////

// if2: (С оптимизацией "gcc -O2") 

// endbr64
// cmp     edi, 32h ; '2'
// mov     edx, 1Ah
// mov     eax, 0Ch
// cmovnz  eax, edx
// retn

/*  
    1. Параметры передаются через регистр edi.
    2. При помощи cmovnz организуются переходы.
    5. Переменная записывается напрямую в регистр eax.

    Так же некоторые операции были заменены на более оптимальные.
*/

int if3(int a, int b, int c)
{
    if (a && c)
        return b;
    else
        return c;
}

// if3: (Без оптимизации)

// endbr64
// push    rbp
// mov     rbp, rsp
// mov     [rbp-4], edi
// mov     [rbp-8], esi
// mov     [rbp-0Ch], edx
// cmp     dword ptr [rbp-4], 0
// jz      short loc_114B
// cmp     dword ptr [rbp-0Ch], 0
// jz      short loc_114B
// mov     eax, [rbp-8]
// jmp     short loc_114E


// loc_114B:                              
//                                         
// mov     eax, [rbp-0Ch]

// loc_114E:                              
// pop     rbp
// retn

/*
    1. Параметры передаются через регистр edi, esi, edx.
    2.1 При помощи cmp (сравнение), переходом без условия (jmp) и переходом с условием jz.
    5. Переменная записывается в стек со смещением в 4, 8, 12 байт ([rbp-4], [rbp-8], [rbp-0Ch])
*/

//////////////////////////////////////////////////////////////////////////////////

// if3: (С оптимизацией "gcc -O2") 

// endbr64
// mov     eax, esi
// test    edi, edi
// jz      short loc_1150
// test    edx, edx
// jz      short loc_1150
// retn

// align 10h

// loc_1150:                              
//                                        
// mov     eax, edx
// retn

/*  
    1. Параметры передаются через регистр edi, esi, edx.
    2. При помощи test и переходов с условием jz.
    5. Переменная записывается напрямую в регистр eax.

    Так же некоторые операции были заменены на более оптимальные.
*/

int *s[100];
int t[100];
void f2()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}

// f2: (Без оптимизации)

// endbr64
// push    rbp
// mov     rbp, rsp
// mov     dword ptr [rbp-4], 0
// jmp     short loc_116E


// loc_113A:                               
// mov     eax, [rbp-4] // 4.1
// cdqe
// lea     rdx, ds:0[rax*4]  // 4.2
// lea     rax, t // 4.3
// lea     rcx, [rdx+rax] // 4.4
// mov     eax, [rbp-4]
// cdqe
// lea     rdx, ds:0[rax*8]
// lea     rax, s
// mov     [rdx+rax], rcx
// add     dword ptr [rbp-4], 1

// loc_116E:                             
// cmp     dword ptr [rbp-4], 64h ; 'd'
// jnz     short loc_113A
// nop
// nop
// pop     rbp
// retn

/*
   
   3. i помещается в стек (mov dword ptr [rbp-4], 0) затем переходим в loc_116E
   3.1 сравниваем i и 100 (cmp  dword ptr [rbp-4], 64h), и если не равно, то переходим в loc_113A
   3.2 В конце loc_113A выполняем i++ (add dword ptr [rbp-4], 1)
   4. Обращение к массивам рассмотрим на примере t:
   4.1 Записали в eax - i 
   4.2 Получили адрес i*4
   4.3 Получили адрес t 
   4.4 Получаем &t[i]
   5. i в стеке [rbp-4]; t,s в сегменте данных адрес t[i] высчитывается в коде.
*/
//////////////////////////////////////////////////////////////////////////////////

// f2: (С оптимизацией "gcc -O2") 

// endbr64
// lea     rax, t
// lea     rdx, s
// lea     rcx, [rax+190h]
// nop     dword ptr [rax+00000000h]

// loc_1190:                               
// mov     [rdx], rax
// add     rax, 4
// add     rdx, 8
// cmp     rax, rcx
// jnz     short loc_1190
// retn

/*

    Тоже самое, что и без оптимизации, 
    только цикл выполняется пока мы не пройдем от адреса t[0] до адреса t[190h]

*/
void g();

void f1(int a)
{
    while (a)
    {
        --a;
        g();
    }
}

// f1: (Без оптимизации) 

// endbr64
// push    rbp
// mov     rbp, rsp
// sub     rsp, 8
// mov     [rbp-4], edi
// jmp     short loc_1153


// loc_1145:                               
// sub     dword ptr [rbp-4], 1 // 3.3
// mov     eax, 0
// call    g

// loc_1153:                               
// cmp     dword ptr [rbp-4], 0 // 3.1
// jnz     short loc_1145 // 3.2
// nop
// nop
// leave
// retn

/*
    1. Параметры передаются через регистр edi.
    2  При помощи cmp (сравнение), переходом без условия (jmp) и переходом с условием jnz.
    3. Цикл представлен следующим образом:
    3.1 а равно 0? 
    3.2 если нет, то переходим к loc_1145
    3.3 и вычитаем 1
    3.4 если да, выходим из циклв
    5. Переменная записывается в стек со смещением в 4 байтф [rbp-4]
*/

//////////////////////////////////////////////////////////////////////////////////

// f1: (С оптимизацией "gcc -O2") 

// endbr64
// retn

/*

При оптимизации функция исчезает.

*/

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

// f2: (Без оптимизации)

// endbr64
// push    rbp
// mov     rbp, rsp
// sub     rsp, 8
// mov     [rbp-4], edi

// loc_1143:                             
// cmp     dword ptr [rbp-4], 0 // 3.1
// jz      short loc_1159 // 3.4
// sub     dword ptr [rbp-4], 1 // 3.2
// mov     eax, 0
// call    g
// jmp     short loc_1143 // 3.3


// loc_1159:                               
// nop
// leave
// retn

/*
    1. Параметры передаются через регистр edi.
    2  При помощи cmp (сравнение), переходом без условия (jmp) и переходом с условием jz.
    3. Цикл представлен следующим образом:
    3.1 а равно 0? 
    3.2 если нет, вычитаем 1
    3.3 Переходим обратно к loc_1143
    3.4 если да, выходим из цикла
    5. Переменная записывается в стек со смещением в 4 байтф [rbp-4]
*/


//////////////////////////////////////////////////////////////////////////////////

// f2: (С оптимизацией "gcc -O2") 

// endbr64
// retn

/*

Так же как и в предыдущем, после оптимизации исчезает

*/

void f3(int *p)
{
    for (int i = 0 ; i < 10 ; ++i)
    {
        ++*p;
        if (*p == 5) continue;
        ++*p;
    }
}

// F3: (Без отимизации)

//         endbr64
//         push    rbp
//         mov     rbp, rsp
        
//         mov     [rbp-18h], rdi // Помещаем переданный параметр на стек
//         mov     dword ptr [rbp-4], 0 // Записали 0 (счетчик цикла) на стек 
//         jmp     short loc_118E 

// loc_115E:
//         mov     rax, [rbp-18h]  // Получаем значение из стека в rax
//         mov     eax, [rax] // Записываем в eax значение, находящееся по адресу rax
//         lea     edx, [rax+1] // Прибавляем к rax 1 и записываем в edx 
//         mov     rax, [rbp-18h]  // Получаем значение из стека в rax
//         mov     [rax], edx // Записываем по адресу rax edx
//         mov     rax, [rbp-18h] // Получаем значение из стека в rax
//         mov     eax, [rax] // Записываем в eax значение, находящееся по адресу rax
//         cmp     eax, 5  // Сравниваем с 5 
//         jz      short loc_1189 // Если равно 5, то переходим
//         mov     rax, [rbp-18h] // Получаем значение из стека в rax
//         mov     eax, [rax]  // Записываем в eax значение, находящееся по адресу rax
//         lea     edx, [rax+1] // Прибавляем к rax 1 и записываем в edx 
//         mov     rax, [rbp-18h] // Получаем значение из стека в rax
//         mov     [rax], edx // Записываем по адресу rax edx
//         jmp     short loc_118A
// loc_1189:
//         nop
// loc_118A:                              
//         add     dword ptr [rbp-4], 1  // Прибаляем 1 к счетчику
// loc_118E:
//         cmp     dword ptr [rbp-4], 9 // Сравниваем счетчик с 9 
//         jle     short loc_115E // Если меньше или равно, повторям цикл
//         nop
//         nop
//         pop     rbp
//         retn

//////////////////////////////////////////////////////////////////////////////////

// f3: (С оптимизацией "gcc -O2") 

// endbr64
// mov     eax, [rdi]
// mov     edx, 0Ah
// mov     esi, 5

// loc_1150:                               
// lea     ecx, [rax+2]
// cmp     eax, 4
// mov     eax, ecx
// cmovz   eax, esi
// sub     edx, 1
// jnz     short loc_1150
// mov     [rdi], eax
// retn

/*  
    1. Параметры передаются через регистр rdi
    2. При помощи переходов с условием jnz.
    3. edx изначально равен 10 и с каждой итерацией уменьшается на 1, если равен нулю, выходим из цикла
    5. Переменная записывается напрямую в регистр eax.

    Так же некоторые операции были заменены на более оптимальные.
*/