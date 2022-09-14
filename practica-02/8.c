#include <stdio.h>

void funcion(unsigned char a);

int main(void)
{
    unsigned char a;

    printf("Ingrese un caracter: ");
    scanf("%c", &a);
    funcion(a);

    return 0;
}

void funcion(unsigned char a)
{
    int i;

    for (i = 7; i >= 0; i--)
    {
        if ((a >> i) & 1)
        {
            printf("1");
        }

        else
        {
            printf("0");
        }
    }
    printf("\n");
}