#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*Faça um programa que receba do usuário o tamanho de uma string e chame uma função para alocar dinamicamente essa string. 
Em seguida, o usuário deverá informar o conteúdo dessa string. O programa imprime a string sem suas vogais.*/

main(){
    int tam;
    char *str;
    printf("Digite o tamanho da string: \n");
    scanf("%d",&tam);
    str = (char *) (malloc(tam * sizeof(char)));
    
    printf("Digite o conteudo dessa string: \n"); 
    scanf("%s",str);

    printf("String sem as vogais: "); 
    for(int i=0;i<tam;i++)  {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            continue;
        }else{
            printf("%c",str[i]);
        }
    }

    free(str);

    getche();
}