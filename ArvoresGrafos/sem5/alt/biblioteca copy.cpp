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
template <typename T>
T* bubble(T* array, int n) {
    T aux = 0;
   
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++) {
            comps_bubble++;
            if (array[j + 1] < array[j]) {
                swaps_bubble++;
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    
    return array;
}

template float* bubble(float* array, int n);
template int* bubble(int* array, int n);


// selection
template <typename T>
T* selection(T* array, int n) {
    T aux;
    int selected, min;
  
    for (int i = 0; i < (n - 1); i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min]) {
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

template int* selection(int* array, int n);
template float* selection(float* array, int n);


// insertion
template <typename T>
T* insertion(T* array, int n) {
    int j;
    T aux;
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

template int* insertion(int* array, int n);
template float* insertion(float* array, int n);

// quick
template<typename T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
    swaps_quick++;
}
template void swap(int* a, int* b);
template void swap(float* a, float* b);

template<typename T>
int partition(T* arr, int low, int high) {
    T pivot = arr[high];
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

template int partition(int* arr, int low, int high);
template int partition(float* arr, int low, int high);

template<typename T>
T* quickSort(T* array, int low, int high) {
    if (low < high) {
        int p = partition(array, low, high);

        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }

    recursive_calls_sort++;
    return array;
}

template int* quickSort(int* array, int low, int high);
template float* quickSort(float* array, int low, int high);

// merge
template<typename T>
void merge(T* array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    T L[n1], R[n2];

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
        if (L[i] <= R[j]) {
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

template void merge(int* array, int l, int m, int r) ;
template void merge(float* array, int l, int m, int r) ;

template<typename T>
T* mergeSort(T* array, int l, int r) {
    recursive_calls_merge++;
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, m, r);
    }
    return array;
}

template int* mergeSort(int* array, int l, int r);
template float* mergeSort(float* array, int l, int r);


// heap
template <typename T>
void heapify(T* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comps_heap++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        comps_heap++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    if (largest != i) {
        T temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        swaps_heap++;

        heapify(arr, n, largest);
    }
}
template void heapify(int* arr, int n, int i);
template void heapify(float* arr, int n, int i);

template <typename T>
T* heapsort(T* array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        T temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        swaps_heap++;

        heapify(array, i, 0);
    }

    return array;
}

template int* heapsort(int* array, int n);
template float* heapsort(float* array, int n);

//contadores de trocas
void comparison(int* array, int n) {

    //bubble
    comps_bubble = 0; swaps_bubble = 0;
    int* arrayCopy = copyArray(array, n);
    bubble(arrayCopy, n);
    
    //selection
    comps_selection = 0; swaps_selection = 0;
    arrayCopy = copyArray(array, n);
    selection(arrayCopy, n);
    
    
    //insertion
    comps_insertion = 0; swaps_insertion = 0;
    arrayCopy = copyArray(array, n);
    insertion(arrayCopy, n);
    
    //quick
    arrayCopy = copyArray(array, n);
    comps_quick = 0, swaps_quick = 0, recursive_calls_sort = 0;
    quickSort(arrayCopy, 0, n - 1);
    
    //merge
    arrayCopy = copyArray(array, n);
    comps_merge = 0, swaps_merge = 0, recursive_calls_merge = 0;
    mergeSort(arrayCopy, 0, n - 1);
    
    //heap
    arrayCopy = copyArray(array, n);
    comps_heap = 0, swaps_heap = 0;
    heapsort(arrayCopy, n);
    
    printf("Comparacoes do Bubble: %d, Trocas do Bubble: %d\n",comps_bubble,swaps_bubble);
    printf("Comparacoes do Select: %d, Trocas do Select: %d\n",comps_selection,swaps_selection);
    printf("Comparacoes do Insertion: %d, Trocas do Insertion: %d\n",comps_insertion,swaps_insertion);
    printf("Comparacoes do Quick: %d, Trocas do Quick: %d, Chamadas Recursivas: %d\n",comps_quick,swaps_quick, recursive_calls_sort);
    printf("Comparacoes do Merge: %d, Trocas do Merge: %d, Chamadas Recursivas: %d\n",comps_merge,swaps_merge, recursive_calls_merge);
    printf("Comparacoes do Heap: %d, Trocas do Heap: %d\n\n\n",comps_heap,swaps_heap);
    
}


template<typename T>

T* copyArray(T* array, int n) {
    T* c = (T*) malloc(n * sizeof(T));
    for (int i = 0; i < n; i++) {
        c[i] = array[i];
    }
    return c;
}

template int* copyArray(int* array, int n);
template float* copyArray(float* array, int n);

void printArrayInt(int* array, int n) {
    for(int i = 0; i < n - 1; i++) {
        printf("%d, ", array[i]);
    }
        printf("%d", array[n-1]);
    printf("\n\n");
}

void printArrayFloat(float* array, int n) {
    for(int i = 0; i < n - 1; i++) {
        printf("%.4f, ", array[i]);
    }
        printf("%.4f", array[n-1]);
    printf("\n\n");
}
