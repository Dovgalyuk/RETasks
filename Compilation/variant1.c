unsigned int fd(unsigned int a)
{
    return a / 10;
}

/* gcc -O0 */
<fd>:
        endbr64
        push    rbp
        mov     rbp, rsp
        mov     [rbp-4], edi
        mov     eax, [rbp-4]
        mov     edx, eax
        mov     eax, 0CCCCCCCDh
        imul    rax, rdx
        shr     rax, 20h
        shr     eax, 3
        pop     rbp
        retn

/* gcc -02 */
<fd>:
        endbr64
        mov     eax, edi
        mov     edi, 0CCCCCCCDh
        imul    rax, rdi
        shr     rax, 23h
        retn
/*
 * 1. Параметр в функцию передается с помощью регистра edi.
 * После чего, из регистра edi параметр помещается на стек,
 * на случай, если этот регистр понадобятся для чего-то другого.
 *
 * C Флагом -O2 регистр edi используется сразу, без манипуляций со стеком.
 * 
 * Благодаря оптимизации, помимио отсутсвия взаимодействия со стеком,
 * стало использоваться меньше регистров.
*/

unsigned int fd2(unsigned int a, unsigned int b)
{
    return a / b;
}

/* gcc -O0 */
<fd2>:
        endbr64
        push    rbp
        mov     rbp, rsp
        mov     [rbp-4], edi
        mov     [rbp-8], esi
        mov     eax, [rbp-4]
        mov     edx, 0
        div     dword ptr [rbp-8]
        pop     rbp
        retn

/* gcc -02 */
<fd2>:
        endbr64
        mov     eax, edi
        xor     edx, edx
        div     esi
        retn

/*
 * Аналогично предыдущему.
 * Деление не заменяется, т.к делитель заранее не известен.
 * Также используется ещё один регистр esi для передачи
 * параметра в функцию. (Всего два: edi и esi)
 * 
 * Также в данном примере благодаря флагу -O2 инструкция mov edx, 0
 * заменяется на xor edx, edx. Благодаря этому для кодирования в 
 * машинный код требуется меньше места.
*/

unsigned int fd4(unsigned int a)
{
    return a % 16;
}

/* gcc -O0 */
<fd4>:
        endbr64
        push    rbp
        mov     rbp, rsp
        mov     [rbp-4], edi
        mov     eax, [rbp-4]
        and     eax, 0Fh
        pop     rbp
        retn

/* gcc -02 */
<fd4>:
        endbr64
        mov     eax, edi
        and     eax, 0Fh
        retn

/*
 * Аналогично функции fd.
 * Парметр передается с помощью регистра edi, после чего помещается на стек.
 *
 * C Флагом -O2 регистр edi используется сразу, без манипуляций со стеком.
*/

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

/* gcc -O0 */
<f>:
        endbr64
        push    rbp
        mov     rbp, rsp
        /*
         * Сохранение значения переменной, находящейся в регистре edi, на стек.
         */
        mov     [rbp-4], edi
        cmp     dword ptr [rbp-4], 14h
        /*
         * Переход, если значение переменной строго больше 20.
         * Для знаковых чисел.
         */
        jg      short loc_116A
        cmp     dword ptr [rbp-4], 0
        /*
         * Переход, если значение переменной меньше или равно 0.
         */
        jle     short loc_119C
        cmp     dword ptr [rbp-4], 14h
        /*
         * Переход, если значение переменной строго больше 20.
         * Для беззнаковых чисел.
         */
        ja      short loc_119C
        mov     eax, [rbp-4] 
        /*
         * rax - в данный момент содержит переданный параметр с помощью lea 
         * получаю часть адреса, необходимую для получения адреса перехода.
         */
        lea     rdx, ds:0[rax*4]
        /* 
         * unk_2004 - массив, находящийся в секции _rodata с помощью lea
         * получаем его адрес и прибавляем к адресу, полученному выше.
         * Результат записываем в eax.
         */
        lea     rax, unk_2004
        mov     eax, [rdx+rax]
        cdqe
        lea     rdx, unk_2004
        add     rax, rdx
        db      3Eh
        jmp     rax
        /*
         * Имеем: 
         * - массив unk_2004, содержащий смещение для case меток.
         * - параметр.
         * Идея этого куска:
         * - в массиве  unk_2004 ищем необходимое смещение путём прибавления
         *   адреса массива к принятому параметру, умноженного на 4.
         * - затем, найденное смещение прибавляем к адресу массива unk_2004.
         * - выполняем переход по полученному адресу с помощью jmp.
         *   Таким образом попадаемый в искомый участок кода.
         * - под искомым участком понимается case x: code,
         *   где x - принятый параметр.
         * Пример:
         * - edi = 0x14, тогда получаем смещение по адресу: unk_2004 + edi*4.
         * - Находим в массиве что лежит по этому адресу и приводим к qword.
         *   (для нашего примера там находится 91h.)
         * - Далее: адрес unk_2004 + FFFFFFFFFFFFF191, после чего jmp по
         *   получившемуся результату и мы оказываемся на инструкции:
         *         mov     eax, 8            
         */
