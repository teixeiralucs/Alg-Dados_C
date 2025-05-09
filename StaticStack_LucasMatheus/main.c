#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Stack.h"
#include "Stack.c"

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char obterEntradaChar() {
    char valor = 0;
    char buffer[10];

    if (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] != '\n' && (buffer[1] == '\n' || buffer[1] == '\0')) {
            valor = buffer[0];
        } else if (buffer[0] == '\n') {
             printf("Entrada invalida (vazio). Tente novamente.\n");
             valor = 0;
        } else {
             printf("Entrada invalida (mais de um caractere). Tente novamente.\n");
             if (strchr(buffer, '\n') == NULL) {
                 int c;
                 while ((c = getchar()) != '\n' && c != EOF);
             }
             valor = 0;
        }
    } else {
         printf("Erro de leitura.\n");
         valor = 0;
    }
    return valor;
}


int main() {
    Pilha* pilha = criarPilha();
    if (!pilha) {
        fprintf(stderr, "Nao foi possivel criar a pilha. Encerrando.\n");
        return 1;
    }

    int opcao;
    char valorChar;
    void* dadoDesempilhado = NULL;
    void* dadoTopo = NULL;

    do {
        limparTela();

        printf("--- Status da Pilha Estatica (Array) ---\n");
        dadoTopo = verTopo(pilha);
        printf("Topo: ");
        if (dadoTopo) {
            printf("%c\n", *(char*)dadoTopo);
        } else {
            printf("NULL\n");
        }
        printf("Tamanho: %d\n", obterTamanhoPilha(pilha));
        printf("Memoria alocada: %zu bytes\n", obterMemoriaAlocadaPilha(pilha));

        imprimirPilha(pilha);
        printf("----------------------------------------\n");

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
                printf("Digite o caractere a ser empilhado: ");
                valorChar = obterEntradaChar();

                if(valorChar != 0) {
                    if (!empilhar(pilha, &valorChar)) {
                        printf("Falha ao empilhar. Pilha pode estar cheia.\n");
                    } else {
                        printf("Caractere '%c' empilhado.\n", valorChar);
                    }
                     printf("Pressione Enter para continuar...");
                     getchar();

                } else {
                    printf("Pressione Enter para continuar...");
                    getchar();
                }
                break;

            case 2:
                dadoDesempilhado = desempilhar(pilha);
                if (dadoDesempilhado != NULL) {
                    printf("Desempilhado: %c\n", *(char*)dadoDesempilhado);
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