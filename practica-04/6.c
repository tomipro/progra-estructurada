#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j);
int *dirMemMinArr(int *arr);
void ordenarArr(int *arr);
void imprimirArr(int *arr);

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 13, 5, 6, 11, 9, 0};

    printf("Matriz original: ");
    imprimirArr(arr);
    
    ordenarArr(arr);
    printf("Matriz ordenada: ");
    imprimirArr(arr);

    return 0;
}

int *dirMemMinArr(int *arr)
{
    int *minimo = arr;
    int *aux = NULL;

    if (*arr != 0)
    {
        aux = dirMemMinArr(arr + 1);

        if ((*aux < *arr) && *(arr + 1) != 0)
        {
            minimo = aux;
        }
    }

    return minimo;
}

void swap(int *i, int *j)
{
    int aux;

    aux = *i;
    *i = *j;
    *j = aux;
}

void ordenarArr(int *arr)
{
    int *aux;

    if (*arr != 0)
    {
        aux = dirMemMinArr(arr);
        swap(arr, aux);
        ordenarArr(arr + 1);
    }
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