#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_productos
{
    char *articulo;
    int cant;
    float precio;
    int id;
    char *info;
};
typedef struct s_productos t_productos;

struct s_nodo
{
    t_productos content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void leerStrDeArch(FILE *arch, char **arrC, char sep);
void cargarListaDeArch(t_nodo *lista, char *nomArch, int campo, int orden);
void insertarEnListaOrdenado(t_nodo *nodo, t_productos carga, int campo, int orden);
void imprimirListaR(t_nodo lista);

int main(void)
{
    t_nodo lista = NULL;
    char *nomArch = "./ejemplo1.txt";

    cargarListaDeArch(&lista, nomArch, 3, 0);
    imprimirListaR(lista);

    return 0;
}

void leerStrDeArch(FILE *arch, char **arrC, char sep)
{
    char c;
    int i = 0;

    *(arrC) = malloc(sizeof(char));
    if (!feof(arch))
    {
        c = fgetc(arch);

        while (!feof(arch) && c != sep)
        {
            (*(arrC))[i] = c;
            i++;
            *(arrC) = realloc(*(arrC), (i + 1) * sizeof(char));
            c = fgetc(arch);
        }
    }
    (*(arrC))[i] = '\0';
}

void cargarListaDeArch(t_nodo *lista, char *nomArch, int campo, int orden)
{
    FILE *arch;
    t_productos carga = {NULL, 0, 0, 0};

    arch = fopen(nomArch, "r");

    while (!feof(arch))
    {
        leerStrDeArch(arch, &(carga.articulo), ',');
        fscanf(arch, "%d,%f,%d\n", &(carga.cant), &(carga.precio), &(carga.id));
        insertarEnListaOrdenado(lista, carga, campo, orden);
        // leerStrDeArch(arch, &(carga.info), '\n');
    }

    fclose(arch);
}

void insertarEnListaOrdenado(t_nodo *nodo, t_productos carga, int campo, int orden)
{
    t_nodo aux;

    if (!*nodo)
    {
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->content = carga;
        (*nodo)->sig = NULL;
    }

    else
    {

        if (orden == 1)
        {
            if ((strcmp((*nodo)->content.articulo, carga.articulo) > 0 && campo == 1) || ((*nodo)->content.cant > carga.cant && campo == 2) || ((*nodo)->content.precio > carga.precio && campo == 3) || ((*nodo)->content.id > carga.id && campo == 4))
            {
                aux = (t_nodo)malloc(sizeof(struct s_nodo));
                aux->sig = (*nodo);
                aux->content = carga;
                (*nodo) = aux;
            }

            else
            {
                insertarEnListaOrdenado(&((*nodo)->sig), carga, campo, orden);
            }
        }

        if (orden == 0)
        {
            if ((strcmp((*nodo)->content.articulo, carga.articulo) < 0 && campo == 1) || (((*nodo)->content.cant < carga.cant) && campo == 2) || (((*nodo)->content.precio) < carga.precio && campo == 3) || (((*nodo)->content.id) < carga.id && campo == 4))
            {
                aux = (t_nodo)malloc(sizeof(struct s_nodo));
                aux->sig = (*nodo);
                aux->content = carga;
                (*nodo) = aux;
            }

            else
            {
                insertarEnListaOrdenado(&((*nodo)->sig), carga, campo, orden);
            }
        }
    }
}

void imprimirListaR(t_nodo lista)
{
    if (lista)
    {
        printf("%s,%d,%.1f,%d\n", lista->content.articulo, lista->content.cant, lista->content.precio, lista->content.id);
        imprimirListaR(lista->sig);
    }
}
