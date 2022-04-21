#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Faça um programa que preencha dois vetores inteiros com 10 valores cada. Mostre os dois vetores e um vetor que é o resultado da 
intercalação dos outros dois vetores.*/
main(){
    
    int vet1[10];
    int vet2[10];
    int vetResultado[10];

    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        vet1[i] = rand() % 100;
        vet2[i] = rand() % 100;
        vetResultado[i] = vet1[i] + vet2[i];
        
    }

    printf("\nVetor Resultado: ");
    for(int i = 0; i < 10; i++){
        printf("[%d] ", vetResultado[i]);
    }
}