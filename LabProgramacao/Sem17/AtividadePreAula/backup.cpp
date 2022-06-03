#include <stdio.h>
#define MAX 300

/*1. Faça um programa para criar um arquivo chamado ALUNOS.DAT,no qual cada Cadastro será composto pelos seguintes campos:numero,nome,curso,nota1,nota2.
2. Faça um programa para incluir alunos no arquivo criado no Exercício1,lembrando que não podem existir dois alunos comomesmo número.
3. Faça um programa para alterar as notas dos alunos do arquivo criado no Exercício1.*/

struct Cadastro {

    int numero = 0;
    char nome[50] = " ";
    char curso[20] = " ";
    float nota1 = 0.0,nota2 = 0.0;
    

};

Cadastro criarArquivo(FILE *arquivo, int numMax, Cadastro aluno[]) {

    arquivo = fopen("Alunos.dat", "w");
    
    if(arquivo == NULL) {
        printf("Falha ao criar o arquivo!\n");
        return *aluno;
    }else {
        for(int i = 0; i < numMax; i++) {
            printf("\nAluno %d:\n", i + 1);
            printf(" Numero de matricula: \n • ");
            scanf("%d", &aluno[i].numero);
            getchar();
            printf(" Nome do aluno: \n • ");
            fgets(aluno[i].nome, 50, stdin);
            printf(" Curso: \n • ");
            fgets(aluno[i].curso, 50, stdin);
            printf(" Nota 1: \n • ");
            scanf("%f", &aluno[i].nota1);
            printf(" Nota 2: \n • ");
            scanf("%f", &aluno[i].nota2);

            fprintf(arquivo, "Aluno: %d %s\n", i + 1,"{");
            fprintf(arquivo, "\tNumero: %d\n", aluno[i].numero);
            fprintf(arquivo, "\tNome: %s", aluno[i].nome);
            fprintf(arquivo, "\tCurso: %s", aluno[i].curso);
            fprintf(arquivo, "\tNota1: %.2f\n", aluno[i].nota1);
            fprintf(arquivo, "\tNota2: %.2f\n", aluno[i].nota2);
            fprintf(arquivo, "%s", "}\n");
        }
        fclose(arquivo);
        return *aluno;
    }
}

Cadastro incluirAluno(FILE *arquivo, int num, Cadastro aluno[]) {

    printf("\nAluno %d:\n", num + 1);

    arquivo = fopen("Alunos.dat", "a");

    printf(" Numero de matricula: \n • ");
    scanf("%d", &aluno[num].numero);
    getchar();
    printf(" Nome do aluno: \n • ");
    fgets(aluno[num].nome, 50, stdin);
    printf(" Curso: \n • ");
    fgets(aluno[num].curso, 50, stdin);
    printf(" Nota 1: \n • ");
    scanf("%f", &aluno[num].nota1);
    printf(" Nota 2: \n • ");
    scanf("%f", &aluno[num].nota2);

    fprintf(arquivo, "Aluno: %d %s\n", num + 1,"{");
    fprintf(arquivo, "\tNumero: %d\n", aluno[num].numero);
    fprintf(arquivo, "\tNome: %s", aluno[num].nome);
    fprintf(arquivo, "\tCurso: %s", aluno[num].curso);
    fprintf(arquivo, "\tNota1: %.2f\n", aluno[num].nota1);
    fprintf(arquivo, "\tNota2: %.2f\n", aluno[num].nota2);
    fprintf(arquivo, "%s", "}\n");
    
    fclose(arquivo);

    return *aluno;

}

void vizualizar(FILE *arquivo, Cadastro *alunos){
    
    arquivo = fopen("Alunos.dat","r");
    char text[20];
    printf("\n");
    while(fgets(text,20,arquivo) != NULL){
        printf("%s",text);
    }
    fclose(arquivo);
}

int contaLinhas(FILE *arquivo) {                           
    arquivo = fopen("Alunos.dat", "r");
    int ch=0;
    int lines=0;

    lines++;
    while ((ch = fgetc(arquivo)) != EOF) {
        if (ch == '\n')
        lines++;
        }
    fclose(arquivo);
    return lines;
}

Cadastro alterarNota(FILE *arquivo, int n, Cadastro *aluno) {

}

main() {
    
    FILE *pontArq;
    int n1 = 0, n2 = 0;
    int n3 = ((contaLinhas(pontArq) - 2) / 7) + 1;
    bool aux = false;
    int op;
    Cadastro aluno[MAX];

    do {

        printf("\n|---------------------------------|\n");
        printf("|          Menu de opcoes         |\n");
        printf("|     0. Finalizar programa:      |\n");
        printf("|      1. Cadastrar alunos:       |\n");
        printf("|       2. Incluir alunos:        |\n");
        printf("|       3. Alterar notas:         |\n");
        printf("|  4. Vizualizar todos cadastros: |\n");
        printf("|---------------------------------|\n\n");

        scanf("%d", &op);

        switch(op) {
            case 0: {
                break;
            }
            case 1: {
                printf("Digite a quantidade de alunos que deseja cadastrar: ");
                scanf("%d", &n1);
                *aluno = criarArquivo(pontArq, n1, aluno);
                n2 = n1;
                aux = true;
                break;
            }
            case 2: {
                if(n3 == 0){
                    *aluno = incluirAluno(pontArq, n2, aluno);
                }else{
                    *aluno = incluirAluno(pontArq, n3, aluno);
                }
                break;
                
            }
            case 3: {
                
            }
            case 4: {
                
                vizualizar(pontArq, aluno);
                break;
            }
               
        }

    }while(op != 0);

   

}