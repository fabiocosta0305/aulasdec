#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definindo o número limite para a pessoa tentar descobrir */

#define LIMITE 10
#define ENCERRA printf("Pressione qualquer tecla para continuar!\n"); while(!getchar());

int main (int argc, char** argv)
{
  const int limiteTentativas=(LIMITE/2)-1;
  int numeroPensado=0, numeroDoUsuario=0, maximoTentativas=0,i;
     
  srand(time(NULL)); // Serve para modificar a tabela de números pseudo-aleatórios
  numeroPensado=rand()%LIMITE+1;

  printf("OK! Pensei em um número entre 1 e %d e te desafio a achar ele!\n", LIMITE);
  do
    {
      printf("Quantas tentativas você acha que precisa para descobrir ele? ");
      scanf("%d",&maximoTentativas);

      if (maximoTentativas<1)
	printf("Você precisa tentar ao menos uma vez! :P \n");
      if (maximoTentativas>limiteTentativas)
	printf("%d tentativas? Tá querendo demais também! :P \n",maximoTentativas);
    } while (maximoTentativas<1 || maximoTentativas>limiteTentativas);

  for (i=1; i<=maximoTentativas;i++)
    {
      printf("Vamos lá! %da. tentativa! ",i);
         
      scanf("%d",&numeroDoUsuario);

      if (numeroDoUsuario==numeroPensado)
	{
	  printf("Parabéns! Você acertou!\n");
	  ENCERRA
	    return(0);
	}
      else
	{
	  printf("Não pensei em %d. ", numeroDoUsuario);
	  if (numeroDoUsuario<numeroPensado)
	    printf("Pensei em um número maior.\n");
	  if (numeroDoUsuario>numeroPensado)
	    printf("Pensei em um número menor.\n");
	}
    }

  printf("Que pena! Eu pensei em %d! Melhor sorte da próxima vez! \n",numeroPensado);
  ENCERRA
    return(0);
}
