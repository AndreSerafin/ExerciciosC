#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    float info;
    Node *prox;
};

Node *criaNode();
void addInicio(Node **prim, float info);
void addMeio(Node **prim, int pos, float info);
void addFinal(Node **prim, float info);
void vizualizaLista(Node *prim);

main() {

    Node *lista = NULL;
    
    int op;
    
    do{ 
        system("cls");
        printf("0. Encerrar programa: \n");
        printf("1. Inserir nota no inicio da lista: \n");
        printf("2. Inserir nota no final da lista: \n");
        printf("3. Vizualizar lista: \n");
        printf("4. teste: \n");

        scanf("%d", &op);

        switch (op) {
            float nota;

            case 0:
                break;
            case 1:
                printf("Digite a nota: ");
                scanf("%f", &nota);
                addInicio(&lista, nota);
                break;
            
            case 2:
                printf("Digite a nota: ");
                scanf("%f", &nota);
                addFinal(&lista, nota);
                break;
            case 3:
                vizualizaLista(lista);
                getche();
                break;
            case 4:
                addInicio(&lista,1);
                addInicio(&lista,2);
                addMeio(&lista, 1,4);
            default:
                printf("Opcao invalida!\n\n");
                break;
            }

    }while(op != 0);


}

Node *criaNode() {
    Node *novoNode = (Node *) malloc(sizeof(Node));
    return novoNode;
}

void addInicio(Node **prim, float info) {
    Node *novoNode = criaNode();
    novoNode->info = info;
    novoNode->prox = *prim;
    *prim = novoNode;
}

// void addMeio(Node **prim, int pos, float info) {
//     Node *novoNode = criaNode();
//     novoNode->info = info;
//     novoNode->prox = NULL;
//     int tam = 0;
//     if(*prim == NULL) {
//         *prim = novoNode;
//     }else {
//         Node *tmp = *prim;
//         for(inti=2; i<=pos-1; i++)
//         {
//             tmp = tmp->prox;
 
//             if(tmp == NULL)
//                 break;
//         }
//         if(tmp != NULL)
//         {
//             novoNode->prox = tmp->prox;  //Links the address part of new node
//             tmp->prox = novoNode;   
//         }
//         else
//         {
//             printf(" Insert is not possible to the given position.\n");
//         }
//     }
// }

void addFinal(Node **prim, float info) {
    Node *novoNode = criaNode();
    novoNode->info = info;
    novoNode->prox = NULL;
    if(*prim == NULL) {
        *prim = novoNode;
    }else {
        Node *ultimoNode = *prim;
        while(ultimoNode->prox != NULL) {
            ultimoNode = ultimoNode->prox;
        }
        ultimoNode->prox = novoNode;
    }  
}

void vizualizaLista(Node *prim) {
    Node *temp = prim;
    printf("Lista: ");
    while(temp != NULL) {
        printf("%.2f -> ", temp->info);
        temp = temp->prox;
    }
    printf("NULL\n\n");
}
