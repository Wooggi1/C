#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//Se você me plagiar denovo henrique eu juro que te mato
//Autoria de Thiago da Silva

//troca de valor entre varíaveis utilizando ponteiros para strings
void swap (char **a, char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

//Joga os elementos menores para a esquerda do pivo e os maiores a direita
int particionar(char *arr[], int inicio, int fim) {
    char *pivo = arr[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++){
        if (strcmp(arr[j], pivo) <= 0){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    //Coloca o pivo na posição correta e retorna sua posição
    swap(&arr[i + 1], &arr[fim]);
    return (i + 1);
}
int main() {
    
    char *arrayTeste[] = {"Teste", "String"};
    LARGE_INTEGER frequency;
    LARGE_INTEGER t1, t2;
    double tempo;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&t1);
    particionar(arrayTeste, 0, 1);
    QueryPerformanceCounter(&t2);

    tempo = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("Tempo: %fms \n", tempo);
    
    return 0;
}