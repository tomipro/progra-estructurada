#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct producto
{
    char *nombre;
    int cant;
    double precio;
    int id;
};
typedef struct producto prod;

void cargarStringDin()
{
    char *arreglo = NULL;
    int i = 0;
    arreglo = malloc(sizeof(char));
    char letra = getchar();
    while (letra != '\n')
    {
        *(arreglo + i) = letra; // arreglo[i]
        i++;
        arreglo = realloc(arreglo, (i + 1) * sizeof(char));
        letra = getchar();
    }
    arreglo[i] = '\0';
    printf("\n\n%s", arreglo);
    free(arreglo);
    return;
}

void cargarStringDinArchivo()
{
    struct producto *arreglo = NULL;
    FILE *arch = fopen("datos.txt", "r");
    arreglo = (struct producto *)malloc(sizeof(struct producto));
    prod prod1;
    int caracter = fgetc(arch);
    int i, j = 0, c;
    while (caracter != EOF)
    {

        i = 0;
        // char* arregloDinamico = NULL;
        prod1.nombre = NULL;
        prod1.nombre = malloc(sizeof(char));
        while (caracter != ',')
        {
            *(prod1.nombre + i) = caracter;
            i++;
            prod1.nombre = realloc(prod1.nombre, (i + 1) * sizeof(char));
            caracter = fgetc(arch);
        }
        *(prod1.nombre + i) = '\0';

        // strcpy(prod1.nombre,arregloDinamico);

        c = fscanf(arch, "%d,%lf,%d\n", &prod1.cant, &prod1.precio, &prod1.id);
        *(arreglo + j) = prod1;
        j++;

        caracter = fgetc(arch);
        if (caracter != EOF)
        {
            arreglo = (struct producto)realloc(arreglo, (j + 1)sizeof(struct producto));
        }
    }
    // arreglo[i] = '\0';
    // printf("\n\n%s",arreglo);
    fclose(arch);
    printf("ARTICULO    CANTIDAD    PRECIO  CODIGO\n");

    for (int j = 0; j < 4; j++)
    {
        printf("%s  %d  %lf     %d \n", arreglo[j].nombre, arreglo[j].cant, arreglo[j].precio, arreglo[j].id);
    }

    return;
}

int main()
{
    cargarStringDinArchivo();
    return 0;
}