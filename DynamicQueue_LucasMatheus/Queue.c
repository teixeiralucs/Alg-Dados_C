#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (!fila) {
        perror("Falha ao alocar Fila");
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    fila->memoriaAlocada = sizeof(Fila);
    return fila;
}

void destruirFila(Fila* fila) {
    if (!fila) return;

    No* atual = fila->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        if (atual->dado != NULL) {
            free(atual->dado);
        }
        free(atual);
        atual = proximo;
    }
    free(fila);
}

bool enfileirar(Fila* fila, const void* dado, size_t tamanhoDado) {
    if (!fila || !dado) {
        fprintf(stderr, "Erro: Fila ou dado nulo.\n");
        return false;
    }

    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        perror("Falha ao alocar No");
        return false;
    }
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    novoNo->dado = malloc(tamanhoDado);
    if (!novoNo->dado) {
        perror("Falha ao alocar memoria para o dado");
        free(novoNo);
        return false;
    }
    memcpy(novoNo->dado, dado, tamanhoDado);

    if (estaFilaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        novoNo->anterior = fila->fim;
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }

    fila->tamanho++;
    fila->memoriaAlocada += sizeof(No) + tamanhoDado;

    return true;
}

void* desenfileirar(Fila* fila) {
    if (!fila || estaFilaVazia(fila)) {
        return NULL;
    }

    No* noRemovido = fila->inicio;
    void* dadoRemovido = noRemovido->dado;
    size_t tamanhoDado = 0;

     if(dadoRemovido != NULL) {
       tamanhoDado = sizeof(double);
    }

    fila->inicio = noRemovido->proximo;
    if (fila->inicio != NULL) {
        fila->inicio->anterior = NULL;
    } else {
        fila->fim = NULL;
    }

    fila->tamanho--;
    fila->memoriaAlocada -= (sizeof(No) + tamanhoDado);

    free(noRemovido);

    return dadoRemovido;
}


void* verInicio(const Fila* fila) {
    if (!fila || estaFilaVazia(fila)) {
        return NULL;
    }
    return fila->inicio->dado;
}

void* verFim(const Fila* fila) {
     if (!fila || estaFilaVazia(fila)) {
        return NULL;
    }
     return fila->fim->dado;
}


bool estaFilaVazia(const Fila* fila) {
    return fila == NULL || fila->inicio == NULL;
}

int obterTamanhoFila(const Fila* fila) {
    if (!fila) {
        return 0;
    }
    return fila->tamanho;
}

size_t obterMemoriaAlocadaFila(const Fila* fila) {
    if (!fila) {
        return 0;
    }
    return fila->memoriaAlocada;
}

void imprimirFila(const Fila* fila, void (*imprimirDado)(const void*)) {
    printf("Fila: ");
    if (estaFilaVazia(fila)) {
        printf("Vazia!\n");
        return;
    }

    No* atual = fila->inicio;
    while (atual != NULL) {
        if (atual->dado != NULL && imprimirDado != NULL) {
            imprimirDado(atual->dado);
        } else {
            printf("[NULL]");
        }
        if (atual->proximo != NULL) {
            printf(" <-> ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}