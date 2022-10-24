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

void cargarArch(const char *nomArch, t_nodo *lista);
void push(t_nodo *pila, t_contenido carga);
t_contenido pop(t_nodo *pila);
void pushOrdenado(t_nodo *nodo, t_contenido carga);
void pilaAlista(t_nodo *nodo);
void imprimirR(t_nodo lista);

int main(void)
{
    t_nodo n = NULL;

    cargarArch("./02.txt", &n);
    printf("\nPila del archivo:\n");
    imprimirR(n);

    printf("\nPila a lista ordenada:\n");
    pilaAlista(&n);
    imprimirR(n);

    return 0;
}

void cargarArch(const char *nomArch, t_nodo *lista)
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

        push(lista, aux);

        c = fgetc(arch);
    }

    fclose(arch);
}

void push(t_nodo *pila, t_contenido carga)
{
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->content = carga;
    aux->sig = (*pila);
    (*pila) = aux;
}

void pushOrdenado(t_nodo *nodo, t_contenido carga)
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
        pushOrdenado(&((*nodo)->sig), carga);
    }
}

t_contenido pop(t_nodo *pila)
{
    t_contenido carga;
    t_nodo aux = *pila;

    carga = aux->content;
    *pila = aux->sig;
    free(aux);

    return carga;
}

void pilaAlista(t_nodo *nodo)
{
    t_nodo lista = NULL;
    t_contenido carga;

    while (*nodo)
    {
        carga = pop(nodo);
        pushOrdenado(&lista, carga);
    }
    *nodo = lista;
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%s,%d\n", lista->content.nombre, lista->content.edad);
        imprimirR(lista->sig);
    }
}
