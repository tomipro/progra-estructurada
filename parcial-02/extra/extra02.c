#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_contenido
{
    int id;
    char *art;
    float precio;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void cargarArch(const char *nomArch, t_nodo *nodo, int campo, int orden);
void insertarUltimo(t_nodo *nodo, t_contenido carga);
void insertarOrdenado(t_nodo *nodo, t_contenido carga, int campo, int orden);
void imprimirR(t_nodo lista);

int main(void)
{
    t_nodo lista = NULL;

    printf("\n");
    cargarArch("./extra02.txt", &lista, 2, 1);
    imprimirR(lista);

    return 0;
}

void cargarArch(const char *nomArch, t_nodo *nodo, int campo, int orden)
{
    FILE *arch;
    t_contenido aux;
    int i, c;

    arch = fopen(nomArch, "r");

    while (!feof(arch))
    {
        fscanf(arch, "%d,", &aux.id);
        
        aux.art = malloc(sizeof(char));
        c = fgetc(arch);
        for (i = 0; c != ','; i++)
        {
            aux.art[i] = c;
            aux.art = realloc(aux.art, i + 2);
            c = fgetc(arch);
        }
        aux.art[i] = 0;

        fscanf(arch, "%f\n", &aux.precio);

        // insertarUltimo(nodo, aux);
        insertarOrdenado(nodo, aux, campo, orden);
    }

    fclose(arch);
}

void insertarUltimo(t_nodo *nodo, t_contenido carga)
{
    if (!*nodo)
    {
        (*nodo) = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->content = carga;
        (*nodo)->sig = NULL;
    }

    else
    {
        insertarUltimo(&((*nodo)->sig), carga);
    }
}

void insertarOrdenado(t_nodo *nodo, t_contenido carga, int campo, int orden)
{
    t_nodo aux;

    if (!*nodo || ((*nodo)->content.id > carga.id && campo == 0 && orden == 0) || ((*nodo)->content.id < carga.id && campo == 0 && orden == 1) || ((strcmp((*nodo)->content.art, carga.art) > 0 && campo == 1 && orden == 0)) || ((strcmp((*nodo)->content.art, carga.art) < 0 && campo == 1 && orden == 1)) || ((*nodo)->content.precio > carga.precio && campo == 2 && orden == 0) || ((*nodo)->content.precio < carga.precio && campo == 2 && orden == 1))
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->sig = (*nodo);
        aux->content = carga;
        *nodo = aux;
    }

    else
    {
        insertarOrdenado(&(*nodo)->sig, carga, campo, orden);
    }
}


void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%d,%s,%.2f\n", lista->content.id, lista->content.art, lista->content.precio);
        imprimirR(lista->sig);
    }
}