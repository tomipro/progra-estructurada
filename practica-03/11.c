#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a, b;
} t_dosint;

void intercambiarValores(t_dosint *valores);

int main(void)
{
    t_dosint valores = {1, 2};
    
    printf("Valores iniciales: {%d, %d}\n", valores.a, valores.b);

    intercambiarValores(&valores);

    printf("Valores finales: {%d, %d}\n", valores.a, valores.b);

    return 0;
}

void intercambiarValores(t_dosint *valores)
{
    int aux;

    aux = valores->a;
    valores->a = valores->b;
    valores->b = aux;
}
