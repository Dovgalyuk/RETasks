#include <stdio.h>

int f(int a1, int a2)
{
	unsigned int v3; // [rsp+10h] [rbp-8h]
	int i; // [rsp+14h] [rbp-4h]

	v3 = 1;
	for ( i = 1; i <= a2; ++i )
	v3 = v3 * a1;
	return v3;
}

//Дизассмеблированный и заново востановленный код, переменные которые можно
//выделить в программе объявлены в ее начале, а так же к ним указаны их адреса
// в программе выделена одна функция f(int a1, int a2) производящая умножение элемента a1 на v3 *= a1, a2 раз
// при входных значения N=5, [1, 2, 3, 4, 5] Вывод = Result is 3413
// при входных значения N=2, [1, 2] Вывод = Result is 5
// при входных значения N=5, [5, 5, 5, 5, 5] Вывод = Result is 3905

int main()
{
  int v4; // [rsp+8h] [rbp-18h] 
  int v5; // [rsp+Ch] [rbp-14h] 
  unsigned int v6 = 0; // [rsp+10h] [rbp-10h]
  int i; // [rsp+14h] [rbp-Ch]
 
  printf("Enter N: ");
  scanf("%d", &v4);
  printf("Enter %d numbers: ", (unsigned int)v4);
  for ( i = 1; i <= v4; ++i )
  {
    scanf("%d", &v5);
    v6 = v6 + f(v5, i);
  }
  printf("Result is %d", v6);
  return 0;
}