loc_116A:
        cmp     dword ptr [rbp-4], 3Eh
        /*
         * Переход, если значение переменной равно 62.
         */
        jz      short loc_118E
        /*
         * Иначе переходим к метке loc_119C.
         */
        jmp     short loc_119C
        mov     eax, 5
        jmp     short loc_11A1
        mov     eax, 7
        jmp     short loc_11A1
        mov     eax, 3
        jmp     short loc_11A1
        mov     eax, 4
        jmp     short loc_11A1
loc_118E:
        mov     eax, 1
        jmp     short loc_11A1
        mov     eax, 8
        jmp     short loc_11A1
loc_119C:
        mov     eax, 0
loc_11A1:
        pop     rbp
        retn

/* gcc -02 */
<f>:
        endbr64
        cmp     edi, 14h
        jg      short loc_1180
        xor     eax, eax
        test    edi, edi
        /*
         * Если параметр равен 0, выполняется переход.
         */
        jle     short locret_1172
        cmp     edi, 14h
        ja      short loc_1173
        lea     rdx, unk_2004
        mov     edi, edi
        /*
         * Сразу в rax пишем qword смещение.
         */
        movsxd  rax, dword ptr [rdx+rdi*4]
        add     rax, rdx
        db      3Eh
        jmp     rax
        mov     eax, 7
        retn
        mov     eax, 5
locret_1172:
        retn
loc_1173:
        xor     eax, eax
        retn
        align 20h
loc_1180:
        xor     eax, eax
        cmp     edi, 3Eh ;
        setz    al
        retn
        endp
        mov     eax, 8
        retn
        mov     eax, 3
        retn
        mov     eax, 4
        retn

/*
 * C Флагом -O2 регистр edi используется сразу, без манипуляций со стеком.
 * Также оптимизация операций, например mov eax, 0 зменяется на xor eax, eax.
*/

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

/* gcc -O0 */
<f1>:
        endbr64
        push    rbp
        mov     rbp, rsp
        /*
         * Сохранение значения переменной, находящейся в регистре edi, на стек.
         */
        mov     [rbp-4], edi
        cmp     dword ptr [rbp-4], 0Ah
        /*
         * Переход, если значение переменной равно 10.
         */
        jz      short loc_115C
        cmp     dword ptr [rbp-4], 0Ah
        /*
         * Переход, если значение переменной строго больше 10.
         */
        jg      short loc_1163
        cmp     dword ptr [rbp-4], 1
        /*
         * Переход, если значение переменной равно 1.
         */
        jz      short loc_114E
        cmp     dword ptr [rbp-4], 6
        /*
         * Переход, если значение переменной равно 6.
         */
        jz      short loc_1155
        /*
         * Переход, если ничего из вышеописанного не выполнилось.
         */
        jmp     short loc_1163
loc_114E:
        mov     eax, 5
        jmp     short loc_1168
loc_1155:
        mov     eax, 7
        jmp     short loc_1168
loc_115C:
        mov     eax, 3
        jmp     short loc_1168
loc_1163:
        mov     eax, 0
loc_1168:
        pop     rbp
        retn
/*
 * В отличие от прошлого случая, массив не используется,
 * только операторы перехода.
 */

