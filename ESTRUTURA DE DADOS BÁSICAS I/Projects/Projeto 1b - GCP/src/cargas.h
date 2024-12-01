#ifndef CARGAS_H
#define CARGAS_H

#include <stdbool.h>

typedef struct Carga {
char id[10];
char tipo[50];
float peso;
char prioridade[10];
char descricao[100];
struct Carga *prox;
} Carga;

Carga* getInicio();
void iniciarFila();
bool insercao(Carga carga);
Carga* remocao();
Carga* buscar(const char *id);
void exibir();
void liberarFila();

#endif