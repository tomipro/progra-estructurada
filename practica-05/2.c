#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_contenido
{
    char *nombre;
    char *apellido;
    int dni;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void listaInsertarOrd(t_nodo *nodo, t_contenido carga, int campo);
void imprimirListaR(t_nodo lista);
void prueba(int campo);

int main(void)
{
    int campo;
    printf("\nMENU\n1. Ordenar por nombre\n2. Ordenar por apellido\n3. Ordenar por DNI\nElija su opcion: ");
    scanf("%d", &campo);

    prueba(campo);

    return 0;
}

void listaInsertarOrd(t_nodo *nodo, t_contenido carga, int campo)
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
        if ((((*nodo)->content.dni > carga.dni) && campo == 3) || (strcmp((*nodo)->content.nombre, carga.nombre) > 0 && campo == 1) || (strcmp((*nodo)->content.apellido, carga.apellido) > 0 && campo == 2))
        {
            aux = (t_nodo)malloc(sizeof(struct s_nodo));
            aux->sig = (*nodo);
            aux->content = carga;
            (*nodo) = aux;
        }

        else
        {
            listaInsertarOrd(&(*nodo)->sig, carga, campo);
        }
    }
}

void imprimirListaR(t_nodo lista)
{
    if (lista)
    {
        printf("%s, %s, %d\n", lista->content.nombre, lista->content.apellido, lista->content.dni);
        imprimirListaR(lista->sig);
    }
}

void prueba(int campo)
{
    t_nodo lista = NULL;
    t_contenido contenido;

    contenido.nombre = "Mirtha";
    contenido.apellido = "Legrand";
    contenido.dni = 12345678;
    listaInsertarOrd(&lista, contenido, campo);

    contenido.nombre = "Lionel";
    contenido.apellido = "Messi";
    contenido.dni = 10101010;
    listaInsertarOrd(&lista, contenido, campo);

    contenido.nombre = "Diego";
    contenido.apellido = "Maradona";
    contenido.dni = 98765432;
    listaInsertarOrd(&lista, contenido, campo);

    contenido.nombre = "Pepe";
    contenido.apellido = "Argento";
    contenido.dni = 40195122;
    listaInsertarOrd(&lista, contenido, campo);

    printf("\nLa lista ordenada por el campo [%d] es:\n\n", campo);
    imprimirListaR(lista);
}