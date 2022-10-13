#include <stdio.h>

int productoR(int n1, int n2);

int main(void)
{
    int n1 = 3, n2 = 7;

    printf("%d\n", productoR(n1, n2));

    return 0;
}

int productoR(int n1, int n2)
{
    int aux = 0;

    if (n2 > 0)
    {
        aux = n1 + productoR(n1, n2 - 1);
    }

    return aux;
}