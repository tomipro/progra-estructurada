#include <stdio.h>

float cocienteR(int n1, int n2);

int main(void)
{
    int n1 = 14, n2 = 6;

    printf("%.2f\n", cocienteR(n1, n2));

    return 0;
}

float cocienteR(int n1, int n2)
{
    float aux;

    if (n1 < n2)
    {
        aux = 0;
    }

    else
    {
        aux = 1 + cocienteR(n1 - n2, n2);
    }

    return aux;
}



