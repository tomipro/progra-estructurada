#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_dato
{
    char *alumno;
    int *nota;
    float prom;
};
typedef struct s_dato t_dato;

struct s_nodo
{
    t_dato dato;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void imprimirR(t_nodo lista);
void cargarArch(const char *nomArchNombres, const char *nomArchNotas, t_nodo *nodo);
void cargarOrdenado(t_nodo *nodo, t_dato carga);
void eliminarDesaprobados(t_nodo *nodo, t_dato carga);
float promedio(int *notas);

int main(void)
{
    t_nodo lista = NULL;

    cargarArch("./04nombres.txt", "./04notas.txt", &lista);
    printf("\n%-30s%8s%15s", "NOMBRE", "NOTAS", "PROMEDIO");
    imprimirR(lista);
    printf("\n");

    t_dato aux = {NULL, 0, 6};
    eliminarDesaprobados(&lista, aux);
    printf("\n%-30s%8s%15s", "NOMBRE", "NOTAS", "PROMEDIO");
    imprimirR(lista);
    printf("\n");

    return 0;
}

void cargarArch(const char *nomArchNombres, const char *nomArchNotas, t_nodo *nodo)
{
    FILE *archNombres, *archNotas;
    t_dato aux;
    int i, c;

    archNombres = fopen(nomArchNombres, "r");
    archNotas = fopen(nomArchNotas, "r");

    while (!feof(archNombres) && !feof(archNotas))
    {
        aux.alumno = malloc(sizeof(char));

        c = fgetc(archNombres);
        for (i = 0; c != '\n'; i++)
        {
            aux.alumno[i] = c;
            aux.alumno = realloc(aux.alumno, i + 2);
            c = fgetc(archNombres);
        }
        aux.alumno[i] = 0;

        aux.nota = malloc(sizeof(int));
        fscanf(archNotas, "%d,%d,%d\n", &(aux.nota[0]), &(aux.nota[1]), &(aux.nota[2]));
        aux.nota[3] = -1;

        aux.prom = promedio(aux.nota);

        cargarOrdenado(nodo, aux);
    }

    fclose(archNombres);
    fclose(archNotas);
}

void cargarOrdenado(t_nodo *nodo, t_dato carga)
{
    t_nodo aux;

    if (!*nodo || (strcmp((*nodo)->dato.alumno, carga.alumno) > 0))
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->sig = (*nodo);
        aux->dato = carga;
        (*nodo) = aux;
    }

    else
    {
        cargarOrdenado(&((*nodo)->sig), carga);
    }
}

float promedio(int *notas)
{
    int i;
    float res = 0;

    for (i = 0; notas[i] != -1; i++)
    {
        res += notas[i];
    }

    return res / 3;
}

void eliminarDesaprobados(t_nodo *nodo, t_dato carga)
{
    t_nodo aux;

    if (*nodo)
    {
        if ((*nodo)->dato.prom >= carga.prom)
        {
            eliminarDesaprobados(&((*nodo)->sig), carga);
        }

        else
        {
            aux = (*nodo);
            *nodo = (*nodo)->sig;
            free(aux);
            eliminarDesaprobados(nodo, carga);
        }
    }
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("\n%-30s", lista->dato.alumno);
        for (int i = 0; lista->dato.nota[i] != -1; i++)
        {
            printf("%3d", lista->dato.nota[i]);
        }
        printf("%14.2f", lista->dato.prom);
        imprimirR(lista->sig);
    }
}
