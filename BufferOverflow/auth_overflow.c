#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_authentication(char *password) {
	int auth_flag = 0;
	char password_buffer[16];

	strcpy(password_buffer, password);
	
	if(strcmp(password_buffer, "brillig") == 0)
		auth_flag = 1;
	if(strcmp(password_buffer, "outgrabe") == 0)
		auth_flag = 1;

	return auth_flag;
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Usage: %s <password>\n", argv[0]);
		exit(0);
	}
	if(check_authentication(argv[1])) {
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("      Access Granted.\n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	} else {
		printf("\nAccess Denied.\n");
   }
}

/*

0000000000400607 <check_authentication>:
  400607:	55                   	push   %rbp
  400608:	48 89 e5             	mov    %rsp,%rbp
  40060b:	48 83 ec 30          	sub    $0x30,%rsp
  40060f:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  400613:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40061a:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  40061e:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  400622:	48 89 d6             	mov    %rdx,%rsi
  400625:	48 89 c7             	mov    %rax,%rdi
  400628:	e8 a3 fe ff ff       	callq  4004d0 <strcpy@plt>
  40062d:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  400631:	48 8d 35 4c 01 00 00 	lea    0x14c(%rip),%rsi        # 400784 <_IO_stdin_used+0x4>
  400638:	48 89 c7             	mov    %rax,%rdi
  40063b:	e8 c0 fe ff ff       	callq  400500 <strcmp@plt>
  400640:	85 c0                	test   %eax,%eax
  400642:	75 07                	jne    40064b <check_authentication+0x44>
  400644:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  40064b:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  40064f:	48 8d 35 36 01 00 00 	lea    0x136(%rip),%rsi        # 40078c <_IO_stdin_used+0xc>
  400656:	48 89 c7             	mov    %rax,%rdi
  400659:	e8 a2 fe ff ff       	callq  400500 <strcmp@plt>
  40065e:	85 c0                	test   %eax,%eax
  400660:	75 07                	jne    400669 <check_authentication+0x62>
  400662:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  400669:	8b 45 fc             	mov    -0x4(%rbp),%eax
  40066c:	c9                   	leaveq
  40066d:	c3                   	retq

000000000040066e <main>:
  40066e:	55                   	push   %rbp
  40066f:	48 89 e5             	mov    %rsp,%rbp
  400672:	48 83 ec 10          	sub    $0x10,%rsp
  400676:	89 7d fc             	mov    %edi,-0x4(%rbp)
  400679:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  40067d:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
  400681:	7f 25                	jg     4006a8 <main+0x3a>
  400683:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  400687:	48 8b 00             	mov    (%rax),%rax
  40068a:	48 89 c6             	mov    %rax,%rsi
  40068d:	48 8d 3d 01 01 00 00 	lea    0x101(%rip),%rdi        # 400795 <_IO_stdin_used+0x15>
  400694:	b8 00 00 00 00       	mov    $0x0,%eax
  400699:	e8 52 fe ff ff       	callq  4004f0 <printf@plt>
  40069e:	bf 00 00 00 00       	mov    $0x0,%edi
  4006a3:	e8 68 fe ff ff       	callq  400510 <exit@plt>
  4006a8:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  4006ac:	48 83 c0 08          	add    $0x8,%rax
  4006b0:	48 8b 00             	mov    (%rax),%rax
  4006b3:	48 89 c7             	mov    %rax,%rdi
  4006b6:	e8 4c ff ff ff       	callq  400607 <check_authentication>
  4006bb:	85 c0                	test   %eax,%eax
  4006bd:	74 26                	je     4006e5 <main+0x77>
  4006bf:	48 8d 3d e5 00 00 00 	lea    0xe5(%rip),%rdi        # 4007ab <_IO_stdin_used+0x2b>
  4006c6:	e8 15 fe ff ff       	callq  4004e0 <puts@plt>
  4006cb:	48 8d 3d f6 00 00 00 	lea    0xf6(%rip),%rdi        # 4007c8 <_IO_stdin_used+0x48>
  4006d2:	e8 09 fe ff ff       	callq  4004e0 <puts@plt>
  4006d7:	48 8d 3d 00 01 00 00 	lea    0x100(%rip),%rdi        # 4007de <_IO_stdin_used+0x5e>
  4006de:	e8 fd fd ff ff       	callq  4004e0 <puts@plt>
  4006e3:	eb 0c                	jmp    4006f1 <main+0x83>
  4006e5:	48 8d 3d 0e 01 00 00 	lea    0x10e(%rip),%rdi        # 4007fa <_IO_stdin_used+0x7a>
  4006ec:	e8 ef fd ff ff       	callq  4004e0 <puts@plt>
  4006f1:	b8 00 00 00 00       	mov    $0x0,%eax
  4006f6:	c9                   	leaveq
  4006f7:	c3                   	retq
  4006f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4006ff:	00

  Анализ функции <check_authentication>.
  400607: 55                            pushq   %rbp
  400608: 48 89 e5                      movq    %rsp, %rbp
  Пролог функции.

  400613: c7 45 fc 00 00 00 00          movl    $0, -4(%rbp)
  Сохранение 0 по адресу -4(%rbp).
  Позже значение этого регистра будет передано в регистр возврата
  400669: 8b 45 fc                      movl    -4(%rbp), %eax
  Следовательно, значение этого регистра - auth_flag.

  40061e: 48 8d 45 e0                   leaq    -20(%rbp), %rax
  Создание массива password_buffer

  Из-за особенностей выполнения функция strcpy будет перезаписывать все ячейки памяти,а не только ячейки буфера.

  Следовательно, чтобы перезаписать значение со смещением в стеке -4 строкой, начало которой находится на смещении -20,
  нужно 28 байт - для того, чтобы добраться до смещения флага + от 1 до 4 байтов для того, чтобы перезаписать значение флага.

 */
	
