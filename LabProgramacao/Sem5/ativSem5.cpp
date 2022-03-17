/*Escreva um programa que simule o lançamento de uma moeda. Para cada lançamento da moeda, o programa deve imprimir Cara ou Coroa. 
Deixe o programa lançar a moeda 100 vezes e conte o número de vezes que cada lado da moeda aparece. Imprima os resultados. 
O programa deve chamar uma função separada jogada que não utiliza argumentos e retorna 0 para coroa e 1 para cara.*/
//Alunos: Andre Pereira dos Santos Serafin, Pedro Afonso Ferreira Leite 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lancamento();

int main(){
	
	int res;
	
	res = lancamento();
 	
}

int lancamento(){
	
	int moeda,i,cont0,cont1,resultado;
	
	srand(time(NULL));
	
	for(i = 1; i < 100;i++){
		moeda = rand()%2;
		if(moeda==0){
			cont0+= 1;
			
		}else{
			cont1+= 1;
			
		}
	}
	printf("Coroa %i vezes\n",cont0);
	printf("Cara %i vezes\n",cont1);
	
	return resultado;
	
	
}
