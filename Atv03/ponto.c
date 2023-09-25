#include "ponto.h"
#include <stdlib.h>
#include <math.h>

Ponto* criarPonto(double x, double y) {
    Ponto* ponto = (Ponto*)malloc(sizeof(Ponto));
    if (ponto == NULL) {
        return NULL; // Falha na alocação de memória
    }
    ponto->x = x;
    ponto->y = y;
    return ponto;
}

void destruirPonto(Ponto* ponto) {
    free(ponto);
}

// Função para calcular a área de um triângulo dado três pontos
double calcularAreaTriangulo(double x1, double y1, double x2, double y2, double x3, double y3) {
    return fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}
