#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definindo o n�mero limite para a pessoa tentar descobrir */

#define LIMITE 10
#define ENCERRA printf("Pressione ENTER para continuar!\n"); while(!getchar());

int main (int argc, char** argv)
{
  int numeroPensado=0, numeroDoUsuario=0, limiteTentativas=(LIMITE/2)-1, maximoTentativas=0,i;
  
  srand(time(NULL)); // Serve para modificar a tabela de n�meros pseudo-aleat�rios

  numeroPensado=rand()%LIMITE+1;

  printf("OK! Pensei em um n�mero entre 1 e %d e te desafio a achar ele!\n", LIMITE);

  do
    {
      printf("Quantas tentativas voc� acha que precisa para descobrir ele? ");
      scanf("%d",&maximoTentativas);

      if (maximoTentativas<1)
	printf("Voc� precisa tentar ao menos uma vez! :P\n");
      if (maximoTentativas>limiteTentativas)
	printf("%d tentativas? T� querendo demais tamb�m! :P\n",maximoTentativas);
    } while (maximoTentativas<1 || maximoTentativas>limiteTentativas);

  //  for (i=1; i<=maximoTentativas;i++)
    for (i=1; --maximoTentativas; i++)
    {
      printf("Vamos l�! %da. tentativa! ",i);
      
      scanf("%d",&numeroDoUsuario);

      if (numeroDoUsuario==numeroPensado)
	{
	  printf("Parab�ns! Voc� acertou!\n");
	  ENCERRA
	  return(0);
	}
      else
	{
	  printf("N�o pensei em %d. ", numeroDoUsuario);
	  if (numeroDoUsuario<numeroPensado)
	    printf("Pensei em um n�mero maior.\n");
	  if (numeroDoUsuario>numeroPensado)
	    printf("Pensei em um n�mero menor.\n");
	}
    }

  printf("Que pena! Eu pensei em %d! Melhor sorte da pr�xima vez! \n",numeroPensado);
  ENCERRA
  return(0);
}
