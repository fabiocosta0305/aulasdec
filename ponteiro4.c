#include <stdio.h>
#include <stdlib.h>

int acumulaNota (int*, int);

int main(void)
{
  int notaAcumulada=0,nota=0,alunos=0;

  do
    {
      printf("Digite a nota do proximo aluno - digite -1 para sair:");
      scanf("%d",&nota);
      acumulaNota(&notaAcumulada,nota);
      alunos+=nota==-1?0:1;
    } while (nota!=-1);

  printf("A media da turma de %d alunos e %.2f!\n",alunos,notaAcumulada/alunos);

  return(0);
}

int acumulaNota (int *notaAcumulada, int notaSomar)
{
  *notaAcumulada+=notaSomar;
}
