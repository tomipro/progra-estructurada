#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n, o, p;
    char p1[26], p2[50];
    double a, b, c;
} t_varios;

void intercambiarValores(t_varios *val1, t_varios *val2);

int main(void)
{
    t_varios valor1 = {1, 2, 3, "Palabra1", "PalabraMasLarga1", 1.01, 1.02, 1.03};
    t_varios valor2 = {4, 5, 6, "Palabra2", "PalabraMasLarga2", 2.01, 2.02, 2.03};

    printf("\nLos valores originales son:\n");
    printf("%d %d %d %s %s %lf %lf %lf\n", valor1.n, valor1.o, valor1.p, valor1.p1, valor1.p2, valor1.a, valor1.b, valor1.c);
    printf("%d %d %d %s %s %lf %lf %lf\n", valor2.n, valor2.o, valor2.p, valor2.p1, valor2.p2, valor2.a, valor2.b, valor2.c);

    intercambiarValores(&valor1, &valor2);

    printf("\nLos valores despues de intercambiar son:\n");
    printf("%d %d %d %s %s %lf %lf %lf\n", valor1.n, valor1.o, valor1.p, valor1.p1, valor1.p2, valor1.a, valor1.b, valor1.c);
    printf("%d %d %d %s %s %lf %lf %lf\n\n", valor2.n, valor2.o, valor2.p, valor2.p1, valor2.p2, valor2.a, valor2.b, valor2.c);

    printf("El tamaño del estructura \"t_varios\" es: %zu bytes\n\n", sizeof(t_varios));

    return 0;
}

void intercambiarValores(t_varios *val1, t_varios *val2)
{
    t_varios aux;

    aux = *val1;
    *val1 = *val2;
    *val2 = aux;
}