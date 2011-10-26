#include <stdio.h>

unsigned int fatorial (unsigned int a)
{
  if ((a==0) || (a==1))
    return 1;
  else
    return a*fatorial(a-1);
}

int main(void)
{
  unsigned int numeroFatorial=0;

  printf("Digite o numero ao qual deseja-se obter fatorial (apenas positivos): ");
  scanf("%d", &numeroFatorial);
  
  printf("%d! = %d\n",numeroFatorial,fatorial(numeroFatorial));

  return(0);
}
