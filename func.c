#include <stdio.h>

/**
* Essa função de média irá acrescentar os valores adicionados à média
* anterior e devolverá a média no momento
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
        printf("Digite a próxima nota ou -1 para sair:");
        scanf("%f",&nota);

        if (nota!=-1)
	  printf("Com essa nota, a média total é de %9.2f\n",media(nota));
    } while (nota!=-1);

    printf ("Com um total de %d notas entradas, a média final foi de %.2f",notas,nota);
    return 0;
}
