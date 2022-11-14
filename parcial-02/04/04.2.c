#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_contenido
{
    char *nombre;
    int *notas;
    float promedio;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void cargarArch(const char *nomArchNombres, const char *nomArchNotas, t_nodo *nodo);
void insertarOrdenado(t_nodo *nodo, t_contenido carga);
void borrar(t_nodo *nodo);
void push(t_nodo *nodo, t_contenido carga);
void imprimirR(t_nodo lista);

int main(void)
{
    t_nodo lista = NULL;

    cargarArch("./04nombres.txt", "./04notas.txt", &lista);
    imprimirR(lista);

    printf("\n");
    borrar(&lista);
    imprimirR(lista);

    return 0;
}

void cargarArch(const char *nomArchNombres, const char *nomArchNotas, t_nodo *nodo)
{
    FILE *archNombres, *archNotas;
    t_contenido aux;
    int i, c;

    archNombres = fopen(nomArchNombres, "r");
    archNotas = fopen(nomArchNotas, "r");

    while (!feof(archNombres) && !feof(archNotas))
    {
        aux.nombre = malloc(sizeof(char));
        c = fgetc(archNombres);

        for (i = 0; c != '\n'; i++)
        {
            aux.nombre[i] = c;
            aux.nombre = realloc(aux.nombre, i + 2);
            c = fgetc(archNombres);
        }
        aux.nombre[i] = 0;

        aux.notas = malloc(sizeof(int));
        fscanf(archNotas, "%d,%d,%d\n", &aux.notas[0], &aux.notas[1], &aux.notas[2]);
        aux.notas[3] = -1;

        insertarOrdenado(nodo, aux);
    }

    fclose(archNombres);
    fclose(archNotas);
}

void insertarOrdenado(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux;

    if (!*nodo)
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->sig = (*nodo);
        aux->content = carga;
        (*nodo) = aux;
    }

    else
    {
        insertarOrdenado(&((*nodo)->sig), carga);
    }
}

void borrar(t_nodo *nodo)
{
    t_nodo aux;

    if (*nodo)
    {
        if ((*nodo)->content.nombre[0] != 'G')
        {
            borrar(&((*nodo)->sig));
        }

        else
        {
            aux = (*nodo);
            (*nodo) = (*nodo)->sig;
            free(aux);
            borrar(nodo);
        }
    }
}

void push(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux;

    aux = (*nodo);
    aux->content = carga;
    aux->sig = (*nodo);
    (*nodo) = aux;
}

t_contenido pop(t_nodo *nodo)
{
    t_contenido carga;
    t_nodo aux;

    aux = (*nodo);
    carga = aux->content;
    (*nodo) = aux->sig;
    free(aux);

    return carga;
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%-25s%3d%3d%3d%8.2f\n", lista->content.nombre, lista->content.notas[0], lista->content.notas[1], lista->content.notas[2], lista->content.promedio);
        imprimirR(lista->sig);
    }
}