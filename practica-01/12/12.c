// wip
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 30
#define C 30
#define TERM_INT -999

void cargarMatNumDeArch(int mat[F][C], char nomArch[100]);
void imprimirMatNum(int mat[F][C], int fil, int col);

int main(void)
{
    int mat[F][C] = {0};
    char nomArch[100] = "/Users/tomasprodan/Documents/progra-estructurada/practica-01/12/puntos.txt";

    cargarMatNumDeArch(mat, nomArch);
    imprimirMatNum(mat, 8, 7);

    return 0;
}

void cargarMatNumDeArch(int mat[F][C], char nomArch[100])
{
    int i = 0;
    FILE *arch;

    arch = fopen(nomArch, "r");

    fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
    mat[i][8] = TERM_INT;

    i = 1;
    while (!feof(arch) && i < F - 1)
    {
        fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
        mat[i][8] = TERM_INT;
        i++;
    }
    mat[i][0] = TERM_INT;
}

void imprimirMatNum(int mat[F][C], int fil, int col)
{
    int i, j;

    for (i = 0; i < F && mat[i][0] != TERM_INT && i <= fil; i++)
    {
        for (j = 0; j < C && mat[i][j] != TERM_INT && j <= col; j++)
        {
            if (j == 7 && mat[i][j] > 0)
            {
                printf("%+5d", mat[i][j]);
            }

            else
            {
                printf("%5d", mat[i][j]);
            }
        }
        printf("\n");
    }
}