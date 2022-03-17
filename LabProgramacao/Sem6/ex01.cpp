/*1 - Faça uma sub-rotina que receba um número inteiro e positivo N como parâmetro e retorne a soma dos números 
inteiros existentes entre o número 1 e N (inclusive).*/
//Aluno: André Pereira dos Santos Serafin
#include<stdio.h>
#include<math.h>
#include<locale.h>

int soma(int x);

main(){
	
	int n,res;
	printf("Digite o valor de N: ");
	scanf("%d",&n);
	
	res = soma(n);
	
}

soma(int x){
	
	int soma;
	for(int i = 1;i <= x;i++){
		soma += i;			
	}
	
	printf("N = %i",soma);
	return soma;
	
}

