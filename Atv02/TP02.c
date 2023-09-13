#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void quicksort(char *arr[], int inicio, int fim) {
    if (inicio < fim) {
        //Recebe o indice do pivo
        int pivo = particionar(arr, inicio, fim);

        //Ordena elementos antes do pivo
        quicksort(arr, inicio, pivo - 1);
        //Ordena elementos depois do pivo
        quicksort(arr, pivo + 1, fim);
    }
}
int main() {
    
    char *arrayTeste[] = {"Teste", "String", "ai_pai_para", "modoSexo"};
    

    quicksort(arrayTeste, 0, 3);
    
    
    return 0;
}