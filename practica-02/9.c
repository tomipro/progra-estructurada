#include <stdio.h>

unsigned char shiftDerecha(unsigned int n, int cantidad);

int main(void)
{
    char n;
    int cant;

    printf("Ingrese char a shiftear: ");
    scanf("%c", &n);

    printf("Cuantas veces?: ");
    scanf("%d", &cant);

    n = shiftDerecha(n, cant);
    printf("\nEl nuevo valor ASCII es: %d -> %c\n", n, n);

    return 0;
}

unsigned char shiftDerecha(unsigned int n, int cantidad)
{
    int i;

    for (i = 0; i < cantidad; i++)
    {
        n = (n >> 1) & 255;
    }

    return n;
}