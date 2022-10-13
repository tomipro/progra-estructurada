// WIP
#include <stdio.h>
#include <stdlib.h>

void invertir(int *arr, unsigned int cantidad);

int main(void)
{
    int *arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned int cantidad = 10;

    invertir(arr, cantidad);
    // mostrarArr(&arr, cantidad);

    return 0;
}

void invertir(int *arr, unsigned int cantidad)
{
    int aux;

    if (cantidad > 0)
    {
        aux = arr[cantidad];
        arr[cantidad] = arr[0];
        arr[0] = aux;
        invertir(arr, cantidad - 1);
    }
}
