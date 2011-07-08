/*
 * letras.c
 */

#include "roletrando.h"

int checaLetra (const char* palavra, const char* letrasCertas, char letra)
{
  // Acertos obtidos (0 indica que nao tem a letra em questao na palavra)
  int acertos=0;

  // Ponteiros a serem inicializados
  char *palavraAnalisada, *certas;

  // Inicialidando os ponteiros com os valores recebidos
  palavraAnalisada=(char*)palavra;
  certas=(char*)letrasCertas;

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
  char *letras=(char*)letrasCertas;
  int faltantes=0;

  while (*letras) if (*(letras++)=='-') faltantes++;

  return faltantes;
}


