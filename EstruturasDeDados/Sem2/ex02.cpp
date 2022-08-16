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

    printf("Digite os %d numeros do vetor: ", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &n[i]);
    }

    int pares=0,impares=0;

    for (int i = 0; i < tam; i++) {
        if (n[i] % 2 == 0) {
            pares++;
        }else {
            impares++;
        }
    }

    free(n);
    
    printf("%d sao pares\n", pares);
    printf("%d sao impares\n", impares);
    getche();
}