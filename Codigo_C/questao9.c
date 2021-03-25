#include <stdio.h>
 
int ContPalavras(char linha[])
{
	int cont=0,i=0,esp=0;
	for(;linha[i]!='\x0';i++)
	{
		if((!esp) && (linha[i]!=' '))
		{
			esp=1;
			cont++;
		}else if(esp && (linha[i]==' '))
			esp=0;
	}
	return cont;
}

int main()
{
	FILE *arq;
	char linha[40];
	int cont=0;
	arq=fopen("atividade.txt","r");//r
	if(arq==NULL)
	{
		printf("Erro de abertura do arquivo.\n");
		return 0;
	}
	while(1)
	{
		fgets(linha,40,arq);// fgets
		cont+=ContPalavras(linha);
		if(feof(arq)) // feof(arq)
			break;
	}
	printf("Qtd de palavras = %d\n",cont);
	fclose(arq);
	return 0;
}