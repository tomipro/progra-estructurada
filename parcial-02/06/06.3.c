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

void cargarDatos(t_nodo *nodo);
void push(t_nodo *nodo, t_contenido carga);
void pilaAlista(t_nodo *pila, t_nodo *lista);
void insertarOrdenado(t_nodo *nodo, t_contenido carga);
void eliminar(t_nodo *nodo);

void cargarDatos(t_nodo *nodo)  
{
    FILE *arch;
    int i, c;
    t_contenido aux;

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

        push(nodo, aux);
    }
    fclose(arch);
}

void push(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux;

    aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->content = carga;
    aux->sig = (*nodo);
    (*nodo) = aux;
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

void pilaAlista(t_nodo *pila, t_nodo *lista)
{
    if (*pila)
    {
        insertarOrdenado(lista, (*pila)->content);
        pilaAlista(&((*pila)->sig), lista);
    }
}

void eliminar(t_nodo *nodo)
{
    t_nodo aux;

    if (*nodo)
    {
        if ((*nodo)->content.anio != 2001)
        {
            eliminar(&((*nodo)->sig));
        }

        else
        {
            aux = (*nodo);
            (*nodo) = (*nodo)->sig;
            free(aux);
            eliminar(nodo);
        }
    }
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%-17s%8.2f%10d%8d\n", lista->content.loc, lista->content.sup, lista->content.pob, lista->content.anio);
        imprimirR(lista->sig);
    }
}

int main(void)
{
    t_nodo pila = NULL;
    t_nodo lista = NULL;

    cargarDatos(&pila);
    // imprimirR(pila);


    printf("\n\n\n");
    pilaAlista(&pila, &lista);
    imprimirR(lista);

    printf("\n\n\n");
    eliminar(&lista);
    imprimirR(lista);

    // printf("\n\n\n");
    // imprimirR(pila);

    return 0;
}

