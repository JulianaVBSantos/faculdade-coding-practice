#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "estoque.h"

void carregarEstoque(Estoque *estoque, const char *caminhoArquivo);
void salvarEstoque(Estoque *estoque, const char *caminhoArquivo);

#endif
