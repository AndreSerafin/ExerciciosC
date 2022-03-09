#include <stdio.h>
#include <math.h>


int calculo(int n);

int main(){
    
    int n1 = 1;
    float res;

    printf("Digite o valor inteiro para N: ");
    scanf("%i",&n1);

    res = calculo(n1);

}

int calculo(int n){

    int i;
    float s;

    s=0;

    for(i = 1;i <= n;i++){

        s+= 1.0/i;

    }

    printf("N = %.5f\n",s);

    return 0;

}
