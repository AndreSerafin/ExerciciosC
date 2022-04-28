#include <stdio.h>
#define tam 15
/*Faça um programa que leia um vetor com quinze posições para números inteiros. Depois da leitura, divida todos os seus 
elementos pelo maior valor do vetor. Mostre o vetor após os cálculos.*/

double dividirPorMaior(int *n, int m,int maior){
    
    double novoVet[m];

    for(int i = 0; i < m; i++){
        novoVet[i] = (double) n[i] / maior;
    }
    printf("Novo vetor: [ ");
    for(int i = 0; i < m; i++){
        printf("%.2f ",novoVet[i]);
    }
    printf("]");
    return 0;
}

int acharMaior(int *n, int m){
    
    int maior = 0;

    for(int i = 0; i < m; i++){
        if(n[i] > maior){
            maior = n[i];
        }
    }
    //printf("%d ",maior);
    return maior;
}


main(){
    
    printf("Digite %d numeros: \n",tam);
    int vetor[tam];
    double novovet[tam];

    
    for(int i = 0; i < tam; i++){
        scanf("%d",&vetor[i]);
    }

    int maior = acharMaior(vetor,tam);

    dividirPorMaior(vetor, tam, maior);

    
}