#include <stdio.h>
#include <locale.h>
/*Fa�a um programa que preencha um vetor com seis elementos num�ricos inteiros, calcule mostre:

todos os n�meros pares;
a quantidade de n�meros pares;
todos os n�meros �mpares;
a quantidade de n�meros �mpares.*/

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
