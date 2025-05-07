#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct No {
    void* dado;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
    size_t memoriaAlocada;
} Fila;

Fila* criarFila();
void destruirFila(Fila* fila);
bool enfileirar(Fila* fila, const void* dado, size_t tamanhoDado);
void* desenfileirar(Fila* fila);
void* verInicio(const Fila* fila);
void* verFim(const Fila* fila);
bool estaFilaVazia(const Fila* fila);
int obterTamanhoFila(const Fila* fila);
size_t obterMemoriaAlocadaFila(const Fila* fila);
void imprimirFila(const Fila* fila, void (*imprimirDado)(const void*));

#endif