#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 50
#define C 50
#define TERM_STR '\0'
#define TERM_DATO -999

void cargarMatTit(char matTit[F][C], char nomArch[100]);
void cargarMatEquipos(char matEquipos[F][C], char nomArch[100]);
void cargarMatDatos(int matDatos[F][C], char nomArch[100]);
void imprimirTit(char matTit[F][C]);
void ordenarTabla(char matEquipos[F][C], int matDatos[F][C], int col, int ord);
void imprimirTabla(char matTit[F][C], char matEquipos[F][C], int matDatos[F][C]);

int main(void)
{
    int matDatos[F][C] = {0};
    char matTit[F][C] = {0};
    char matEquipos[F][C] = {0};
    int col, ord;

    cargarMatTit(matTit, "./cabeceras.txt");
    cargarMatEquipos(matEquipos, "./items.txt");
    cargarMatDatos(matDatos, "./datos.txt");

    printf("\nMatriz original:\n");
    imprimirTit(matTit);
    imprimirTabla(matTit, matEquipos, matDatos);

    printf("\nMatriz ordenada:\n");
    ordenarTabla(matEquipos, matDatos, 2, 1);
    imprimirTit(matTit);
    imprimirTabla(matTit, matEquipos, matDatos);

    return 0;
}

void cargarMatTit(char matTit[F][C], char nomArch[100])
{
    int i = 0, j = 0, leido = 0;
    FILE *arch;

    arch = fopen(nomArch, "r");
    leido = fgetc(arch);

    while ((i < F - 1) && (leido != EOF))
    {
        j = 0;
        while ((j < C - 1) && (leido != EOF) && (leido != '\n'))
        {
            matTit[i][j] = leido;
            leido = fgetc(arch);
            j++;
        }
        matTit[i][j] = TERM_STR;
        i++;

        if (leido != EOF)
        {
            leido = fgetc(arch);
        }
    }
    matTit[i][0] = TERM_STR;

    fclose(arch);
}

void cargarMatEquipos(char matEquipos[F][C], char nomArch[100])
{
    int i = 0, j = 0, leido = 0;
    FILE *arch;

    arch = fopen(nomArch, "r");
    leido = fgetc(arch);

    while ((i < F - 1) && (leido != EOF))
    {
        j = 0;
        while ((j < C - 1) && (leido != EOF) && (leido != '\n'))
        {
            matEquipos[i][j] = leido;
            leido = fgetc(arch);
            j++;
        }
        matEquipos[i][j] = TERM_STR;
        i++;

        if (leido != EOF)
        {
            leido = fgetc(arch);
        }
    }
    matEquipos[i][j] = TERM_STR;

    fclose(arch);
}

void cargarMatDatos(int matDatos[F][C], char nomArch[100])
{
    int i = 0;
    FILE *arch;

    arch = fopen(nomArch, "r");
    fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d\n", &matDatos[i][0], &matDatos[i][1], &matDatos[i][2], &matDatos[i][3], &matDatos[i][4], &matDatos[i][5], &matDatos[i][6], &matDatos[i][7]);
    matDatos[i][8] = TERM_DATO;
    i = 1;

    while (!feof(arch) && i < F - 1)
    {
        fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d\n", &matDatos[i][0], &matDatos[i][1], &matDatos[i][2], &matDatos[i][3], &matDatos[i][4], &matDatos[i][5], &matDatos[i][6], &matDatos[i][7]);
        matDatos[i][8] = TERM_DATO;
        i++;
    }
    matDatos[i][0] = TERM_DATO;

    fclose(arch);
}

void imprimirTit(char matTit[F][C])
{
    int i = 0, j = 0;

    printf("%-20s", matTit[0]);
    for (i = 1; i < F - 1 && matTit[i][0] != TERM_STR; i++)
    {
        printf("%6s", &matTit[i][0]);
    }
    printf("\n---------------------------------------------------------------------\n");
}

void ordenarTabla(char matEquipos[F][C], int matDatos[F][C], int col, int ord)
{
    int i, j, k, aux;
    char auxStr[C];
    col = col - 1;

    for (i = 0; i < F - 1 && matDatos[i][0] != TERM_DATO; i++)
    {
        for (j = i + 1; j < F - 1 && matDatos[j][0] != TERM_DATO; j++)
        {
            if (matDatos[i][col] < matDatos[j][col] && ord)
            {
                strcpy(auxStr, matEquipos[i]);
                strcpy(matEquipos[i], matEquipos[j]);
                strcpy(matEquipos[j], auxStr);

                for (int k = 0; k < 8; k++)
                {
                    aux = matDatos[i][k];
                    matDatos[i][k] = matDatos[j][k];
                    matDatos[j][k] = aux;
                }
            }

            else if (matDatos[i][col] > matDatos[j][col] && !ord)
            {
                strcpy(auxStr, matEquipos[i]);
                strcpy(matEquipos[i], matEquipos[j]);
                strcpy(matEquipos[j], auxStr);

                for (int k = 0; k < 8; k++)
                {
                    aux = matDatos[i][k];
                    matDatos[i][k] = matDatos[j][k];
                    matDatos[j][k] = aux;
                }
            }
        }
    }
}

void imprimirTabla(char matTit[F][C], char matEquipos[F][C], int matDatos[F][C])
{
    int i = 0, j = 0;

    for (i = 0; i < F && matEquipos[i][0] != TERM_STR; i++)
    {
        printf("%-20s", matEquipos[i]);
        for (j = 0; j < C && matDatos[i][j] != TERM_DATO; j++)
        {
            if (j == 7 && matDatos[i][j] > 0)
            {
                printf("%+6d", matDatos[i][j]);
            }

            else
            {
                printf("%6d", matDatos[i][j]);
            }
        }
        printf("\n");
    }
}