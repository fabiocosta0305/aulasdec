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

