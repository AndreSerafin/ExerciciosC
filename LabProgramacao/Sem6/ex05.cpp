/*Faça uma sub-rotina que receba um valor inteiro e verifique se ele é positivo ou negativo.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

func(int x){
	
	if(x > 0){
		return 1;
	}else{
		return 0;
	}
	
}

main(){
	
	int n;
	
	printf("Digite um numero: ");
	scanf("%i",&n);
	
	if(func(n)==1){
		printf("Positivo!");
	}else{
		printf("Negativo!");
	}
	
}
