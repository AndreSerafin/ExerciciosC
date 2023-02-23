#include <stdio.h>
#include <stdlib.h>

// Andre Pereira dos Santos Serafin - 2120481
/*Implementar uma estrutura de Pilhas que:

- receba um elemento 

- organize a pilha

- imprima a pilha ordenada*/


struct Node {
    int info;
    Node* next;
};

Node* create_node(Node* stack, int info);
void push(Node** stack, int info);
void pop(Node** stack);
void print_stack(Node* stack);

int main() {

    Node* stack = NULL;
    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 5);
    push(&stack, 7);
    push(&stack, 3);
    push(&stack, 5);

    print_stack(stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    print_stack(stack);

    push(&stack, 5);
    push(&stack, 7);
    push(&stack, 3);
    push(&stack, 5);

    print_stack(stack);
    
    return 0;
}

Node* create_node(int info) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->info = info;
    new_node->next = NULL;
    return new_node;
}

void push(Node** stack, int info) {
    Node* new_node = create_node(info);
    if(stack == NULL) {
        *stack = new_node;
    }else {
        new_node->next = *stack;
        *stack = new_node;
    }
}

void pop(Node** stack) {
    if(stack == NULL) {
        printf("Pilha Vazia!\n");
    }else {
        Node *temp = *stack;
        *stack = temp->next;
        free(temp);
    }
}

void print_stack(Node* stack) {
    Node* temp = stack;
    printf("TOP->");
    while(temp->next != NULL){
        printf("%d->", temp->info);
        temp = temp->next;
    }
    printf("%d\n", temp->info);
    
}