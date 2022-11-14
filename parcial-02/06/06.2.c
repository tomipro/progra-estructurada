#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_contenido
{
    char *loc;
    float sup;
    int pob;
    int anio;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void cargarContenido(t_nodo *nodo);
void insertarOrdenado(t_nodo *nodo, t_contenido carga);
void imprimirR(t_nodo lista);
t_contenido pop(t_nodo *nodo);
void push(t_nodo *nodo, t_contenido carga);
void listaApila(t_nodo *lista, t_nodo *pila);

void cargarContenido(t_nodo *nodo)
{
    FILE *arch;
    t_contenido aux;
    int i, c;

    arch = fopen("./06.txt", "r");

    while (!feof(arch))
    {
        aux.loc = malloc(sizeof(char));
        c = fgetc(arch);

        for (i = 0; c != ','; i++)
        {
            aux.loc[i] = c;
            aux.loc = realloc(aux.loc, i + 2);
            c = fgetc(arch);
        }
        aux.loc[i] = 0;

        fscanf(arch, "%f,%d,%d\n", &aux.sup, &aux.pob, &aux.anio);

        insertarOrdenado(nodo, aux);
    }

    fclose(arch);
}

void insertarOrdenado(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux;

    if (!*nodo || ((*nodo)->content.pob) > carga.pob)
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->content = carga;
        aux->sig = (*nodo);
        (*nodo) = aux;
    }

    else
    {
        insertarOrdenado(&((*nodo)->sig), carga);
    }
}

void push(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux;

    aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->content = carga;
    aux->sig = (*nodo);
    (*nodo) = aux;
}

t_contenido pop(t_nodo *nodo)
{
    t_contenido content;
    t_nodo aux = (*nodo);

    content = aux->content;
    (*nodo) = aux->sig;
    free(aux);

    return content;
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%-17s%8.2f%10d%8d\n", lista->content.loc, lista->content.sup, lista->content.pob, lista->content.anio);
        imprimirR(lista->sig);
    }
}

void listaApila(t_nodo *lista, t_nodo *pila)
{
    if (*lista)
    {
        push(pila, (*lista)->content);
        listaApila(&((*lista)->sig), pila);
    }
}

void eliminar(t_nodo *nodo, int anio)
{
    t_nodo aux;

    if (*nodo)
    {
        if ((*nodo)->content.anio != anio)
        {
            eliminar(&((*nodo)->sig), anio);
        }

        else
        {
            aux = (*nodo);
            (*nodo) = (*nodo)->sig;
            free(aux);
            eliminar(nodo, anio);
        }
    }
}

int main(void)
{
    t_nodo lista = NULL;
    t_nodo pila = NULL;

    cargarContenido(&lista);
    imprimirR(lista);

    printf("\n\n");

    listaApila(&lista, &pila);
    imprimirR(pila);

    printf("\n\n");
    imprimirR(lista);
    
    printf("\n\n");
    eliminar(&lista, 2010);
    imprimirR(lista);

    return 0;
}