#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void imprimeMatriz(Matriz A) {
    for (int i = 0; i < A.nlin; i++) {
        Celula *atualLinha = A.cabeca->direita;  // Inicializa atualLinha para a primeira célula na linha

        for (int j = 0; j < A.ncol; j++) {
            if (atualLinha != NULL && atualLinha->linha == i && atualLinha->coluna == j) {
                printf("%d ", atualLinha->valor);
                atualLinha = atualLinha->direita;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}



Matriz leMatriz(FILE *arquivo) {
    Matriz A;
    int nlin, ncol;

    // Lendo o número de linhas e colunas do arquivo
    fscanf(arquivo, "%d, %d", &nlin, &ncol);

    A.nlin = nlin;
    A.ncol = ncol;

    // Criando a célula cabeça
    A.cabeca = (Celula *)malloc(sizeof(Celula));
    A.cabeca->direita = NULL;
    A.cabeca->abaixo = NULL;

    Celula *ultimaLinha[A.nlin];
    Celula *ultimaColuna[A.ncol];

    for (int i = 0; i < A.nlin; i++) {
        ultimaLinha[i] = A.cabeca;
    }

    for (int j = 0; j < A.ncol; j++) {
        ultimaColuna[j] = A.cabeca;
    }

    int valor, linha, coluna;

    // Lendo os elementos da matriz do arquivo
    while (fscanf(arquivo, "%d, %d, %d", &linha, &coluna, &valor) == 3) {
        if (linha < 1 || linha > A.nlin || coluna < 1 || coluna > A.ncol) {
            fprintf(stderr, "Erro: Coordenadas fora dos limites da matriz.\n");
            exit(EXIT_FAILURE);
        }

        if (valor != 0) {
            Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
            novaCelula->valor = valor;
            novaCelula->linha = linha - 1; // Subtrai 1 para ajustar para índice base 0
            novaCelula->coluna = coluna - 1; // Subtrai 1 para ajustar para índice base 0

            // Atualizando ponteiros
            novaCelula->direita = ultimaLinha[novaCelula->linha]->direita;
            ultimaLinha[novaCelula->linha]->direita = novaCelula;
            ultimaLinha[novaCelula->linha] = novaCelula;

            novaCelula->abaixo = ultimaColuna[novaCelula->coluna]->abaixo;
            ultimaColuna[novaCelula->coluna]->abaixo = novaCelula;
            ultimaColuna[novaCelula->coluna] = novaCelula;
        }
    }

    return A;
}

Matriz somaMatrizes(Matriz A, Matriz B) {
    Matriz C;
    C.nlin = A.nlin;
    C.ncol = A.ncol;

    // Criando a célula cabeça
    C.cabeca = (Celula *)malloc(sizeof(Celula));
    C.cabeca->direita = NULL;
    C.cabeca->abaixo = NULL;

    Celula *ultimaLinha[C.nlin];
    Celula *ultimaColuna[C.ncol];

    for (int i = 0; i < C.nlin; i++) {
        ultimaLinha[i] = C.cabeca;
    }

    for (int j = 0; j < C.ncol; j++) {
        ultimaColuna[j] = C.cabeca;
    }

    // Percorrendo as matrizes A e B simultaneamente
    for (int i = 0; i < A.nlin; i++) {
        Celula *atualA = A.cabeca->abaixo;

        for (int j = 0; j < A.ncol; j++) {
            float valorA = 0, valorB = 0;

            // Verificando se há valor na posição (i, j) em A
            if (atualA != NULL && atualA->linha == i && atualA->coluna == j) {
                valorA = atualA->valor;
                atualA = atualA->abaixo;
            }

            // Verificando se há valor na posição (i, j) em B
            Celula *atualB = B.cabeca->abaixo;
            while (atualB != NULL && atualB->linha != i && atualB->coluna != j) {
                atualB = atualB->abaixo;
            }
            if (atualB != NULL) {
                valorB = atualB->valor;
            }

            // Calculando a soma
            float soma = valorA + valorB;

            if (soma != 0) {
                Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
                novaCelula->valor = soma;
                novaCelula->linha = i;
                novaCelula->coluna = j;

                // Atualizando ponteiros
                novaCelula->direita = ultimaLinha[i]->direita;
                ultimaLinha[i]->direita = novaCelula;
                ultimaLinha[i] = novaCelula;

                novaCelula->abaixo = ultimaColuna[j]->abaixo;
                ultimaColuna[j]->abaixo = novaCelula;
                ultimaColuna[j] = novaCelula;
            }
        }
    }

    return C;
}   