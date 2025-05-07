#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include "Stack.c"

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void imprimirFloat(const void* dado) {
    if (dado) {
        printf("%.2f", *(float*)dado);
    } else {
        printf("NULL");
    }
}

int main() {
    Pilha* pilha = criarPilha();
    if (!pilha) {
        fprintf(stderr, "Nao foi possivel criar a pilha. Encerrando.\n");
        return 1;
    }

    int opcao;
    float valorFloat;
    void* dadoDesempilhado = NULL;
    void* dadoTopo = NULL;

    do {
        limparTela();

        printf("--- Status da Pilha Dinamica (Lista Encadeada) ---\n");
        dadoTopo = verTopo(pilha);
        printf("Topo: ");
        if (dadoTopo) {
            imprimirFloat(dadoTopo);
            printf("\n");
        } else {
            printf("NULL\n");
        }
        printf("Tamanho: %d\n", obterTamanhoPilha(pilha));
        printf("Memoria alocada: %zu bytes\n", obterMemoriaAlocadaPilha(pilha));

        imprimirPilha(pilha, imprimirFloat);
        printf("--------------------------------------------------\n");

        printf("\nMENU (0 para encerrar o programa):\n");
        printf("1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
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
                printf("Digite o valor float a ser empilhado: ");
                if (scanf("%f", &valorFloat) != 1) {
                     printf("Entrada invalida para float.\n");
                     int c;
                     while ((c = getchar()) != '\n' && c != EOF);
                } else {
                    getchar();
                    if (!empilhar(pilha, &valorFloat, sizeof(float))) {
                        printf("Falha ao empilhar.\n");
                    } else {
                        printf("Valor %.2f empilhado.\n", valorFloat);
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 2:
                dadoDesempilhado = desempilhar(pilha);
                if (dadoDesempilhado != NULL) {
                    printf("Desempilhado: ");
                    imprimirFloat(dadoDesempilhado);
                    printf("\n");
                    free(dadoDesempilhado);
                    dadoDesempilhado = NULL;
                } else {
                    printf("Pilha vazia. Nada para desempilhar.\n");
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

    destruirPilha(pilha);
    printf("Memoria liberada. Programa encerrado.\n");

    return 0;
}