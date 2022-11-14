#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_contenido
{
    char *txt;
    int limite;
    int valido;
    char *info;
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
void pilaAlista(t_nodo *pila, t_nodo *lista);
void insertarOrdenado(t_nodo *nodo, t_contenido carga);
int contarCar(char *frase);
void eliminarElemento(t_nodo *nodo);
void imprimirR(t_nodo lista);

int main(void)
{
    t_nodo pila = NULL;
    t_nodo lista = NULL;

    cargarArch("./05.2.txt", &pila);
    imprimirR(pila);

    printf("\n");
    pilaAlista(&pila, &lista);
    imprimirR(lista);

    return 0;
}

void pilaAlista(t_nodo *pila, t_nodo *lista)
{
    t_contenido carga;

    while (*pila)
    {
        carga = pop(pila);
        insertarOrdenado(lista, carga);
    }
}

void cargarArch(const char *nomArch, t_nodo *nodo)
{
    FILE *arch;
    t_contenido aux;
    int i, c;

    arch = fopen(nomArch, "r");

    c = fgetc(arch);
    while (!feof(arch))
    {
        aux.txt = malloc(sizeof(char));

        for (i = 0; c != ';'; i++)
        {
            aux.txt[i] = c;
            aux.txt = realloc(aux.txt, i + 2);
            c = fgetc(arch);
        }
        aux.txt[i] = 0;

        fscanf(arch, "%d;", &aux.limite);

        if (contarCar(aux.txt) <= aux.limite)
        {
            aux.valido = 1;
        }

        else
        {
            aux.valido = 0;
        }

        aux.info = malloc(sizeof(char));
        c = fgetc(arch);

        for (i = 0; c != '\n'; i++)
        {
            aux.info[i] = c;
            aux.info = realloc(aux.info, i + 2);
            c = fgetc(arch);
        }
        aux.info[i] = 0;

        push(nodo, aux);
        eliminarElemento(nodo);

        c = fgetc(arch);
    }

    fclose(arch);
}

void push(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux;

    aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->sig = (*nodo);
    aux->content = carga;
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

void insertarOrdenado(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux;

    if (!*nodo || (strcmp((*nodo)->content.txt, carga.txt) > 0))
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

int contarCar(char *frase)
{
    if (*frase == '\0')
    {
        return 0;
    }

    else
    {
        return 1 + contarCar(frase + 1);
    }
}

void eliminarElemento(t_nodo *nodo)
{
    t_nodo aux;

    if (*nodo)
    {
        if ((*nodo)->content.valido == 1)
        {
            eliminarElemento(&((*nodo)->sig));
        }

        else
        {
            aux = (*nodo);
            (*nodo) = aux->sig;
            free(aux);
            eliminarElemento(nodo);
        }
    }
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%-70s%5d%5d%35s\n", lista->content.txt, lista->content.limite, lista->content.valido, lista->content.info);
        imprimirR(lista->sig);
    }
}