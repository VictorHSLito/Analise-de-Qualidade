#include "utils.h"
#include "produto.h"
#include "carrinho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menu(Produto *p[], Carrinho *c[], int *carrinhoIndex, int *contador) { 
    /*Aqui todas as variáveis foram passadas por referência
    pois o controle de valores delas serão todos feitos através das
    funções e não da função main*/
    char input[10]; // String que previnirá do usuário digitar uma opção fora do escopo
    int opc = 0; // Variável auxiliar que será usada para o switch-case
    do {   
        printf("\tBem vindo(a) ao menu! O que gostaria de fazer?\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Comprar Produtos\n");
        printf("4 - Visualizar Carrinho\n");
        printf("5 - Fechar Pedido\n");
        printf("6 - Descasdatrar Produto\n");
        printf("7 - Remover Produto do Carrinho\n");
        printf("8 - Sair\n");
        
        fgets(input, sizeof(input), stdin);
        if (validaEntrada(input) != 0) {
            printf("Numero digitado invalido!\n");
            continue;
        }
        opc = atoi(input);
        if (opc < 1 || opc > 8 ) {
            printf("Voce digitou uma opcao invalida! Tente novamente\n\n");
        }
        else {
            switch (opc)
            {
            case 1:
                cadastrarProduto(p, contador);
                break;
            case 2:
                listarProdutos(p, contador);
                break;
            case 3:
                comprarProdutos(p, c, carrinhoIndex, contador);
                break;
            case 4:
                visualizarCarrinho(c, carrinhoIndex);
                break;
            case 5:
                finalizarPedido(c, carrinhoIndex);
                break;    
            case 6:
                descadastrarProduto(p, c, contador, carrinhoIndex);
                break;
            case 7:
                removerProduto(c, carrinhoIndex);
                break;
            case 8:
                return -1;  // Retorna -1 para que o loop do-while na função main pare de executar
                break;
            }
        }
    } while (opc < 1 || opc > 8);
    return 0; // Retorna 0 para que o loop do-while na função main continue executando
}

int validaEntrada(char *string) { 
/*Remover o '\n' do final da string, se houver*/
    size_t len = strlen(string);
    if (string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }

    // Verificar se todos os caracteres são dígitos
    for (unsigned i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i])) {
            return 1;  // Retorna 1 se não for um número
        }
    }

    return 0;  // Retorna 0 se a string for válida (somente números)
}



