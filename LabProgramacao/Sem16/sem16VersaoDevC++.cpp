#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 4 //Alterar o numero maximo de contas

/*Faca um programa que realize o cadastro de contas bancarias com as seguintes informcoes:numero
da conta,nome do cliente e saldo.Obanco permitir�o cadastramento de apenas 15 contas e nao podera 
haver mais que uma conta como mesmo n�mero. Crie o menu de opcoes a seguir.
Menu de opcoes:
1. Cadastrar contas.
2. Visualizar todas as contas de determinado cliente.
3. Excluir a conta com menor saldo(supondo a n�o exist�ncia de saldos iguais).
4. Sair.*/

    typedef struct {
        char titular[50];
        int numConta;
        float saldo;
    } Contas;

    Contas cadastro() {

        Contas c;

        printf("\nDigite o nome do titular: \n  ");
        scanf("%s", &c.titular);
        printf("Digite o numero da conta: \n  ");
        scanf("%d", &c.numConta);
        printf("Digite o saldo da conta: \n  R$ ");
        scanf("%f", &c.saldo);
        
        return c;
    }

    void vizualizar(Contas c[MAX], int cont) {

        int op;
        
        do{

        printf("\n|---------------------------------------------|\n");
        printf("|         0. Voltar ao menu anterior:         |\n");
        printf("|        1. Vizualizar todas as contas:       |\n");
        printf("| 2. Vizualizar as contas de um unico cliente:|\n");
        printf("|---------------------------------------------|\n\n");

        scanf("%d", &op);

        switch(op) {
            case 1:
            if(cont == 0){

                for (int i = 0; i < MAX; i++) {
                printf("\nTitular: %s\n", c[i].titular);
                printf("  Numero da conta: %d\n", c[i].numConta);
                printf("  Saldo R$: %.2f\n", c[i].saldo);

                }
            }else{

                for (int i = 0; i < cont; i++) {
                printf("\nTitular: %s\n", c[i].titular);
                printf("  Numero da conta: %d\n", c[i].numConta);
                printf("  Saldo R$: %.2f\n", c[i].saldo);

                }
            }
            break;
            case 2:
                char nome[50];
                printf("\nDigite o nome do titular: \n ");
                scanf("%s",nome);
                for (int i = 0; i < MAX; i++) {
                        if(strcmp (c[i].titular, nome) == 0){
                            printf("\nTitular: %s\n", c[i].titular);
                            printf("  Numero da conta: %d\n", c[i].numConta);
                            printf("  Saldo R$: %.2f\n", c[i].saldo);
                        }
                }
            break;
            case 0:
            break;
            default:
                printf("\nOpcao Invalida!");
        }

        }while(op != 0);
    }



    main() {
        
        setlocale(LC_ALL, "Portuguese");
        
        int op;
        Contas conta[MAX];
        int cont = 0, cont2 = 0;

        do {
            printf("\n|---------------------------------------------|\n");
                printf("|               Menu de opcoes:               |\n");
                printf("|          0. Finalizar programa:             |\n");
                printf("|           1. Cadastrar contas:              |\n");
                printf("|      2. Visualizar contas dos clientes:     |\n");
                printf("|     3. Excluir a conta com o menor saldo:   |\n");
                printf("|---------------------------------------------|\n\n");

            scanf("%d", &op);

            switch(op){
                case 1:
                    cont++;
                    for(int i = 0; i < MAX; i++) {
                        conta[i] = cadastro();
                    }
                break;
                case 2:
                    if(cont == 0){
                        printf("\nNenhuma conta cadastrada ate o momento!\n");
                        break;
                    }else{

                        vizualizar(conta, cont2);
                        break;
                    }
                case 3:
                    cont2 = 0;
                    if(cont == 0){
                        printf("\nNenhuma conta cadastrada ate o momento!\n");
                        break;
                    }else{
                        
                        double menor = __FLT_MAX__;
                        char nome[50];
                        int posicao = 0;

                        for (int i = 0; i < MAX; i++) {
                            if(conta[i].saldo < menor){
                                menor = conta[i].saldo;
                                posicao = i;
                                cont2++;
                            }
                            
                        }


                        if(menor == conta[posicao].saldo) {
                            for (int i = posicao; i < MAX; i++) {
                                conta[i] = conta[i + 1];
                            }
                            
                        }

                        conta[cont2].saldo = __FLT_MAX__;   
                        
                    }
                    case 0:
                    break;
                    default:
                        printf("\nOpcao Invalida!");
                        break;
            }
        }while(op != 0);




    }
