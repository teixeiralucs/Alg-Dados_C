#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (!pilha) {
        perror("Falha ao alocar Pilha");
        return NULL;
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    pilha->memoriaAlocada = sizeof(Pilha);
    return pilha;
}

void destruirPilha(Pilha* pilha) {
    if (!pilha) return;

    No* atual = pilha->topo;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        if (atual->dado != NULL) {
            free(atual->dado);
        }
        free(atual);
        atual = proximo;
    }
    free(pilha);
}

bool empilhar(Pilha* pilha, const void* dado, size_t tamanhoDado) {
    if (!pilha || !dado) {
        fprintf(stderr, "Erro: Pilha ou dado nulo.\n");
        return false;
    }

    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        perror("Falha ao alocar No");
        return false;
    }

    novoNo->dado = malloc(tamanhoDado);
    if (!novoNo->dado) {
        perror("Falha ao alocar memoria para o dado");
        free(novoNo);
        return false;
    }

    memcpy(novoNo->dado, dado, tamanhoDado);
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;
    pilha->memoriaAlocada += sizeof(No) + tamanhoDado;

    return true;
}

void* desempilhar(Pilha* pilha) {
    if (!pilha || estaPilhaVazia(pilha)) {
        return NULL;
    }

    No* noRemovido = pilha->topo;
    void* dadoRemovido = noRemovido->dado;
    size_t tamanhoDado = 0;

    if(dadoRemovido != NULL) {
       tamanhoDado = sizeof(float);
    }


    pilha->topo = noRemovido->proximo;
    pilha->tamanho--;
    pilha->memoriaAlocada -= (sizeof(No) + tamanhoDado);

    free(noRemovido);

    return dadoRemovido;
}

void* verTopo(const Pilha* pilha) {
    if (!pilha || estaPilhaVazia(pilha)) {
        return NULL;
    }
    return pilha->topo->dado;
}

bool estaPilhaVazia(const Pilha* pilha) {
    return pilha == NULL || pilha->topo == NULL;
}

int obterTamanhoPilha(const Pilha* pilha) {
    if (!pilha) {
        return 0;
    }
    return pilha->tamanho;
}

size_t obterMemoriaAlocadaPilha(const Pilha* pilha) {
    if (!pilha) {
        return 0;
    }
    return pilha->memoriaAlocada;
}

void imprimirPilha(const Pilha* pilha, void (*imprimirDado)(const void*)) {
    printf("Pilha: ");
    if (estaPilhaVazia(pilha)) {
        printf("Vazia!\n");
        return;
    }

    No* atual = pilha->topo;
    bool primeiro = true;
    while (atual != NULL) {
        if (!primeiro) {
            printf(" -> ");
        }
        if (atual->dado != NULL && imprimirDado != NULL) {
            imprimirDado(atual->dado);
        } else {
            printf("[NULL]");
        }
        atual = atual->proximo;
        primeiro = false;
    }
    printf("\n");
}