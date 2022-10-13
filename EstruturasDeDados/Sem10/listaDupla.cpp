#include <stdio.h>
#include <stdlib.h>

struct Carro {
    char nome[80];
    char ano_de_fab[5];
    char marca[80];
    float preco_estimado;
};

struct Node {
    Carro info;
    Node *prox;
    Node *ant;
};

Node *criaNode(Node *prim, Carro info);
Carro registraCarro();
void incluirCarroInicio(Node **head, Carro info);
void incluirCarroFinal(Node **head, Carro info);
void vizualizaLista(Node *prim);

main() {

    Node *lista = NULL;
    Carro carro1 = registraCarro();
    Carro carro2 = registraCarro();

    incluirCarroInicio(&lista, carro1);
    incluirCarroInicio(&lista, carro1);
    incluirCarroInicio(&lista, carro1);
    incluirCarroInicio(&lista, carro1);

    incluirCarroFinal(&lista, carro2);
    incluirCarroFinal(&lista, carro2);
    incluirCarroFinal(&lista, carro2);
    incluirCarroFinal(&lista, carro2);
    vizualizaLista(lista);
    system("pause");
    

}

Node *criaNode(Carro info) {
    Node *novoNode = (Node*) malloc(sizeof(Node));
    novoNode->info = info;
    novoNode->ant = NULL;
    novoNode->prox = NULL;
    return novoNode;
}

void incluirCarroInicio(Node **head, Carro info) {
    Node *novoNode = criaNode(info);
    novoNode->ant = NULL;
    novoNode->prox = *head;
    if(*head) {
        (*head)->ant = novoNode;
    }
    *head = novoNode;
}

void incluirCarroFinal(Node **head, Carro info) {
    Node *novoNode = criaNode(info);
    if(*head == NULL) {
        *head = novoNode;
    }else {
        Node *ultimoNode = *head;
        while(ultimoNode->prox != NULL) {
            ultimoNode = ultimoNode->prox;
        }
        novoNode->ant = ultimoNode;
        ultimoNode->prox = novoNode;
    }
}

void vizualizaLista(Node *prim) {
    Node *temp = prim;
    printf("Lista: \n\n");
    while(temp != NULL) {
        printf("Nome do Carro: %s \n", temp->info.nome);
        printf("Ano de Fabricacao: %s \n", temp->info.ano_de_fab);
        printf("Marca: %s \n", temp->info.marca);
        printf("Preco estimado: R$ %.2f \n\n", temp->info.preco_estimado);
        temp = temp->prox;
    }
}


Carro registraCarro() {
    Carro novoCarro;
    printf("Nome do carro: ");
    scanf("%s", &novoCarro.nome);
    printf("Ano de fabricacao: ");
    scanf("%s", &novoCarro.ano_de_fab);
    printf("Marca: ");
    scanf("%s", &novoCarro.marca);
    printf("Preco estimado: ");
    scanf("%f", &novoCarro.preco_estimado);
    return novoCarro;
}