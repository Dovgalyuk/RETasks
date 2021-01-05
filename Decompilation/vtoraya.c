#include <stdio.h>

int f(int a1, int a2)
{
	// Объявление переменных функции
	//var_18= dword ptr -18h
	//var_14= dword ptr -14h
	//var_8= dword ptr -8
	//var_4= dword ptr -4

	//push    rbp
	//mov     rbp, rsp
	//mov     [rbp+var_14], edi
	//mov     [rbp+var_18], esi
	//mov     [rbp+var_8], 1
	//mov     [rbp+var_4], 1
	
	unsigned int v3; // [rsp+10h] [rbp-8h]
	int i; // [rsp+14h] [rbp-4h]
	
	// Голова цикла
	//loc_712:
	//mov     eax, [rbp+var_4]
	//cmp     eax, [rbp+var_18]
	//jg      short loc_72A
	
	// Тело цикла
	//mov     eax, [rbp+var_8]
	//imul    eax, [rbp+var_14]
	//mov     [rbp+var_8], eax
	//add     [rbp+var_4], 1
	//jmp     short loc_712
	
	v3 = 1;
	for ( i = 1; i <= a2; ++i )
	v3 = v3 * a1;
	return v3;
	// возвращение из функции
	//loc_72A:
	//mov     eax, [rbp+var_8]
	//pop     rbp
	//retn
	//_Z1fii endp
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
 
	//push    rbp
	//mov     rbp, rsp
	//sub     rsp, 20h
	//mov     rax, fs:28h
	//mov     [rbp+var_8], rax
	//xor     eax, eax
	//mov     [rbp+var_10], 0
	//lea     rdi, format     ; "Enter N: "
	//mov     eax, 0
	//call    _printf
	printf("Enter N: ");
	//lea     rax, [rbp+var_18]
	//mov     rsi, rax
	//lea     rdi, aD         ; "%d"
	//mov     eax, 0
	//call    _scanf
	scanf("%d", &v4);
	//mov     eax, [rbp+var_18]
	//mov     esi, eax
	//lea     rdi, aEnterDNumbers ; "Enter %d numbers: "
	//mov     eax, 0
	//call    _printf
	printf("Enter %d numbers: ", (unsigned int)v4);
	//mov     [rbp+var_C], 1
  
	//loc_793:
	//mov     eax, [rbp+var_18]
	//cmp     [rbp+var_C], eax
	//jg      short loc_7CB
 		
  for ( i = 1; i <= v4; ++i )
  {
	//lea     rax, [rbp+var_14]
	//mov     rsi, rax
	//lea     rdi, aD         ; "%d"
	//mov     eax, 0
	//call    _scanf
	scanf("%d", &v5);
	//mov     eax, [rbp+var_14]
	//mov     edx, [rbp+var_C]
	//mov     esi, edx        ; int
	//mov     edi, eax        ; int
	//call    _Z1fii          ; f(int,int)
    	v6 = v6 + f(v5, i);
	//add     [rbp+var_10], eax
	//add     [rbp+var_C], 1
	//jmp     short loc_793


  }
  
	//loc_7CB:
	//mov     eax, [rbp+var_10]
	//mov     esi, eax
	//lea     rdi, aResultIsD ; "Result is %d"
	//mov     eax, 0
	//call    _printf
	printf("Result is %d", v6);
	//mov     eax, 0
	//mov     rcx, [rbp+var_8]
	//xor     rcx, fs:28h
	//jz      short locret_7FA
  	return 0;
}



