#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "biblioteca.h"

int comps_bubble = 0, swaps_bubble = 0;
int comps_selection = 0, swaps_selection = 0;
int comps_insertion = 0, swaps_insertion = 0;
int comps_quick = 0, swaps_quick = 0, recursive_calls_sort = 0;
int comps_merge = 0, swaps_merge = 0, recursive_calls_merge = 0;;
int comps_heap = 0, swaps_heap = 0;

// bubble
Paciente* bubble_idade(Paciente* array, int n) {
    Paciente aux;
   
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++) {
            comps_bubble++;
            if (array[j + 1].idade < array[j].idade) {
                swaps_bubble++;
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    
    return array;
}

Paciente* bubble_renda_salarial(Paciente* array, int n) {
    Paciente aux;
   
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++) {
            comps_bubble++;
            if (array[j + 1].renda_salarial < array[j].renda_salarial) {
                swaps_bubble++;
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    
    return array;
}

Paciente* bubble_qtdd_moradores(Paciente* array, int n) {
    Paciente aux;
   
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++) {
            comps_bubble++;
            if (array[j + 1].qtdd_moradores < array[j].qtdd_moradores) {
                swaps_bubble++;
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    
    return array;
}



// selection
Paciente* selection_idade(Paciente* array, int n) {
    Paciente aux;
    int selected, min;
  
    for (int i = 0; i < (n - 1); i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j].idade < array[min].idade) {
                comps_selection++;
                min = j;
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

Paciente* selection_renda_salarial(Paciente* array, int n) {
    Paciente aux;
    int selected, min;
  
    for (int i = 0; i < (n - 1); i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j].renda_salarial < array[min].renda_salarial) {
                comps_selection++;
                min = j;
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

Paciente* selection_qtdd_moradores(Paciente* array, int n) {
    Paciente aux;
    int selected, min;
  
    for (int i = 0; i < (n - 1); i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j].qtdd_moradores < array[min].qtdd_moradores) {
                comps_selection++;
                min = j;
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

// insertion
Paciente* insertion_idade(Paciente* array, int n) {
    int j;
    Paciente aux;
    for (int i = 1; i < n; i++) {
        aux = array[i];
        j = i - 1;

        while (j >= 0 && array[j].idade > aux.idade) {
            array[j + 1] = array[j];
            j = j - 1;
            comps_insertion++;
        }
        array[j + 1] = aux;
        swaps_insertion++;
    }
    
    return array;
}

Paciente* insertion_renda_salarial(Paciente* array, int n) {
    int j;
    Paciente aux;
    for (int i = 1; i < n; i++) {
        aux = array[i];
        j = i - 1;

        while (j >= 0 && array[j].renda_salarial > aux.renda_salarial) {
            array[j + 1] = array[j];
            j = j - 1;
            comps_insertion++;
        }
        array[j + 1] = aux;
        swaps_insertion++;
    }
    
    return array;
}

Paciente* insertion_qtdd_moradores(Paciente* array, int n) {
    int j;
    Paciente aux;
    for (int i = 1; i < n; i++) {
        aux = array[i];
        j = i - 1;

        while (j >= 0 && array[j].qtdd_moradores > aux.qtdd_moradores) {
            array[j + 1] = array[j];
            j = j - 1;
            comps_insertion++;
        }
        array[j + 1] = aux;
        swaps_insertion++;
    }
    
    return array;
}

// quick idade

void swap_idade(Paciente* a, Paciente* b) {
    Paciente temp = *a;
    *a = *b;
    *b = temp;
}

int partition_idade(Paciente* arr, int low, int high) {
    int pivot = arr[high].idade;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].idade < pivot) {
            i++;
            swap_idade(&arr[i], &arr[j]);
        }
    }
    swap_idade(&arr[i + 1], &arr[high]);
    return i + 1;
}

Paciente* quickSort_idade(Paciente* array, int low, int high) {
    if (low < high) {
        int p = partition_idade(array, low, high);

        quickSort_idade(array, low, p - 1);
        quickSort_idade(array, p + 1, high);
    }

    return array;
}

// quick renda

void swap_renda_salarial(Paciente* a, Paciente* b) {
    Paciente temp = *a;
    *a = *b;
    *b = temp;
}

int partition_renda_salarial(Paciente* arr, int low, int high) {
    float pivot = arr[high].renda_salarial;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].renda_salarial < pivot) {
            i++;
            swap_renda_salarial(&arr[i], &arr[j]);
        }
    }
    swap_renda_salarial(&arr[i + 1], &arr[high]);
    return i + 1;
}

Paciente* quickSort_renda_salarial(Paciente* array, int low, int high) {
    if (low < high) {
        int p = partition_renda_salarial(array, low, high);

        quickSort_renda_salarial(array, low, p - 1);
        quickSort_renda_salarial(array, p + 1, high);
    }

    return array;
}

