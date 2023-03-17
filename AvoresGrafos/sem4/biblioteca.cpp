#include <stdio.h>
#include <locale.h>
#include <string>
#include "biblioteca.h"

int comps_bubble = 0, swaps_bubble = 0;
int comps_selection = 0, swaps_selection = 0;
int comps_insertion = 0, swaps_insertion = 0;
int comps_quick = 0, swaps_quick = 0, recursive_calls = 0;

int* bubble(int* array, int n) {
    
    comps_bubble = 0, swaps_bubble = 0;
    int aux = 0;
   
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++) {
            comps_bubble++;
            if (array[j + 1] < array[j]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                swaps_bubble++;
            }
        }
    }
    
    return array;
}

int* selection(int* array, int n) {
    
    comps_selection = 0, swaps_selection = 0;
    int aux, selected, min;
  
    for (int i = 0; i < (n - 1); i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min]) {
                min = j;
                comps_selection++;
            }   
        }

        if (i != min) {
            aux = array[i];
            array[i] = array[min];
            array[min] = aux;
            swaps_selection++;
        }
    
    }

    return array;
}

int* insertion(int* array, int n) {

    comps_insertion = 0, swaps_insertion = 0;
    int j, aux;
    for (int i = 1; i < n; i++) {
        aux = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > aux) {
            array[j + 1] = array[j];
            j = j - 1;
            comps_insertion++;
        }
        array[j + 1] = aux;
        swaps_insertion++;
    }
    
    return array;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps_quick++;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comps_quick++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int* quickSort(int* array, int low, int high) {
    if (low < high) {
        int p = partition(array, low, high);

        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }

    recursive_calls++;
    return array;
}

void comparison(int* array, int n) {

    bubble(array, n);
    selection(array, n);
    insertion(array, n);
    comps_quick = 0, swaps_quick = 0, recursive_calls = 0;
    quickSort(array, 0, n - 1);
    
    printf("Comparacoes do Bubble: %d, Trocas do Bubble: %d\n",comps_bubble,swaps_bubble);
    printf("Comparacoes do Select: %d, Trocas do Select: %d\n",comps_selection,swaps_selection);
    printf("Comparacoes do Insertion: %d, Trocas do Insertion: %d\n",comps_insertion,swaps_insertion);
    printf("Comparacoes do Quick: %d, Trocas do Quick: %d, Chamadas da Funcao principal: %d\n\n\n",comps_quick,swaps_quick, recursive_calls);
    
}


int* copyArray(int* array, int n) {
    int* c = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        c[i] = array[i];
    }
    return c;
}

void printArray(int* array, int n) {
    for(int i = 0; i < n - 1; i++) {
        printf("%d, ", array[i]);
    }
        printf("%d", array[n-1]);
    printf("\n\n");
}