#include <stdio.h>

int cocienteR(int n1, int n2);

int main(void)
{
    int n1 = 14, n2 = 6;

    printf("%d\n", cocienteR(n1, n2));

    return 0;
}

int cocienteR(int n1, int n2)
{
    int aux = n1;

    if (n1 - n2 >= 0)
    {
        aux = cocienteR(n1 - n2, n2);
    }

    return aux;
}

