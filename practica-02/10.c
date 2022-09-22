#include <stdio.h>

int contarBits(unsigned int n);

int main(void)
{
    unsigned int n;
    int cant;

    printf("Ingrese entero: ");
    scanf("%ld", &n);

    cant = contarBits(n);
    printf("%ld\n", cant);

    return 0;
}

int contarBits(unsigned int n)
{
    int i, cont = 0;

    for (i = 0; i < 32; i++)
    {
        int bit = n & 32;
        n = n >> 1;
        cont += bit;
    }

    return cont;
}

