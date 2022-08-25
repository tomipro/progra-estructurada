#include <stdio.h>
#define T 8

int len(char arr[]);
void imprimirArrI(int arrI[]);

int main(void)
{
    char arrC[T] = "hola";
    int arrI[T] = {23, 33, 0, 55, 23, 33, 44, 55};

    printf("%s\n", arrC);
    imprimirArrI(arrI);

    return 0;
}

int len(char arr[])
{
    int i;

    for (i = 0; arr[i] != '\0'; i++);

    return i;
}

void imprimirArrI(int arrI[])
{
    int i;
    
    for (i = 0; arrI[i] != 0 && i < T; i++)
    {
        printf("%5d\n", arrI[i]);
    }
}