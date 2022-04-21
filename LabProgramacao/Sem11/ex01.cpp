#include <stdio.h>
#include <locale.h>
/*Faça um programa que preencha um vetor com seis elementos numéricos inteiros, calcule mostre:

todos os números pares;
a quantidade de números pares;
todos os números ímpares;
a quantidade de números ímpares.*/

main(){
	
	int vet[6];
	int par=0, impar=0;
	int valPares[6],valImpares[6];
	
	printf("Digite 6 valores:\n");
	for(int i = 0; i < 6; i++){
		scanf("%i",&vet[i]);
		if(vet[i] % 2 == 0){
			valPares[par] = vet[i];	
			par++;								
		}else{
			valImpares[impar] = vet[i];
			impar++;								
		}
		
	}
	
	
	printf("Pares: ");
	for(int i = 0;i < par;i++){
		printf("%i ",valPares[i]);
	}
	printf("\n");
	
	printf("Impares: ");
	for(int i = 0;i < impar;i++){
		printf("%i ",valImpares[i]);
	}
	printf("\n");
	
	printf("Quantidade de impares: %i\n",impar);
	printf("Quantidade de pares: %i\n",par);
}