/* gcc -O2 */
<f1>:
        endbr64
        sub     edi, 1
        xor     eax, eax
        cmp     edi, 9
        /*
         * Переход, если значение переменной больше 10.
         */
        ja      short locret_1158
        lea     rax, CSWTCH_1
        /*
        * Возвращённое значение вычисляется следующим образом:
        * - из принятого параметра вычитаем 1.
        * - получившеся значение умножаем на 4.
        * - результат прибавляем к адресу таблицы CSWTCH_1, которая находится
        *   в секции _rodata.
        * - полученное значение по данному адресу и будет
        *   возвращаемым значением.
        */
        mov     eax, [rax+rdi*4]
locret_1158:
        retn

void g();

/* gcc -O0 */
<g>:
    endbr64
    push    rbp
    mov     rbp, rsp
    nop
    pop     rbp
    retn

/* gcc -O2 */
<g>:
    endbr64
    retn
/*
 * Без оптимизации есть только эпилог и пролог функции, после чего возврат.
 * С оптимизацией только возврат.
 */

void f1(int a)
{
    while (a)
    {
        --a;
        g();
    }
}

/* gcc -O0 */
<f1>:
        endbr64
        push    rbp
        mov     rbp, rsp
        /*
         * Выделяем 8 байт стеку
         */
        sub     rsp, 8
        /*
         * Сохранение значения переменной, находящейся в регистре edi, на стек.
         */
        mov     [rbp-4], edi
        jmp     short loc_1153
loc_1145:
        /*
         * Вычетание из переменной 1.
         */
        sub     dword ptr [rbp-4], 1
        mov     eax, 0
        /*
        * Вызов функции g.
        */
        call    g
loc_1153:
        cmp     dword ptr [rbp-4], 0
        /*
         * Переход, если значение переменной не равно 0.
         */
        jnz     short loc_1145
        nop
        nop
        leave
        retn

/*
 * Как работатет цикл:
 * - проверяется, что переменная не равна 0 с помощью инструкций:
 *          cmp dword ptr [rbp-4], 0
 *          jnz
 * - Если условие выполняется, то вычетаем из переменной 1:
 *          sub     dword ptr [rbp-4], 1
 * - Иначе с помощью инструкции leave происходит удаляение последнего 
 *   кадра из стека.
 */

/* gcc -O2 */
<f1>:
    endbr64
    retn
/*
 * Т.к цикл не делает ничего полезного, при использовании флага оптимизации
 * он исчезает.
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

/* gcc -O0 */
<f2>:
        endbr64
        push    rbp
        mov     rbp, rsp
        /*
         * Выделяем 8 байт стеку
         */
        sub     rsp, 8
        /*
         * Сохранение значения переменной, находящейся в регистре edi, на стек.
         */
        mov     [rbp-4], edi
loc_1143:
        cmp     dword ptr [rbp-4], 0
        /*
         * Переход, если значение переменной равно 0.
         */
        jz      short loc_1159
        /*
         * Вычетание из переменной 1.
         */
        sub     dword ptr [rbp-4], 1
        mov     eax, 0
        /*
         * Вызов функции g.
         */
        call    g
        /*
         * Переход по метке.
         */
        jmp     short loc_1143
loc_1159:
        nop
        leave
        retn

/*
 * Как работает:
 * - проверяется, что переменная равна 0 с помощью инструкций:
 *          cmp dword ptr [rbp-4], 0
 *          jz
 * - если условие выполняется, то с помощью инструкции leave происходит
 *   удаляение последнего кадра из стека.
 * - иначе из переменной вычетаем 1:
 *          sub     dword ptr [rbp-4], 1
 * - после чего вызываем функцию g()
 * - и выполняется переход обратно к первому шагу с помощью метки loc_1143.
 * 
 * Таким образом, спомощью метки, мы получили цикл.
 */


/* gcc -O2 */
<f2>:
        endbr64
        retn

/*
 * Т.к цикл не делает ничего полезного, при использовании флага оптимизации
 * он исчезает.
 */

void f1(int *p)
{
    for (int i = 0 ; i < 10 ; ++i)
        *p++ = 0;
}

/* gcc -O0 */
<f1>:
        endbr64
        push    rbp
        mov     rbp, rsp
        mov     [rbp-18h], rdi
        mov     dword ptr [rbp-4], 0
        jmp     short loc_1174
