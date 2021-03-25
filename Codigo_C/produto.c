#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char linha[30],custoStr[3];
	int prodA,prodB,i=0;
	FILE *arq;
	arq=fopen("matrizcustos.txt","r");
	if(arq==NULL)
	{
		printf("Erro de abertura de arquivo origem.");
		return 0;
	}
	printf("Produto A (de 0 a 3):");
	scanf("%d",&prodA);
	printf("Produto B:(de 0 a 3): ");
	scanf("%d",&prodB);
	for(;i<=prodA;i++)
		fgets(linha,30,arq);
	printf("linha selecionada: %s\n",linha);
	strncpy(custoStr,&linha[prodB*3],2);
	custoStr[3]='\x0';
	fclose(arq);
	printf("Custo = %d",atoi(custoStr));
	return 0;
}