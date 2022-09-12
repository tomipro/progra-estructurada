#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct s_punto
{
    int x, y;
};
typedef struct s_punto p_punto;

float distPuntos(p_punto origen, p_punto p1, p_punto p2);

int main(void)
{
    p_punto origen = {0, 0};
    p_punto p1 = {0, 0};
    p_punto p2 = {0, 0};
    float distancia;

    printf("Ingrese primer punto (x, y): ");
    scanf("%d, %d", &p1.x, &p1.y);

    printf("Ingrese segundo punto (x, y): ");
    scanf("%d, %d", &p2.x, &p2.y);

    distancia = distPuntos(origen, p1, p2);
    if (distancia != 0)
    {
        printf("%.2f unidades\n", distancia);
    }

    else
    {
        printf("\n");
    }

    return 0;
}

float distPuntos(p_punto origen, p_punto p1, p_punto p2)
{
    float dist = 0;
    float dist1 = sqrt(fabs((pow((p1.x - origen.x), 2) - pow((p1.y - origen.y), 2))));
    float dist2 = sqrt(fabs((pow((p2.x - origen.x), 2) - pow((p2.y - origen.y), 2))));

    if (dist1 > dist2)
    {
        dist = dist1;
        printf("\nEl primer punto se encuentra mas lejos: ");
    }

    else if (dist1 < dist)
    {
        dist = dist2;
        printf("\nEl segundo punto se encuentra mas lejos: ");
    }

    else
    {
        printf("\nAmbos puntos se encuentran a la misma distancia. ");
    }

    return dist;
}
