#include <stdio.h>
#define F 30
#define C 20

void cargarMatTexDeArch(char mat[F][C], char nomArch[100]);
void imprimirMat(char mat[F][C]);

int main(void)
{
    char arch[100] = "/Users/tomasprodan/Documents/progra-estructurada/practica-01/10/equipos.txt";
    char mat[F][C] = {0};

    cargarMatTexDeArch(mat, arch);
    imprimirMat(mat);

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
        mat[i][j] = '\0';
        i++;
        if (leido != EOF)
        {
            leido = fgetc(arch);
        }
    }
    mat[i][0] = '\0';
}

void imprimirMat(char mat[F][C])
{
    int i, j;

    for (i = 0; i < F && mat[i][0] != '\0'; i++)
    {
        for (j = 0; j < C && mat[i][j] != '\0'; j++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}