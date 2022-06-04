#include <stdio.h>
/*1. Faça um programa para criar um arquivo chamado ALUNOS.DAT,no qual cada Cadastro será composto pelos seguintes campos:numero,nome,curso,nota1,nota2.
2. Faça um programa para incluir alunos no arquivo criado no Exercício1.
3. Faça um programa para alterar as notas dos alunos do arquivo criado no Exercício1.*/

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
        printf("\n Nome do aluno: \n • ");
        fgets(aluno.nome, 50, stdin);
        printf(" Numero de matricula: \n • ");
        scanf("%d", &aluno.numero);
        getchar();
        printf(" Curso: \n • ");
        fgets(aluno.curso, 50, stdin);
        printf(" Nota 1: \n • ");
        scanf("%f", &aluno.nota1);
        printf(" Nota 2: \n • ");
        scanf("%f", &aluno.nota2);
        getchar();
        fwrite(&aluno,sizeof(Cadastro), 1, file);
        fclose(file);

    }else{
        printf("Erro ao abrir o arquivo!");
    }

}

void alterarArquivo(char arq[]) {

    FILE *file = fopen(arq, "rb+");
    Cadastro aluno;
    int i = 1, id;
    
    if(file != NULL) {
        printf("\nLista de alunos: \n");
        printf("-------------------------");
        while(fread(&aluno, sizeof(Cadastro), 1, file)){
            
            printf("\nIndice: %d\n\n", i);
            printf(" Numero: %d\n", aluno.numero);
            printf(" Nome: %s", aluno.nome);
            printf(" Curso: %s", aluno.curso);
            printf(" Nota1: %.2f\n", aluno.nota1);
            printf(" Nota2: %.2f\n", aluno.nota2);
            i++;
        }
        printf("-------------------------\n");

        printf("Digite o indice do cadastro que deseja alterar: ");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1){
            printf("Digite as novas notas: \n");
            scanf("%f", &aluno.nota1);
            scanf("%f", &aluno.nota2);
            fseek(file, id * sizeof(Cadastro), SEEK_SET);
            fwrite(&aluno, sizeof(Cadastro), 1, file);
        }
        fclose(file);


    }else{
        printf("Erro ao abrir o arquivo!");
    }

}
main() {

    char arquivo[] = {"Alunos.dat"};
    
    
    int n1 = 0, n2 = 0;
    bool aux = false;
    int op, num1[500], num2;

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
                getchar();
                
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
                alterarArquivo(arquivo);
                break;
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