#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



typedef struct Produtos{
    int cod;
    char nomeProduto[50];
    float valor;
}Produtos;



typedef struct comanda {

    int cod;
    float valor;
    struct comanda *proxCom;

}comanda;

typedef struct Node {

    int info;
    char nome_cliente[50];
    struct comanda *Comanda;
    struct Node *prox;

}Node;

typedef struct Lista {

    struct Node *inicio;
    struct Node *fim;

}Lista;



void DaChocolate(void);

void InsereProd(Lista *L, int mesa, int prod);

void Insere(Lista *L, int x);

int Desempilha(Lista *L);

int DesempilhaMesa(Lista *L, int mesa);

void Imprime(Lista *L);


#endif // LISTA_H_INCLUDED
