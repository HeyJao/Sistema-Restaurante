#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lista.h"
#define MAX 5

int main() {


setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
Node *n;
Lista L;

Inicializa(&L);

int opcao, mesa, valor;


printf("--------------------------------------\n");
printf("                 R E S T A U R A N T E\n");
printf("                         D A\n");
printf("                 C O M P U T A C A O\n");
printf("--------------------------------------\n");
while (1) {



printf("\n\nEscolha o numero de preferencia\n\n");printf("1 - Inserir mesa"); printf("\n");printf("2 - Inserir produto\n");
printf("3 - Remover mesa\n");printf("4 - Imprimir lista\n");printf("5 - Sair\n"); scanf("%d", &opcao);

switch (opcao) {

case 1: printf("Digite o numero da mesa: "); scanf("%d", &mesa);

if(mesa!=1 && mesa !=2 && mesa!=3 && mesa!=4 && mesa!=5){

    printf("\n\nMesa invalida(apenas mesas: 1, 2, 3, 4, 5)\n\n");
}else{

    Insere(&L, mesa);
}

break;

case 2: printf("Digite o numero da mesa: "); scanf("%d", &mesa);

printf("Digite o número referente ao produto \n\n Arroz - 1  Feijão - 2  Carne - 3  Suco - 4\n"); scanf("%d", &valor); InsereProd(&L, mesa, valor);   break;

case 3:
    printf("Digite o numero da mesa: ");
    scanf("%d", &mesa);
    DesempilhaMesa(&L, mesa);

    DaChocolate();


 break;

case 4: Imprime(&L); break;

case 5: return 0;
}
}
return 0;
}
