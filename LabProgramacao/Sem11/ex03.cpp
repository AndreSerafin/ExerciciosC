#include <stdio.h>
/*Faça um programa que preencha um vetor com quinze elementos inteiros e verifique a 
existência de elementos iguais a 30, mostrando as posições em que apareceram.*/
 main(){
 	
 	int vetor[15];
 	
   printf("Digite 15 elementos inteiros:\n");
   for(int i = 0;i < 15;i++){
         scanf("%i",&vetor[i]);
         if(vetor[i] == 30){
            printf("Posicao: %d \n", i);
         }
   }

 	
 }