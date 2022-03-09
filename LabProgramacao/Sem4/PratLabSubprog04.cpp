/*Faça uma função que receba como parâmetro a hora de inicio e a hora de término de
um jogo, ambas subdivididas em dois valores distintos: hora e minutos. A função deverá
retornar a duração expressa em minutos, considerando que o tempo máximo de
duração de um jogo é de 24 horas e que ele pode começar em um dia e terminar no
outro.*/
//Aluno: André Pereira dos Santos Serafin

#include <stdio.h>

int calculo(int hi,int mi ,int ht,int mt);

int main(){

   int hori,hort,mini,mint,part;

    printf("Digite as a hora e o minuto de inicio separados por espaco: ");
    scanf("%i%i",&hori,&mini);
    printf("Digite as a hora e o minuto de termino separados por espaco: ");
    scanf("%i %i",&hort,&mint);

    part = calculo(hori,mini,hort,mint);
    printf("%i",part);

}

int calculo(int hi,int mi ,int ht,int mt){
    int hor1,min1,hor2,min2,t;

    min1 = hi * 60 + mi;
    min2 = ht * 60 + mi;

    if(min1 > min2){
        min2 += 24 * 60;
    }

    t = min2 - min1;

    return t;
}