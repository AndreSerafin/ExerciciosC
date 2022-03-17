/*Elabore uma sub-rotina que receba dois números como parâmetros e retorne 0, se o primeiro número for divisível pelo segundo número. Caso contrário,
deverá retornar o próximo divisor.*/

#include<stdio.h>
#include<math.h>
#include<locale.h>

calculo(int n1,int n2){
	int i;
	
	if(n1 % n2 == 0){
		return 0;
	}else{
		
		for(i = n2; i <= n1;i++){
			
			if(n1 % i == 0){
				return i;			
			}			
		}
	}
}

main(){
	int x,y;
	
	printf("Digite dois numeros inteiros: ");
	scanf("%i%i",&x,&y);
	
	if(calculo(x,y) == 0){
		printf("Eles eram divisiveis!\n");
	}else{
		printf("O proximo divisor e: %i\n",calculo(x,y));
	}
	
}

