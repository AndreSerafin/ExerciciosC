#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

struct Paciente {
    int idade;
    char sexo;
    float renda_salarial;
    char bairro[50];
    int qtdd_moradores;
};

// bubble
Paciente* bubble_idade(Paciente* array, int n);
Paciente* bubble_renda_salarial(Paciente* array, int n);
Paciente* bubble_qtdd_moradores(Paciente* array, int n);

// selection
Paciente* selection_idade(Paciente* array, int n);
Paciente* selection_renda_salarial(Paciente* array, int n);
Paciente* selection_qtdd_moradores(Paciente* array, int n);

// insertion
Paciente* insertion_idade(Paciente* array, int n);
Paciente* insertion_renda_salarial(Paciente* array, int n);
Paciente* insertion_qtdd_moradores(Paciente* array, int n);

// quick sort
Paciente* quickSort_idade(Paciente* array, int low, int high);
Paciente* quickSort_renda_salarial(Paciente* array, int low, int high);
Paciente* quickSort_qtdd_moradores(Paciente* array, int low, int high);

// merge sort
Paciente* mergeSort_idade(Paciente* array, int l, int r);
Paciente* mergeSort_renda_salarial(Paciente* array, int l, int r);
Paciente* mergeSort_qtdd_moradores(Paciente* array, int l, int r);

// heap sort
Paciente* heapSort_idade(Paciente* array, int n);
Paciente* heapSort_renda_salarial(Paciente* array, int n);
Paciente* heapSort_qtdd_moradores(Paciente* array, int n);

Paciente* copyArray(Paciente* array, int n);

void printArrayPacientes(Paciente* pacientes, int n);

#endif // BIBLIOTECA_H_INCLUDED