#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_dato
{
    char *nom;
    int edad;
};
typedef struct s_dato t_dato;

struct s_nodo
{
    t_dato content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void cargarDeArch(const char *nomArch, t_nodo *nodo, int orden, int campo);
void insertarUltimo(t_nodo *nodo, t_dato carga);
void insertarOrdenado(t_nodo *nodo, t_dato carga, int orden, int campo);
void borrarElemento(t_nodo *nodo, t_dato carga);
void imprimirListaR(t_nodo lista);
void imprimirListaI(t_nodo lista);

int main(void)
{
    t_nodo lista = NULL;
    t_nodo listaOrdenada = NULL;
    int orden, campo;

    printf("\nLista sin ordenar:\n");
    cargarDeArch("./personas.txt", &lista, -1, -1);
    imprimirListaI(lista);

    printf("\nLista ordenada:\n");
    cargarDeArch("./personas.txt", &listaOrdenada, 0, 1);
    imprimirListaI(listaOrdenada);

    printf("\nLista con elemento borrado:\n");
    t_dato borro = {"Diego Maradona", 47};
    borrarElemento(&listaOrdenada, borro);
    imprimirListaI(listaOrdenada);
    
    return 0;
}

void cargarDeArch(const char *nomArch, t_nodo *nodo, int orden, int campo)
{
    FILE *arch;
    t_dato aux;
    int i;

    arch = fopen(nomArch, "r");

    int c = fgetc(arch);
    while (!feof(arch))
    {
        aux.nom = malloc(sizeof(char));

        for (i = 0; c != ','; i++)
        {
            aux.nom[i] = c;
            aux.nom = realloc(aux.nom, i + 2);
            c = fgetc(arch);
        }
        aux.nom[i] = 0;

        fscanf(arch, "%d\n", &aux.edad);

        // insertarUltimo(nodo, aux);
        insertarOrdenado(nodo, aux, orden, campo);

        c = fgetc(arch);
    }
    fclose(arch);
}

void insertarUltimo(t_nodo *nodo, t_dato carga)
{
    if (!*nodo)
    {
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->content = carga;
        (*nodo)->sig = NULL;
    }
    else
    {
        insertarUltimo(&((*nodo)->sig), carga);
    }
}

void insertarOrdenado(t_nodo *nodo, t_dato carga, int orden, int campo)
{
    t_nodo aux;

    if (!*nodo || ((*nodo)->content.edad > carga.edad) && (campo == 1) && (orden == 0) || ((*nodo)->content.edad < carga.edad) && (campo == 1) && (orden == 1) || ((strcmp((*nodo)->content.nom, carga.nom) > 0) && (campo == 0) && (orden == 0)) || ((strcmp((*nodo)->content.nom, carga.nom) < 0) && (campo == 0) && (orden == 1)))
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->sig = (*nodo);
        aux->content = carga;
        *nodo = aux;
    }

    else
    {
        insertarOrdenado(&((*nodo)->sig), carga, orden, campo);
    }
}

void borrarElemento(t_nodo *nodo, t_dato carga)
{
    t_nodo aux;

    if (*nodo)
    {
        if ((*nodo)->content.edad != carga.edad)
        {
            borrarElemento(&(*nodo)->sig, carga);
        }

        else
        {
            aux = (*nodo);
            *nodo = (*nodo)->sig;
            free(aux);
            // borrarElemento(nodo, carga); // si quiero borrar todas las ocurrencias
        }
    }
}

void imprimirListaR(t_nodo lista)
{
    if (lista)
    {
        printf("%-15s%-10d\n", lista->content.nom, lista->content.edad);
        imprimirListaR(lista->sig);
    }
}

void imprimirListaI(t_nodo lista)
{
    printf("%-20s%10s\n", "NOMBRE", "EDAD");
    while (lista)
    {
        printf("%-20s%10d\n", lista->content.nom, lista->content.edad);
        lista = lista->sig;
    }
}
