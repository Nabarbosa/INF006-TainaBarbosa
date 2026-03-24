#include<stdio.h>
#include<stdlib.h>

typedef struct Dimensao{
    float largura;
    float altura;
    float profundidade;
} Dimensao;

typedef struct Produto{
    float preco;
    char * nome; // Ponteiro para caracter é um array de caracteres, que é uma string
    char * codigo;
    Dimensao * dimensao;
} Produto;
