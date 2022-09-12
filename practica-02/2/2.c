#include <stdio.h>
#include <math.h>
#define LEN 11

struct s_punto
{
    int x, y;
};
typedef struct s_punto p_punto;

float distancia(p_punto p1, p_punto p2);
void cargarPuntos(p_punto arr[LEN], char nomArch[50]);
void imprimirArr(p_punto arr[LEN]);
float distMinCons(p_punto arr[LEN]);
float distMinCualq(p_punto arr[LEN]);

int main(void)
{
    p_punto coord[LEN] = {0, 0};
    float distanciaCons, distanciaCualq;

    cargarPuntos(coord, "./puntos.csv");

    distanciaCons = distMinCons(coord);
    printf("\nLa distancia minima entre 2 puntos consecutivos es: %.2f\n", distanciaCons);

    distanciaCualq = distMinCualq(coord);
    printf("\nLa distancia minima entre 2 puntos cualquiera es: %.2f\n", distanciaCualq);

    printf("\nPuntos cargados:\n");
    imprimirArr(coord);

    return 0;
}

void cargarPuntos(p_punto arr[LEN], char nomArch[50])
{
    int i = 0;
    FILE *arch;

    arch = fopen(nomArch, "r");
    fscanf(arch, "%d, %d", &arr[i].x, &arr[i].y);
    i = 1;

    while (!feof(arch) && i < LEN - 1)
    {
        fscanf(arch, "%d, %d", &arr[i].x, &arr[i].y);
        i++;
    }

    fclose(arch);
}

void imprimirArr(p_punto arr[LEN])
{
    int i = 0, j = 0;

    for (i = 0; i < LEN - 1; i++)
    {
        printf("%5d %5d\n", arr[i].x, arr[i].y);
    }
}

float distancia(p_punto p1, p_punto p2)
{
    return sqrt((pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
}

float distMinCons(p_punto arr[LEN])
{
    int i, j;
    p_punto p1, p2;
    float distMin, dist;

    for (i = 0; i < LEN - 1; i++)
    {
        for (j = i + 1; j < LEN; j++)
        {
            p1 = arr[i];
            p2 = arr[j];
            dist = distancia(p1, p2);
            if (i == 0 || dist < distMin)
            {
                distMin = dist;
            }
        }
    }
    return distMin;
}

float distMinCualq(p_punto arr[LEN])
{
    int i;
    p_punto p1, p2;
    float distMin, dist;

    for (i = 0; i < LEN - 1; i++)
    {
        p1 = arr[i];
        p2 = arr[i + 1];
        dist = distancia(p1, p2);
        if (i == 0 || dist < distMin)
        {
            distMin = dist;
        }
    }
    return distMin;
}