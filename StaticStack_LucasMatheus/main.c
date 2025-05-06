#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include "Stack.c"

void limparATela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

char input(){
    char valor = 0;
    char buffer [10];

    if(fgets(buffer, sizeof(buffer), stdin)){
        if (buffer[0] != '\n' && (buffer [1] == '\n' || buffer[1] == '\0')){
            valor = buffer[0];
        }
        else if (buffer[0] == '\n'){
            printf("Entrada Inválida (vazio), por favor, tente novamente.\n");
            valor = 0;
        }
        else{
            printf("Entrada inválida (mais de um caractere), por favor, tente novamente.\n");
            valor = 0;
        }
    }
    else{
        printf("Erro de leitura.\n");
        valor = 0;
    }
    return valor;
}

int main(){
    Pilha* pilha = criarPilha();
    if(!pilha){
        return 1;
    }
    int opcao;
    char charValue;
    void* dadoRetirado = NULL;
    void* dadoMaximo = NULL;

    do {
        limparATela();
        printf("Bem Vindo(a) ao programa de Pilha Estática\n");
        printf("O Status da Pilha Estática é: \n");
        dadoMaximo = Topo(pilha);
        printf("Topo: ");
        if (dadoMaximo){
            printf("%c\n", *(char*)dadoMaximo);
        }
        else {
            printf("NULL\n");
        }
        printf("Tamanho: %d\n", TamanhodaPilha(pilha));
        printf("Memória Alocada: %zu bytes\n"), MemoriaAlocadaDaPilha(pilha);

        ImprimirPilha(pilha);
        printf("=====================================================\n");

        printf("\nMenu (pressione 0 para encerrar o programa)\n");
        printf("1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
        printf("\nDigite uma opcão: ");

        if(scanf("%d" , &opcao) != 1){
            while(getchar() != '\n');
            opcao = -1;
        }
        while(getchar() != '\n');

        switch (opcao){
            case 1:
                printf("Digite o caractere a ser empilhado");
                charValue = Imput();
                if (charValue =! 0){
                    if (!push(pilha, &charValue)){
                        printf("Falha ao empilhar, a pilha pode estar cheia.\n");
                    }
                    else{
                        printf("Caractere '%c' empilhado com sucesso.\n" , charValue);
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 2:
                dadoRetirado = Pop(pilha);
                if (!dadoRetirado != NULL){
                    printf("Desempilhado: '%c'\n" , *(char*)dadoRetirado);
                    free(dadoRetirado);

                    dadoRetirado(NULL);
                }
                else{
                    printf("Pilha Vazia. Nada para desenpilhar.\n");
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 0:
                printf("Encerrando o programa, obrigado!");
                break;
            
            default:
                printf("Opção inválida. Tente novamente!\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }
    }
    while (opcao != 0);
    destruirPilha(pilha);
    printf("Memória liberada e programa encerrado.\n");

    return 0;
}