#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//Função pra printar array aplicando o princípio DRY
void printarArray(char *arr[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        comparacoes += 2;
        if (i == tamanho - 1){
            comparacoes -= 1;
            printf("%s", arr[i]); 
            break;
        } 
        if (i == 6 || i == 12)
            printf("\n");
        printf("%s, ", arr[i]);
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
    FILE *arquivo = fopen("Arquivofinal.txt", "w");
    
    quicksort(arr, 0, tamanhoArray - 1);
    printf("\nArray ordenado\n");
    printarArray(arr, tamanhoArray);
    printf("mediana do array: %s\n", arr[tamanhoArray/2]);
    

    fprintf(arquivo, "\t\tARQUIVO FINAL\n\n");
    fprintf(arquivo, "array ordenado: ");
    for (int i = 0; i < tamanhoArray; i++){
        comparacoes += 2;
        if (i == tamanhoArray - 1){
            comparacoes -= 1;
            fprintf(arquivo, "%s", arr[i]); 
            break;
        }
        if (i == 6 || i == 12)
            fprintf(arquivo, "\n\t\t\t\t");
        fprintf(arquivo, "%s, ", arr[i]);
    }
    
        fprintf(arquivo, "\nTrocas: %d\n", trocas);
        fprintf(arquivo, "Comparacoes: %d\n", comparacoes);
        fprintf(arquivo, "mediana do array: %s\n", arr[tamanhoArray/2]);
    

    fclose(arquivo);

    return 0;
}