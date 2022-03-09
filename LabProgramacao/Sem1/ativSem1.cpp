#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{

    for (int i = 0; i <= 4; i++)
    {

        int op;
        setlocale(LC_ALL, "Portuguese");
        printf("--------Escolha uma opcao---------\n");
        printf("1 - Calcular a area de um triangulo\n");
        printf("2 - Ordenar de forma crescente os valores\n");
        printf("3 - Ordenar de forma decrescente os valores\n");
        printf("4 - Calcular as raizes de uma equacao do 2º Grau\n");
        scanf("%i", &op);

        switch (op)
        {
        case 1:

            float area, alt, base;

            printf("Digite o valor da base do triangulo: ");
            scanf("%f", &base);

            printf("Digite o valor da altura do triangulo: ");
            scanf("%f", &alt);

            area = (base * alt) / 2;

            printf("O valor da area desse triangulo é: %.2f\n", area);

            break;

        case 2:

            int n1, n2, n3;
            printf("Digite tres numeros para coloca-los em ordem crescente: ");
            scanf("%i%i%i", &n1, &n2, &n3);

            if (n1 > n3)
            {
                int aux = n3;
                n3 = n1;
                n1 = aux;
            }
            if (n1 > n2)
            {
                int aux = n2;
                n2 = n1;
                n1 = aux;
            }
            if (n2 > n3)
            {
                int aux = n3;
                n3 = n2;
                n2 = aux;
            }

            printf("A ordem crescente é: %i,%i,%i\n", n1, n2, n3);

            break;

        case 3:

            int n4, n5, n6;
            printf("Digite tres numeros para coloca-los em ordem decrescente: ");
            scanf("%i%i%i", &n4, &n5, &n6);

            if (n4 < n6)
            {
                int aux = n6;
                n6 = n4;
                n4 = aux;
            }
            if (n4 < n5)
            {
                int aux = n5;
                n5 = n4;
                n4 = aux;
            }
            if (n5 < n6)
            {
                int aux = n6;
                n6 = n5;
                n5 = aux;
            }

            printf("A ordem decrescente é: %i,%i,%i\n", n4, n5, n6);

            break;

        case 4:

            float a, b, c, delta, raiz1, raiz2;
            printf("Digite o A da equacao: ");
            scanf("%f", &a);
            printf("Digite o B da equacao: ");
            scanf("%f", &b);
            printf("Digite o C da equacao: ");
            scanf("%f", &c);

            delta = pow(b, 2) - 4 * (a * c);

            if (delta >= 0)
            {

                raiz1 = ((-b) + sqrt(delta)) / 2;
                raiz2 = ((-b) - sqrt(delta)) / 2;

                printf("O delta da equacao e: %.1f\n", delta);
                printf("A raiz 1 da equacao e: %.1f\n", raiz1);
                printf("A raiz 2 da equacao e: %.1f\n", raiz2);
            }
            else
            {
                printf("A equacao nao possui raizes reais!\n");
            }
            break;
        }
    }
}