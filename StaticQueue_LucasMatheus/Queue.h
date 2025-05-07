#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

#define TAMANHO_MAX_FILA 50

typedef struct {
    void* dados[TAMANHO_MAX_FILA];
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
    size_t memoriaAlocadaDados;
} Fila;

Fila* criarFila();
void destruirFila(Fila* fila);
bool estaFilaVazia(const Fila* fila);
bool estaFilaCheia(const Fila* fila);
bool enfileirar(Fila* fila, const void* dado, size_t tamanhoDado);
void* desenfileirar(Fila* fila, size_t* tamanhoDadoRemovido);
void* verInicio(const Fila* fila);
void* verFim(const Fila* fila);
int obterTamanhoFila(const Fila* fila);
size_t obterMemoriaAlocadaFila(const Fila* fila);
void imprimirFila(const Fila* fila, void (*imprimirDado)(const void*));

#endif