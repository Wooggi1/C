#ifndef PONTO_H
#define PONTO_H

typedef struct {
    double x;
    double y;
} Ponto;

Ponto* criarPonto(double x, double y);
void destruirPonto(Ponto* ponto);
double calcularAreaTriangulo(double x1, double y1, double x2, double y2, double x3, double y3);

#endif
