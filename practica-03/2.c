#include <stdio.h>

#define N 10

int *funcion(int arr[N], int pos);
void imprimirPos(int arr[N]);

int main(void)
{
    int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("\nDireccion de memoria del arreglo en la posicion [0]: %p\n", arr);
    imprimirPos(arr);

    return 0;
}

int *funcion(int arr[N], int pos)
{
    return arr + pos;
}

void imprimirPos(int arr[N])
{
    int i = 1;
    int *res;

    while (i < N)
    {
        res = funcion(arr, i);
        printf("\nDireccion de memoria del arreglo en la posicion [%d]: %p\n\n", i, res);
        i++;
    }
}
