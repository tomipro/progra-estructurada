#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int operacion(int a, int b, char op);

int main(void)
{
    int a, b;
    char op;
    printf("Ingrese primer numero: ");
    scanf("%d", &a);
    printf("Ingrese segundo numero: ");
    scanf("%d", &b);
    printf("Ingrese una operacion: [+ - * /]: ");
    scanf(" %c", &op);


    printf("El resultado de la operacion es: %d\n", operacion(a, b, op));

    return 0;
}

int operacion(int a, int b, char op)
{
    int res;

    if (op == '+')
    {
        res = a + b;
    }
    else if (op == '-')
    {
        res = a - b;
    }
    else if (op == '*')
    {
        res = a * b;
    }
    else if (op == '/')
    {
        res = a / b;
    }
    else
    {
        printf("Error. Operacion no valida");
    }

    return res;
}
