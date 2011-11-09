#include "agenda.h"

void limpandoDados(agenda_info *dados)
{
  memset(dados->nome,'\0',sizeof(dados->nome));
  memset(dados->rua,'\0',sizeof(dados->rua));
  memset(dados->cidade,'\0',sizeof(dados->cidade));
  memset(dados->estado,'\0',sizeof(dados->estado));
  memset(dados->cep,'\0',sizeof(dados->cep));
  memset(dados->datanasc,'\0',sizeof(dados->datanasc));
  memset(dados->email,'\0',sizeof(dados->email));
  dados->sexo=0;
}

void insereItem (agenda **head)
{
  agenda_info *dados=(agenda_info*)malloc(sizeof(agenda_info));
  agenda *entrada=(agenda*)malloc(sizeof(agenda)), *hook;

  char sexo='M';

  if ((!entrada) || (!dados))
    exit(1);

  limpandoDados(dados);

  printf("Digite o nome da pessoa, ou então FIM se entrou por engano: \n");
  fgets(dados->nome,sizeof(dados->nome),stdin);

  if(strncmp(dados->nome,"FIM",strlen("FIM"))==0)
    {
      free(dados);
      return;
    }

  printf("Digite a rua onde essa pessoa mora: ");
  fgets(dados->rua,sizeof(dados->rua),stdin);

  printf("Digite a cidade onde essa pessoa mora: ");
  fgets(dados->cidade,sizeof(dados->cidade),stdin);

  printf("Digite o estado onde essa pessoa mora: ");
  fgets(dados->estado,sizeof(dados->estado),stdin);

  printf("Digite o cep onde essa pessoa mora: ");
  fgets(dados->cep,sizeof(dados->cep),stdin);

  printf("Digite o email dessa pessoa: ");
  fgets(dados->email,sizeof(dados->email),stdin);

  printf("Digite a data de nascimento dessa pessoa: ");
  fgets(dados->datanasc,sizeof(dados->datanasc),stdin);


  do
    {
      printf("Digite o sexo [M/F]: ");
      scanf("%c",&sexo);
      getchar();

      sexo=((sexo>='a')&&(sexo<='z'))?sexo+'A'-'a':sexo;

      printf("%c\n",sexo);

      if (sexo!='M'&&sexo!='F') printf ("sexo inválido\n");

    } while (sexo!='M'&&sexo!='F');

  dados->sexo=(sexo=='F')?0:1;

  /**
   *  Checa se já existem itens dentro da agenda
   */

  if (!*head)
    {
      *head=entrada;
      (*head)->next=NULL;
    }
  else
    {
      hook=*head;
      while (hook->next!=NULL) hook=hook->next;
      hook->next=entrada;
    }

  entrada->entrada=dados;

  return;
}
