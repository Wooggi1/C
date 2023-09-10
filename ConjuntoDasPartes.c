
#include <stdio.h>

void ConstruirPartes(int Conjunto[], int tamanho, int indice, int subconjunto[]) {
    
    if (indice == tamanho) {
        printf("{ ");
        for (int i = 0; i <  tamanho; i++) {
            if (subconjunto[i] == 1) printf("%d ", Conjunto[i]);
        }
        printf("\n");
        return;
    }

    // O elemento da posição indice está no subconjunto
    subconjunto[indice] = 1;
    ConstruirPartes(Conjunto, tamanho, indice + 1, subconjunto);

    // O elemento da posição indice não está no subconjunto
    subconjunto[indice] = 0;
    ConstruirPartes(Conjunto, tamanho, indice + 1, subconjunto);
}

void ImprimirParte (int Conjunto[], int tamanho) {
    int subconjunto[tamanho];
    ConstruirPartes(Conjunto, tamanho, 0, subconjunto); 
}
    
int main() {
    int Conjunto[] = {1, 2, 3};
    int tamanho = sizeof(Conjunto)/sizeof(Conjunto[0]);
    printf("Conjunto das partes: ");
    ImprimirParte(Conjunto, tamanho);
    return 0;
}
