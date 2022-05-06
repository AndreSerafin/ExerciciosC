#include <stdio.h>
#define lin 5
#define col 4

void func(){

    int n;
    int nums[lin][col];

    int contParLinha = 1;
    int contParColuna = 0;

    int contImparLinha = 0;
    int contImparColuna = 0;

    for(int i = 0; i < lin * col; i++){
        int aux = 1;
        do{
            scanf("%d", &n);
            if(n % 2 == 0){
                if(contParColuna == col){
                    contParLinha += 2;
                    contParColuna = 0;
                }
                if(contParLinha > lin){
                    printf("Limite de Pares atingido\n");
                }else{
                    nums[contParLinha][contParColuna] = n;
                    contParColuna++;
                    aux = 1;
                }
            }else{
                if(contImparColuna == col){
                    contImparLinha += 2;
                    contImparColuna = 0;
                }
                if(contImparLinha > lin){
                    printf("Limite de Impares atingido\n");
                }else{
                    nums[contImparLinha][contImparColuna] = n;
                    contImparColuna++;
                    aux = 1;
                }
            }
        }while(aux == 0);
    }

    printf("\nMatriz digitada:\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
        printf("%d  ", nums[i][j]);
        }
        printf("\n");
    }

}

main(){
    
    func();
    
}