/*1 - Fa�a uma sub-rotina que receba um n�mero inteiro e positivo N como par�metro e retorne a soma dos n�meros 
inteiros existentes entre o n�mero 1 e N (inclusive).*/
//Aluno: Andr� Pereira dos Santos Serafin
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

