#include <stdio.h>

#define N 50

struct s_info
{
    char texto[N];
    unsigned int fecha;
};
typedef struct s_info t_info;

void cargarMat(t_info info[N], char nomArch[N]);
void imprimirMat(t_info info[N]);
int decodificarAnio(unsigned int fecha);
int decodificarMes(unsigned int fecha);

int main(void)
{
    t_info informacion[N] = {0};

    cargarMat(informacion, "./01.txt");
    imprimirMat(informacion);

    return 0;
}

void cargarMat(t_info info[N], char nomArch[N])
{
    int i = 0, r;
    FILE *arch;

    arch = fopen(nomArch, "r");

    r = fscanf(arch, "%[^,],%d\n", info[i].texto, &info[i].fecha);

    for (i = 1; !feof(arch); i++)
    {
        r = fscanf(arch, "%[^,],%d\n", info[i].texto, &info[i].fecha);
    }

    info[i].texto[0] = 0;
}

void imprimirMat(t_info info[N])
{
    int i;

    for (i = 0; info[i].texto[0] != 0; i++)
    {
        printf("%s: %d/%d\n", info[i].texto, decodificarAnio(info[i].fecha), decodificarMes(info[i].fecha));
    }
}

int decodificarAnio(unsigned int fecha)
{
    return (fecha >> 20);
}

int decodificarMes(unsigned int fecha)
{
    int num;

    num = fecha >> 16;
    num = num & 15;
    return num;
}

/*
Enunciado:

Crear una funcion que lea un archivo:

---------------------------------------

Comienzo de la cuarentena,2118362448
Compromiso de Juan,2117468160
Viaje a Europa,2113565021

---------------------------------------

Donde el anio esta en el bit 20-31 y el mes esta en el bit 16-19

00000000-00000000-0000000-0000000


*/