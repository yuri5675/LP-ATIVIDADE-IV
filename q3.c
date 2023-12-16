#include <stdio.h>
#include <stdlib.h>

struct produto
{
    char nome[200];
    float preco;
    int quantidade;
};

float totalv(struct produto box){
    return box.preco*box.quantidade;
};

void comprar(struct produto *box, int quantidade)
{
    if (quantidade > 0 && quantidade <= box->quantidade)
    {
        box->quantidade -= quantidade;
        printf("Compra realizada com sucesso!\n");
    }
    else
    {
        printf("Quantidade invalida ou insuficiente em estoque.\n");
    }
}


int main (){

int opcao;
int quantidade;

struct produto box;

do
{
    printf("\nMENU DE OPCAO");
    printf("\n1 ADICIONAR PRODUTO");
    printf("\n2 REALIZAR UMA COMPRA");
    printf("\n3 CONSULTAR ESTOQUE");
    printf("\n4 Sair do Programa");

    printf("\n\nDigite a opcao:");
    scanf("%d",&opcao);

    fflush(stdin);
    
    switch (opcao)
    {
    case 1:
        
        printf("\nAdicione o Produto");
        printf("\nDigite o nome do produto:");
        gets(box.nome);

        fflush(stdin);

        printf("\nDigite o preco do produto:");
        scanf("%f",&box.preco);

        fflush(stdin);

        printf("\nDigite a quantidade do produto:");
        scanf("%d",&box.quantidade);

        totalv(box);
        system("cls");
        break;
    case 2:
            printf("Digite o produto que voce deseja comprar:");
            scanf("%d",&quantidade);
            comprar(&box, quantidade);

        break;    
    case 3 :
        
        printf("\nEstoque de Mercadoria");
        printf("\n|Nome do produto  |Quantidade do | Preco do|Valor total|");
        printf("\n|       %s        |     %d       |  %.1f   |%.1f    |",box.nome,box.quantidade,box.preco,totalv(box));      
        break;
    default:
      printf("\nEssa opcao nao Tente Novamente!");
        break;
    }
   
} while (opcao != 4 );

return 0;
}