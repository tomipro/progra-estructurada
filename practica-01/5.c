#include <stdio.h>
#define T 100

int esPos(int num);
int estaEnArr(int arr[T], int num);
void cargarArrPNR(int arr[T]);
void imprimirArr(int arr[T]);

int main(void)
{
    int arr[T] = {0};

    printf("Ingrese numeros enteros positivos:\n");
    cargarArrPNR(arr);
    imprimirArr(arr);

    return 0;
}

int esPos(int num)
{
    int res = 0;

    if (num >= 0)
    {
        res = 1;
    }

    return res;
}

int estaEnArr(int arr[T], int num)
{
    int res = 0;

    for (int i = 0; arr[i] != 0; i++)
    {
        if (arr[i] == num)
        {
            res = 1;
        }
    }

    return res;
}

void cargarArrPNR(int arr[T])
{
    int aux, i = 0;

    while (aux != 0)
    {
        scanf("%d", &aux);

        if (estaEnArr(arr, aux))
        {
            printf("El numero ingresado ya existe.\n");
        }

        else if (!esPos(aux))
        {
            printf("El numero ingresado es negativo.\n");
        }

        else
        {
            arr[i] = aux;
            i++;
        }
    }
}

void imprimirArr(int arr[T])
{
    for (int i = 0; i < T - 1 && arr[i] != 0; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}