#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_INSTRUCOES 100

// Fun��o para ler as instru��es do arquivo
int ler_instrucoes(char instrucoes[][50], char *arquivo) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    int i = 0;
    while (fgets(instrucoes[i], 50, file)) {
        // Remover a quebra de linha no final da instru��o
        instrucoes[i][strlen(instrucoes[i]) - 1] = '\0';
        i++;
    }

    fclose(file);
    return i;
}

// Fun��o para simular o pipeline
void simular_pipeline(char instrucoes[][50], int num_instrucoes) {
    char pipeline[4][50];
    int ciclos_com_pipeline = 0;
    int ciclos_sem_pipeline = 0;

    for (int i = 0; i < num_instrucoes; i++) {
        // Est�gio 1: Buscar instru��o
        strcpy(pipeline[0], instrucoes[i]);
        printf("Estagio 1 - Buscar Instrucao: %s\n", pipeline[0]);

        // Est�gio 2: Decodificar instru��o
        strcpy(pipeline[1], pipeline[0]);
        printf("Estagio 2 - Decodificar Instrucao: %s\n", pipeline[1]);

        // Est�gio 3: Executar instru��o
        strcpy(pipeline[2], pipeline[1]);
        printf("Estagio 3 - Executar Instrucao: %s\n", pipeline[2]);

        // Est�gio 4: Escrever resultado
        strcpy(pipeline[3], pipeline[2]);
        printf("Estagio 4 - Escrever Resultado: %s\n", pipeline[3]);

        // Contar os ciclos com e sem pipeline
        ciclos_com_pipeline++;
        ciclos_sem_pipeline += 4;

        // Aguardar um segundo antes do pr�ximo ciclo
        sleep(1);
    }

    // Imprimir relat�rio
    printf("\nRelatorio:\n");
    printf("Numero de ciclos com pipeline: %d\n", ciclos_com_pipeline);
    printf("Numero de ciclos sem pipeline: %d\n", ciclos_sem_pipeline);
}

int main() {
    char instrucoes[MAX_INSTRUCOES][50];
    int num_instrucoes;

    char arquivo_instrucoes[] = "instrucoes.txt";

    // Ler as instru��es do arquivo
    num_instrucoes = ler_instrucoes(instrucoes, arquivo_instrucoes);

    if (num_instrucoes == -1) {
        return 1;
    }

    // Simular o pipeline
    simular_pipeline(instrucoes, num_instrucoes);

    return 0;
}
