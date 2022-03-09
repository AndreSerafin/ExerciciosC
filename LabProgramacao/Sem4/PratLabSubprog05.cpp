/*Crie uma função que receba como parâmetro um valor inteiro e positivo N, e retorne o
valor de S, obtido pelo seguinte cálculo:*/
//Aluno: André Pereira dos Santos Serafin

#include <stdio.h>

int calc(int a);

int main(void){
    
    int n;
    double res;

    printf("Digite um valor para N: ");
    scanf("%d",&n);

    res = calc(n);

    return 0;
}

int calc(int a){

    int fat = 1;
    double s;

    for(int i = 1;i<=a;i++){
        fat *= i;
        s += 1.0/fat;
    }
	
	printf("S = %.8f",s);
    return s;
}