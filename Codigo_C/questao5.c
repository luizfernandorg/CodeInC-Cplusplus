#include <stdio.h>

int main()
{
	FILE *arq;
	long pos,i;
	char carac;
	arq = fopen("conteudo.txt","r");
	if(arq==NULL)
	{
		printf("Erro de aberura do arquivo.");
		return 0;
	}
	fseek(arq,0,SEEK_END);
	pos=ftell(arq);
	printf("Pos = %ld\n",pos);
	for(i=pos-1; i>=0; i--)
	{
		fseek(arq,i,SEEK_SET);
		carac = fgetc(arq);
		printf("%c",carac);
	}
	return 0;
}