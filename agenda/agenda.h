#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _agendainfo
{
  char nome[80];
  char rua[80];
  char cidade[40];
  char estado[40];
  char cep[10];
  char datanasc[11];
  char email[100];
  int sexo;                            // utilizaremos 0 para feminino e 1 para masculino
}  agenda_info;

typedef struct _agenda
{
  agenda_info *entrada;
  struct _agenda *next;
} agenda;

void creditos (void);
void insereItem(agenda **head);
void listaAgenda(agenda *head);
