/*Crie uma sub-rotina que receba como parâmetro um valor inteiro e positivo e retorne a soma dos divisores desse valor.*/
#include<stdio.h>

func(int x){
	int soma = 0;
	for(int i = 1; i <= x; i++){
		if(x % i == 0){
			soma += i;
		}
	}return soma;
}

main(){
	int a;
	printf("Digite um valor: ");
	scanf("%i", &a);
	printf("A soma dos divisores e %i", func(a));
	
}
