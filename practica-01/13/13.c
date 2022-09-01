// wip
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 30
#define C 30
#define TERM_STR '\0'
#define TERM_DATO -999

void cargarMatDatos(int mat[F][C]);
void cargarMatTit(char matTit[F][C]);
void cargarMatEquipos(char matTit[F][C]);
void imprimirTit(char matTit[F][C]);
void ordenarTabla(char matEquipos[F][C], int matDatos[F][C], int col, int ord);
void imprimirTabla(char matTit[F][C], char matEquipos[F][C], int matDatos[F][C]);

int main(void)
{
    int matDatos[F][C] = {0};
    char matTit[F][C] = {0};
    char matEquipos[F][C] = {0};
    int col, ord;

    cargarMatTit(matTit);
    cargarMatEquipos(matEquipos);
    cargarMatDatos(matDatos);

    ordenarTabla(matEquipos, matDatos, col, ord);
    imprimirTit(matTit);
    imprimirTabla(matTit, matEquipos, matDatos);

    return 0;
}