/*
 * Тело цикла
 */
loc_115E:
        /*
        * получаем текущее значение из rbp-18h:
        */
        mov     rax, [rbp-18h]
        /*
        * получам адрес следующего элемента, после найденного:
        */
        lea     rdx, [rax+4]
        /*
         * записываем в rbp-18h полученный адрес:
         */
        mov     [rbp-18h], rdx
        /*
         * обнуляем элемент, полученный из rbp-18h (537 строка):
         */
        mov     dword ptr [rax], 0
        /*
         * инкриментируем 'i':
         */
        add     dword ptr [rbp-4], 1
/*
 * Конец тела цикла
 */
loc_1174:
        /*
         * сравниваем 'i' с 9:
         */
        cmp     dword ptr [rbp-4], 9
        /*
         * если 'i' меньше или равно 9, происходит переход:
         */
        jle     short loc_115E
        nop
        nop
        pop     rbp
        retn

/*
 * - 'p' передается через регистр rdi и сохраняется в ячейке rbp-18h:
 *          mov     [rbp-18h], rdi
 * - 'i' хранится в ячейке rbp-4 и сначала равна 0:
 *          mov     dword ptr [rbp-4], 0
 * 
 * Как работает:
 * 
 * На каждом шаге происходит проверка условия выхода из цикла. Если 'i' <= 9,
 * то выполняется переход к "телу цикла". В нём мы получаем текущий элемент,
 * и сохраняем его в rax. После чего ищем адрес следующего элемента и помещаем
 * его в rbp-18h как текущий элемент. Теперь значение по адресу, хранящемуся в
 * rax - обнуляется и происходит инкриментрирование 'i'.
 * Как только проверка не выполняется, программа завершается.
 */

/* gcc -O2 */
<f1>:
        endbr64
        /*
         * Получаю адрес следующего за последним элемента
         */
        lea     rax, [rdi+28h]
        nop     dword ptr [rax+rax+00000000h]
loc_1150:
    /*
     * Регистр rdi будет указывать на следующий элемент.
     */
    add     rdi, 4
    /*
     * Обнуляю текущий
     */
    mov     dword ptr [rdi-4], 0
    /*
     * Проверка на равенство адреса текщего элемента адресу следующего за
     * последним элемента.  
     */
    cmp     rax, rdi
    jnz     short loc_1150
    retn

/*
 * В результате оптимизации переменная 'i' больше не используется, а цикл
 * идёт, пока адрес текущего и следующего за последним элемета не совпадут.
 */

int *s[100];
int t[100];
void f2()
{
    for (int i = 0 ; i != 100 ; ++i)
        s[i] = &t[i];
}

/* gcc -O0 */
<f2>:
        endbr64
        push    rbp
        mov     rbp, rsp
        mov     dword ptr [rbp-4], 0
        jmp     short loc_116E
loc_113A:
        /*
         * В eax помещаем 'i'
         */
        mov     eax, [rbp-4]
        cdqe
        /*
         * Получаю первую часть адреса, зависящую от индекса 'i'. 
         */
        lea     rdx, ds:0[rax*4]
        /*
         * Получаю адрес массива t
         */
        lea     rax, t
        /*
         * Получаю адрес элемента массива с индексом 'i', т.е &t[i]
         */
        lea     rcx, [rdx+rax]
        /*
         * Записываю в eax -> 'i'
         */
        mov     eax, [rbp-4]
        cdqe
        /*
         * Получаю первую часть адреса, зависящую от индекса 'i'. 
         */
        lea     rdx, ds:0[rax*8]
         /*
         * Получаю адрес массива s
         */
        lea     rax, s
        /*
         * Помещаю в s[i] адрес t[i]
         */
        mov     [rdx+rax], rcx
        /*
         * Увеличиваю 'i'
         */
        add     dword ptr [rbp-4], 1
loc_116E:
        /*
         * Сравниваю 'i' с 100.
         */
        cmp     dword ptr [rbp-4], 64h
        /*
         * Если 'i' не равно 100, то выполняем переход
         */
        jnz     short loc_113A
        nop
        nop
        pop     rbp
        retn

