#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    Matriz A, B, C;
    FILE *Matriz_A = fopen("Matriz_A.txt", "r");
    FILE *Matriz_B = fopen("Matriz_B.txt", "r");

    if (Matriz_A == NULL || Matriz_B == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    A = leMatriz(Matriz_A);
    imprimeMatriz(A);
}