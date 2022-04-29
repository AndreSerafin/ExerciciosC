#include <stdio.h>
#define lin 10
#define col 3

/*Faça um programa que preencha uma matriz 10 × 3 com as notas de dez alunos em três provas. O programa deverá mostrar 
um relatório com o número dos alunos (número da linha) e a prova em que cada aluno obteve menor nota. Ao final do relatório, 
deverá mostrar quantos alunos tiveram menor nota em cada uma das provas: na prova 1, na prova 2 e na prova 3.*/

float acharMenor(float nota[lin][col], int n, int m){

    float menor = 0;

    float vetMenor[n];
    int posicaoProva[n];
    int cont = 0;

    for(int i = 0; i < n; i++){
        menor = __INT_MAX__;
        for(int j = 0; j < m; j++){
            if(nota[i][j] <= menor){
                menor = nota[i][j];
                vetMenor[i] = menor;
                if(j > 0){
                    posicaoProva[i] = j;
                    cont++;
                }else{
                    posicaoProva[i] = 0;
                    cont++;
                }

            }
        }
    }

    

    for(int i = 0; i < n; i++){
        printf("Aluno %d, Menor nota: %.2f \n", i+1,vetMenor[i]);
        
    }

    int prova1 = 0,prova2 = 0,prova3 = 0;

    for(int i = 0; i < n; i++){
        if(posicaoProva[i] == 0){
            prova1++;
        }else if(posicaoProva[i] == 1){
            prova2++;
        }else{
            prova3++;
        }
        //printf("%d ",posicaoProva[i]);
        
    }
    printf("\nProva 1: %d menores\n",prova1);
    printf("Prova 2: %d menores\n",prova2);
    printf("Prova 3: %d menores\n",prova3);

}

main(){

    float notas[lin][col];
    printf("Digite as notas dos alunos: \n");

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%f",&notas[i][j]);
        }
    }

    printf("\n");
    for(int i = 0; i < lin; i++){
        printf("Aluno %d: ",i+1);
        for(int j = 0; j < col; j++){
            printf("%.2f ",notas[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    acharMenor(notas, lin, col);


}