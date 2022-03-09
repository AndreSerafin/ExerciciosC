/*Criar uma função que verifique se um número digitado pelo usuário é primo.*/
//Aluno: André Pereira dos Santos Serafin

#include <stdio.h>

int calculo(int x1);

int main(){

    int n1,res;
    int aux1;

    printf("Digite um numero para saber se e primo: ");
    scanf("%i",&n1);

    aux1 = calculo(n1);

    if(aux1 == 1){
        printf("E primo!");
    }else{
        printf("Nao e primo");
    }


    return 0;
}

int calculo(int x1){
    int res = 0;
    int aux2;

    for (int i = 2; i <= x1 / 2; i++) {
        if (x1 % i == 0) {
       res++;
       break;
        }
    }
    if(res == 0){
        aux2 = 1;
    }else{
        aux2 = 0;
    }

    return(aux2);

}
