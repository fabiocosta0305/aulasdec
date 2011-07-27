#include <stdio.h>
#include <stdlib.h>
	 
/*
 * (c) 2010 GPL
 */
	 
int main (int argc, char** argv)
{
  int primeiro=0, segundo=0, soma=0, resto=0, divisaoInteira=0;
  float divisaoFlutuante=0;
  char nome[80];
  char palavra[20];
  /*
   * O comando abaixo inicializa as strings nome e palavra
   */
  memcpy(nome,"\0",sizeof(nome));
  memcpy(palavra,"\0",sizeof(palavra));
	 
  printf("Olá! Digite seu nome, por favor!\n");
  fgets(nome,sizeof(nome),stdin);
	 
  printf("Digite uma palavra que devo exibir e dois números para eu fazer umas contas.\n");
  scanf("%s %d %d",palavra,&primeiro,&segundo);
	 
  getc(stdin);
	 
  soma=primeiro+segundo;
  divisaoInteira=primeiro/segundo;
  resto=primeiro%segundo;
  divisaoFlutuante=(float)primeiro/(float)segundo;
	 
  printf("Olá, %s\n",nome);
  printf("Você me pediu para exibir %s e os números %d e %d\n",palavra,primeiro,segundo);
  printf("Algumas continhas!\n%d+%d=%d\n",primeiro,segundo,soma);
  printf("%d:%d=%d(Resto %d)",primeiro,segundo,divisaoInteira,resto);
  printf(" ou %7.2f\n",divisaoFlutuante);
  printf("Divertido, não? Aperte qualquer tecla para continuar...");
  getc(stdin);
  return(0);
}
