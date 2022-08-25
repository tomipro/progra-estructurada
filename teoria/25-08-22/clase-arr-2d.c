#include <stdio.h>
#include <string.h>
#define T 8
#define TERM_I -999
#define F 10
#define C 10

int len(char arr[]);
// void imprimirMatC(char matC[F][C]);
void imprimirMatC2(char matC[F][C]);
void imprimirMatI(int matI[F][C]);
void cargarMatC(char matC[F][C]);
void cargarMatI(int matI[F][C]);

int main(void)
{
    char matC[F][C] = {0};
    int matI[F][C] = {{12, 14, 20, TERM_I}, {13, 29, 27, TERM_I}, {29, 18, 22, TERM_I}, {TERM_I, 0, 0, 0}};

    cargarMatC(matC);
    imprimirMatC2(matC);
    imprimirMatI(matI);

    return 0;
}

int len(char arr[])
{
    int i;

    for (i = 0; arr[i] != '\0'; i++)
        ;

    return i;
}

void imprimirArrI(int arrI[])
{
    int i;

    for (i = 0; arrI[i] != 0 && i < T; i++)
    {
        printf("%5d\n", arrI[i]);
    }
}

void cargarMatC(char matC[F][C])
{
    strcpy(matC[0], "Hola");
    strcpy(matC[1], "hoy");
    strcpy(matC[2], "es");
    strcpy(matC[3], "jueves");
    matC[4][0] = '\0';
}

/*
void imprimirMatC(char matC[F][C])
{
    int i = 0;

    for (i = 0; matC[i][0] != '\0' && i < F - 1; i++)
    {
        printf("%s\n", matC[i]);
    }
}
*/

void imprimirMatC2(char matC[F][C])
{
    int i = 0, j = 0;

    for (i = 0; matC[i][0] != '\0' && i < F - 1; i++)
    {
        for (j = 0; matC[i][j] != '\0' && j < C - 1; j++)
        {
            printf("%c", matC[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatI(int matI[F][C])
{
    int i = 0, j = 0;

    for (i = 0; matI[i][0] != TERM_I && i < F - 1; i++)
    {
        for (j = 0; matI[i][j] != TERM_I && j < C - 1; j++)
        {
            printf("%6d", matI[i][j]);
        }
        printf("\n");
    }
}