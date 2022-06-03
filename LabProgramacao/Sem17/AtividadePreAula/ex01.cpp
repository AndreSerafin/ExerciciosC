#include <stdio.h>

typedef struct {

    int numero = 0;
    char nome[50] = " ";
    char curso[20] = " ";
    float nota1 = 0.0, nota2 = 0.0;
    
} Cadastro;

void lerArquivo(char arq[]) {
    Cadastro aluno;
    FILE *file = fopen(arq, "rb");

    if(file != NULL) {
            
        while(!feof(file)) {

            if(fread(&aluno, sizeof(Cadastro), 1, file)){

                printf("\nNumero: %d\n", aluno.numero);
                printf("Nome: %s", aluno.nome);
                printf("Curso: %s", aluno.curso);
                printf("Nota1: %.2f\n", aluno.nota1);
                printf("Nota2: %.2f\n", aluno.nota2);
            }
        }
        fclose(file);

    }else{
        printf("Erro ao abrir o arquivo!");
    }

}

void excluirArquivo(char arq[]) {
    Cadastro aluno;
    FILE *file = fopen(arq, "wb");

    fclose(file);
}

void criarArquivo(char arq[]) {

    Cadastro aluno;
    FILE *file = fopen(arq, "ab");

    if(file != NULL) {
        printf(" Numero de matricula: \n • ");
        scanf("%d", &aluno.numero);
        getchar();
        printf(" Nome do aluno: \n • ");
        fgets(aluno.nome, 50, stdin);
        printf(" Curso: \n • ");
        fgets(aluno.curso, 50, stdin);
        printf(" Nota 1: \n • ");
        scanf("%f", &aluno.nota1);
        printf(" Nota 2: \n • ");
        scanf("%f", &aluno.nota2);
        fwrite(&aluno,sizeof(Cadastro), 1, file);
        fclose(file);

    }else{
        printf("Erro ao abrir o arquivo!");
    }

}

main() {

    char arquivo[] = {"Alunos.dat"};
    
    
    int n1 = 0, n2 = 0;
    bool aux = false;
    int op;

    do {

        printf("\n|---------------------------------|\n");
        printf("|          Menu de opcoes         |\n");
        printf("|     0. Finalizar programa:      |\n");
        printf("|      1. Cadastrar alunos:       |\n");
        printf("|       2. Incluir alunos:        |\n");
        printf("|       3. Alterar notas:         |\n");
        printf("|  4. Vizualizar todos cadastros: |\n");
        printf("|   5. Excluir todos cadastros:   |\n");
        printf("|---------------------------------|\n\n");

        scanf("%d", &op);

        switch(op) {
            case 0: {
                break;
            }
            case 1: {
                printf("Digite a quantidade de alunos que deseja cadastrar: ");
                scanf("%d", &n1);
                for(int i = 0; i < n1; i++) {
                    criarArquivo(arquivo);
                }
                break;
            }
            case 2: {
                criarArquivo(arquivo);
                break;
            }
            case 3: {
                
            }
            case 4: {   
                lerArquivo(arquivo);
                break;
            }
            case 5: {
                excluirArquivo(arquivo);
                break;
            }
               
        }

    }while(op != 0);

}