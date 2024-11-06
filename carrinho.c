#include "carrinho.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void comprarProdutos(Produto *p[], Carrinho *c[], int *carrinhoIndex, int *index) { 
    /*Aqui são passados 4 parâmetros, o da estrutura Produtos, Carrinho, contador do carrinho
    e o contador dos produtos*/

    c[*carrinhoIndex] = (Carrinho *) malloc(sizeof(Carrinho)); // Aloca memória para um ponteiro da estrutura Carrinho
    int opc = 999; // Variável que será usada para escolher o produto, inicia com um valor arbirtrários apenas para não gerar erro
    int quantidade = 0; // Variável que será usada para escolhe a quantidade

    if (*index != 0) {
        int aux = 0;
        printf("Qual produto gostaria de comprar? \n");
        listarProdutos(p, index); // Somente foi passado como parametro a estrutura Produto e o contador dos produtos para que chamasse a função
        do {
            char input[10];
            printf("Sua escolha [Digite o Index do Produto]: ");
            fgets(input, sizeof(input), stdin);

            if (validaEntrada(input) != 0) {
                printf("Digite apenas numeros!\n");
            }
            else {
                opc = atoi(input);
                if (opc > *index - 1 || opc < 0) {
                printf("Voce tentou comprar um produto inexistente! Tente novamente!\n");
                }
            }
            
        } while (opc > *index - 1 || opc < 0); // Impede o usuário de digitar uma opção fora do index    
        
        aux = verificaCarrinho(p, c, carrinhoIndex, opc);
        if (aux == 0) {
            c[*carrinhoIndex]->item = *p[opc]; // Aqui estarei dizendo que o ponteiro C apontará para o ponteiro da estrutura Produto de acordo com opção escolhida
            do {
                char input[10];
                printf("Qual a quantidade? ");
                fgets(input, sizeof(input), stdin);
                setbuf(stdin, NULL);
            
                if (validaEntrada(input) != 0) {
                    printf("Numero invalido!!!!!!!\n");
                }
                else {
                    quantidade = atoi(input);
                }
            } while (quantidade <= 0); // Impede o usuario de digitar uma quantidade negativa ou zero
            c[*carrinhoIndex]->quantidade = quantidade;
            (*carrinhoIndex)++; // Atualiza o contador do carrinho sempre que um novo produto é colocado no carrinho
            printf("PRODUTO ADICIONADO AO CARRINHO COM SUCESSO!\n");
        }
    }
    else {
        printf("Nao eh possivel comprar! Nenhum produto foi cadastrado ainda!\n");
        printf("Tente cadastrar um produto primeiro...\n");
    }
}
void visualizarCarrinho(Carrinho *c[], int *carrinhoIndex) { 
/*Função que mostrará todos os itens contidos no Carrinho*/
    if (*carrinhoIndex != 0) {
        printf("\t-------------Itens do Carrinho-------------\n");
        for (int i = 0; i < *carrinhoIndex; i++) {
        printf("\tItem: %s", c[i]->item.nome);
        printf("\tQuantidade do item: %d\n", c[i]->quantidade);
        printf("\tPreco do Produto: %.2f\n", c[i]->item.preco);
        }
    //temNoCarrinho(c, carrinhoIndex); // Está é uma função auxiliar para saber se já algum produto no carrinho, caso o seu carrinho esteja muito cheio
    }
    else {
        printf("Carrinho vazio!\n");
    }
}
void removerProduto(Carrinho *c[], int *carrinhoIndex) { 
 /*Essa função funciona de forma parecida com a função descadastrarProduto
    a diferença sútil é que ela apenas remove o produto do carrinho sem "destruí-lo"*/
    if (*carrinhoIndex != 0) {
        int aux = 0;
        do {
            visualizarCarrinho(c, carrinhoIndex);
            printf("Qual produto gostaria de remover do carrinho? ");
            scanf("%d", &aux);
            setbuf(stdin, NULL);
        } while (aux < 0 || aux > *carrinhoIndex - 1);
        free(c[aux]);
        c[aux] = NULL;
        (*carrinhoIndex)--;
    }
    else {
        printf("Nao eh possivel remover um produto, pois o seu carrinho esta vazio!\n");
    }
}
void finalizarPedido(Carrinho *c[], int *carrinhoIndex) {
/*Essa função mostrará o total gerado pelas compras dos produtos*/
    visualizarCarrinho(c, carrinhoIndex);
    if (*carrinhoIndex != 0) {
        printf("\t-------------Total a Pagar-------------\n");
        float total = 0; 
        for (int i = 0; i < *carrinhoIndex; i++) { // Loop que irá interar por todos os itens do carrinho
            total += c[i]->quantidade*c[i]->item.preco; // Fará a multiplicação da quantidade dos itens pelo respectivo preço
        }

        printf("\tPreco Final: %.2f\n", total);
        printf("\tEsvaziando carrinho...\n");

        for (int i = 0 ; i < *carrinhoIndex; i++) {
            free(c[i]); // Esvazia a memória alocada para o carrinho
            c[i] = NULL; // Faz com que não haja ponteiros soltos no programa
        }
        (*carrinhoIndex) = 0; // Atualiza o index do carrinho para 0

        printf("\tCarrinho esvaziado com sucesso!\n");
    }
    else {
        printf("Nao ha como fechar pedido, pois o seu carrinho esta vazio!\n");
    }
}
int verificaCarrinho(Produto *p[], Carrinho *c[], int *carrinhoIndex, int opc) { 
/*Adicionei essa função que irá verificar se o produto que o usuário está tentando
    comprar já está no carrinho, caso esteja, ele adicionará mais quantidades dele*/
    for (int i = 0; i < *carrinhoIndex; i++) { // Loop que percorrerar toda a estrutura do Carrinho
            if (c[i]->item.codigo == p[opc]->codigo) {
                int aux = 0;
                printf("Produto ja esta no carrinho!\n");
                do {
                    printf("O que deseja fazer:\n");
                    printf("1 - Adicionar mais quantidade do produto\n");
                    printf("2 - Remover quantidade do produto\n");
                    printf("3 - Sair\n");
                    printf("Sua escolha: ");
                    scanf("%d", &aux);
                    setbuf(stdin, NULL);
                    if (aux == 1 || aux == 2) {
                        int quant = 0;
                        switch (aux) {                        
                        case 1:                            
                            do {
                                printf("Quanto gostaria de adicionar? ");
                                scanf("%d", &quant);
                                setbuf(stdin, NULL);
                            } while (quant <= 0);                           
                            c[i]->quantidade += quant;
                            return 1; // Retorna 1 para que não haja continuidade na função comprarProduto
                        case 2: 
                            do {
                                printf("Quanto gostaria de remover? ");
                                scanf("%d", &quant);
                                setbuf(stdin, NULL);
                            } while (quant > c[i]->quantidade);
                            c[i]->quantidade -= quant;
                            return 1; // Retorna 1 para que não haja continuidade na função comprarProduto
                        case 3:
                            return 1; // Retorna 1 para que não haja continuidade na função comprarProduto
                        }
                    }
                } while (aux < 0);
                return 1;
            }
        }
    return 0; // Caso o produto não se encontre no carrinho ainda, ele retornará 0 e será adicionado normalmente
}
