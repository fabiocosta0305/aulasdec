#include <stdio.h>
#include <stdlib.h>

struct tComplexo
{
  int real;
  int imaginario;
};

struct tComplexo somaComplexo (struct tComplexo a, struct tComplexo b)
{
  struct tComplexo soma;

  soma.real=a.real+b.real;
  soma.imaginario=a.imaginario+b.imaginario;

  return soma;
}

int main()
{
  struct tComplexo a,b,total;

  a.real=b.real=a.imaginario=b.imaginario=0;

  printf("Digite o seu primeiro numero complexo (separe por espaco as partes real e imaginaria):\n");
  scanf("%d %d", &a.real, &a.imaginario);

  printf("Digite o seu segundo numero complexo (separe por espaco as partes real e imaginaria):\n");
  scanf("%d %d", &b.real, &b.imaginario);

  total=somaComplexo(a,b);

  printf("A soma entre %d+%di e %d+%di é igual a %d+%di\n", a.real, a.imaginario, b.real, b.imaginario, total.real, total.imaginario);

  return(0);

}
