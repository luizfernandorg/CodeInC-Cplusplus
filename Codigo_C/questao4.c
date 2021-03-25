#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i=0,max;
	char *charvet;
	charvet=(char *)malloc(10*sizeof(char));
	if(charvet==NULL)
	{
		printf("Erro de alocacao.\n");
		return 0;
	}
	strcpy(charvet,"abcdefgh");
	max=strlen(charvet);
	for(;i<max; i++)
	{
		if(i%2)
		printf("%c ",*charvet);
		charvet++;
	}
	free(charvet);
	return 0;
}