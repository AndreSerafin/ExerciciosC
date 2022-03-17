/*Faça uma sub-rotina que receba como parâmetro o raio de uma esfera, calcule e mostre no programa principal o seu volume: v = 4/3 * R³.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

float calculo(float raio){
	float vol;	
	vol = (4* 3.14 * pow(raio,3))/3;
	return vol;
}

main(){
	float r;
	printf("Digite o valor do raio da esfera: ");
	scanf("%f",&r);
	
		printf("O volume da esfera e: %.4f",calculo(r));
	
}


