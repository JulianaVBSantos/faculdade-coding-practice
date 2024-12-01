#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargas.h"
#include "persistencia.h"

// controle da fila
static Carga *inicio = NULL; // p/ apontar para o primeiro elem. da fila de cargas
static Carga *fim = NULL;

Carga* getInicio() {
    return inicio;
}

void iniciarFila() {
    inicio = NULL;
    fim = NULL;
}

bool insercao(Carga carga) {
    Carga *nova = (Carga *)malloc(sizeof(Carga));
    if (!nova) return false;

    *nova = carga;
    nova->prox = NULL;

    if (!inicio) {
        inicio = nova;
        fim = nova;
    } else {
        fim->prox = nova;
        fim = nova;
    }
    return true;
}

Carga* remocao() {
    if (!inicio) return NULL;

    Carga *atual = inicio;
    Carga *antes = NULL;

    while (atual) {
        if (strcmp(atual->prioridade, "Alta") == 0) break;
        antes = atual;
        atual = atual->prox;
    }

    if (!atual) {
        atual = inicio;
        inicio = inicio->prox;
    } else if (atual == inicio) {
        inicio = atual->prox;
    } else {
        antes->prox = atual->prox;
    }

    if (atual == fim) fim = antes;

    return atual;
}

void exibir() {
    Carga *atual = inicio;
    if (atual == NULL) {
        printf("A fila de cargas esta vazia.\n");
        return;
    }
    
    printf("\n--- Cargas na fila ---\n");
    while (atual) {
        printf("ID: %s | Tipo: %s | Peso: %.2f | Prioridade: %s | Descricao: %s\n",
               atual->id, atual->tipo, atual->peso, atual->prioridade, atual->descricao);
        atual = atual->prox;
    }
}

Carga* buscar(const char *id) {
    Carga *atual = inicio;
    while (atual) {
        if (strcmp(atual->id, id) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void liberarFila() {
    Carga *atual = inicio;
    while (atual) {
        Carga *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    inicio = NULL;
    fim = NULL;
}