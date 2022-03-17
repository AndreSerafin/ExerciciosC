/*Crie uma sub-rotina que receba como parâmetro dois valores X e Z, calcule e retorne Xz sem utilizar funções ou operadores de potência prontos.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

int pot(int x, int y){
	
	int soma = 1;

	for(int i = 1; i <= y; i++){
		soma *= x;
	}return soma;
	
}

main(){
	int n1,n2;
	
	printf("Digte o valor de x e z: \n");
	scanf("%i %i",&n1,&n2);
	
	printf("%i elevado a %i = %i",n1,n2,pot(n1,n2));
	
}

