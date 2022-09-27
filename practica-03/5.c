#include <stdio.h>

typedef struct
{
    int a, b, c;
} t_tres;

void ordenar(t_tres *valores);

int main(void)
{
    t_tres valores = {3, 9, 6};

    printf("\nLos valores sin ordenar son: %d %d %d\n", valores.a, valores.b, valores.c);

    ordenar(&valores);

    printf("\nLos valores ordenados son: %d %d %d\n\n", valores.a, valores.b, valores.c);

    return 0;
}

void ordenar(t_tres *valores)
{
    int *val[3] = {&valores->a, &valores->b, &valores->c};
    int i, j;
    int aux;

    for (i = 0; i < 2; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            if (*val[i] > *val[j])
            {
                aux = *val[i];
                *val[i] = *val[j];
                *val[j] = aux;
            }
        }
    }
}