#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct No {
    void* dado;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
    int tamanho;
    size_t memoriaAlocada;
} Pilha;

Pilha* criarPilha();
void destruirPilha(Pilha* pilha);
bool empilhar(Pilha* pilha, const void* dado, size_t tamanhoDado);
void* desempilhar(Pilha* pilha);
void* verTopo(const Pilha* pilha);
bool estaPilhaVazia(const Pilha* pilha);
int obterTamanhoPilha(const Pilha* pilha);
size_t obterMemoriaAlocadaPilha(const Pilha* pilha);
void imprimirPilha(const Pilha* pilha, void (*imprimirDado)(const void*));

#endif