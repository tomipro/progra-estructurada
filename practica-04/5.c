#include <stdio.h>
#include <stdlib.h>

int numMaxArr(int *arr);
int *dirMemMaxArr(int *arr);
void imprimirArr(int *arr);

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 13, 5, 6, 11, 9, 0};

    printf("Arreglo: ");
    imprimirArr(arr);

    int maximo = numMaxArr(arr);
    int *dir = dirMemMaxArr(arr);

    printf("El valor maximo es %d y su direccion en memoria es <%p>\n", maximo, dir);

    return 0;
}

int numMaxArr(int *arr)
{
    int maximo = *arr;
    int aux;

    if (*arr != 0)
    {
        arr++;
        aux = numMaxArr(arr);

        if (aux > maximo)
        {
            maximo = aux;
        }
    }

    return maximo;
}

int *dirMemMaxArr(int *arr)
{
    int *maximo = arr;
    int *aux = NULL;

    if (*arr)
    {
        arr++;
        aux = dirMemMaxArr(arr);

        if (*aux > *arr)
        {
            maximo = aux;
        }
    }

    return maximo;
}

void imprimirArr(int *arr)
{
    int i;

    for (i = 0; arr[i] != 0; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}