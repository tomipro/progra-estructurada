#include <stdio.h>

void funcion(int *num1, int *num2);

int main(void)
{
    int n1, n2;

    printf("Ingrese primer numero: ");
    scanf("%d", &n1);

    printf("Ingrese segundo numero: ");
    scanf("%d", &n2);

    printf("\nUsted ingreso:\n%d: %p\n%d: %p\n\n", n1, &n1, n2, &n2);
    funcion(&n1, &n2);
    printf("\nUsted ingreso:\n%d: %p\n%d: %p\n\n", n1, &n1, n2, &n2);

    return 0;
}

void funcion(int *num1, int *num2)
{
    int *aux;

    *aux = *num1;
    *num1 = *num2;
    *num2 = *aux;
}