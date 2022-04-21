#include <stdio.h>
#include <locale.h>
/*Fa�a um programa que preencha um vetor com seis elementos num�ricos inteiros, calcule mostre:

todos os n�meros pares;
a quantidade de n�meros pares;
todos os n�meros �mpares;
a quantidade de n�meros �mpares.*/

main(){
	
	int vet[7];
	int mult2=0, mult3=0, mult2e3=0;
	int valMult2[7], valMult3[7], valMult2e3[7];
	
	printf("Digite 7 valores:\n");
	for(int i = 0; i < 7; i++){
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
