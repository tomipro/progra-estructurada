#include <stdio.h>
#include <string.h>

struct s_fecha
{
    int dia, mes, anio;
};
typedef struct s_fecha t_fecha;

struct s_punto
{
    double x, y, z;
    char nom[25];
    t_fecha fecha;
};
typedef struct s_punto t_punto;

void imprimirPunto(t_punto p);

int main(void)
{
    t_punto arrP[50];
    t_punto pa;
    t_punto pb = {1, 2, 3, 0};
    int i = 0;

    arrP[i].x = 10;
    arrP[i].y = 11;
    arrP[i].z = 11;
    strcpy(arrP[i].nom, "Luna");
    arrP[i].fecha.dia = 18;
    arrP[i].fecha.mes = 3;
    arrP[i].fecha.anio = 1972;

    // printf("\n%10s: (%6.2f%6.2f%6.2f) - ", arrP[i].nom, arrP[i].x, arrP[i].y, arrP[i].z);
    // printf("%5d/%2d/%2d\n\n", arrP[i].fecha.anio, arrP[i].fecha.mes, arrP[i].fecha.dia);

    imprimirPunto(arrP[i]);

    // printf("%10s: (%6.2f%6.2f%6.2f)\n", arrP[i].nom, arrP[i].x, arrP[i].y, arrP[i].z);
    /*
    pa.x = 10;
    pa.y = 11;
    pa.z = 12;

    strcpy(pa.nom, "Luna");
    pa.nom[0] = 'l';
    */

    // printf("%10s: (%6.2f%6.2f%6.2f)\n", pa.nom, pa.x, pa.y, pa.z);

    // pb = pa;
    // printf("(%6.2f%6.2f%6.2f)\n", pb.x, pb.y, pb.z);
    // printf("%10s: (%6.2f%6.2f%6.2f)\n", pb.nom, pb.x, pb.y, pb.z);

    return 0;
}

void imprimirPunto(t_punto p)
{
    printf("\n%10s: (%6.2f%6.2f%6.2f) - ", p.nom, p.x, p.y, p.z);
    printf("%5d/%2d/%2d\n\n", p.fecha.anio, p.fecha.mes, p.fecha.dia);
}
