#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    Produto item;
    int quantidade;
} Carrinho;

void cadastrarProduto(Produto *p[], int *index);
void listarProdutos(Produto *p[], int *index);
void descadastrarProduto(Produto *p[], Carrinho *c[], int *index, int *carrinhoIndex);
int verificaProduto(Produto *p[], int *index, int codigo);

#endif
