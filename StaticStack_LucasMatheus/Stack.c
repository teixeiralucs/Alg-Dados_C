#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pilha* criarPilha(){
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (!pilha){
        perror ("Não foi possivel alocar memória");
        return NULL;
    }
    pilha -> maximo = -1;
    pilha -> capacidade = MAX_STACK_SIZE;
    pilha -> memoriaAlocada = sizeof(Pilha);
    return pilha;
}

void destruirPilha (Pilha* pilha){
    if (!pilha){
        return;
    }
    while (!pilhaEstaVazia(pilha)){
        void* dado = Pop(pilha);
        free(dado);
    }
    free(pilha);
}

bool pilhaEstaVazia (const Pilha* pilha){
    return pilha == NULL || pilha -> maximo == -1;
}

bool PilhaEstaCheia (const Pilha* pilha){
    return pilha != NULL && pilha -> maximo == pilha -> capacidade -1;
}

bool Push (Pilha* pilha, const void* dado){
    if (!pilha || pilhaEstaVazia(pilha)){
        printf(stderr, "Erro: A pilha está cheia ou vazia\n");
        return false;
    }
    if(!dado){
        printf(stderr, "Erro: Não há dado para inserir");
        return false;
    }
    char* copiarDado = (char*)malloc(sizeof(char));
    if(!copiarDado){
        perror("Erro ao alocar memória para o dado");
        return false;
    }
    *copiarDado = *(char*)dado;

    pilha -> maximo++;
    pilha -> dado -> maximo = copiarDado;
    pilha -> memoriaAlocada += sizeof(char);

    return true;
}

void* Pop(Pilha* pilha){
    if (!pilha || pilhaEstaVazia(pilha)){
        return NULL;
    }
    void* dadoPonteiro = pilha -> dado -> maximo;
    pilha -> dado -> maximo = NULL;
    pilha -> maximo--;
    pilha memoriaAlocada -= sizeof(char);

    return dadoPonteiro;
}

void* Topo (const Pilha* pilha){
    if(!pilha || pilhaEstaVazia(pilha)){
        return NULL;
    }
    return pilha -> dado -> maximo;
}

int TamanhodaPilha (const Pilha* pilha){
    if (!pilha){
        return 0;
    }
    return pilha -> maximo + 1;
}

size_t MemoriaAlocadaDaPilha (const Pilha* pilha){
    if (!stack){
        return 0;
    }
    return sizeof(Pilha) + (TamanhodaPilha(pilha) + sizeof(char));
}

void ImprimirPilha(const Pilha* pilha){
    printf("Pilha: ");
    if (pilhaEstaVazia(pilha));
    printf("Vazia\n");
    return;
    
    for (int i = pilha -> maximo; i >=0; i--){
        printF("%c", *(char*)(pilha -> dado[i]));
        if (i> 0){
            printf("->");
        }
    }
    printf("\n");
}







