#ifdef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stddef.h>
#define MAX_STACK_SIZE 50

typedef struct{
    void* dado[MAX_STACK-SIZE];
    int maximo;
    int capacidade;
    size_t memoriaAlocada;
}Pilha;

Pilha* criarPilha();
void destruirPilha (Pilha* pilha);
bool pilhaEstaVazia (const Pilha* pilha);
bool PilhaEstaCheia (const Pilha* pilha);
bool Push (Pilha* pilha, const void* dado);
void* Pop (Pilha* pilha);
void* Topo (const Pilha* pilha);
int TamanhodaPilha (const Pilha* pilha);
size_t MemoriaAlocadaDaPilha (const Pilha* pilha);
void ImprimirPilha(const Pilha* pilha);

#endif