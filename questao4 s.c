#include <stdio.h>
#include <stdlib.h>
#include <string.h>


   
     
#include <stdio.h>

struct ContaBancaria
{
    int numerodaConta;
    char Titular[500];
    float saldo;
    char tipodeConta[200];
};

void depositar(struct ContaBancaria *conta, float valor)
{
    if (valor > 0)
    {
        conta->saldo += valor;
        printf("Deposito de R$ %.2f realizado com sucesso.\n", valor);
    }
    else
    {
        printf("Valor invalido para depósito.\n");
    }
}

void sacar(struct ContaBancaria *conta, float valor)
{
    if (valor > 0 && valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso.\n", valor);
    }
    else
    {
        printf("Valor invalido para saque ou saldo insuficiente.\n");
    }
}

void Saldo(struct ContaBancaria conta)
{
    fflush(stdin);
    printf("Saldo atual: R$ %.2f\n", conta.saldo);
    printf("conta numero %d\n", conta.numerodaConta);
    printf("titular: %s\n", conta.Titular);
    printf("tipo da conta: %s\n", conta.tipodeConta);
}

int main()
{

    struct ContaBancaria Conta;
    int opcao;
    float valor;

    printf("digite o numero da conta: ");
    scanf("%d", &Conta.numerodaConta);

    printf("digite o nome do titular: ");
    scanf("%s", &Conta.Titular);

    printf("qual o tipo da conta: ");
    scanf("%s", &Conta.tipodeConta);

    fflush(stdin);

    do
    {
        printf("\nMenu:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Imprimir Saldo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("Digite o valor do deposito: ");
            scanf("%f", &valor);
            depositar(&Conta, valor);
            break;
        case 2:
            printf("Digite o valor do saque: ");
            scanf("%f", &valor);
            sacar(&Conta, valor);
            break;
        case 3:
            Saldo(Conta);
            break;
        case 4:
            printf("fechando programa.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

return 0;
}