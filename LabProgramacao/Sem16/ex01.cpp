#include <stdio.h>
#define MAX 5
/*Faça um programa que realize o cadastro de contas bancárias com as seguintes informações:número
da conta,nome do cliente e saldo.Obanco permitiráo cadastramento de apenas 15 contas e não poderá 
haver mais que uma conta como mesmo número. Crie o menu de opções a seguir.
Menu de opções:
1. Cadastrar contas.
2. Visualizar todas as contas de determinado cliente.
3. Excluir a conta com menor saldo(supondo a não existência de saldos iguais).
4. Sair.*/

    typedef struct {
        char titular[50];
        int numConta;
        float saldo;
    } Contas;

    Contas cadastro() {

        Contas c;

        printf("\nDigite o nome do titular: \n ► ");
        scanf("%s", &c.titular);
        printf("Digite o numero da conta: \n ► ");
        scanf("%d", &c.numConta);
        printf("Digite o saldo da conta: \n ► R$ ");
        scanf("%f", &c.saldo);
        
        return c;
    }

    void vizualizar(Contas c[MAX]) {

        int op;
        
        do{

        printf("\n╭─────────────────────────────────────────────╮\n");
        printf("│         0. Voltar ao menu anterior:         │\n");
        printf("│        1. Vizualizar todas as contas:       │\n");
        printf("│ 2. Vizualizar as contas de um unico cliente:│\n");
        printf("╰─────────────────────────────────────────────╯\n\n");

        scanf("%d", &op);

        switch(op) {
            case 1:
                for (int i = 0; i < MAX; i++) {
                printf("\nTitular: %s\n", c[i].titular);
                printf(" • Numero da conta: %d\n", c[i].numConta);
                printf(" • Saldo R$: %.2f\n", c[i].saldo);

                }
            break;
            case 2:
                char nome[50];
                printf("\nDigite o nome do titular: \n ► ");
                scanf("%s", nome);
                for (int i = 0; i < MAX; i++) {
                    for (int j = 0; j < MAX; j++){

                        if(c[i].titular[j] == nome[j]){
                            printf("\nTitular: %s\n", c[i].titular);
                            printf(" • Numero da conta: %d\n", c[i].numConta);
                            printf(" • Saldo R$: %.2f\n", c[i].saldo);
                        }
                    }
                }
            break;
        }

        }while(op != 0);


    }


    main() {
        
        
        int op;
        Contas conta[MAX];
        int cont = 0;

        do {
            printf("\n╭─────────────────────────────────────────────╮\n");
                printf("│               Menu de opções:               │\n");
                printf("│          0. Finalizar programa:             │\n");
                printf("│           1. Cadastrar contas:              │\n");
                printf("│      2. Visualizar contas dos clientes:     │\n");
                printf("│     3. Excluir a conta com o menor saldo:   │\n");
                printf("╰─────────────────────────────────────────────╯\n\n");

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
                        break;
                    }else{

                        vizualizar(conta);
                        break;
                    }
                
            }
            
        }while(op != 0);




    }