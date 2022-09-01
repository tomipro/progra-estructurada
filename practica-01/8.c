#include <stdio.h>
#define F 3
#define C 3
#define TERM -999

void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);
void transponer(int mat[F][C]);

int main(void)
{
    int mat[F][C] = {0};

    cargarMat(mat);
    printf("\nMatriz original: \n");
    imprimirMat(mat);

    printf("\nMatriz transpuesta: \n");
    transponer(mat);
    imprimirMat(mat);

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

void transponer(int mat[F][C])
{
    int i, j, aux, k = 1;

    for (i = 0; mat[i][0] != TERM && i < F; i++)
    {
        for (j = k; mat[i][j] != TERM && j < C; j++)
        {
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
        k++;
    }
}
