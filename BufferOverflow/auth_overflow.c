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
 * Из-за отключения защиты от переполнения мы перезаписываем значение auth_flag во время копирыванияя строки.
 * Данное явление происходит, когда мы копируем строку большего размера в буфер меньшего.
 * Так как auth_flag находится в соседней области памяти, он оказывается перезаписан данными,
 * не помещающимися в строку, которую мы копируем в буффер password_buffer.
 * Следовательно необходимо вписать пароль большего размера, чем буффер.
 */
	
