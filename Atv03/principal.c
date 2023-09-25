#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    int n;

    // Abre o arquivo "dados.txt" para leitura
    FILE *arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Encerra o programa com erro
    }

    // Lê o número de lados do polígono
    fscanf(arquivo, "%d", &n);

    double x, y;
    double x1, y1, x2, y2, x3, y3;
    double areaTotal = 0.0;

    // Lê as coordenadas do primeiro vértice
    fscanf(arquivo, "%lf %lf", &x1, &y1);
    x2 = x1;
    y2 = y1;

    // Loop para ler as coordenadas dos vértices e calcular a área do polígono
    for (int i = 2; i <= n; i++) {
        // Lê as coordenadas do próximo vértice
        fscanf(arquivo, "%lf %lf", &x, &y);
        x3 = x;
        y3 = y;

        // Calcula a área do triângulo e adiciona à área total
        areaTotal += calcularAreaTriangulo(x1, y1, x2, y2, x3, y3);

        // Atualiza os vértices do triângulo
        x2 = x3;
        y2 = y3;
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Exibe a área do polígono
    printf("A área do polígono é: %.2lf\n", areaTotal);

    return 0;
}
