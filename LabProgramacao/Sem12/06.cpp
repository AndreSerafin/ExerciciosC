#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 10
/*Faça um programa que preencha uma matriz 10 x 10, com números inteiros. O Programa deverá mostrar a matriz preenchida, a matriz 
contendo somente os valores da DP - Diagonal Principal, a matriz contendo somente os valores da DS - Diagonal Secundária e uma matriz 
mostrando somente os valores das DP e DS. */

int diagPrincipal(int matriz[tam][tam], int n){

    printf("Diagonal Principal:\n\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                printf("%d ", matriz[i][j]);
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

int diagSecundaria(int matriz[tam][tam], int n){

    printf("Diagonal Secundaria:\n\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + j == n - 1){
                printf("%d ", matriz[i][j]);
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");

    return 0;

}

int diagSecPrinc(int matriz[tam][tam], int n){

    printf("Diagonal Principal e Secundaria:\n\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){           
            if(i == j){
                printf("%d ", matriz[i][j]);
            }
            else if(i + j == n - 1){
                printf("%d ", matriz[i][j]);
            }else{
                printf("   ");
            }
            
        }
        printf("\n");
    }
    printf("\n");

    return 0;

}

main(){
    
    int mat[tam][tam];

    srand(time(NULL));

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            mat[i][j] = rand() % 100;
        }
    }

    printf("Matriz Preenchida:\n\n");
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    diagPrincipal(mat, tam);
    diagSecundaria(mat, tam);
    diagSecPrinc(mat, tam);

}