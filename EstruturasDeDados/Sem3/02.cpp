#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
/*Faça um programa que realize o cadastro de contas bancárias com as seguintes informações: número da conta, 
nome do cliente e saldo. O banco permitirá o cadastramento da quantidade de contas que for informado pelo usuário, 
aloque dinamicamente a memória para essa estrutura, não poderá haver mais que uma conta com o mesmo número. Crie o 
menu de opções a seguir.*/

struct Conta {
    int num_conta;
    char nome[50];
    float saldo;
};

Conta *cadastraConta(Conta *conta, int tam){

    conta = (Conta *) (malloc(tam * sizeof(Conta)));
    for (int i = 0; i < tam; i++){
        printf("\nNumero da conta: ");
        scanf("%d", &conta[i].num_conta);
        printf("Nome: ");
        scanf("%s", &conta[i].nome);
        printf("Saldo: ");
        scanf("%f", &conta[i].saldo);
    }
    return conta;
}

void vizualizaTodasDeUmCliente(Conta *conta, int tam) {
    char nome[50];
    scanf("%s", nome);

    for (int i = 0; i < tam; i++){
        if(!strcmp(nome, conta[i].nome)){
            printf("%d", i);
            printf("\nNumero da conta: %d \n", conta[i].num_conta);
            printf("Nome: %s\n", conta[i].nome);
            printf("Saldo: %.2f\n", conta[i].saldo);
        }
    }
    
}
void vizualizaTodas(Conta *conta, int tam) {
    char nome[50];
    scanf("%s", nome);

    for (int i = 0; i < tam; i++){
        
        printf("%d", i);
        printf("\nNumero da conta: %d \n", conta[i].num_conta);
        printf("Nome: %s\n", conta[i].nome);
        printf("Saldo: %.2f\n", conta[i].saldo);
        
    }
    
}

Conta *excluiContas(Conta *conta,int tam){
     int cont2;
     double menor = __FLT_MAX__;
        char nome[50];
        int posicao = 0;

        for (int i = 0; i < tam; i++) {
            if(conta[i].saldo < menor){
                menor = conta[i].saldo;
                posicao = i;
                cont2++;
            }
            
        }
        
        if(menor == conta[posicao].saldo) {
            for (int i = posicao; i < tam; i++) {
                conta[i] = conta[i + 1];
            }
            
        }
    return conta;
}

main() {

    Conta *conta;
    int tam;
    printf("Quantidade de contas: ");
    scanf("%d", &tam);
    
    int op;

    do{

        printf("0) Fechar programa\n");
        printf("1) Cadastrar contas\n");
        printf("2) Visualizar todas as contas de um cliente\n");
        printf("3) Visualizar todas as contas\n");
        printf("4) Excluir a conta com menor saldo\n");

        scanf("%d", &op);

        switch (op)
        {
            case 1:
                conta = cadastraConta(conta, tam);
                break;
            case 2:
                vizualizaTodasDeUmCliente(conta,tam);
                break;
            case 3:
                vizualizaTodas(conta,tam);
                break;
            case 4:
                conta = excluiContas(conta, tam);
                break;
            default:
                break;
        }
    }while(op != 0);

}
