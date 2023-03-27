#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include "biblioteca.h"

void menu_metodo_ordenacao();
void ordenacao_idade(int op, Paciente* pacientes, int tam);
void ordenacao_renda_salarial(int op, Paciente* pacientes, int tam);
void ordenacao_qtdd_moradores(int op, Paciente* pacientes, int tam);


int main() {

    setlocale(LC_ALL, "Portuguese");

    Paciente pacientes_db[] = {
        {22, 'M', 12400.20, "Jaiara", 4},
        {45, 'F', 1600.20, "Jundiai", 4},
        {19, 'F', 122200.50, "Vila Mariana", 2},
        {32, 'M', 2500.20, "Vila Madalena", 7},
        {41, 'F', 1750.80, "Jardim Paulista", 6},
        {26, 'M', 1900.25, "Pinheiros", 3},
        {52, 'F', 3000.00, "Vila Nova Conceicao", 10},
        {29, 'M', 1500.99, "Moema", 4}
    };

    int tam = sizeof(pacientes_db) / sizeof(pacientes_db[0]);
    
    printf("Ordenacao de pacientes!\n");

    bool key = false;

    do {

        printf("1 - Ordenar por Idade: \n"); 
        printf("2 - Ordenar por Renda Salarial: \n");
        printf("3 - Ordenar por Quantidade de Moradores na Residencia: \n");
        printf("4 - Imprimir Pacientes: \n");
        printf("5 - Sair: \n");

        int op1;
        scanf("%d", &op1);

        int op2;

        Paciente* p1 = pacientes_db;
        switch (op1) {
            case 1:
                menu_metodo_ordenacao();
                scanf("%d", &op2);
                ordenacao_idade(op2, p1, tam);
                break;
            case 2:
                menu_metodo_ordenacao();
                scanf("%d", &op2);
                ordenacao_renda_salarial(op2, p1, tam);
                break;
            
            case 3:
                menu_metodo_ordenacao();
                scanf("%d", &op2);
                ordenacao_qtdd_moradores(op2, p1, tam);
                break;
            case 4:
                printArrayPacientes(p1, tam);
                break;
            case 5:
                key = true;
                break;
            default:
                break;
        }
    
    } while (!key);
    

}

void menu_metodo_ordenacao() {
    
    printf("Selecione o Metodo de ordenacao\n");
    printf("1-Bubble Sort\n");
    printf("2-Select Sort\n");
    printf("3-Insertion Sort\n");
    printf("4-Quick Sort\n");
    printf("5-Merge Sort\n");
    printf("6-Heap Sort\n\n");
}

void ordenacao_idade(int op, Paciente* pacientes, int tam) {

    switch(op) {
        case 1:
            bubble_idade(pacientes, tam);
            break;
        case 2:
            selection_idade(pacientes, tam);
            break;
        case 3:
            insertion_idade(pacientes, tam);
            break;
        case 4:
            quickSort_idade(pacientes,0, tam - 1);
            break;
        case 5:
            mergeSort_idade(pacientes,0, tam - 1);
            break;
        case 6:
            heapSort_idade(pacientes, tam);
            break;
        default:
            printf("Opção Inválida!");
    }
}

void ordenacao_renda_salarial(int op, Paciente* pacientes, int tam) {

    switch(op) {
        case 1:
            bubble_renda_salarial(pacientes, tam);
            break;
        case 2:
            selection_renda_salarial(pacientes, tam);
            break;
        case 3:
            insertion_renda_salarial(pacientes, tam);
            break;
        case 4:
            quickSort_renda_salarial(pacientes,0, tam - 1);
            break;
        case 5:
            mergeSort_renda_salarial(pacientes,0, tam - 1);
            break;
        case 6:
            heapSort_renda_salarial(pacientes, tam);
            break;
        default:
            printf("Opção Inválida!");
    }
}

void ordenacao_qtdd_moradores(int op, Paciente* pacientes, int tam) {

    switch(op) {
        case 1:
            bubble_qtdd_moradores(pacientes, tam);
            break;
        case 2:
            selection_qtdd_moradores(pacientes, tam);
            break;
        case 3:
            insertion_qtdd_moradores(pacientes, tam);
            break;
        case 4:
            quickSort_qtdd_moradores(pacientes,0, tam - 1);
            break;
        case 5:
            mergeSort_qtdd_moradores(pacientes,0, tam - 1);
            break;
        case 6:
            heapSort_qtdd_moradores(pacientes, tam);
            break;
        default:
            printf("Opção Inválida!");
    }

}


