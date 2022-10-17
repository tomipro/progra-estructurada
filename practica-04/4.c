#include <stdio.h>
#include <stdlib.h>

void invertir(int *arr, unsigned int cantidad);
void imprimirArr(int *arr, unsigned int cantidad);

int main(void)
{
    unsigned int cantidad = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Arreglo original: ");
    imprimirArr(arr, cantidad);

    printf("Arreglo inverso: ");
    invertir(arr, cantidad);
    imprimirArr(arr, cantidad);

    return 0;
}

void invertir(int *arr, unsigned int cantidad)
{
    int aux = arr[0];

    arr[0] = arr[cantidad - 1];
    arr[cantidad - 1] = aux;

    if ((cantidad != 2) && (cantidad != 1))
    {
        invertir(arr + 1, cantidad - 2);
    }
}

void imprimirArr(int *arr, unsigned int cantidad)
{
    int i;

    for (i = 0; i < cantidad; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
