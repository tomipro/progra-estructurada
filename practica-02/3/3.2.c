#include <stdio.h>
#include <string.h>

#define T 50
#define N 10

struct s_datos
{
    char nomEquipo[T];
    int pts, pj, pg, pe, pp, gf, gc, dif;
};
typedef struct s_datos t_datos;

void cargarDatos(t_datos datos[N], char nomArchDatos[T], char nomArchItems[T]);
void imprimirTabla(t_datos datos[N]);
void ordenarTabla(t_datos datos[N], int col);

int main(void)
{
    t_datos datos[N] = {0};

    cargarDatos(datos, "./datos.txt", "./items.txt");

    printf("Tabla Original:\n");
    imprimirTabla(datos);

    printf("\nTabla Ordenada Por Puntos:\n");
    ordenarTabla(datos, 1);
    imprimirTabla(datos);

    printf("\nTabla Ordenada Por DIF:\n");
    ordenarTabla(datos, 8);
    imprimirTabla(datos);

    printf("\nTabla Ordenada Por GF:\n");
    ordenarTabla(datos, 6);
    imprimirTabla(datos);

    return 0;
}

void cargarDatos(t_datos datos[N], char nomArchDatos[T], char nomArchItems[T])
{
    int i = 0, j = 0, r;
    FILE *archD, *archI;

    archD = fopen(nomArchDatos, "r");
    archI = fopen(nomArchItems, "r");

    r = fscanf(archD, "%d, %d, %d, %d, %d, %d, %d, %d\n", &datos[i].pts, &datos[i].pj, &datos[i].pg, &datos[i].pe, &datos[i].pp, &datos[i].gf, &datos[i].gc, &datos[i].dif);
    for (i = 1; i < N; i++)
    {
        r = fscanf(archD, "%d, %d, %d, %d, %d, %d, %d, %d\n", &datos[i].pts, &datos[i].pj, &datos[i].pg, &datos[i].pe, &datos[i].pp, &datos[i].gf, &datos[i].gc, &datos[i].dif);
    }

    r = fscanf(archI, "%[^\n]\n", datos[j].nomEquipo);
    for (j = 1; j < N; j++)
    {
        r = fscanf(archI, "%[^\n]\n", datos[j].nomEquipo);
    }

    fclose(archD);
    fclose(archI);
}

void imprimirTabla(t_datos datos[N])
{
    int i, j;

    printf("%-20s %-3s %-3s %-3s %-3s %-3s %-3s %-3s %-3s\n", "Equipo", "PTS", "PJ", "PG", "PE", "PP", "GF", "GC", "DIF");
    printf("-----------------------------------------------------\n");

    for (i = 0; i < N && datos[i].pj != 0; i++)
    {
        printf("%-20s %-3d %-3d %-3d %-3d %-3d %-3d %-3d", datos[i].nomEquipo, datos[i].pts, datos[i].pj, datos[i].pg, datos[i].pe, datos[i].pp, datos[i].gf, datos[i].gc);
        if (datos[i].dif <= 0)
        {
            printf(" %-3d\n", datos[i].dif);
        }

        else
        {
            printf(" +%-3d\n", datos[i].dif);
        }
    }
}

void ordenarTabla(t_datos datos[N], int col)
{
    int i, j;
    t_datos aux;

    for (i = 0; datos[i].pj != 0; i++)
    {
        for (j = 0; datos[j].pj != 0; j++)
        {
            if (((col == 1) && (datos[i].pts > datos[j].pts)) || (col == 6) && (datos[i].gf > datos[j].gf) || ((col == 8) && (datos[i].dif > datos[j].dif)))
            {
                aux = datos[i];
                datos[i] = datos[j];
                datos[j] = aux;
            }
        }
    }
}
