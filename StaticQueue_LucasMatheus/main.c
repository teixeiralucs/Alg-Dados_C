#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Queue.h"
#include "Queue.c"

#define TAMANHO_BUFFER_STRING 100

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void imprimirString(const void* dado) {
    if (dado) {
        printf("%s", (char*)dado);
    } else {
        printf("NULL");
    }
}

void removerQuebraLinha(char *str) {
    if (str == NULL) return;
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}


int main() {
    Fila* fila = criarFila();
    if (!fila) {
        fprintf(stderr, "Nao foi possivel criar a fila. Encerrando.\n");
        return 1;
    }

    int opcao;
    char bufferString[TAMANHO_BUFFER_STRING];
    void* dadoDesenfileirado = NULL;
    void* dadoInicio = NULL;
    void* dadoFim = NULL;
    size_t tamanhoRemovido;

    do {
        limparTela();

        printf("--- Status da Fila Estatica (Array) ---\n");
        dadoInicio = verInicio(fila);
        dadoFim = verFim(fila);

        printf("Primeiro: ");
        imprimirString(dadoInicio);
        printf("\n");

        printf("Ultimo: ");
        imprimirString(dadoFim);
        printf("\n");

        printf("Tamanho: %d\n", obterTamanhoFila(fila));
        printf("Memoria alocada: %zu bytes\n", obterMemoriaAlocadaFila(fila));

        imprimirFila(fila, imprimirString);
        printf("----------------------------------------\n");

        printf("\nMENU (0 para encerrar o programa):\n");
        printf("1 - Enfileirar (enqueue)\n");
        printf("2 - Desenfileirar (dequeue)\n");
        printf("0 - Encerrar o programa (exit)\n");
        printf("\nDigite uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            opcao = -1;
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        switch (opcao) {
            case 1:
                printf("Digite a string a ser enfileirada: ");
                if (fgets(bufferString, TAMANHO_BUFFER_STRING, stdin)) {
                     removerQuebraLinha(bufferString);
                     if (strlen(bufferString) > 0) {
                        if (!enfileirar(fila, bufferString, strlen(bufferString) + 1)) {
                            printf("Falha ao enfileirar. Fila pode estar cheia.\n");
                        } else {
                            printf("String \"%s\" enfileirada.\n", bufferString);
                        }
                     } else {
                         printf("Entrada vazia. Nada foi enfileirado.\n");
                     }
                } else {
                    printf("Erro ao ler a string.\n");
                     int c;
                     while ((c = getchar()) != '\n' && c != EOF);
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 2:
                dadoDesenfileirado = desenfileirar(fila, &tamanhoRemovido);
                if (dadoDesenfileirado != NULL) {
                    printf("Desenfileirado: ");
                    imprimirString(dadoDesenfileirado);
                    printf(" (Tamanho: %zu bytes)\n", tamanhoRemovido);
                    free(dadoDesenfileirado);
                    dadoDesenfileirado = NULL;
                } else {
                    printf("Fila vazia. Nada para desenfileirar.\n");
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 0:
                printf("Encerrando o programa e liberando memoria...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }

    } while (opcao != 0);

    destruirFila(fila);
    printf("Memoria liberada. Programa encerrado.\n");

    return 0;
}