#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include "biblioteca.h"

main() {
    
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

    Paciente* t1 = copyArray(pacientes_db,tam);
    Paciente* t2 = copyArray(pacientes_db,tam);
    Paciente* t3 = copyArray(pacientes_db,tam);
    
    printf("idade: \n");
    quickSort_idade(t1, 0,tam -1);
    printArrayPacientes(t1,tam);

    printf("renda: \n");
    quickSort_renda_salarial(t2, 0,tam -1);
    printArrayPacientes(t2,tam);

    printf("qtdd moradores: \n");
    quickSort_qtdd_moradores(t3, 0,tam -1);
    printArrayPacientes(t3,tam);


}