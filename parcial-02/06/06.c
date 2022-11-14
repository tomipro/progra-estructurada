#include <stdio.h>
#include <stdlib.h>

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

void push(t_nodo *nodo, t_contenido carga);
void insertarOrdenado(t_nodo *nodo, t_contenido carga);

void cargarContenido(t_nodo *nodo)
{
    t_contenido aux;
    FILE *arch;
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

t_contenido pop(t_nodo *nodo)
{
    t_contenido carga;
    t_nodo aux = (*nodo);

    carga = aux->content;
    (*nodo) = aux->sig;
    free(aux);

    return carga;
}

void pilaAlista(t_nodo *pila, t_nodo *lista)
{
    t_contenido contenido;
    t_nodo *aux = pila;

    while (*aux)
    {
        contenido = pop(aux);
        insertarOrdenado(lista, contenido);
    }
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

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        imprimirR(lista->sig);
        printf("%-17s%8.2f%10d%8d\n", lista->content.loc, lista->content.sup, lista->content.pob, lista->content.anio);
    }
}

int main(void)
{
    t_nodo pila = NULL;
    t_nodo lista = NULL;

    cargarContenido(&pila);
    // imprimirR(pila);
    pilaAlista(&pila, &lista);
    imprimirR(lista);

    printf("\n\n");
    imprimirR(pila);

    return 0;
}
