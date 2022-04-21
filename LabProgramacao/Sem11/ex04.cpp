#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Faça um programa que preencha um vetor com 100 números inteiros. Calcule e mostre:
• O vetor preenchido 
• Os números primos e suas posições
• Quantos números são menores que a soma dos primos*/
 main(){
 	
     printf("Digite o o tamanho do vetor: ");
    int n = 0;
    scanf("%d",&n);

    int vetor[n];
    int posicao;
    
    srand(time(NULL));
    printf("\nVetor Preenchido: ");
    for(int i = 0;i<n;i++){
        vetor[i] = rand() % 100;
        printf("[%d] ",vetor[i]);
    }
    printf("\n");

    int soma = 0;
    printf("\nValores Primos: ");
    for (int i=1; i <= n; i++)
    {
        if(vetor[i] == 2 || vetor[i] == 3 || vetor[i] == 5 || vetor[i] == 7){
            printf("[%d] ",vetor[i]);
            soma += vetor[i];
        }else if(vetor[i] == 1 || vetor[i] % 2 == 0 || vetor[i] % 3 == 0 || vetor[i] % 5 == 0 || vetor[i] % 7 == 0){
            //nao primo
        }else{
            printf("[%d] ",vetor[i]);
            soma += vetor[i];
        }
    }

    int quantidade = 0;

    for(int i = 0; i <= n; i++){
        if(vetor[i] < soma){
            quantidade++;
        }
    }

    printf("\nNumeros menores que a soma dos primos: %d",quantidade);
    
 }