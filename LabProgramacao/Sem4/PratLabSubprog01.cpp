/*Faça uma função que receba 3 números inteiros por parâmetro: a,b e c, onde a deve 
ser maior que 1. A função deve somar todos os inteiros entre b e c que sejam divisíveis 
por a (inclusive b e c) e retornar o resultado para a função principal.*/
//Aluno: André Pereira dos Santos Serafin

#include <stdio.h>

int somaNumeros (int a, int b, int c);

main(){
		
			
	int a, b, c, resultado;
	
	printf("Digite tres valores. \n");
	scanf("%i%i%i", &a, &b, &c);
	resultado = somaNumeros(a, b, c);
	printf("O resultado deu %i", resultado);	
	
}


	int somaNumeros (int a, int b, int c){
		int soma = 0;
		
		if(a > 1) {
			for (int i = b; i <= c; i++){
				if (i % a == 0){
					soma += i;
				}	
			}
			return soma;	
		}else{
			return 0;
		}	
	}
	
	
