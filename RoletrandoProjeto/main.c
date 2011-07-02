#include "roletrando.h"

int main (void)
{

  // Declarando variaveis

  // Biblioteca de palavras
  char palavras[][TAMANHO_PALAVRAS]={"rotina", "retina", "palhaco", "lembranca",
                                     "sistema", "musica","curioso", "fantasia",
                                     "malabares","sonhador","atitude","pacoca",
                                     "sonhador"};

  // Ponteiros necessarios
  char *palavraEscolhida, *letrasCertas;

  // Algumas variaveis de apoio
  int tentativasErradas=0,i;

  explicarRegras();

  srand(time(NULL)); // Serve para modificar a tabela de números pseudo-aleatórios

  palavraEscolhida=palavras[rand()%((sizeof(palavras)/TAMANHO_PALAVRAS)-1)];

  letrasCertas=malloc(strlen(palavraEscolhida)+1);

  if (!letrasCertas)
    {
      printf("Nao consegui alocar memoria!\n");
      return(1);
    }

  memset(letrasCertas,'\0', strlen(palavraEscolhida)+1);
  memset(letrasCertas,'-', strlen(palavraEscolhida));

  int tentativaAtual=0;
  while(tentativasErradas<NUM_TENTATIVAS)
    {
      char minhaLetra;
      tentativaAtual++;

      printf ("Okay, tentativa no %d (%d tentativas erradas):", tentativaAtual, tentativasErradas);
      scanf ("%c", &minhaLetra);
      getchar();
      if (!checaLetra(palavraEscolhida,letrasCertas,minhaLetra))
	{
	  printf("Que pena, essa letra nao aparece!\n");
	  tentativasErradas++;
	  continue;
	}

      printf("A palavra ate agora e: %s\n",letrasCertas);

      if (contaFaltantes(letrasCertas)<=(strlen(palavraEscolhida)/2))
	{
	  if((contaFaltantes(letrasCertas)==0)||testaCerto(palavraEscolhida,&tentativasErradas))
	    {
	      printf("Muito bem! Você acertou!\n");
	      free(palavraEscolhida);
	      free(letrasCertas);
	      return(0);
	    }
	}
    }
}
