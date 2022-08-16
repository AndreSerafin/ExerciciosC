#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
Deverão ser armazenados, para cada aluno: matricula, nome (apenas um) e ano de nascimento.
> Ao início do programa, o usuário deverá informar o número de alunos que serão armazenados
> O programa devera alocar dinamicamente a quantidade necessária de memória para armazenar os registros dos alunos.
> O programa deverá pedir ao usuário que entre com as informações dos alunos.
> Ao final, mostrar os dados armazenados e liberar a memória alocada.*/

struct Cadastro {

    int matricula;
    char nome[25];
    int anoDeNascimento;
    
};

main(){

    int numAlunos;
    Cadastro *cadastro;

    printf("Digite a quantidade de alunos a serem cadastrados: ");
    scanf("%d", &numAlunos);

    cadastro = (Cadastro *) (malloc (sizeof(Cadastro)));

    for (int i = 0; i < numAlunos; i++) {
        printf("\nDigite os dados do aluno %d \n", i + 1);
        printf("\nMatricula: ");
        scanf("%d", &cadastro[i].matricula);
        printf("Nome: ");
        getchar();
        fgets(cadastro[i].nome, sizeof(cadastro[i].nome), stdin);
        printf("Ano de nascimento: ");
        scanf("%d", &cadastro[i].anoDeNascimento);
    }
    
    system("cls");
    for (int i = 0; i < numAlunos; i++) {
        printf("\n--Aluno %d--\n", i + 1);
        printf("Matricula: %d\n", cadastro[i].matricula);
        printf("Nome: %s\n", cadastro[i].nome);
        printf("Ano de nascimento: %d\n", cadastro[i].anoDeNascimento);
    } 

    free(cadastro);

    getche();
}