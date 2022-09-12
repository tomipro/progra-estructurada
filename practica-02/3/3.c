// wip
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 50
#define F 50
#define C 50
#define TERM_DATO -999
#define TERM_STR '\0'

struct s_datos
{
    char nomEquipo[TAM];
    int pg, pp, pe, gf, gc;
};
typedef struct s_datos t_datos;

void cargarDatos(t_datos datos[TAM], char archItems[TAM], char archDatos[TAM]);
void imprimirMat(t_datos datos);

int main(void)
{
    t_datos datos = {0};

    cargarDatos(datos, "./items.txt", "./datos.txt");
    imprimirMat(datos);

    return 0;
}

void cargarDatos(t_datos datos[TAM], char archItems[TAM], char archDatos[TAM])
{
    int i = 0, j = 0, r, leido = 0;
    FILE *archI, *archD;
    char aux;

    archI = fopen(archItems, "r");
    archD = fopen(archDatos, "r");

    while (i < F - 1 && !feof(archI) && !feof(archD))
    {
        t_datos dato;
        fscanf(archD, "%d, %d, %d, %d, %d\n", &dato.pg, &dato.pp, &dato.pe, &dato.gf, &dato.gc);
        
        j = 0;
        while (j < C - 1 && aux != '\n')
        {
            aux = fgetc(archI);
            dato.nomEquipo[j] = aux;
            j++;
        }
        dato.nomEquipo[j - 1] = TERM_STR;
        i++;
    }

    fclose(archI);
    fclose(archD);
}

void imprimirMat(t_datos datos)
{
    int i = 0;

    while (i < F - 1)
    {
        t_datos info = datos[i];
        printf("%-15s %5d %5d %5d %5d %d\n", info.nomEquipo, info.pg, info.pp, info.pe, info.gf, info.gc);
        i++;
    }
}