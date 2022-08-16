#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


/*Escreva um programa em linguagem C que solicita ao usuário a quantidade de alunos de uma
turma e aloca um vetor de notas (números reais). Depois de ler as notas, imprime a média
aritmética. Obs: não deve ocorrer desperdício de memória; e após ser utilizada a memória deve
ser devolvida.*/

main() {
    
    float *notas, soma;
    int numNotas;

    printf("Digite a qunatidade de alunos: ");
    scanf("%d", &numNotas);

    notas = (float * ) (malloc(numNotas * sizeof(float)));
    double media;

    for (int i = 0; i < numNotas; i++) {
        printf("%d nota: \n", i + 1);
        scanf("%f", &notas[i]);
        media += notas[i];
    }

    free(notas);

    media /= numNotas;
    printf("%.2f", media);
    
}
