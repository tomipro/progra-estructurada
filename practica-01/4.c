#include <stdio.h>
#define T 100
#define TERM 0
#define TERM_INT '\0'

void cargarArr(int arr[T]);
void imprimirArr(int arr[T]);
void invertirArr(int arr[T]);
int lenArr(int arr[T]);
void ordenarArr(int arr[T]);

int main(void)
{
    int arr1[T] = {0};
    int arr2[T] = {0};

    printf("Arreglo 1 - Ingrese valores (0 para terminar): ");
    cargarArr(arr1);
    imprimirArr(arr1);
    invertirArr(arr1);
    imprimirArr(arr1);
    // int largoArr1 = lenArr(arr1);
    // printf("%d\n", largoArr1);

    printf("Arreglo 2 - Ingrese valores (0 para terminar): ");
    cargarArr(arr2);
    imprimirArr(arr2);
    ordenarArr(arr2);
    imprimirArr(arr2);

    return 0;
}

void cargarArr(int arr[T])
{
    int i;
    int aux;

    for (i = 0; i < T - 1 && aux != TERM; i++)
    {
        scanf("%d", &aux);
        arr[i] = aux;
    }

    arr[T - 1] = '\0';
}

void invertirArr(int arr[T])
{
    int largoArr = lenArr(arr);
    int temp;

    for (int i = 0; i < largoArr / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[largoArr - 1 - i];
        arr[largoArr - 1 - i] = temp;
    }
}

void imprimirArr(int arr[T])
{
    int i;

    for (i = 0; i < T - 1 && arr[i] != TERM; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int lenArr(int arr[T])
{
    int cont = 0;

    for (int i = 0; i < T - 1 && arr[i] != TERM_INT; i++)
    {
        cont++;
    }

    return cont;
}

void ordenarArr(int arr[T])
{
    int len = lenArr(arr);
    int i, j, aux;

    for (i = 0; i < len - 1; i++)
    {
        for (j = i + 1; j < len - 1; j++)
        {
            if (arr[i] < arr[j])
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}