/*
 * - 'i' хранится в ячейке rbp-4 и сначала равна 0:
 *          mov     dword ptr [rbp-4], 0
 * - массивы t и s хранится в секции .bss, предназначенной для хранения
 *   переменных.
 *
 * Как работает:
 * 
 * Сначала сравниваем i с 100. Если i != 100, то получаем адрес t[i], а затем
 * s[i], после чего, присваиваем элементу s[i] адрес t[i].
 *
 * Обращение к массивам происходит по индексам: К адресу массива необходимо
 * добавить смещение, которое вычисляется следующим образом: индекс * на
 * размер одного элемента массива (для int - 4, а для int* - 8). В ходе этой
 * операции получается указатель на s[i]. Чтобы получить значение, необходимо 
 * добавить квадратные скобки: [адрес массива + смещение]. 
 */

/* gcc -O2 */
<f2>:
        endbr64
        /*
        * Получаем адреса массивов.
        */
        lea     rax, t
        lea     rdx, s
        lea     rcx, [rax+190h]
        nop     dword ptr [rax+00000000h]
loc_1190:
        /*
         * В s[i] записываем &t[i]
         */
        mov     [rdx], rax
        /*
         * переходим к &s[i+1] и &t[i+1]
         */
        add     rax, 4
        add     rdx, 8
        /*
         * сравнение
         */
        cmp     rax, rcx
        jnz     short loc_1190
        retn
/*
 * В слечае с оптимизацией избавляемся от 'i'.
 * Цикл выполняется до тех пор, пока &t[i] != &t[400].
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

/* gcc -O0 */
<f3>:
        endbr64
        push    rbp
        mov     rbp, rsp
        mov     [rbp-18h], rdi
        mov     dword ptr [rbp-4], 0
        jmp     short loc_118E
loc_115E:
        /*
         * получаем текущее значение из rbp-18h:
         */
        mov     rax, [rbp-18h]
        /*
         * В eax получаем значение элемента
         */
        mov     eax, [rax]
        /*
         * В edx получаем значение элемента + 1
         */
        lea     edx, [rax+1]
        /*
         * получаем текущее значение из rbp-18h:
         */
        mov     rax, [rbp-18h]
        /*
         * в текущее знчение пишем edx
         */
        mov     [rax], edx
        /*
         * получаем текущее значение из rbp-18h:
         */
        mov     rax, [rbp-18h]
        /*
         * В eax получаем значение элемента
         */
        mov     eax, [rax]
        /*
         * Проверка элемента на равенство 5
         */
        cmp     eax, 5
        /*
         * Если равен, то переходим
         */
        jz      short loc_1189
        /*
         * получаем текущее значение из rbp-18h:
         */
        mov     rax, [rbp-18h]
        /*
         * В eax получаем значение элемента
         */
        mov     eax, [rax]
        /*
         * В edx получаем значение элемента + 1
         */
        lea     edx, [rax+1]
        /*
         * получаем текущее значение из rbp-18h:
         */
        mov     rax, [rbp-18h]
         /*
         * в текущее знчение пишем edx
         */
        mov     [rax], edx
        jmp     short loc_118A
loc_1189:
        nop
loc_118A:
        /*
         * инкриментируем 'i'.
         */
        add     dword ptr [rbp-4], 1      
loc_118E:
        /*
         * сравниваем 'i' с 9:
         */
        cmp     dword ptr [rbp-4], 9
        /*
         * если 'i' меньше или равно 9, происходит переход:
         */
        jle     short loc_115E
        nop
        nop
        pop     rbp
        retn

/*
 * - 'p' передается через регистр rdi и сохраняется в ячейке rbp-18h:
 *          mov     [rbp-18h], rdi
 * - 'i' хранится в ячейке rbp-4 и сначала равна 0:
 *          mov     dword ptr [rbp-4], 0
 */

/* gcc -O2 */
<f3>:
        endbr64
        mov     eax, [rdi]
        mov     edx, 0Ah
        mov     esi, 5
loc_1150:
        lea     ecx, [rax+2]
        cmp     eax, 4
        mov     eax, ecx
        /*
         * Если элемент равен 4, то запивсываем в него 5.
         */
        cmovz   eax, esi
        sub     edx, 1
        jnz     short loc_1150
        mov     [rdi], eax
        retn

