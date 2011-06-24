/* Faculdade de Tecnologia de Carapicu�ba
 *  Professor: Ciro Cirne Trindade
 *  Disciplina: Programa��o-II
 *  Curso: An�lise de Sistemas e Tecnologia da Informa��o
 *  Turma: 2o ciclo � Noite (Turma A)
 *  Data de Entrega: 14-05-2010
 *  Grupo: Deborah G. O. de Paula - 2080137-8             
 *         Grazielle Tomioka	  - 2080158-0
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Op��es do menu */
#define VENDER_CADEIRA_ISOLADA 1
#define VENDER_LOTE_CADEIRA 2
#define CONSULTAR_CADEIRAS_FOLGA 3
#define CONSULTAR_CADEIRAS_VISTA_LIVRE 4
#define FECHAMENTO_BILHETERIA 5
#define SAIR 6

/* Prot�tipos das fun��es */ //Deborah: Tenho algumas d�vidas com rela��o aos par�metros dessas fun��es, por conta de ainda n�o ter pensado em todas elas.
int ** cria_matriz_lugares(int, int, int *);
void print_matriz_lugares(int **, int, int *);
int menu(char * []);
void vender_cadeira_isolada(int **);
void vender_lote_cadeira(int **, int);
void consultar_cadeiras_folga(int **, int, int *);
void consultar_cadeiras_vista_livre(int);
void fechamento_bilheteria(int **, int, int);

