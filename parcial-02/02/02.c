#include <stdio.h>
#include <stdlib.h>

struct s_contenido
{
    char *nombre;
    int edad;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void cargarArch(const char *nomArch, t_nodo *nodo);
void push(t_nodo *nodo, t_contenido carga);
t_contenido pop(t_nodo *nodo);
void cargarListaOrd(t_nodo *nodo, t_contenido carga);
void imprimirR(t_nodo lista);
void desapilarAlista(t_nodo *pila, t_nodo *lista);

int main(void)
{
    t_nodo pila = NULL;
    t_nodo lista = NULL;

    cargarArch("./02.txt", &pila);
    printf("\nPila del archivo:\n");
    imprimirR(pila);

    desapilarAlista(&pila, &lista);

    printf("\nLista ordenada:\n");
    imprimirR(lista);

    return 0;
}

void desapilarAlista(t_nodo *pila, t_nodo *lista)
{
    t_contenido contenido;

    while (*pila)
    {
        contenido = pop(pila);
        cargarListaOrd(lista, contenido);
    }
}

void cargarArch(const char *nomArch, t_nodo *nodo)
{
    FILE *arch;
    t_contenido aux;
    int i;

    arch = fopen(nomArch, "r");

    char c = fgetc(arch);
    while (!feof(arch))
    {
        aux.nombre = malloc(sizeof(char));

        for (i = 0; c != ','; i++)
        {
            aux.nombre[i] = c;
            aux.nombre = realloc(aux.nombre, i + 2);
            c = fgetc(arch);
        }
        aux.nombre[i] = 0;

        fscanf(arch, "%d\n", &aux.edad);

        push(nodo, aux);

        c = fgetc(arch);
    }

    fclose(arch);
}

void push(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->content = carga;
    aux->sig = (*nodo);
    (*nodo) = aux;
}

void cargarListaOrd(t_nodo *nodo, t_contenido carga)
{
    if (!*nodo || (*nodo)->content.edad > carga.edad)
    {
        t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->sig = (*nodo);
        aux->content = carga;
        *nodo = aux;
    }

    else
    {
        cargarListaOrd(&((*nodo)->sig), carga);
    }
}

t_contenido pop(t_nodo *nodo)
{
    t_contenido carga;
    t_nodo aux = *nodo;

    carga = aux->content;
    *nodo = aux->sig;
    free(aux);

    return carga;
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%s,%d\n", lista->content.nombre, lista->content.edad);
        imprimirR(lista->sig);
    }
}