/*
 * - В EAX записываем значение первого элемента.
 * - В edx записываем значение 10.
 * - в esi записываем значение 5.
 *
 * - Оптимизируется сравнение: сразу значение сравнивается с 4, а не
 *   добавляется 1 и сравнивается с 5.
 * - Сразу прибавляется 2 вместо 1.
 * - edx как счётчик, после каждого прохода уменьшается на 1.
 */

void f4(int a)
{
    do
    {
        --a;
        g();
    }
    while (a);
}

/* gcc -O0 */
<f4>:
        endbr64
        push    rbp
        mov     rbp, rsp
        /*
         * Выделяем 8 байт стеку
         */
        sub     rsp, 8
        /*
         * Сохранение значения переменной, находящейся в регистре edi, на стек.
         */
        mov     [rbp-4], edi
loc_1143:
        /*
         * уменьшаем значение переменной на 1
         */
        sub     dword ptr [rbp-4], 1
        mov     eax, 0
        /*
         * вызов функции g
         */
        call    g
        /*
         * Сравнение с 0 и переход к метке, если больше
         */
        cmp     dword ptr [rbp-4], 0
        jnz     short loc_1143
        nop
        nop
        leave
        retn

/* gcc -O2 */
<f4>:
        endbr64
        retn
/*
 * Т.к цикл не делает ничего полезного, при использовании флага оптимизации
 * он исчезает.
 */

int if1(int a)
{
    int b = a == 0 ? 1 : 2;
    return b;
}

/* gcc -O0 */
<if1>:
        endbr64
        push    rbp
        mov     rbp, rsp
        mov     [rbp-14h], edi
        cmp     dword ptr [rbp-14h], 0
        jnz     short loc_1141
        mov     eax, 1
        jmp     short loc_1146
loc_1141:
        mov     eax, 2
loc_1146:
        mov     [rbp-4], eax
        mov     eax, [rbp-4]
        pop     rbp
        retn
/*
 * Если параметр не равен 0, то возвращем 2:
 *      cmp     dword ptr [rbp-14h], 0
 *      jnz     short loc_1141
 *      mov     eax, 2
 * Иначе возвращаем 1:
 *      cmp     dword ptr [rbp-14h], 0
 *      mov     eax, 1
 */

/* gcc -O2 */
<if2>:
        endbr64
        xor     eax, eax
        test    edi, edi
        setnz   al
        add     eax, 1
        retn
/*
 * Нету меток, за счёт инструкции setnz. 
 */

int if4(int a, int b, int c)
{
    if (a || c == b)
        return b;
    else
        return a;
}

/* gcc -O0 */
<if4>:
        endbr64
        push    rbp
        mov     rbp, rsp
        mov     [rbp-4], edi
        mov     [rbp-8], esi
        mov     [rbp-0Ch], edx
        cmp     dword ptr [rbp-4], 0
        jnz     short loc_1148
        mov     eax, [rbp-0Ch]
        cmp     eax, [rbp-8]
        jnz     short loc_114D
loc_1148:
        mov     eax, [rbp-8]
        jmp     short loc_1150
loc_114D:
        mov     eax, [rbp-4]
loc_1150:
        pop     rbp
        retn

/*
 * Параметры передаются в функцию в edi, esi, edx.
 *
 * Если первый параметр НЕ равен 0, то возвращеам втрой:
 *      cmp     dword ptr [rbp-4], 0
 *      jnz     short loc_1148
 *      mov     eax, [rbp-8]
 * Иначе получаю третй параметр и если он НЕ равен втрому, то возвращеам втрой:
 *      mov     eax, [rbp-0Ch]
 *      cmp     eax, [rbp-8]
 *      jnz     short loc_114D
 *      mov     eax, [rbp-8]
 * Иначе, возвращаю первый параметр.
 */

/* gcc -O2 */
<if4>:
        endbr64
        test    edi, edi
        jnz     short loc_1150
        xor     eax, eax
        cmp     edx, esi
        jz      short loc_1150
        retn
        align 10h
loc_1150:
        mov     eax, esi
        retn

/*
 * Не используется стек. Более оптимальные сравнения.
 */