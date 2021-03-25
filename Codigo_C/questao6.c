#include <stdio.h>  //arquivo header para a funcao printf()
#include <stdlib.h> //arquivo header para as funcoes srand() e rand()
#include <time.h>   //arquivo header para a funcao time()

//in ; * ; em branco ; 
int func1(int *x, int a)
{
  *x=rand()%a;
  return *x*(rand()%5);
}
 
int main()
{
  int aleat,ret;
  int a=10;
  srand(time(NULL));  //iniciacao do gerador de numeros aleatorios
  for(int i=0; i<10;i++)
    {
      ret=func1(&aleat,a);
      printf("valor aleatorio gerado %d: %d (limitado %d) - ret funcao: %d.\n",
              i,aleat,a,ret);
    }
  return 0;
}