// quick qtdd_moradores

void swap(Paciente* a, Paciente* b) {
    Paciente temp = *a;
    *a = *b;
    *b = temp;
}

int partition_qtdd_moradores(Paciente* arr, int low, int high) {
    int pivot = arr[high].qtdd_moradores;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].qtdd_moradores < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

Paciente* quickSort_qtdd_moradores(Paciente* array, int low, int high) {
    if (low < high) {
        int p = partition_qtdd_moradores(array, low, high);

        quickSort_qtdd_moradores(array, low, p - 1);
        quickSort_qtdd_moradores(array, p + 1, high);
    }

    return array;
}

// merge idade

void merge_idade(Paciente* array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Paciente L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        comps_merge++;
        if (L[i].idade <= R[j].idade) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        swaps_merge++;
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
        swaps_merge++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
        swaps_merge++;
    }
}

Paciente* mergeSort_idade(Paciente* array, int l, int r) {
    recursive_calls_merge++;
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort_idade(array, l, m);
        mergeSort_idade(array, m + 1, r);

        merge_idade(array, l, m, r);
    }
    return array;
}

// merge renda

void merge_renda_salarial(Paciente* array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Paciente L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        comps_merge++;
        if (L[i].renda_salarial <= R[j].renda_salarial) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        swaps_merge++;
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
        swaps_merge++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
        swaps_merge++;
    }
}

Paciente* mergeSort_renda_salarial(Paciente* array, int l, int r) {
    recursive_calls_merge++;
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort_renda_salarial(array, l, m);
        mergeSort_renda_salarial(array, m + 1, r);

        merge_renda_salarial(array, l, m, r);
    }
    return array;
}

// merge qtdd moradores

void merge_qtdd_moradores(Paciente* array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Paciente L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        comps_merge++;
        if (L[i].qtdd_moradores <= R[j].qtdd_moradores) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        swaps_merge++;
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
        swaps_merge++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
        swaps_merge++;
    }
}

Paciente* mergeSort_qtdd_moradores(Paciente* array, int l, int r) {
    recursive_calls_merge++;
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort_qtdd_moradores(array, l, m);
        mergeSort_qtdd_moradores(array, m + 1, r);

        merge_qtdd_moradores(array, l, m, r);
    }
    return array;
}


// heap idade
void heapify_idade(Paciente* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comps_heap++;
        if (arr[left].idade > arr[largest].idade) {
            largest = left;
        }
    }

    if (right < n) {
        comps_heap++;
        if (arr[right].idade > arr[largest].idade) {
            largest = right;
        }
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        swaps_heap++;

        heapify_idade(arr, n, largest);
    }
}

Paciente* heapSort_idade(Paciente* array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_idade(array, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        swaps_heap++;

        heapify_idade(array, i, 0);
    }

    return array;
}

// heap renda

void heapify_renda_salarial(Paciente* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comps_heap++;
        if (arr[left].renda_salarial > arr[largest].renda_salarial) {
            largest = left;
        }
    }

    if (right < n) {
        comps_heap++;
        if (arr[right].renda_salarial > arr[largest].renda_salarial) {
            largest = right;
        }
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        swaps_heap++;

        heapify_renda_salarial(arr, n, largest);
    }
}

Paciente* heapSort_renda_salarial(Paciente* array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_renda_salarial(array, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        swaps_heap++;

        heapify_renda_salarial(array, i, 0);
    }

    return array;
}

// heap qtdd moradores

void heapify_qtdd_moradores(Paciente* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comps_heap++;
        if (arr[left].qtdd_moradores > arr[largest].qtdd_moradores) {
            largest = left;
        }
    }

    if (right < n) {
        comps_heap++;
        if (arr[right].qtdd_moradores > arr[largest].qtdd_moradores) {
            largest = right;
        }
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify_qtdd_moradores(arr, n, largest);
    }
}

Paciente* heapSort_qtdd_moradores(Paciente* array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_qtdd_moradores(array, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);

        heapify_qtdd_moradores(array, i, 0);
    }

    return array;
}

Paciente* copyArray(Paciente* array, int n) {
    Paciente* c = (Paciente*) malloc(n * sizeof(Paciente));
    for (int i = 0; i < n; i++) {
        c[i] = array[i];
    }
    return c;
}


void printArrayPacientes(Paciente* pacientes, int n) {
    for(int i = 0; i < n; i++) {
        printf("Paciente: #%d - ", i+1);
        printf("Idade: %d, Sexo: %c, Renda Salarial: R$ %.2f, Bairro: %s, Quantidade de moradores: %d\n", 
        pacientes[i].idade, pacientes[i].sexo, pacientes[i].renda_salarial, pacientes[i].bairro, pacientes[i].qtdd_moradores);
    }
    printf("\n\n");
}