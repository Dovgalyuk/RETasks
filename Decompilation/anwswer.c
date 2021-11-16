//
// Created by Alex Skakun on 16.11.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a = 1;
    int myArray[3];

    printf("Enter three numbers: ");
    scanf("%d %d %d", &myArray[0], &myArray[1], &myArray[2]);

    if((myArray[2] + myArray[1]) > myArray[0])
    {
        if (myArray[2] + myArray[0] > myArray[1])
        {
            if(myArray[1] + myArray[0] <= myArray[2])
            {
                a = 0;
            }
        } else {
            a = 0;
        }
    } else {
        a = 0;
    }


    if(a)
    {
        printf("Yes");
        return 0;
    }
    else
    {
        printf("No");
        return 0;
    }
}


/*
 *  bin 18
 *  Переменные: булевый флаг и массив int из 3-х элементов.
 *  Кроме функции  main никаких написанных функций выделить нельзя.
 *  Результат работы программы: YES если сумма любых 2х элементов больше третьего. NO иначе
 */


