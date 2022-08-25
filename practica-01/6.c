#include <stdio.h>
#define T 100
#define TERM '\n'

void cargarText(char arr[T]);
void imprimirText(char arr[T]);
void normalizar(char arr[T]);
int len(char arr[T]);

int main(void)
{
    char arr[T] = {'\0'};

    cargarText(arr);
    printf("\n");
    imprimirText(arr);
    printf("\n");
    normalizar(arr);
    imprimirText(arr);
    printf("\n");

    return 0;
}

void cargarText(char arr[T])
{
    int i;
    char aux;

    for (i = 0; i < T - 1 && aux != TERM; i++)
    {
        aux = getchar();
        arr[i] = aux;
    }

    arr[i] = '\0';
}

void imprimirText(char arr[T])
{
    printf("%s", arr);
}

void normalizar(char arr[T])
{
    int i;
    int largo = len(arr);

    if (arr[largo - 1] != '.')
    {
        arr[largo - 1] = '.';
        // arr[largo] = '\0';
        largo++;
    }

    for (i = 0; i < T - 1 && arr[i] != '\0'; i++)
    {
        if (arr[0] >= 'a' && arr[0] <= 'z')
        {
            arr[0] = arr[0] - 32;
        }

        if (arr[i] == ' ' && arr[i + 1] == ' ' && arr[i] != '\0')
        {
            arr[i] = arr[i + 1];
        }
    }
}

int len(char arr[T])
{
    int i;

    for (i = 0; i < T - 1 && arr[i] != '\0'; i++)
        ;

    return i;
}