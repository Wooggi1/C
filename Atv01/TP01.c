#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define NUM_NOTAS 2

//Função feita para calcular a média do aluno
float calcularMedia(float notas[], int numNotas) {
    float soma = 0.0;
    for (int i = 0; i < numNotas; i++) {
        soma += notas[i];
    }
    return soma / numNotas;
}

//Função que determina se o aluno está reprovado ou aprovado
const char* determinarSituacao(float media) {
    if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    FILE *saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        perror("Erro ao abrir os arquivos");
        exit(1);
    }

    char linha[MAX_NOME + 2 * (NUM_NOTAS + 1)];

    //Loop roda até o fgets chegar ao fim do arquivo
    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        char nome[MAX_NOME];
        float notas[100];
        int numNotas = 0;

        //Separa a string em tokens a partir da chave ","
        char *token = strtok(linha, ",");
        strcpy(nome, token);

        //Continua separando até o strtok retornar NULL, ou seja, chegou ao final da linn
        while ((token = strtok(NULL, ",")) != NULL) {
            notas[numNotas++] = atof(token);
        }

        // Calcular a média das notas
        float media = calcularMedia(notas + 2, numNotas - 2); // Ignorar os dois primeiros campos (nome e telefone)

        // Determina se o aluno está aprovado ou reprovado
        const char *situacao = determinarSituacao(media);

        //if para pular a primeira iteração do while
        if(strcmp(nome, "Nome") == 0)
            continue;
        fprintf(saida, "%s, %.2f, %s\n", nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    printf("Processamento concluido. Verifique o arquivo SituacaoFinal.csv\n");

    return 0;
}