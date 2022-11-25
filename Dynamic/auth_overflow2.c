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
	//char password_buffer[16];
	char* password_buffer = NULL;

	//scanf("%s", password_buffer);
	scanf("%ms", &password_buffer);
	
	if (password_buffer == NULL)
		return 0;

	if (strcmp(password_buffer, "brillig") == 0)
		return 1;
	if (strcmp(password_buffer, "outgrabe") == 0)
		return 1;

	free(password_buffer);
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
