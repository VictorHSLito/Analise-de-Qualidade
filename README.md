# Sistema de Mercado em C
Este repositório é um sistema desenvolvido em C que simula o funcionamento de um mercado. Este sistema permite o cadastro de produtos, adição de itens ao carrinho, visualização dos produtos no carrinho e a finalização de compras.

## Estruturação do Código
Este sistema é composto por vários arquivos, organizados de forma modular. O arquivo principal é o **main.c**, enquanto os arquivos auxiliares são responsáveis por diversas funcionalidades específicas:

- **produto.h** e **produto.c**: Contêm as definições e implementações relacionadas ao gerenciamento de produtos.

- **carrinho.h** e **carrinho.c**: Gerenciam as operações do carrinho de compras.

- **utils.h** e **utils.c**: Contêm funções utilitárias auxiliares que são responsáveis para validação de dados e funcionamento do programa

A estrutura modular facilita a manutenção e expansão do sistema, permitindo uma organização clara do código.

## Como Executar?
Compile o código com um compilador para linguagem C/C++ da seguinte forma:
```bash 
gcc -o marketsystem main.c carrinho.c produto.c utils.c
```
Após compilação de todos os arquivos, execute o seguinte comando:
```bash
.\marketsystem.exe
```

## Sugestões
Estarei aberto a qualquer tipo de sugestão acerca do código, caso queira contribuir com o projeto, solicite um _Pull Request_.