#include <stdio.h>
#include <stdlib.h>

int soma (int, int);
int subtracao (int, int);
int multiplicacao (int, int, int);
int divisao (int, int);

int main(void)
{
  int (*funcPointer)(int,int); // o meu ponteiro de funcao vem aqui

  int a=0,b=0,c=0,oper=0;

  printf ("Entre com dois numeros inteiros separados por espaco: ");
  scanf ("%d %d", &a, &b);

  do
    {
      printf ("Escolha uma operação a se realizar com esses numeros:\n");
      printf ("1-) Soma\n");
      printf ("2-) Subtracao\n");
      printf ("3-) Multiplicacao\n");
      printf ("4-) Divisao\n");
      scanf("%d", &oper);
    } while (!((oper>=1) && (oper<=4)));

  switch(oper)
    {
    case 1:
      {
	funcPointer=soma;
	break;
      }
    case 2:
      {
	funcPointer=subtracao;
	break;
      }
    case 3:
      {
	funcPointer=multiplicacao;
	break;
      }
    case 4:
      {
	funcPointer=divisao;
	break;
      }
    }

  c=(*funcPointer)(a,b);

  printf("O resultado da operacao desejada com os valores %d e %d e %d\n",a,b,c);
  
  printf("A funcao usada para executar a operacao desejada localiza-se em %p\n",funcPointer);

  return(0);

}

int soma (int a, int b)
{
  return a+b;
}

int subtracao (int a, int b)
{
  return a-b;
}

int multiplicacao (int a, int b, int c)
{
  return a*b;
}

int divisao (int a, int b)
{
  if (b==0)
    {
      printf("Nao posso dividir nada por zero!\n");
      return 0;
    }
  return a/b;
}
