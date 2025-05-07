#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"
#include "Queue.c"

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void imprimirDouble(const void* dado) {
    if (dado) {
        printf("%.2lf", *(double*)dado);
    } else {
        printf("NULL");
    }
}

int main() {
    Fila* fila = criarFila();
    if (!fila) {
        fprintf(stderr, "Nao foi possivel criar a fila. Encerrando.\n");
        return 1;
    }

    int opcao;
    double valorDouble;
    void* dadoDesenfileirado = NULL;
    void* dadoInicio = NULL;
    void* dadoFim = NULL;


    do {
        limparTela();

        printf("--- Status da Fila Dinamica (Lista Duplamente Encadeada) ---\n");
        dadoInicio = verInicio(fila);
        dadoFim = verFim(fila);

        printf("Primeiro: ");
        imprimirDouble(dadoInicio);
        printf("\n");

        printf("Ultimo: ");
        imprimirDouble(dadoFim);
        printf("\n");

        printf("Tamanho: %d\n", obterTamanhoFila(fila));
        printf("Memoria alocada: %zu bytes\n", obterMemoriaAlocadaFila(fila));

        imprimirFila(fila, imprimirDouble);
        printf("----------------------------------------------------------\n");

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
                printf("Digite o valor double a ser enfileirado: ");
                if (scanf("%lf", &valorDouble) != 1) {
                     printf("Entrada invalida para double.\n");
                     int c;
                     while ((c = getchar()) != '\n' && c != EOF);
                } else {
                    getchar();
                    if (!enfileirar(fila, &valorDouble, sizeof(double))) {
                        printf("Falha ao enfileirar.\n");
                    } else {
                        printf("Valor %.2lf enfileirado.\n", valorDouble);
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 2:
                dadoDesenfileirado = desenfileirar(fila);
                if (dadoDesenfileirado != NULL) {
                    printf("Desenfileirado: ");
                    imprimirDouble(dadoDesenfileirado);
                    printf("\n");
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