/* In�cio da fun��o main() */
int main() {
    
    /* Declara��o de vari�veis */
    int ** mat_int;
    int n, c, aux_c, aux;
    float preco1;
    char opcao;
    
    /* op��es do menu */
    char * opcoes[] = {"Venda de Cadeiras Isoladas",
                        "Venda de Lotes de Cadeiras",
                        "Consulta de Cadeiras com Folga",             
                        "Consulta de Cadeiras com Vista Livre",
                        "Fechamento da Bilheteria",                          
                        "Finalizar programa"}; // vetor de strings inicializado com as op��es do menu principal.
    
    /* Fim da "Declara��o de vari�veis" */
    
    printf("\t\t\tABT - TEATROS\n\n\n\n");
    printf("\tProgramacao da bilheteria\n\n");
 
    /* Entrada das fileiras, cadeiras e pre�o da 1� fileira */
    do {
        printf("\n - Entre com o numero de filas: \n");
        scanf("%d",&n);
        printf("\n - Entre com o numero de cadeiras: \n");
        scanf("%d",&c);
        printf("\n - Preco da(s) PRIMEIRA(S) FILA(S): R$ ");
        scanf("%f",&preco1);
        if(n < 2 || n > 26 || c == 0) {
            printf("\n\n\t\tPor favor, entre com valores validos!\n");
            printf("\t\t(Fileiras: 2 a 26; Cadeira(s): >= 0.)\n\n");
            aux = 1;
        }  
    } while(aux == 1);
    aux_c = c;
    
    mat_int = cria_matriz_lugares(n,c,&aux_c);
    if(mat_int == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    print_matriz_lugares(mat_int,n,&aux_c);
     
/* Menu */
    do {
        opcao = menu(opcoes);
        switch(opcao) {
            case VENDER_CADEIRA_ISOLADA:       // se a op��o escolhida for a 1
                 vender_cadeira_isolada(mat_int);      // fazer fun��o para a venda_cadeira_isolada
                 break;
            case VENDER_LOTE_CADEIRA:   // se a op��o escolhida for a 2
	         vender_lote_cadeira(mat_int,n);         // fazer fun��o para a venda de lote de cadeiras
                 break;
            case CONSULTAR_CADEIRAS_FOLGA:    // se a op��o escolhida for a 3
	         consultar_cadeiras_folga(mat_int, n, c);   // fazer fun��o para consultar cadeiras com folga
                 break;            
            case CONSULTAR_CADEIRAS_VISTA_LIVRE:     // se a op��o escolhida for a 4
	         consultar_cadeiras_vista_livre(n);       // fazer fun��o consultar cadeiras vista livre
                 break;   
            case FECHAMENTO_BILHETERIA:     // se a op��o escolhida for a 5
                 fechamento_bilheteria(mat_int,n,c);      // fazer fun��o fechamento bilheteria
                 break;
            case SAIR:                 // se a op��o escolhida for a 6
                 break;               //  acabar a execu��o do programa
            default:
                 printf("Opcao invalida!\n");
        }
    } while(opcao != SAIR);
/* Fim "Menu" */    
      
//system("pause");
return 0;
}     

/****************************************** Fun��es **********************************************/
/* Exibe Menu */
int menu(char *opcoes[]) {
    int opcao, //Armazena a op��o selecionada.
        i; //Vari�vel contadora.
    
    printf("\n\n\t* * * *  Menu de Opcoes  * * * *\n\n");
    
    //Exibe as op��es do menu.
    for(i = 0; i < 6; i++) {
        printf("\t%d - %s\n", i + 1, opcoes[i]);   //printa a lista de op��es do menu principal
    }
    
    //Valida a op��o selecionada.
        printf("\n\tEscolha sua opcao (Entre 1 e 6): ");
        scanf("%d",&opcao);   // guarda a op��o selecionada na vari�vel opcao 
        return opcao;
}
/* Fim da fun��o "menu" */


/* Aloca��o da matriz: cria_matriz_lugares */
int ** cria_matriz_lugares(int l, int c, int *pauxc) {
    int ** mat, i=0;
    if((mat = (int **) calloc(l,sizeof(int *))) == NULL) {
            return NULL;
    }
    for(i = 0; i < l; i++) {
          if((mat[i] = (int *) calloc(*pauxc, sizeof(int))) == NULL) {
                     return NULL;
          }
          *pauxc += 2;
    }
    *pauxc -= 2;

    return mat;

}
/* Fim da fun��o "cria_matriz_lugares */


/* Imprime matriz de lugares */  
void print_matriz_lugares(int ** mat, int l, int *pauxc) {
     int i,j,k;
     printf("\n\n\t%d, %d", l, *pauxc);
     printf("\n\nMatriz lado certo:\n");
     for(i = (l - 1); i >= 0; i--) {
           for(j = 0; j < *pauxc; j++) {
                 printf("%d ",mat[i][j]);
           }     
           printf("\n");
           for(k = i; k < l; k++) {
				printf("  ");
			}
           *pauxc -= 2;
     }   
     *pauxc += 2;
}
/* Fim da fun��o "print_matriz_lugares" */


/* Fun��o: vender_cadeira_isolada */
void vender_cadeira_isolada(int ** mat) {
    char fila; //fila em formato de caracter
    int coluna, 
        i, 
        j, 
        linha; // aux para trabalharmos com a linha na matriz
    
    printf("\n\n\tINFORME:\n");
    printf("\nFILA: ");
    scanf("%c", &fila);
    printf("\nNUMERO DO ASSENTO: ");
    scanf("%d", &coluna);
    fila = toupper(fila);
    linha = 65 - (int)fila; //65 equivale � 1� fileira (fileira '0')

    for(i = 0; i == fila; i++) {
        for(j = 0; j == coluna; j++) {
            if(mat[i][j] == 0) {
                printf("\nCadeira reservada com sucesso!\n");
                mat[i][j] = 1;
            }
            else {
                printf("\nA cadeira encontra-se OCUPADA!\n");
            }
        }
    }
}
/* Fim da fun��o "vender_cadeira_isolada" */

/*
/* Fun��o: vender_lote_cadeira */
void vender_lote_cadeira(int ** mat, int c) {
     
    char f;
    int m, i, j, fila;
    
    printf("\n\n\tINFORME:\n");
    printf("\nFILA: ");
    scanf("%c", &f);
    printf("\nNUMERO DE CADEIRAS: ");
    scanf("%d", &m);
    f = toupper(f);
    fila = 65 - (int)f;

    for(i = 0; i < fila; i++) {
        for(j = 0; j < c; j++) {
            if(mat[i][j] == 0) {
                printf("\nCadeira vendida com sucesso!\n");
                mat[i][j] = 1;
            }
            else {
                printf("\nA cadeira encontra-se OCUPADA!\n");
            }
        }
    }
}
/* Fim da fun��o "vender_lote_cadeira" */


/* Fun��o: consultar_cadeiras_folga */

void consultar_cadeiras_folga(int ** mat, int l, int *pauxc) {
  int i,j,k;
  //     printf("\n\n\t%d, %d", l, *pauxc);
//     printf("\n\nMatriz lado certo:\n");
  
  for(i = (l - 1); i >= 0; i--) {
    for(j = 0; j < *pauxc; j++) {
      if ((j==0) && (mat[i][1]=="0"))
	printf("%c%d",'A'+i,j+1);
      else if ((j==*pauxc) && (mat[i][(*pauxc)-1]=="0"))
	printf("%c%d",'A'+i,j+1);
      else if ((mat[i][j-1]=="0") && (mat[i][j+1]=="0"))
	printf("%c%d",'A'+i,j+1);
    }
    *pauxc-=2;
  }
}
/* Fim da fun��o "consultar_cadeiras_folga" */


/* Fun��o: consultar_cadeiras_vista_livre */

void consultar_cadeiras_vista_livre (int c)
{
}

/* Fim da fun��o "consultar_cadeiras_vista_livre" */


/* Fun��o: fechamento_bilheteria */
void fechamento_bilheteria(int ** mat, int n, int c) {
    float faturamento, perc_fila, perc_total, preco1;
    int i, j, aux_c;
    
    aux_c += 2;
    for(i = 0; i < n/2; i++) {
        for(j = 0; j < c; j ++) {
            if(mat[i][j] == 1) {
                faturamento += preco1;
                perc_fila += 1;
                perc_total += 1;
            }
        }
        perc_fila = (perc_fila * 100) / c;
        printf("\nPercentual de ocupa��o da fila %d: %.1f%%.", c, perc_fila);
        c += 2;
    }
    for(i; i < n; i++) {
        for(j = 0; j < c; j++) {
            if(mat[i][j] == 1) {
                faturamento += preco1 / 2;
                perc_fila += 1;
                perc_total += 1;
            }
        }
        perc_fila = (perc_fila * 100) / c;
        printf("\nPercentual de ocupa��o da fila %d: %.1f%%.", c, perc_fila);
        c += 2;
    }
    printf("\nPercentual de ocupa��o do teatro: %.1f%%.", c, perc_total);
    printf("\n\tFaturamento da bilheteria: %.2f\n", faturamento);
}
/* Fim da fun��o "fechamento_bilheteria" */

