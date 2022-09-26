#include <stdio.h>
#include <string.h>

#define N 50

struct s_generacion
{
    char central[N];
    char region[N];
    char fuente[N];
    int generacion;
    unsigned long int fecha;
};
typedef struct s_generacion t_generacion;

void cargarMat(t_generacion gen[N], char nomArch[N]);
void imprimirMat(t_generacion gen[N], char fuente[N]);
void ordYfiltrar(t_generacion gen[N]);
int decodificarAnio(unsigned long int fecha);
int decodificarMes(unsigned long int fecha);

int main(void)
{
    t_generacion gen[N] = {0};
    char central[N];

    cargarMat(gen, "./02.txt");

    strcpy(central, "CAPE");

    printf("\nOrdenada y filtrada:\n");
    ordYfiltrar(gen);
    imprimirMat(gen, central);

    return 0;
}

void cargarMat(t_generacion gen[N], char nomArch[N])
{
    int i = 0, r;
    FILE *arch;

    arch = fopen(nomArch, "r");

    r = fscanf(arch, "%[^,],%[^,],%[^,],%d,%ld\n", gen[i].central, gen[i].region, gen[i].fuente, &gen[i].generacion, &gen[i].fecha);

    for (i = 1; !feof(arch); i++)
    {
        r = fscanf(arch, "%[^,],%[^,],%[^,],%d,%ld\n", gen[i].central, gen[i].region, gen[i].fuente, &gen[i].generacion, &gen[i].fecha);
    }

    gen[i].fecha = -999;

    fclose(arch);
}

void imprimirMat(t_generacion gen[N], char fuente[N])
{
    int i;

    for (i = 0; gen[i].fecha != -999; i++)
    {
        if (strcmp(gen[i].central, fuente) == 0)
        {
            printf("%s,%s,%s,%d,%d/%d\n", gen[i].central, gen[i].region, gen[i].fuente, gen[i].generacion, decodificarAnio(gen[i].fecha), decodificarMes(gen[i].fecha));
        }
    }
    printf("\n");
}

void ordYfiltrar(t_generacion gen[N])
{
    int i, j, aux;
    char auxStr[N];

    for (i = 0; gen[i].fecha != -999; i++)
    {
        for (j = 0; gen[j].fecha != -999; j++)
        {
            if (gen[i].generacion > gen[j].generacion)
            {
                strcpy(auxStr, gen[i].central);
                strcpy(gen[i].central, gen[j].central);
                strcpy(gen[j].central, auxStr);

                strcpy(auxStr, gen[i].region);
                strcpy(gen[i].region, gen[j].region);
                strcpy(gen[j].region, auxStr);

                strcpy(auxStr, gen[i].fuente);
                strcpy(gen[i].fuente, gen[j].fuente);
                strcpy(gen[j].fuente, auxStr);

                aux = gen[i].generacion;
                gen[i].generacion = gen[j].generacion;
                gen[j].generacion = aux;

                aux = gen[i].fecha;
                gen[i].fecha = gen[j].fecha;
                gen[j].fecha = aux;
            }
        }
    }
}

int decodificarAnio(unsigned long int fecha)
{
    return (fecha >> 20);
}

int decodificarMes(unsigned long int fecha)
{
    fecha = fecha >> 16;
    fecha = fecha & 15;
    return fecha;
}