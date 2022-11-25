#include <stdio.h>

#define MAX 10

int inicio, fim;
int pilha[MAX];

void push(int x);
int pop();

int pilhaVazia();
int pilhaCheia();


main() {
    inicio = 0;
    fim = 0;

    push(12);
    push(13);
    push(15);
    push(16);
    push(17);
    push(17);
    push(17);

    for (int i = 0; i < MAX; i++) {
        printf("%d ", pilha[i]);
    }
}

int pilhaVazia() {
    return (inicio == fim);
}

int pilhaCheia() {
    return (fim == MAX);
}

void push(int x) {
    if (!pilhaCheia()) {
        pilha[fim++] = x;
    }else {
        printf("Pilha Cheia!\n");
    }
}

int pop() {
    int aux;
    if (!pilhaVazia()) {
        aux = pilha[fim - 1];
        fim--;
    }else {
        printf("Pilha Vazia!");
    }
    return aux;
}


