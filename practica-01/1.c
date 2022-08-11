#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rondear(float num);

int main(void)
{
    float num;
    printf("Ingrese un numero: ");
    scanf("%f", &num);
    printf("Piso = %d\n", (int)num);
    printf("Techo =  %d\n", rondear(num));
    printf("Redondeo = %f\n", round(num));

    return 0;
}

int rondear(float num)
{
    return (int)round(num);
}