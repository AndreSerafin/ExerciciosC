#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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
void buscaCarro(Node *lista, char nome_do_carro[80]);
void removeCarro(Node **head, int pos);

main() {

    Node *lista = NULL;
    
    int op;

    do{
        
        system("cls"); // Comentar se usar terminal integrado
        printf("1. Incluir um Carro: \n");
        printf("2. Remover um Carro: \n");
        printf("3. Listar todos os Carros: \n");
        printf("4. Pesquisar um Carro pelo nome: \n");
        printf("5. Sair do Programa: \n");
        
        scanf("%d", &op);

        system("cls"); // Comentar se usar terminal integrado

        switch(op) {
            case 1:
                int op2;
                printf("\n1. Incluir no inicio\n");
                printf("2. Incluir no final\n");
                scanf("%d", &op2);
                switch(op2) {
                    case 1:
                        incluirCarroInicio(&lista, registraCarro());
                        break;
                    case 2:
                        incluirCarroFinal(&lista, registraCarro());
                        break;
                    default:
                        printf("Opcao Invalida!\n");
                        break;
                }
                break;

            case 2:
                if(lista == NULL){
                    printf("\nLista vazia!\n");
                    break;
                }else{
                    int pos;
                    vizualizaLista(lista);
                    printf("Digite a posicao do carro que deseja remover: \n");
                    scanf("%d", &pos);
                    removeCarro(&lista, pos);
                    break;
                }
            case 3:
                if(lista == NULL) {
                    printf("\nLista vazia!\n");
                    break;
                }else{
                    vizualizaLista(lista);
                    break;
                }
            case 4:
                if(lista == NULL) {
                    printf("\nLista vazia!\n");
                    break;
                }else{
                    char nome_carro[80];
                    printf("Digite o nome do carro: ");
                    scanf("%s", &nome_carro);
                    buscaCarro(lista,nome_carro);
                }
            case 5:
                break;
            default:
                printf("\nOpcao Invalida!\n");
        }

        getche();

    }while(op != 5);
    

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
    int index = 0;
    printf("\nLista: \n\n");
    while(temp != NULL) {
        index++;
        printf("Carro #%d\n", index);
        printf("Nome do Carro: %s \n", temp->info.nome);
        printf("Ano de Fabricacao: %s \n", temp->info.ano_de_fab);
        printf("Marca: %s \n", temp->info.marca);
        printf("Preco estimado: R$ %.2f \n\n", temp->info.preco_estimado);
        temp = temp->prox;
    }
}

void removeCarro(Node** head, int pos)
{
    Node* temp;
    Node* ant;
    temp = *head;
    ant = *head;
    for (int i = 0; i < pos; i++) {
        if (i == 0 && pos == 1) {
            *head = (*head)->prox;
            free(temp);
        }
        else {
            if (i == pos - 1 && temp) {
                ant->prox = temp->prox;
                free(temp);
            }
            else {
                ant = temp;
 
                if (ant == NULL)
                    break;
                temp = temp->prox;
            }
        }
    }
}
 

void buscaCarro(Node *lista, char nome_do_carro[]) {
    if(lista == NULL) {
        printf("Lista Vazia");
        return;
    }else {
        Node *temp = lista;
        while(temp != NULL) {
            
            if(strcmp(temp->info.nome, nome_do_carro) == 0) {
                printf("\nNome do Carro: %s \n", temp->info.nome);
                printf("Ano de Fabricacao: %s \n", temp->info.ano_de_fab);
                printf("Marca: %s \n", temp->info.marca);
                printf("Preco estimado: R$ %.2f \n\n", temp->info.preco_estimado);
            }
            temp = temp->prox;
        }
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