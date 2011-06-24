#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_TENTATIVAS 6
#define TAMANHO_PALAVRAS 20

int checaLetra (const char* palavraEscolhida, const char* letrasCertas, char letra);
void explicarRegras (void);
int contaFaltantes (const char* letrasCertas);
int testaCerto (const char* palavraEscolhida, int* tentativasErradas);

int main (void)
{

  // Declarando variaveis

  // Biblioteca de palavras
  char palavras[][TAMANHO_PALAVRAS]={"rotina", "retina", "palhaco", "lembranca", 
                                     "sistema", "musica","curioso", "fantasia",
				     "malabares","sonhador","atitude","pacoca"};

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
	  printf("Que pena, voce errou!\n");
	  tentativasErradas++;
	  continue;
	}

      printf("A palavra ate agora e: %s\n",letrasCertas);
      printf("A palavra  e: %s\n",palavraEscolhida);

      if (contaFaltantes(letrasCertas)<=(strlen(palavraEscolhida)/2))
	{
	  if((contaFaltantes(letrasCertas)==0)||testaCerto(palavraEscolhida,&tentativasErradas))
	    {
	      printf("Muito bem! Você acertou!\n");
	      return(0);
	    }
	}
    }
}

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

int checaLetra (const char* palavra, const char* letrasCertas, char letra)
{
  // Acertos obtidos (0 indica que nao tem a letra em questao na palavra)
  int acertos=0;

  // Ponteiros a serem inicializados
  char *palavraAnalisada, *certas;
  
  // Inicialidando os ponteiros com os valores recebidos
  palavraAnalisada=palavra;
  certas=letrasCertas;

  char letraComparada=((letra>='A')&&(letra<='Z'))?letra-'A'+'a':letra;

  while (*palavraAnalisada)
  {
    if (*palavraAnalisada==letraComparada)
      {
	acertos++;
	*certas=letraComparada;
      }
    palavraAnalisada++;
    certas++;
  }

  return acertos;
}

int contaFaltantes(const char* letrasCertas)
{
  char *letras=letrasCertas;
  int faltantes=0;

  while (*letras) if (*(letras++)=='-') faltantes++;

  return faltantes;
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
  gets(minhaResposta);

  // Convertendo para minusculas e eliminando os caracteres de nova linha - \n
  while (*conversao)
    {
      printf("%s\n",minhaResposta);
      *conversao=((*conversao>='A')&&(*conversao<='Z'))?*conversao-'A'+'a':*conversao;
      if (*conversao=='\n') *conversao='\0';
	  conversao++;
    }
  
  if(strncmp(minhaResposta,palavraEscolhida,strlen(palavraEscolhida))==0)
    return(1);
  else
    {
      printf("Que pena, você errou!\n");
      (*tentativasErradas)++;
      return(0);
    }
}
