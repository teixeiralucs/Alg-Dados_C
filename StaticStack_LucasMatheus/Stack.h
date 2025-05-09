#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

#define TAMANHO_MAX_PILHA 50

typedef struct {
    void* dados[TAMANHO_MAX_PILHA];
    int topo;
    int capacidade;
} Pilha;

Pilha* criarPilha();
void destruirPilha(Pilha* pilha);
bool estaPilhaVazia(const Pilha* pilha);
bool estaPilhaCheia(const Pilha* pilha);
bool empilhar(Pilha* pilha, const void* dado);
void* desempilhar(Pilha* pilha);
void* verTopo(const Pilha* pilha);
int obterTamanhoPilha(const Pilha* pilha);
size_t obterMemoriaAlocadaPilha(const Pilha* pilha);
void imprimirPilha(const Pilha* pilha);

#endif