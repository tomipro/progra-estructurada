#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_contenido
{
    char *txt;
    int limite;
    int validez;
    int *notas;
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
void insertarOrdenado(t_nodo *nodo, t_contenido carga);
t_contenido pop(t_nodo *nodo);
void despilarAlista(t_nodo *pila, t_nodo *lista);
void eliminar(t_nodo *nodo);
void imprimirR(t_nodo lista);

int main(void)
{
    t_nodo pila = NULL;
    t_nodo lista = NULL;

    cargarArch("./05.3.txt", &pila);
    imprimirR(pila);

    eliminar(&pila);

    printf("\n");
    despilarAlista(&pila, &lista);
    imprimirR(lista);

    return 0;
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
        
        aux.validez = 0;

        aux.notas = malloc(sizeof(int));
        fscanf(arch, "%d,%d,%d;", &aux.notas[0], &aux.notas[1], &aux.notas[2]);
        aux.notas[3] = -1;

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

        c = fgetc(arch);
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

    if (!*nodo)
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->content = carga;
        aux->sig = (*nodo);
        (*nodo) = aux;
    }

    else
    {
        insertarOrdenado(&(*nodo)->sig, carga);
    }
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

void despilarAlista(t_nodo *pila, t_nodo *lista)
{
    t_contenido aux;

    while (*pila)
    {
        aux = pop(pila);
        insertarOrdenado(lista, aux); 
    }
}

void eliminar(t_nodo *nodo)
{
    t_nodo aux;

    if (*nodo)
    {
        if ((*nodo)->content.limite != 40)
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
        printf("%-70s%6d%5d%5d%5d%5d%35s\n", lista->content.txt, lista->content.limite, lista->content.validez, lista->content.notas[0], lista->content.notas[1], lista->content.notas[2], lista->content.info);
        imprimirR(lista->sig);
    }
}