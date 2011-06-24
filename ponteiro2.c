#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned long int i=0,numeroFib=0,*sequenciaFib,*operFib;

  do
    {
      printf("Indique o tamanho da sequencia Fibonacci (a partir do 3): ");
      scanf("%d",&numeroFib);
    }while (numeroFib<3);

  sequenciaFib=(unsigned long int *)malloc(sizeof(unsigned long int)*numeroFib);
  if(!sequenciaFib)
    {
      printf("Sem memória!\n");
      return(1);
    }

  operFib=sequenciaFib;

  *operFib=1;
  ++operFib;
  *operFib=1;
  ++operFib;

  for (i=0;i<numeroFib-2;i++)
    {
      *operFib=*(operFib-1)+*(operFib-2);
      operFib++;
    }

  operFib=sequenciaFib;

  for (i=0;i<numeroFib;i++)
    {
      printf("%02do. numero Fibonacci e %u e esta armazenado no endereco %p\n",i+1,*operFib,operFib);
      ++operFib;
    }
  
  free(sequenciaFib);

  return(0);
}
