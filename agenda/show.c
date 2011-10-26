#include "agenda.h"

void listaAgenda(agenda *head)
{
  agenda *item;
  agenda_info *registro;
  int counter=0;
  item=head;

  while (item!=NULL)
    {
      registro=item->entrada;
      counter++;

      printf("Registro no. %d\n\n",counter);
      printf("Nome.....: %s\n",registro->nome);
      printf("Endereco.: %s\n",registro->rua);
      printf("Cidade...: %s\n",registro->cidade);
      printf("Estado...: %s\n",registro->estado);
      printf("CEP......: %s\n",registro->cep);
      printf("DataNasc.: %s\n",registro->datanasc);
      printf("Email....: %s\n",registro->email);
      printf("Sexo.....: %c\n",(registro->sexo==0)?'F':'M');

      printf("Pressione qualquer tecla para continuar!\n"); while(!getchar());

      item=item->next;
    } 

  printf("Exibidos %d registros\n", counter);
  return;
}
