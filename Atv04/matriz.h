#include <stdio.h>
#include <stdlib.h>

typedef struct tCelula {
    struct tCelula *direita, *abaixo;
    int linha, coluna;
    float valor;
} Celula;

typedef struct {
    Celula *cabeca;
    int nlin, ncol;
} Matriz;

void imprimeMatriz(Matriz A);
Matriz leMatriz(FILE *arquivo);
Matriz somaMatrizes(Matriz A, Matriz B);
void insereCelula(Matriz *matriz, int linha, int coluna, float valor);
void deletaCelula(Matriz *matriz, int linha, int coluna);