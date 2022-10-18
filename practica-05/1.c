#include <stdio.h>
#include <stdlib.h>

struct s_contenido
{
    char *nombre;
    char *apellido;
    unsigned int dni;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void insertarUltimoEnLista(t_nodo *nodo, t_contenido carga);
void imprimirR(t_nodo lista, int orden);
void prueba();

int main(void)
{
    prueba();

    return 0;
}

void insertarUltimoEnLista(t_nodo *nodo, t_contenido carga)
{
    if (!*nodo)
    {
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->content = carga;
        (*nodo)->sig = NULL;
    }

    else
    {
        insertarUltimoEnLista(&((*nodo)->sig), carga);
    }
}

void imprimirR(t_nodo lista, int orden)
{
    if (lista && orden != 0)
    {
        imprimirR(lista->sig, orden);
        printf("%s, %s, %d\n", lista->content.nombre, lista->content.apellido, lista->content.dni);
    }

    else if (lista && orden == 0)
    {
        printf("%s, %s, %d\n", lista->content.nombre, lista->content.apellido, lista->content.dni);
        imprimirR(lista->sig, orden);
    }
}

void prueba()
{
    t_nodo lista = NULL;
    t_contenido datos;

    datos.nombre = "Mirtha";
    datos.apellido = "Legrand";
    datos.dni = 12345678;
    insertarUltimoEnLista(&lista, datos);

    datos.nombre = "Lionel";
    datos.apellido = "Messi";
    datos.dni = 10101010;
    insertarUltimoEnLista(&lista, datos);

    datos.nombre = "Diego";
    datos.apellido = "Maradona";
    datos.dni = 98765432;
    insertarUltimoEnLista(&lista, datos);

    datos.nombre = "Pepe";
    datos.apellido = "Argento";
    datos.dni = 40195122;
    insertarUltimoEnLista(&lista, datos);

    printf("La lista original:\n");
    imprimirR(lista, 0); // El 0 imprime la lista normal, cualquier numero != 0 imprime inversa
    printf("\nLa lista inversa:\n");
    imprimirR(lista, 1);
}