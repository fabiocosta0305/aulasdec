#include <stdio.h>

int main (void)
{
  char palavra[80]="Hello World!";
  char *palavra2;

  palavra2=palavra;

  printf("O texto %s esta armazenado no endereco %p\n",palavra,palavra);
  while (*palavra2)
    {
      printf("O caracter %c da palavra %s esta no endereco %p\n",*palavra2,palavra,palavra2);
      palavra2++;
    }
  return(0);

}
