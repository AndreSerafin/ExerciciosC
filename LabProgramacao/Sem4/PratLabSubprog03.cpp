/*Faça uma função que leia 5(cinco) valores inteiros e retorne o maior, o menor deles e a
média dos digitados*/
//Aluno: André Pereira dos Santos Serafin


#include <stdio.h>


int calculo(int x1,int x2,int x3,int x4,int x5);

int main(){

    int n1,n2,n3,n4,n5,res1,res2,res3;
    
    printf("Digite 5 numeros: \n");
    scanf("%i%i%i%i%i", &n1,&n2,&n3,&n4,&n5);
    
    res1 = calculo(n1,n2,n3,n4,n5);

    return 0;
}

int calculo(int x1,int x2,int x3,int x4,int x5){

    int maior,menor;
    float media;

    media = (x1+x2+x3+x4+x5)/5.0;

    if(x1 > x2 && x1 > x3 && x1 > x4 && x1 > x5){
        maior = x1;
    }else if(x2 > x3 && x2 > x4 && x2 > x5){
        maior = x2;
    }else if(x3 > x4 && x3 > x5){
        maior = x3;
    }else if(x4 > x5){
        maior = x4;
    }else{
        maior = x5;
    }

    if(x1 < x2 && x1 < x3 && x1 < x4 && x1 < x5){
        menor = x1;
    }else if(x2 < x3 && x2 < x4 && x2 < x5){
        menor = x2;
    }else if(x3 < x4 && x3 < x5){
        menor = x3;
    }else if(x4 < x5){
        menor = x4;
    }else{
        menor = x5;
    }

    
    printf("Maior = %i\n",maior);
    printf("Menor = %i\n",menor);
    printf("Media = %.2f\n",media);

    return 0;

}