#include <stdio.h>
#define tam 10

/*Faça um programa que receba dez números inteiros e armazene-os em um vetor. Calcule e mostre dois vetores resultantes: 
o primeiro com os números pares e o segundo, com os números ímpares.*/

int pares(int *vet, int m){

    int pares[m];
    int cont = 0;

    for(int i = 0; i < m; i++){
        if(vet[i] % 2 == 0){
            pares[cont] = vet[i];
            cont++;
        }
    }
    printf("Pares: ");
    for(int i = 0; i < cont; i++){
        printf("%d ", pares[i]);
    }
    printf("\n");

    return 0;

}

int impares(int *vet, int m){

    int impares[m];
    int cont = 0;

    for(int i = 0; i < m; i++){
        if(vet[i] % 2 != 0){
            impares[cont] = vet[i];
            cont++;
        }
    }
    printf("Impares: ");
    for(int i = 0; i < cont; i++){
        printf("%d ", impares[i]);
    }
    printf("\n");

    return 0;

}

main(){

    printf("Digite %d numeros: \n",tam);
    int numeros[tam];

    for(int i = 0; i < tam; i++){ 
        scanf("%d", &numeros[i]);
    }

    pares(numeros,tam);
    impares(numeros,tam);

}