#include <stdio.h>
#define tam 10
/*Faça um programa que preencha dois vetores de dez posições cada, determine e mostre um terceiro contendo os elementos 
dos dois vetores anteriores ordenados de maneira decrescente.*/

int ordemDecrescente(int *vet1, int *vet2){

    int vet3[tam * 2];
    int cont=0;

    for(int i = 0; i < tam * 2; i++){
        if(i < tam){
            vet3[i] = vet1[i];
        }else{
            vet3[i] = vet2[cont];
            cont++;
        }
    }

    for(int i = 0; i < tam * 2; i++){
        for(int j = 0; j < tam * 2; j++){
            if(vet3[i] > vet3[j]){
                int aux = vet3[i];
                vet3[i] = vet3[j];
                vet3[j] = aux;
            }
        }
    }

    printf("Ordem decrescente: ");
    for(int i = 0; i < tam * 2; i++){
        printf("%d ", vet3[i]);
    }
    printf("\n");

    return 0;

}

main(){

    int vetor1[tam],vetor2[tam];

    printf("Digite %d numeros para o primeiro vetor: \n", tam);
    for(int i = 0; i < tam; i++){
        scanf("%d",&vetor1[i]);
    }

    printf("Digite %d numeros para o segundo vetor: \n", tam);
    for(int i = 0; i < tam; i++){
        scanf("%d",&vetor2[i]);
    }
    ordemDecrescente(vetor1,vetor2);

}