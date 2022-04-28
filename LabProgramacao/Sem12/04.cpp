#include <stdio.h>
#define tam 2

/*Faça um programa que preencha uma matriz M (2 x 2), calcule e mostre a matriz R, resultante da 
multiplicação dos elementos de M pelo seu maior elemento.*/

int maior(int matriz[tam][tam], int n){
    int maior = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }

    return maior;

}

int multiplicacao(int matriz[tam][tam], int n, int maior){

    int novaMatriz[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            novaMatriz[i][j] = matriz[i][j] * maior;
        }
    }

    printf("\nMatriz resultante: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", novaMatriz[i][j]);
        }
        printf("\n");
    }
    
}

main(){
    
    int m[tam][tam];

    printf("Preencha a matriz %d x %d: \n",tam,tam);
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            scanf("%d", &m[i][j]);
        }
    }

    int maiorNum = maior(m,tam);
    multiplicacao(m,tam,maiorNum);

}