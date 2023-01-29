
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lista.h"
#define MAX 5

Produtos produtos[] = {
{1, "Arroz", 12.5},
{2, "Feijão", 15.0},
{3, "Carne", 18.0},
{4, "Suco", 7.5}
};


#define QUEUE_SIZE 5
char chocolateQueue[QUEUE_SIZE][10]={"Alpino","Nestle","Choco","Nutella","Batom"};
int head = 0;
int tail = 0;

void DaChocolate(void) {
if (head == tail) { // Lista vazia, preencher novamente
head = 0;
tail = 0;
// Adicionar os chocolates na ordem desejada
strcpy(chocolateQueue[tail++], "Alpino");
strcpy(chocolateQueue[tail++], "Nestle");
strcpy(chocolateQueue[tail++], "Choco");
strcpy(chocolateQueue[tail++], "Nutella");
strcpy(chocolateQueue[tail++], "Batom");
}
printf("\n\nO cliente recebeu um chocolate %s\n", chocolateQueue[head++]);
}




void InsereProd(Lista *L, int mesa, int prod){

Node *ptr = L->inicio;
float valor;
char nomeProduto[50];

// encontra a mesa na lista
while (ptr != NULL && ptr->info != mesa) {
    ptr = ptr->prox;
}

if (ptr != NULL) {
    // encontra o produto no array de produtos
    for (int i = 0; i < sizeof(produtos)/sizeof(Produtos); i++) {
        if (produtos[i].cod == prod) {
            valor = produtos[i].valor;
            strcpy(nomeProduto, produtos[i].nomeProduto);
            break;
        }
    }

    comanda *novaComanda = (comanda *)malloc(sizeof(comanda));
    novaComanda->cod = prod;
    novaComanda->valor = valor;
    novaComanda->proxCom = ptr->Comanda;
    ptr->Comanda = novaComanda;
}

}

void Inicializa(Lista *L){
L->inicio = NULL;
L->fim = NULL;
}

void Insere(Lista *L, int x) {
    Node *novo = (Node *)malloc(sizeof(Node));

    if(novo == NULL){
        printf("Erro ao alocar");
        return;
    } else {
        Node *temp = L->inicio;
        while(temp != NULL){
            if(temp->info == x){
                printf("Mesa existente");
                return;
            }
            temp = temp->prox;
        }

        novo->info = x;
        novo->prox = NULL;
        novo->Comanda = (comanda *)malloc(sizeof(comanda));
        novo->Comanda->cod = 0;
        novo->Comanda->valor = 0;
        novo->Comanda->proxCom = NULL;

        printf("Insira o nome do cliente:");
        scanf("%s", novo->nome_cliente);

        if(L->inicio==NULL){
            L->inicio = novo;
            L->fim = novo;
        } else {
            L->fim->prox = novo;
        }
        L->fim = novo;
    }
}
int Desempilha(Lista *L){
Node *ptr = L->inicio;
int dado;

if(L->inicio == NULL){
    printf("Lista vazia");
}else{

    L->inicio = ptr->prox;
    ptr->prox = NULL;
    dado = ptr->info;
    free(ptr->Comanda);
    free(ptr);

}
return dado;

}

int DesempilhaMesa(Lista *L, int mesa){

    Node *ptr = L->inicio;
    Node *anterior = NULL;

int dado;

while (ptr != NULL && ptr->info != mesa) {
    anterior = ptr;
    ptr = ptr->prox;
}

if (ptr == NULL) {
    printf("Mesa não existe");
} else {
    if (anterior == NULL) {
        L->inicio = ptr->prox;
    } else {
        anterior->prox = ptr->prox;
    }
    dado = ptr->info;


    comanda *auxiliar = ptr->Comanda;

    if(auxiliar->proxCom==NULL){

        float recebe;
        int range = rand();
        recebe = recebe + auxiliar->valor;
        printf("Sua conta ficou em %f \n Volte sempre, ficamos felizes em atender você \n Você recebeu um chocolate de brinde %d", recebe);

    }

    while(auxiliar->proxCom!=NULL){

        float recebe2;
        recebe2 = recebe2 + auxiliar->valor;
        auxiliar=auxiliar->proxCom;

        if(auxiliar->proxCom==NULL){

            printf("Sua conta ficou em %f", recebe2);

        }


    }






    free(ptr->Comanda);
    free(ptr);
}

return dado;

}

void Imprime(Lista *L){
Node *ptr = L->inicio;

while (ptr != NULL) {
    printf("Mesa: %d\n", ptr->info);
    printf("Cliente: %s\n", ptr->nome_cliente);
    comanda *temp = ptr->Comanda;
    while (temp != NULL) {
        for (int i = 0; i < sizeof(produtos)/sizeof(Produtos); i++) {
            if (temp->cod == produtos[i].cod) {
                printf("Produto: %s\n", produtos[i].nomeProduto);
                printf("Valor: %.2f\n", temp->valor);
                break;
            }
        }
        temp = temp->proxCom;
    }
    ptr = ptr->prox;
}

}
