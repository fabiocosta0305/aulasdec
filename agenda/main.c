#include "agenda.h"

void creditos (void);
void limpaDados (agenda *minhaAgenda);

int main(void)
{
  agenda *minhaAgenda=NULL;
  int op;
  creditos();
  do
    {
      printf("Escolha uma das op��es abaixo para a sua agenda\n\n");
      printf("1 - Inserir um novo registro\n");
      printf("2 - Listar os registros inseridos\n");
      printf("3 - Sair\n");
      printf("4 - Cr�ditos\n\n\nEscolha sua op��o:");
      scanf("%d",&op);
      while(getchar()!='\n');
      switch(op)
        {
        case 1:
          insereItem(&minhaAgenda);
          break;
        case 2:
          listaAgenda(minhaAgenda);

          break;
        case 3:
          limpaDados(minhaAgenda);
          return(0);
        case 4:
          creditos();
          break;
        default:
          printf("Op��o inv�lida!\n");
        }
    } while (op!=3);
}

void creditos(void)
{
    printf("Programa de agenda simples do curso de C livre do Aulas de C\n\n\n\n");
    printf("Autor...: F�bio Emilio Costa <fabiocosta0305@gmail.com>\n");
    printf("Licen�a.: GPL 2\n\n");
}

void limpaDados (agenda *minhaAgenda)
{
  agenda *next,*now;

  next=minhaAgenda;

  while(next!=NULL)
    {
      now=next;
      next=next->next;

      free(now->entrada);
      free(now);
    }
}
