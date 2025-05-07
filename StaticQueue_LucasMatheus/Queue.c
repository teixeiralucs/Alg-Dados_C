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
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
    fila->capacidade = TAMANHO_MAX_FILA;
    fila->memoriaAlocadaDados = 0;
    for(int i = 0; i < TAMANHO_MAX_FILA; ++i) {
        fila->dados[i] = NULL;
    }
    return fila;
}

void destruirFila(Fila* fila) {
    if (!fila) return;

    if (fila->tamanho > 0) {
         int indice_atual = fila->inicio;
         for (int i = 0; i < fila->tamanho; ++i) {
             if (fila->dados[indice_atual] != NULL) {
                 free(fila->dados[indice_atual]);
                 fila->dados[indice_atual] = NULL;
             }
             indice_atual = (indice_atual + 1) % fila->capacidade;
         }
     }
    free(fila);
}


bool estaFilaVazia(const Fila* fila) {
    return fila == NULL || fila->tamanho == 0;
}

bool estaFilaCheia(const Fila* fila) {
    return fila != NULL && fila->tamanho == fila->capacidade;
}

bool enfileirar(Fila* fila, const void* dado, size_t tamanhoDado) {
    if (!fila || estaFilaCheia(fila)) {
        fprintf(stderr, "Erro: Fila cheia ou nula.\n");
        return false;
    }
    if (!dado) {
         fprintf(stderr, "Erro: Dado nulo.\n");
         return false;
    }

    void* copiaDado = malloc(tamanhoDado);
    if (!copiaDado) {
        perror("Falha ao alocar memoria para o dado da fila");
        return false;
    }
    memcpy(copiaDado, dado, tamanhoDado);

    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->dados[fila->fim] = copiaDado;
    fila->tamanho++;
    fila->memoriaAlocadaDados += tamanhoDado;

    return true;
}

void* desenfileirar(Fila* fila, size_t* tamanhoDadoRemovido) {
    if (!fila || estaFilaVazia(fila)) {
        if (tamanhoDadoRemovido) *tamanhoDadoRemovido = 0;
        return NULL;
    }

    void* dadoRemovido = fila->dados[fila->inicio];
    size_t tamanhoEstimado = 0;

    if (dadoRemovido != NULL) {
        tamanhoEstimado = strlen((char*)dadoRemovido) + 1;
    }

    fila->dados[fila->inicio] = NULL;
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    fila->memoriaAlocadaDados -= tamanhoEstimado;
    if(fila->tamanho == 0) {
        fila->inicio = 0;
        fila->fim = -1;
         fila->memoriaAlocadaDados = 0;
    }

    if (tamanhoDadoRemovido) {
        *tamanhoDadoRemovido = tamanhoEstimado;
    }

    return dadoRemovido;
}


void* verInicio(const Fila* fila) {
    if (!fila || estaFilaVazia(fila)) {
        return NULL;
    }
    return fila->dados[fila->inicio];
}

void* verFim(const Fila* fila) {
     if (!fila || estaFilaVazia(fila)) {
        return NULL;
    }
     return fila->dados[fila->fim];
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
    return sizeof(Fila) + fila->memoriaAlocadaDados;
}

void imprimirFila(const Fila* fila, void (*imprimirDado)(const void*)) {
    printf("Fila: ");
    if (estaFilaVazia(fila)) {
        printf("Vazia!\n");
        return;
    }

    int indice_atual = fila->inicio;
    for (int i = 0; i < fila->tamanho; ++i) {
        if (fila->dados[indice_atual] != NULL && imprimirDado != NULL) {
            imprimirDado(fila->dados[indice_atual]);
        } else {
            printf("[NULL]");
        }
        if (i < fila->tamanho - 1) {
            printf(" <- ");
        }
        indice_atual = (indice_atual + 1) % fila->capacidade;
    }
    printf("\n");
}