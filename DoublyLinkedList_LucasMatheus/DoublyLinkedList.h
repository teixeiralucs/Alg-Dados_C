#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct No{
    void* dado;
    struct No* proximo;
    struct No* anterior;    
    } No;
typedef struct ListaDuplamenteEncadeada {
    No* inicio;
    No* fim;
    int tamanho;
    size_t memoriaAlocada;
} ListaDuplamenteEncadeada; 

ListaDuplamenteEncadeada* criarLista();
void destruirLista(ListaDuplamenteEncadeada* lista);
bool listaEstaVazia(const ListaDuplamenteEncadeada* lista);
bool inserirNoInicio (ListaDuplamenteEncadeada* lista, const void* dado, size_t tamanhoDoDado);
bool inserirNoFim(ListaDuplamenteEncadeada* lsita, const void* dado, size_t tamanhoDoDado);
void* removerDoInicio(ListaDuplamenteEncadeada* lista);
void* removerDoFim(ListaDuplamenteEncadeada* lista);
void* pegarInicio(const ListaDuplamenteEncadeada* lista);
void* pegarFim(const ListaDuplamenteEncadeada* lista);
int tamanhoDaLista(const ListaDuplamenteEncadeada* lista);
size_t MemoriaAlocadaDaLista (const ListaDuplamenteEncadeada* lista);
void imprimirLista(const ListaDuplamenteEncadeada* lista, void (*imprimirDado)(const void*));

#endif 