/*Elabore uma sub-rotina que leia um número não determinado de valores positivos e retorne a média aritmética desses valores. 
Terminar a entrada de dados com o valor zero.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

float calc(int *args,int quant){
	double soma,media;
	for(int i;i<quant;i++){
		soma += args[i];
	}
	media = soma / quant;
	
	return media;
}

main(){
	
	int qtdd,ind = 0;
	int nums[99];
	
	printf("Digite a quantidade de valores que deseja: \n");
	scanf("%i",&qtdd);
	
	printf("Digite os valores: \n");
	while(ind < qtdd){
		scanf("%i",&nums[ind]);
		ind ++;
	}
	
	printf("Media = %.2f",calc(nums,qtdd));
	
}
