#include <stdio.h>
#include <locale.h>
/*Faça um programa que preencha um vetor com seis elementos numéricos inteiros, calcule mostre:

todos os números pares;
a quantidade de números pares;
todos os números ímpares;
a quantidade de números ímpares.*/

main(){
	
	int vet[7];
	int mult2=0, mult3=0, mult2e3=0;
	int valMult2[7], valMult3[7], valMult2e3[7];
	
	printf("Digite 7 valores:\n");
	for(int i = 0; i < 6; i++){
		scanf("%i",&vet[i]);
		if(vet[i] % 2 == 0 && vet[i] % 3 == 0){
			valMult2e3[mult2e3] = vet[i];
			mult2e3++;											
		}
		if(vet[i] % 3 == 0){
			valMult3[mult3] = vet[i];
			mult3++;								
		}
		if(vet[i] % 2 == 0){
			valMult2[mult2] = vet[i];	
			mult2++;
		}
		
		
	}
	
	
	printf("Multiplos de 2: ");
	for(int i = 0;i < mult2;i++){
		printf("%i ",valMult2[i]);
	}
	printf("\n");
	
	printf("Multiplos de 3: ");
	for(int i = 0;i < mult3;i++){
		printf("%i ",valMult3[i]);
	}
	printf("\n");
	
	printf("Multiplos de 2 e 3: ");
	for(int i = 0;i < mult2e3;i++){
		printf("%i ",valMult2e3[i]);
	}
	printf("\n");
}
