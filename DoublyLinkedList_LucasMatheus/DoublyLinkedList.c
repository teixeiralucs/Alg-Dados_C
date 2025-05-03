#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaDuplamenteEncadeada* criarLista(){
    ListaDuplamenteEncadeada* lista = (ListaDuplamenteEncadeada*)malloc(sizeof(ListaDuplamenteEncadeada));
}

if (!lista) {
    perror("Não foi possível alocar memória")
    return NULL;
}

lista->inicio = NULL;
lista->fim = NULL;
lista->tamanho = 0;
lista->memoriaAlocada = sizeof(ListaDuplamenteEncadeada);
return lista;

void destruirLista(ListaDuplamenteEncadeada* lista){
    if(!lista) return;
    No* atual = lista -> inicio;
    while (atual != NULL){
        No* proximo = atual -> proximo;
        if (atual -> dado != NULL){
            free(atual -> dado);
        }
        free(atual);
        atual = proximo;
    }
    free(lista);
}

bool listaEstaVazia(const ListaDuplamenteEncadeada* lista){
    return lista == NULL || lista -> inicio == NULL;
}

bool inserirNoInicio(ListaDuplamenteEncadeada* lista, const void* dado, size_t tamanhoDoDado){
    if (!lista || !dado) return false;
    No* novoNo = (No*)malloc(sizeof(No));
    if(!novoNo){
        perror("Falha ao alocar memórioa no Nó");
        return false;
    }
    novoNo -> anterior = NULL;
    novoNo -> proximo = NULL;
    novoNo -> dado = malloc (tamanhoDoDado);

    if(!novoNo -> dado){
        perror("Falha ao alocar memória para o dado");
        free(novoNo);
        return(false);
    }
    memcpy(novoNo -> dado, dado, tamanhoDoDado);

    if (listaEstaVazia(lista)){
        lista -> inicio = novoNo;
        lista -> fim = novoNo;
    }
    else{
        novoNo -> proximo - lista -> inicio;
        lista -> inicio -> anterior = novoNo;
        lista -> inicio = novoNo;
    }
    lista -> tamanho++;
    lista -> memoriaAlocada += sizeof(No) + tamanhoDoDado;

    return true;
}

bool inserirNoFim(ListaDuplamenteEncadeada* lista, const void* dado, size_t tamanhoDoDado){
    if (!lista || !dado) return false;

    No* novoNo = (No*)malloc(sizeof(No));
    if(!novoNo){
        perror("Falha ao alocar memória no Nó");
        return false;
    }

    novoNo -> anterior = NULL;
    novoNo -> proximo = NULL;
    novoNo -> dado = malloc(tamanhoDoDado);

    if(!novoNo -> dado){
        perror("Falha ao alocar memória para o dado");
        free(novoNO);
        return false;
    }
    memcpy(novoNo -> dado, dado, tamanhoDoDado);

    if (listaEstaVazia(lista)){
        lista -> inicio = novoNo;
        lista -> fim = novoNo;
    }
    else{
        novoNo -> anterior = lista -> fim;
        lista -> fim -> proximo = novoNo;
        lista -> fim = novoNo;
    }
    lista -> tamanho++;
    lista -> memoriaAlocada += sizeof(No) + tamanhoDoDado;

    return true;
}

void* removerDoInicio(ListaDuplamenteEncadeada* lista){
    if(!lista || listaEstaVazia(lista)) return NULL;

    No* noRemovido = lista -> inicio;
    void* dadoRemovido = noRemovido -> dado;
    size_t tamanhoDoDado = sizeof(int);
    
    lista -> inicio = noRemovido -> proximo;

    if(lista -> inicio != NULL){
        lista -> inicio -> anterior = NULL;
    }
    else{
        lista -> fim = NULL;
    }
    lista -> tamanho--;
    lista -> memoriaAlocada -= (sizeof(No) + tamanhoDoDado);
    free(noRemovido)

    return dadoRemovido;
}

void* removerDoFim(ListaDuplamenteEncadeada* lista){
    if (!lista || listaEstaVazia(lista)) return NULL;

    No* noRemovido = lista -> fim;
    size_t tamanhoDoDado = sizeof(int);

    lista -> fim = noRemovido -> anterior;

    if (lista -> fim != NULL){
        lista -> fim -> proximo = NULL;
    } 
    else{
        lista -> inicio =NULL;
    }
    lista -> tamanho--;
    lista -> memoriaAlocada -= (sizeof(No) + tamanhoDoDado);
    free(noRemovido);

    return dadoRemovido;
}
void* pegarInicio(const ListaDuplamenteEncadeada* lista){
    if (!lista || listaEstaVazia(lista)) return NULL;
    return lista -> inicio -> dado;
}
void* pegarFim(const ListaDuplamenteEncadeada* lista){
    if (!lista || listaEstaVazia(lista)) return NULL;
    return lista -> fim -> dado;
}
int tamanhoDaLista(const ListaDuplamenteEncadeada* lista){
    if(!lista) return 0;
    return lista -> tamanho;
}
size_t memoriaAlocadaDaLista (const ListaDuplamenteEncadeada* lista){
    if(!lista) return 0;
    return lista -> memoriaAlocada;
}
void imprimirLista(const ListaDuplamenteEncadeada* lista, void (*imprimirDado)(const void*)){
    printf("Lista: ");
    if(listaEstaVazia(lista)){
        printf("Lista Vazia\n");
        return;
    }
    No* atual = lista -> inicio;
    while(atual != NULL){
        if (atual -> dado != NULL && imprimirDado != NULL){
            imprimirDado(atual -> dado);
        }
        else{
            printf("[NULL]");
        }
        if (atual -> proximo != NULL){
            printf("<->");
        }
        atual = atual -> proximo;
    }
    printf("\n");
}



