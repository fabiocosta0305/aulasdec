#include <stdio.h>

/**
* Essa fun��o de m�dia ir� acrescentar os valores adicionados � m�dia
* anterior e devolver� a m�dia no momento
*/
float media(float nota)
{
   static float mediaAtual=0.0;
   mediaAtual=(mediaAtual==0)?nota:(mediaAtual+nota)/2;
   return mediaAtual;
}

int main(void)
{
    float nota=0.0;
    int notas=0;

    do
    {
        notas++;
        printf("Digite a pr�xima nota ou -1 para sair:");
        scanf("%f",&nota);

        if (nota!=-1)
	  printf("Com essa nota, a m�dia total � de %9.2f\n",media(nota));
    } while (nota!=-1);

    printf ("Com um total de %d notas entradas, a m�dia final foi de %.2f",notas,nota);
    return 0;
}
