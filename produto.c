#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarProduto(Produto *p[], int *index) {
/*Aqui é passado a estrutura Produtos e o contador
    que irá atualizar quando um novo produto for adicionado*/
    int aux = 0;
    p[*index] = (Produto *) malloc(sizeof(Produto)); // Aloca memória para um ponteiro p do tipo Produto, que conterá as informações
    printf("Digite o codigo do produto: ");
    scanf("%d", &p[*index]->codigo);
    aux = verificaProduto(p, index, p[*index]->codigo);
    setbuf(stdin, NULL); // Função que limpa o buffer do teclado após os scanf`s
    if (aux == 0) {
        printf("Digite o nome do produto: ");
        fgets(p[*index]->nome, sizeof(p[*index]->nome), stdin);
        setbuf(stdin, NULL);
        do {
            printf("Digite o preco do produto: ");
            scanf("%f", &p[*index]->preco);
            setbuf(stdin, NULL);
        } while (p[*index]->preco <= 0);
        
        (*index)++; // Atualiza o contador de produtos sempre que um novo produto é cadastrado
        printf("PRODUTO CADASTRADO COM SUCESSO!\n");
    }    
}

void listarProdutos(Produto *p[], int *index) { 
/*Lista todos os produtos cadastrados*/
    if (*index != 0) {
        for (int i = 0; i < *index; i++) {
            printf("\t-------------Produto #%d-------------\n", i);
            printf("Codigo do produto: %d\n", p[i]->codigo);
            printf("Nome do produto: %s", p[i]->nome);
            printf("Preco do produto: %.2f\n", p[i]->preco);
        }
    }
    else {
        printf("Nenhum produto foi cadastrado ainda!\n");
        printf("Tente cadastrar um produto primeiro...\n");
    }
}
void descadastrarProduto(Produto *p[], Carrinho *c[], int *index, int *carrinhoIndex) { 
/*Quando um produto for descadastrado é preciso removê-lo do carrinho também*/
    if (*index != 0) {
        int aux = 0;
        do {
        listarProdutos(p, index);
        printf("Qual produto gostaria de descadastrar: \n");
        scanf("%d", &aux);
        setbuf(stdin, NULL);
        } while (aux < 0 || aux > *index - 1);
        free(p[aux]); // Libera a estrutra selecionada do Produto
        free(c[aux]); // Libera a estrutra selecionada do Carrinho
        p[aux] = NULL;
        c[aux] = NULL;
        (*index)--;
        (*carrinhoIndex)--;
        printf("Produto descadastrado com sucesso!\n");
    }

    else {
        printf("Nao eh possivel remover um produto, pois nenhum foi cadastrado ainda!\n");
    }
}

int verificaProduto(Produto *p[], int *index, int codigo) {
/*Semelhante à função verificaCarrinho, no caso verificará se o produto já está
    cadastrado com o código digitado, caso contrário retorna 0*/
    for (int i = 0; i < *index; i++) {
        if (p[i]->codigo == codigo) {
            printf("Opa! Ja existe um produto com esse codigo! Tente novamente\n");
            return 1;
        }
    }
    return 0;
}
