#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------------------

// Ejemplo 01:

/*

int main(void)
{
    char msj[8] = {0};
    char *arrCD = NULL;
    arrCD = malloc(8);

    strcpy(msj, "hola");
    printf("\nmsj -> %s\n", msj);

    strcpy(arrCD, "hola");
    printf("\narrCD -> %s\n", arrCD);
    free(arrCD);

    return 0;
}
*/

// --------------------------------------------------------------

// Ejemplo 02:

/*

char *crearArr(int tam);
void cargarArrCD(char *arrCD, int t);

int main(void)
{
    char *arrCD = NULL;
    int tam = 8;
    arrCD = crearArr(tam);

    if (arrCD != NULL)
    {
        printf("Ingrese palabra: ");
        cargarArrCD(arrCD, tam);
        printf("\n%s\n", arrCD);
        free(arrCD);
    }

    return 0;
}

char *crearArr(int tam)
{
    return (char *)malloc(tam);
}

void cargarArrCD(char *arrCD, int t)
{
    int i;
    int c = getchar();

    for (i = 0; i < t - 1 && c != '\n'; i++)
    {
        *(arrCD + i) = c; // arrCD[i] = c;
        c = getchar();
    }

    *(arrCD + i) = '\0';
}

*/

// --------------------------------------------------------------

// Ejemplo 03:

/*

char *cargarArrCD(int tam);

int main(void)
{
    char *arrCD = NULL;
    int tam = 8;
    arrCD = cargarArrCD(tam);

    if (arrCD != NULL)
    {
        printf("\n%s\n", arrCD);
        free(arrCD);
    }

    return 0;
}

char *cargarArrCD(int tam)
{
    char *arrCD = (char *)malloc(tam);
    int i;

    if (arrCD != NULL)
    {
        int c = getchar();

        for (i = 0; i < tam - 1 && c != '\n'; i++)
        {
            *(arrCD + i) = c; // arrCD[i] = c;
            c = getchar();
        }

        *(arrCD + i) = '\0';
    }

    return arrCD;
}

*/

// --------------------------------------------------------------

// Ejemplo 04: pasando con doble puntero por parametro, no retorna

/*

void cargarArrCD(char **arrCD, int tam);

int main(void)
{
    char *arrCD = NULL;
    int tam = 8;

    cargarArrCD(&arrCD, tam);

    if (arrCD != NULL)
    {
        printf("\n%s", arrCD);
        free(arrCD);
    }

    return 0;
}

void cargarArrCD(char **arrCD, int tam)
{
    *arrCD = (char *)malloc(tam);
    int i;

    if (*arrCD != NULL)
    {
        int c = getchar();

        for (i = 0; i < tam - 1 && c != '\n'; i++)
        {
            *((*arrCD) + i) = c; // *arrCD[i] = c;
            c = getchar();
        }

        *((*arrCD) + i) = '\0';
    }
}

*/

// --------------------------------------------------------------

// Ejemplo 05: realloc

void cargarArrCD(char **arrCD);

int main(void)
{
    char *arrCD = NULL;
    int tam = 8;

    cargarArrCD(&arrCD);

    if (arrCD != NULL)
    {
        printf("\n%s", arrCD);
        free(arrCD);
    }

    return 0;
}

void cargarArrCD(char **arrCD)
{
    *arrCD = (char *)malloc(sizeof(char));
    int i = 0;

    if (*arrCD != NULL)
    {
        int c = getchar();

        while (c != '\n')
        {
            *((*arrCD) + i) = c; // *arrCD[i] = c;
            i++;
            *arrCD = (char *)realloc(*arrCD, sizeof(char) * (i + 1));
            c = getchar();
        }
        *((*arrCD) + i) = '\0';
    }
}