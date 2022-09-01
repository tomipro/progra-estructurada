#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 30
#define C 50
#define N 25
#define TERM_STR '\0'

void cargarMatTexDeArch(char mat[F][C], char nomArch[100]);
void imprimirMat(char mat[F][C]);
int len(char mat[F][C]);
void ordenarTexto(char mat[F][C]);

int main(void)
{
    char mat[F][C] = {0};
    char nomArch[100] = "/Users/tomasprodan/Documents/progra-estructurada/practica-01/11/equipos.txt";

    printf("\nMatriz Original:\n");
    printf("-----------------\n");
    cargarMatTexDeArch(mat, nomArch);
    imprimirMat(mat);

    printf("\n\nMatriz Ordenada:\n");
    printf("-----------------\n");
    ordenarTexto(mat);
    imprimirMat(mat);
    printf("\n");

    return 0;
}

void cargarMatTexDeArch(char mat[F][C], char nomArch[50])
{
    int i = 0, j = 0, leido = 0;
    FILE *arch;

    arch = fopen(nomArch, "r");
    leido = fgetc(arch);

    while ((i < F - 1) && (leido != EOF))
    {
        j = 0;

        while ((j < C - 1) && (leido != EOF) && (leido != '\n') && (leido != '\t') && (leido != ','))
        {
            mat[i][j] = leido;
            leido = fgetc(arch);
            j++;
        }
        mat[i][j] = TERM_STR;
        i++;

        if (leido != EOF)
        {
            leido = fgetc(arch);
        }
    }
    mat[i][0] = TERM_STR;
}

void imprimirMat(char mat[F][C])
{
    int i, j;

    for (i = 0; i < F && mat[i][0] != TERM_STR; i++)
    {
        for (j = 0; j < C && mat[i][j] != TERM_STR; j++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

int len(char mat[F][C])
{
    int i;

    for (i = 0; i < F && mat[i][0] != TERM_STR; i++)
        ;
    return i;
}

void ordenarTexto(char mat[F][C])
{
    int i, j;
    char aux[C];

    int lenMat = len(mat);

    for (i = 0; i < lenMat - 1; i++)
    {
        for (j = i + 1; j < lenMat; j++)
        {
            if (strcmp(mat[i], mat[j]) > 0)
            {
                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}