#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*Faça um programa que leia do usuário o tamanho de um vetor (inteiros) a ser lido e faça a sua
alocação dinâmica de memória. Depois, leia do usuário seus valores e imprima o vetor lido e
mostre quantos dos números são pares e quantos são impares.*/

main() {
    int *n, tam;

    printf("Digite o tamanho do vetor");
    scanf("%d", &tam);

    n = (int *) (malloc(tam * sizeof(int)));

    for (int i = 0; i < tam; i++) {
        
    }
}