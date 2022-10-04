#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ejemplo 01:

/*
void f(int n);

int main(void)
{
    f(3);

    return 0;
}

void f(int n)
{
    printf("[%d]: Holi\n", n);

    if (n > 1)
    {
        f(n - 1);
    }

    printf("[%d]: Chauchi\n", n);
}
*/

// Ejemplo 02:

int sumaR(int n);

int sumaR(int n)
{
    int aux = 0;

    if (n > 0)
    {
        aux = n + sumaR(n - 1);
    }

    return aux;
}

int main(void)
{
    printf("%d\n", sumaR(5));

    return 0;
}