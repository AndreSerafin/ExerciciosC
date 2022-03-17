/*Faça uma sub-rotina que receba um valor inteiro e positivo, calcule e mostre seu fatorial. 9.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

int fat(int n){
	int fat = 1;
	for(int i = 1;i <= n;i++){
		fat = fat * i;
	}
	return fat;
}

main(){	
	int num;
	
	printf("Digite um valor inteiro positivo: \n");
	scanf("%i",&num);
	
	printf("%i",fat(num));
}
