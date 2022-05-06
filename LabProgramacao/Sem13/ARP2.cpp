#include <stdio.h>
#include <stdlib.h>

void somaDiag(int n, int **numeros){

    int soma = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            if(j >= n - i){
                printf("%d ",numeros[i][j]);
                soma += numeros[i][j];
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("Soma dos elementos abaixo da diagonal secundaria: %d", soma);
}

void liberaMatriz(int l, int **nums){
  int i;
  for(i=0;i<l;i++){
    free(nums[i]);
  }
  free(nums);
}

main(){
    int tam;
    printf("Digite um tamanho para a matriz:\n");
    
    scanf("%d",&tam);
    int **nums;
    int i,j;

    nums = (int**)malloc(tam*sizeof(int*));

    for(i=0;i<tam;i++){
     nums[i] = (int*)malloc(tam*sizeof(int));
  }

    
    printf("Preencha a matriz %d x %d\n",tam,tam);
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            scanf("%d", &nums[i][j]);
        }
    }

    printf("\nMatriz digitada\n");
    printf("Preencha a matriz %d x %d\n",tam,tam);
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }

    somaDiag(tam, nums);
    liberaMatriz(tam, nums);
}

