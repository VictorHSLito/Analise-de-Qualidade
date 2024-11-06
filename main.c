#include <stdio.h> // Biblioteca usada para entrada e saída de dados
#include <stdlib.h> // Biblioteca usada para alocação dinâmica
#include "produto.h" // Inclui a Biblioteca Produto
#include "carrinho.h" // Inclui a Biblioteca Carrinho
#include "utils.h" // Inclui a Biblioteca de funções auxiliares

/*Programa Principal*/
int main() {
    Produto *p[50]; // Cria um array de 50 espaços da estrutura Produtos
    Carrinho *c[50]; // Cria um array de 50 espaços da estrutura Produtos
    int opc = 0; // Variável auxiliar que fará o controle do loop do programa
    int cont = 0; // Contador que irá operar sobre os index dos Produtos
    int carrinhoIndex = 0; //Contador que irá operar sobre os index do Carrinho

    do
    {
        opc = menu(p, c, &carrinhoIndex, &cont);
    } while (opc == 0);
    
    return 0;
}

