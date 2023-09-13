#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Se você me plagiar denovo henrique eu juro que te mato
//Autoria de Thiago da Silva

//Contadores de trocas e comparações
int trocas = 0;
int comparacoes = 0;

//troca de valor entre varíaveis utilizando ponteiros para strings
void swap (char **a, char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

//Joga os elementos menores para a esquerda do pivo e os maiores a direita
int particionar(char *arr[], int inicio, int fim) {
    char *pivo = arr[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++){
        comparacoes++;
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
    comparacoes++;
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
    
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", 
        "limão", "manga", "abacate", "kiwi", "cereja",
        "morango", "pêssego", "goiaba", "melancia", "framboesa",
        "amora", "caqui", "figo", "papaya"
    };
    int tamanhoArray = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array antes\n");
    for (int i = 0; i < tamanhoArray; i++){
        puts(arr[i]);
    }
    
    quicksort(arr, 0, tamanhoArray - 1);
    printf("\nArray depois\n");
    for (int i = 0; i < tamanhoArray; i++){
        puts(arr[i]);
    }

    printf("Trocas: %d\n", trocas);
    printf("Comparacoes: %d\n", comparacoes);
    return 0;
}