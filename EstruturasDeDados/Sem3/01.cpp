#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*Criar uma estrutura que represente uma pessoa, contendo nome, data de nascimento e CPF. Crie uma variável que 
é um ponteiro para essa estrutura (no programa principal). Depois crie uma função que receba este ponteiro e 
preencha os dados da estrutura e também uma uma função que receba este ponteiro e imprima os dados da estrutura. 
Finalmente, faça a chamada a esta função na função principal. Aloque dinamicamente a estrutura para que sejam 
armazenadas a quantidade de registros definidos pelo usuário.*/

struct Pessoa {
    char nome[50];
    char cpf[50];
    char dataNascimento[10];

};

Pessoa *alocaVetor(Pessoa *pessoa, int tam){

    pessoa = (Pessoa *) (malloc(tam * sizeof(Pessoa)));
    for(int i = 0; i < tam; i++) {
        printf("\nNome: ");
        scanf("%s", &pessoa[i].nome);
        printf("Cpf: ");
        scanf("%s", &pessoa[i].cpf);
        printf("Data de nascimento: ");
        scanf("%s", &pessoa[i].dataNascimento);
    }
    return pessoa;
}

void imprimeDados(Pessoa *pessoa, int tam) {
    for(int i = 0; i < tam;i++) {
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Cpf: %s\n", pessoa[i].cpf);
        printf("Data de nascimento: %s\n", pessoa[i].dataNascimento);
    }

    free(pessoa);
}

main() {
    
    Pessoa *pessoa;
    int tam;
    printf("Digite o tamnaho do vetor: ");
    scanf("%d", &tam);
    
    pessoa = alocaVetor(pessoa, tam);

    imprimeDados(pessoa, tam);
    getche();

}