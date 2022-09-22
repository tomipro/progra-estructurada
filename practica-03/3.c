#include <stdio.h>
#include <math.h>

void funcion(double *num);

int main(void)
{
    double numero;
    
    printf("Ingrese numero de tipo double: ");
    scanf("%lf", &numero);
    
    funcion(&numero);
    printf("%.0f\n", numero);

    return 0;
}

void funcion(double *num)
{
    *num = round(*num);
}