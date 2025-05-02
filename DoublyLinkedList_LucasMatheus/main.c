#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.c"

void limparATela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void imprimirInt (const void* dado){
    if (dado){
        printf("%d" , *(int*)dado);
    }
    else{
        printf("NULL");
    }
}
int main(){
    ListaDuplamenteEncadeada* lista = criarLista();
    if (!lista){
        fprintf(stderr , "Não foi possivel criar a lista, Encerrando o programa.\n");
        return 1;
    }
    int opcao;
    int valorInteiro;
    void* dadoRemovido = NULL;
    void* dadoInicio = NULL;
    void* dadoFim = NULL;

    do{
        limparATela();
        printf("Bem Vindo(a) ao programa de Lista Duplamente Encadeada\n");
        printf("O Status da Lista Duplamente encadeada é:");
        dadoInicio = pegarInicio(lista);
        dadoFim = pegarFim(lista);

        printf("Incio da Lista: ");
        imprimirInt(dadoInicio);
        printf("\n");

        printf("Fim da Lista: ");
        imprimirInt(dadoFim);
        printf("\n");

        printf("Tamanho da Lista: %d\n", tamanhoDaLista(lista));
        printf("Memoria Alocada: %zu bytes\n" , memoriaAlocadaDaLista(lista));

        printf("=====================================================\n");

        printf("\nMenu (pressione 0 para encerrar o programa)\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover do Início\n");
        printf("4 - Remover do fim\n");
        printf("\nDigite uma opcão: ");

        if (scanf("%d" , &opcao != 1)){
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            opcao = -1;
        }
        else{
            int c; 
            while((c = getchar()) !n '\n' && c != EOF);

        }
        switch (opcao){
            case 1:
                printf("Digite o valor inteiro a ser inserido no início");
                if(scanf("%d" , &valorInteiro) != 1 ){
                    printf("Número diitado incorreto para o tipo inteiro.\n");
                    int c;
                    while ((c = getchat()) != '\n' && c != EOF);
                }
                else{
                    getchar();
                }
                if(!inserirNoInicio(lista, &valorInteiro, sizeof(int))){
                    printf("Falha ao inserir no início. \n");
                }
                else{
                    printf("Valor %d inserido no início com sucesso.\n" , valorInteiro);
                }
                printf("Pressione Enter para continuar...");
                getchar();
            break;
        case 2:
        }
    }
}