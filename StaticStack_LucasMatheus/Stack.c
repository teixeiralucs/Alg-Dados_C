#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (!pilha) {
        perror("Falha ao alocar estrutura da pilha");
        return NULL;
    }
    pilha->topo = -1;
    pilha->capacidade = TAMANHO_MAX_PILHA;
    return pilha;
}

void destruirPilha(Pilha* pilha) {
    if (!pilha) {
        return;
    }
    while (!estaPilhaVazia(pilha)) {
        void* dado = desempilhar(pilha);
        if (dado != NULL) {
            free(dado);
        }
    }
    free(pilha);
}

bool estaPilhaVazia(const Pilha* pilha) {
    return pilha == NULL || pilha->topo == -1;
}

bool estaPilhaCheia(const Pilha* pilha) {
    return pilha != NULL && pilha->topo == pilha->capacidade - 1;
}

bool empilhar(Pilha* pilha, const void* dado) {
    if (!pilha || estaPilhaCheia(pilha)) {
        fprintf(stderr, "Erro: Pilha esta cheia ou eh nula.\n");
        return false;
    }
    if (!dado) {
        fprintf(stderr, "Erro: Nao eh possivel empilhar dado nulo.\n");
        return false;
    }

    char* copiaDado = (char*)malloc(sizeof(char));
    if (!copiaDado) {
        perror("Falha ao alocar memoria para elemento da pilha");
        return false;
    }

    *copiaDado = *(char*)dado;

    pilha->topo++;
    pilha->dados[pilha->topo] = copiaDado;

    return true;
}

void* desempilhar(Pilha* pilha) {
    if (!pilha || estaPilhaVazia(pilha)) {
        return NULL;
    }

    void* ponteiroDado = pilha->dados[pilha->topo];
    pilha->dados[pilha->topo] = NULL;
    pilha->topo--;

    return ponteiroDado;
}

void* verTopo(const Pilha* pilha) {
    if (!pilha || estaPilhaVazia(pilha)) {
        return NULL;
    }
    return pilha->dados[pilha->topo];
}

int obterTamanhoPilha(const Pilha* pilha) {
    if (!pilha) {
        return 0;
    }
    return pilha->topo + 1;
}

size_t obterMemoriaAlocadaPilha(const Pilha* pilha) {
     if (!pilha) {
        return 0;
    }
     size_t memoriaElementos = (size_t)obterTamanhoPilha(pilha) * sizeof(char);
     return sizeof(Pilha) + memoriaElementos;
}

void imprimirPilha(const Pilha* pilha) {
    printf("Pilha: ");
    if (estaPilhaVazia(pilha)) {
        printf("Vazia!\n");
        return;
    }

    for (int i = pilha->topo; i >= 0; i--) {
        if (pilha->dados[i] != NULL) {
             printf("%c", *(char*)(pilha->dados[i]));
             if (i > 0) {
                 printf(" -> ");
             }
        } else {
            printf("[NULL]");
             if (i > 0) {
                 printf(" -> ");
             }
        }
    }
    printf("\n");
}