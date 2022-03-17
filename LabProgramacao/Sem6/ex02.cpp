/*2 - Crie uma sub-rotina que receba três números inteiros como parâmetros, representando horas, minutos e segundos, e os converta em segundos. 
Exemplo: 2h, 40min e 10s correspondem a 9.610 segundos.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

conversor(int hrs,int mins, int segs){
	int segsTotal;
	
	segsTotal = (hrs * 60 *60) + (mins *60) + segs;
	printf("O total de segundos e: %i", segsTotal);
	
	return segsTotal;
	
}


main(){
	
	int a,b,c,res;
	
	printf("Digite um horario para converter: ");
	scanf("%i%*c%i%*c%i",&a,&b,&c);
	
	res = conversor(a,b,c);
	
}


