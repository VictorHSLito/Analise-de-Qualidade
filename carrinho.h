#ifndef CARRINHO_H
#define CARRINHO_H

#include "produto.h"

void comprarProdutos(Produto *p[], Carrinho *c[], int *carrinhoIndex, int *contador);
void visualizarCarrinho(Carrinho *c[], int *carrinhoIndex);
void removerProduto(Carrinho *c[], int *carrinhoIndex);
void finalizarPedido(Carrinho *c[], int *carrinhoIndex);
int verificaCarrinho(Produto *p[], Carrinho *c[], int *carrinhoIndex, int opc);

#endif
