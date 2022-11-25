#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    int info;
    Node *prox;
};


Node *cria_node(int info);
void vizualiza_pilha(Node *pilha);
void push(Node **head, int info);
void pop(Node **head);

main() {

    Node *pilha = NULL;
    
    int op;
    
    do {
        printf("0 - Encerrar: \n");
        printf("1 - Inserir elemento na pilha: \n");
        printf("2 - Remover elemento da pilha: \n");
        printf("3 - Vizualizar pilha: \n");

        scanf("%d", &op);

        switch (op) {
        case 1:
            int num;
            printf("Digite um numero inteiro: ");
            scanf("%d", &num);
            push(&pilha, num);
            break;
        case 2:
            pop(&pilha);
            break;
        case 3:
            vizualiza_pilha(pilha);
            break;
        default:
            break;
        }

        getche();
        printf("\n");
        system("cls");
    }while(op != 0);
}

Node *cria_node(int info) {
    Node *novo_node = (Node*) malloc(sizeof(Node));
    novo_node->info = info;
    novo_node->prox = NULL;

    return novo_node;
}

void push(Node **head, int info) {
    Node *novo_node = cria_node(info);
    if (*head == NULL) {
        *head = novo_node;
    }else {
        novo_node->prox = *head;
        *head = novo_node;
    }
}

void pop(Node **head)
{
   if(*head == NULL)
      printf("PILHA VAZIA\n");
   else{
      struct Node *temp = *head;
      *head = temp->prox;
      free(temp);
   }
}

void vizualiza_pilha(Node *pilha){
    Node *temp = pilha;
    printf("TOPO->");
    while(temp->prox != NULL) {
        printf("%d->", temp->info);
        temp = temp->prox;
    }
    printf("%d", temp->info);
}