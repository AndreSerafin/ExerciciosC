#include <stdio.h>
#include <locale.h>

int* bubble(int* array, int n);
void printArray(int* array, int n);
int* selection(int* array, int n);

int comparacao, troca;

int main() {

    bool key = false;

    while (!key) {

        int n;

        printf("Digite a quantidade de numeros: ");
        scanf("%d", &n);

        int array[n];
        for (int i = 0; i < n; i++) {
            printf("Digite o %d numero: ", i + 1);
            scanf("%d", &array[i]);
        }
        printf("\nNumeros: ");
        printArray(array, n);

        printf("Selecione o metodo de ordenacao: \n");
        printf("1 - Metodo Bubble.\n");
        printf("2 - Metodo Selection.\n");
        printf("3 - Encerrar Programa.\n");

        int op;
        scanf("%d", &op);

        int* sortedArray;

        switch(op) {
            case 1:
                sortedArray = bubble(array, n);
                printf("Bubble: ");
                printArray(sortedArray, n);
                printf("Comparacoes: %d\n", comparacao);
                printf("Trocas: %d\n", troca);
                break;
            case 2: 
                sortedArray = bubble(array, n);
                printf("Selection: ");
                printArray(sortedArray, n);
                printf("Trocas: %d\n", troca);
                break;
            case 3:
                key = true;
                break;
            default:
                printf("Opcao Invalida!");
        }
    }
    
    
    return 0;
}

int* bubble(int* array, int n) {
    int aux = 0;
    comparacao = 0;
    troca = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++) {
            comparacao++;
            if (array[j + 1] < array[j]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                troca++;
            }
        }
    }
    
    return array;
}

int* selection(int* array, int n) {
    int selected;
    for (int i = 0; i < n - 1; i++){
        selected = i;
        for (int j = 0; j < n + 1; j++) {
            if (array[selected] > array[j]) {
                selected = array[j];
            }
        }
        if(selected != i) {
            int aux = array[i];
            array[i] = array[selected];
            array[selected] = aux;
            troca++;
        }
    }
    return array;
}

void printArray(int* array, int n) {
    for(int i = 0; i < n - 1; i++) {
        printf("%d, ", array[i]);
    }
        printf("%d", array[n-1]);
    printf("\n\n");
}