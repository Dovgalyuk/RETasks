//
// Created by Alex Skakun on 16.11.2021.
//
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a = 1;

    printf("Enter three numbers: ");
    int first, second , third;
    scanf("%d %d %d", &first, &second, &third);

    if( third + second > first)
    {
        if (first + third > second)
        {
            if(second + first > third)
            {
                a = 0;
            }
        }
    }


    if(a == 0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}


/*
bin 18
00000000000006fa <main>:
     6fa: 55                            pushq   %rbp
     6fb: 48 89 e5                      movq    %rsp, %rbp
     Стандартный пролог функции
     6fe: 48 83 ec 20                   subq    $32, %rsp
     702: 64 48 8b 04 25 28 00 00 00    movq    %fs:40, %rax
     70b: 48 89 45 f8                   movq    %rax, -8(%rbp)
     70f: 31 c0                         xorl    %eax, %eax
     711: c6 45 eb 01                   movb    $1, -21(%rbp)
     Присваивание -21(%rbp) значения 1
     Как покажет код ниже, данное значение будет использоваться как флаг.
     715: 48 8d 3d 28 01 00 00          leaq    296(%rip), %rdi  # 844 <_IO_stdin_used+0x4>
     Вывод в консоль (Enter three numbers: )
     71c: b8 00 00 00 00                movl    $0, %eax
     721: e8 9a fe ff ff                callq   0x5c0 <.plt+0x20>
     726: 48 8d 4d f4                   leaq    -12(%rbp), %rcx
     Создание первой переменной
     72a: 48 8d 55 f0                   leaq    -16(%rbp), %rdx
     Создание второй переменной
     72e: 48 8d 45 ec                   leaq    -20(%rbp), %rax
     Создание третьей переменной
     732: 48 89 c6                      movq    %rax, %rsi
     735: 48 8d 3d 1e 01 00 00          leaq    286(%rip), %rdi  # 85a <_IO_stdin_used+0x1a>
     Считывание значений переменных из консоли
     73c: b8 00 00 00 00                movl    $0, %eax
     741: e8 8a fe ff ff                callq   0x5d0 <.plt+0x30>
     746: 8b 55 ec                      movl    -20(%rbp), %edx
     749: 8b 45 f0                      movl    -16(%rbp), %eax
     74c: 01 c2                         addl    %eax, %edx
     Сложение третьей и второй переменной...
     74e: 8b 45 f4                      movl    -12(%rbp), %eax
     751: 39 c2                         cmpl    %eax, %edx
     И сравнение суммы с первой
     753: 7e 1e                         jle     0x773 <main+0x79>
     Если сумма будет меньше или равна, переходим на <main+0x79>
     755: 8b 55 ec                      movl    -20(%rbp), %edx
     758: 8b 45 f4                      movl    -12(%rbp), %eax
     75b: 01 c2                         addl    %eax, %edx
     Суммируем третью и первую...
     75d: 8b 45 f0                      movl    -16(%rbp), %eax
     760: 39 c2                         cmpl    %eax, %edx
     И сравниваем со второй
     762: 7e 0f                         jle     0x773 <main+0x79>
     Если сумма меньше или равна, переходим на <main+0x79>
     764: 8b 55 f0                      movl    -16(%rbp), %edx
     767: 8b 45 f4                      movl    -12(%rbp), %eax
     76a: 01 c2                         addl    %eax, %edx
     И, наконец, суммируем первую и вторую...
     76c: 8b 45 ec                      movl    -20(%rbp), %eax
     76f: 39 c2                         cmpl    %eax, %edx
     Сравниваем сумму и третью переменную
     771: 7f 04                         jg      0x777 <main+0x7d>
     Если сумма больше, переходим на 0x777 <main+0x7d>
     773: c6 45 eb 00                   movb    $0, -21(%rbp)
     Присваеваем флагу значение 0
     777: 80 7d eb 00                   cmpb    $0, -21(%rbp)
     77b: 74 13                         je      0x790 <main+0x96>
     Если значение флага равно 0...
     77d: 48 8d 3d dd 00 00 00          leaq    221(%rip), %rdi  # 861 <_IO_stdin_used+0x21>
     Выводим Yes
     784: b8 00 00 00 00                movl    $0, %eax
     789: e8 32 fe ff ff                callq   0x5c0 <.plt+0x20>
     78e: eb 11                         jmp     0x7a1 <main+0xa7>
     790: 48 8d 3d ce 00 00 00          leaq    206(%rip), %rdi  # 865 <_IO_stdin_used+0x25>
     No иначе
     797: b8 00 00 00 00                movl    $0, %eax
     79c: e8 1f fe ff ff                callq   0x5c0 <.plt+0x20>
     0 в регистре возврата - конец кода
     7a1: b8 00 00 00 00                movl    $0, %eax
     7a6: 48 8b 75 f8                   movq    -8(%rbp), %rsi
     7aa: 64 48 33 34 25 28 00 00 00    xorq    %fs:40, %rsi
     7b3: 74 05                         je      0x7ba <main+0xc0>
     7b5: e8 f6 fd ff ff                callq   0x5b0 <.plt+0x10>
     7ba: c9                            leave
     7bb: c3                            retq
     7bc: 0f 1f 40 00                   nopl    (%rax)

 *  Переменные: флаг и 3 переменных под вводимые числа.
 *  Кроме функции  main никаких написанных функций выделить нельзя.
 *  Результат работы программы: YES если сумма любых 2х элементов больше третьего. NO иначе
 */


