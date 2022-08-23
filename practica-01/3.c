#include <stdio.h>
#define LARGO 100
#define TERM '\n'

void leer(char arr[LARGO]);
void reemplazar(char arr[LARGO]);

int main(void)
{
    char arr[LARGO] = {'\0'};

    printf("Ingrese texto: ");
    leer(arr);
    printf("%s\n", arr);
    reemplazar(arr);
    printf("%s\n", arr);

    return 0;
}

void leer(char arr[LARGO])
{
    int i;
    char aux;

    for (i = 0; aux != TERM && i < LARGO - 1; i++)
    {
        aux = getchar();
        arr[i] = aux;
    }

    arr[LARGO - 1] = '\0';
}

void reemplazar(char arr[LARGO])
{
    char car1 = ' ';
    char car2 = ' ';
    int i;

    printf("Ingrese caracter a reemplazar: ");
    car1 = getchar();
    fflush(stdin);
    printf("Ingrese caracter por el que reemplazar: ");
    car2 = getchar();

    for (i = 0; i < LARGO - 1; i++)
    {
        if (arr[i] == car1)
        {
            arr[i] = car2;
        }
    }
}