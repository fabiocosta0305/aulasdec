#include <stdio.h>

int soma(int a, int b);
int subtracao(int a, int b);
int multiplicacao(int a, int b);
int divisao(int a, int b);

void main(void)
{
  /**
   * No GCC, esse cabecalho para main retorna o seguinte warning:
   *
   * warning: return type of \u2018main\u2019 is not \u2018int\u2019
   */
  int val1=0, val2=0, opt=0, res=0;

  do
    {
      printf("Digite um valor:");
      scanf("%d",&val1);

      printf("Digite outro valor:");
      scanf("%d",&val2);

      printf("Escolha a operação a ser realizada\u2026\n\n");
      printf("1 \u2013 Soma\n");
      printf("2 \u2013 Subtracao\n");
      printf("3 \u2013 Multiplicacao\n");
      printf("4 \u2013 Divisao");
      printf("0 \u2013 Sair do Programa\n\nDigite os operadores e a operacao separados por espaco:");

      scanf("%d",&opt);

      switch(opt)
	{
	case 1:
	  res=soma(val1,val2);
	  break;
	case 2:
	  res=subtracao(val1,val2);
	  break;
	case 3:
	  res=multiplicacao(val1,val2);
	  break;
	case 4:
	  res=divisao(val1,val2);
	  break;
	case 0:
	  break;
	default:
	  printf("Opcao invalida\n");
	  continue;
	}
      if (opt!=0) printf ("O resultado da sua operacao para %d e %d e %d\n\n",val1,val2,res);
    } while (opt!=0);

  /**
   * No GCC, a linha abaixo provoca o seguinte warning:
   *
   * warning: 'return' with a value, in function returning void
   */

  return(0);
}

int soma(int a, int b)
{
  return a+b;
}

int subtracao(int a, int b)
{
  return a-b;
}

int multiplicacao(int a, int b)
{
  return a*b;
}

int divisao(int a, int b)
{
  return a/b;
}
