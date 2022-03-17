/*Crie uma sub-rotina que receba como parâmetro a altura (alt) e o sexo de uma pessoa e retorne seu peso ideal. 
Para homens, deverá calcular o peso ideal usando a fórmula: peso ideal = 72.7 *alt - 58; para mulheres: peso ideal = 62.1 *alt - 44.7.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

float calculo(char sx, float a){
	
	float pesoIdeal;
	
	if(sx == 'M'){
		pesoIdeal = (72.7 * a) - 58;
	}else if(sx == 'F'){
		pesoIdeal = (62.1 * a) - 44.7;
	}else{
		return 0;
	}
	return pesoIdeal;
}

main(){
	char sexo;
	float altura;
	
	printf("Digite M para masculino e F para Feminino: \n");
	scanf("%c",&sexo);
	printf("Digite a altura em metros:\n");
	scanf("%f",&altura);
	if(calculo(sexo,altura) == 0){
		printf("Sexo nao invalido!\n");
	}else{
		printf("O peso ideal para essa pessoa e: %.4f\n",calculo(sexo,altura));
	}
}


