#include "roletrando.h"

void explicarRegras (void)
{
  // Explicando as regras do jogo para o jogador
  printf ("Okay, vamos explicar as regras!\n");
  printf ("Eu conheco algumas palavras, e vou escolher aleatoriamente uma delas.\n");
  printf ("Voce vai me dizer qual letra voce acha que essa palavra tem!\n");
  printf ("Se voce errar, vou considerar uma tentativa errada!\n");
  printf ("Se voce acertar, vou te mostrar onde as letras estao!\n");
  printf ("Quando voce tiver acertado metade das palavras, vou te dar ");
  printf ("a chance de dizer qual palavra e essa. \n");
  printf ("Se voce errar, vou considerar uma tentativa errada!\n");
  printf ("Se voce acertar antes de acabar as tentativas, voce vence!\n\n\n");
  printf ("Algumas observacoes:\n");
  printf ("Voce tem %d tentativas que voce pode errar.\n",NUM_TENTATIVAS);
  printf ("Nenhuma palavra possui acentos, cedilha ou trema.\n");
  printf ("Nao estou diferenciando maisculas e minusculas. \n\n");
}

int testaCerto (const char* palavraEscolhida, int *tentativasErradas)
{
  char *minhaResposta;

  minhaResposta=(char*)malloc(strlen(palavraEscolhida)+1);
  memset(minhaResposta,'\0', strlen(palavraEscolhida)+1);

  if (!minhaResposta)
    {
      printf("Nao consegui alocar memoria!\n");
      return(1);
    }

  char *conversao=minhaResposta;
  printf("Qual palavra voce acha que e essa? ");
  fgets(minhaResposta,strlen(palavraEscolhida)+1,stdin);

  // Convertendo para minusculas e eliminando os caracteres de nova linha - \n
  while (*conversao)
    {
      *conversao=((*conversao>='A')&&(*conversao<='Z'))?*conversao-'A'+'a':*conversao;
      conversao++;
    }

  minhaResposta[strlen(minhaResposta)]='\0';

  if(strncmp(minhaResposta,palavraEscolhida,strlen(palavraEscolhida))==0)
    {
       free(minhaResposta);
       return(1);
    }
  else
    {
      printf("Que pena, você errou!\n");
      (*tentativasErradas)++;
      free(minhaResposta);
      return(0);
    }
}
