#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include<time.h>
#include "biblioteca.h"
#define TAM_VETOR 1000


int main() {

    srand(time(NULL));

    bool key = false;
    
    int vetor[TAM_VETOR];

    for (int i = 0; i < TAM_VETOR; i++) {
        vetor[i] = rand() % TAM_VETOR;
    }
    
    printf("Vetor gerado: ");
    printArray(vetor, TAM_VETOR);

    while(!key) {

        int* vetorOrdenado;

        printf("Selecione o Metodo de ordenacao\n");
        printf("1-Bubble Sort\n");
        printf("2-Select Sort\n");
        printf("3-Insertion Sort\n");
        printf("4-Quick Sort\n");
        printf("5-Comparacao\n");
        printf("6-Gerar Outro Vetor\n");
        printf("7-Sair\n");

        int op;
        scanf("%d", &op);

        int* copiaVetor;
        
        switch(op) {
            case 1:

                copiaVetor = copyArray(vetor, TAM_VETOR);
                vetorOrdenado = bubble(copiaVetor, TAM_VETOR);
                printf("Vetor Ordenado: ");
                printArray(vetorOrdenado, TAM_VETOR);
                getche();
                break;
            case 2:
                copiaVetor = copyArray(vetor, TAM_VETOR);
                vetorOrdenado = selection(copiaVetor, TAM_VETOR);
                printf("Vetor Ordenado: ");
                printArray(vetorOrdenado, TAM_VETOR);
                getche();
                break;
            case 3:
                copiaVetor = copyArray(vetor, TAM_VETOR);
                vetorOrdenado = insertion(copiaVetor, TAM_VETOR);
                printf("Vetor Ordenado: ");
                printArray(vetorOrdenado, TAM_VETOR);
                getche();
                break;
            case 4:
                copiaVetor = copyArray(vetor, TAM_VETOR);
                printf("Vetor Ordenado: ");
                vetorOrdenado = quickSort(copiaVetor, 0,TAM_VETOR - 1);
                printArray(vetorOrdenado, TAM_VETOR);
                getche();
                break;
            case 5:
                copiaVetor = copyArray(vetor, TAM_VETOR);
                comparison(copiaVetor, TAM_VETOR);
                getche();
                break;
            case 6:
                for (int i = 0; i < TAM_VETOR; i++) {
                    vetor[i] = rand() % TAM_VETOR;
                }
                printf("Vetor gerado: ");
                printArray(vetor, TAM_VETOR);
                getche();
                break;
            case 7:
                key = true;
                getche();
                break;
            default:
                printf("Opcao Invalida");
                break;

        }
        system("cls");

    }

}
