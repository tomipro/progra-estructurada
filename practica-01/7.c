#include <stdio.h>
#define F 3
#define C 3
#define TERM -999

void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);
int promMat(int mat[F][C]);
int len(int mat[F][C]);

int main(void)
{
    int mat[F][C] = {0};

    cargarMat(mat);
    printf("\nMatriz ingresada:\n\n");
    imprimirMat(mat);

    printf("\n");

    int suma = promMat(mat);
    int largo = len(mat);
    float promedio = suma / largo;

    printf("Promedio: %.2f\n", promedio);

    return 0;
}

void cargarMat(int mat[F][C])
{
    int i, j, num;

    for (i = 0; mat[i][0] != TERM && i < F; i++)
    {
        for (j = 0; mat[i][j] != TERM && j < C; j++)
        {
            printf("Ingrese numero [%d][%d]: ", i, j);
            scanf("%d", &num);
            mat[i][j] = num;
        }
    }
}

void imprimirMat(int mat[F][C])
{
    int i, j;

    for (i = 0; mat[i][0] != TERM && i < F; i++)
    {
        for (j = 0; mat[i][j] != TERM && j < C; j++)
        {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
}

int promMat(int mat[F][C])
{
    int i, j, prom = 0;

    for (i = 0; mat[i][0] != TERM && i < F; i++)
    {
        for (j = 0; mat[i][j] != TERM && j < C; j++)
        {
            prom = prom + mat[i][j];
        }
    }
    return prom;
}

int len(int mat[F][C])
{
    int i, j, largo = 0;

    for (i = 0; mat[i][0] != TERM && i < F; i++)
    {
        for (j = 0; mat[i][j] != TERM && j < C; j++)
        {
            largo += i;
        }
    }
    return largo;
}