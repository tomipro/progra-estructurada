#include <stdio.h>
#include <stdlib.h>

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

void insertarListaUltimo(t_nodo *nodo, t_contenido carga);
t_contenido borrarPorPosicion(t_nodo *nodo, int posicion);
void imprimirLista(t_nodo lista);
void pruebas();

int main(void)
{
    pruebas();

    return 0;
}

void insertarListaUltimo(t_nodo *nodo, t_contenido carga)
{
    t_contenido aux;

    if (!*nodo)
    {
        (*nodo) = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->content = carga;
        (*nodo)->sig = NULL;
    }

    else
    {
        insertarListaUltimo(&(*nodo)->sig, carga);
    }
}

void imprimirLista(t_nodo lista)
{
    if (lista)
    {
        printf("%s, %s, %d\n", lista->content.nombre, lista->content.apellido, lista->content.dni);
        imprimirLista(lista->sig);
    }
}

t_contenido borrarPorPosicion(t_nodo *nodo, int posicion)
{
    t_contenido carga;
    t_nodo aux;

    if (*nodo)
    {
        if (posicion > 0)
        {
            carga = borrarPorPosicion(&(*nodo)->sig, posicion - 1);
        }

        else if (posicion == 0)
        {
            aux = (t_nodo)malloc(sizeof(struct s_nodo));
            carga = aux->content;
            (*nodo) = (*nodo)->sig;
            free(aux);
        }
    }

    return carga;
}

void pruebas()
{
    t_nodo lista = NULL;
    t_contenido datos;
    int posicion;

    datos.nombre = "Mirtha";
    datos.apellido = "Legrand";
    datos.dni = 12345678;
    insertarListaUltimo(&lista, datos);

    datos.nombre = "Lionel";
    datos.apellido = "Messi";
    datos.dni = 10101010;
    insertarListaUltimo(&lista, datos);

    datos.nombre = "Diego";
    datos.apellido = "Maradona";
    datos.dni = 98765432;
    insertarListaUltimo(&lista, datos);

    printf("\nLista original:\n");
    imprimirLista(lista);

    printf("\nElija posicion de lista a borrar: ");
    scanf("%d", &posicion);
    borrarPorPosicion(&lista, posicion);

    printf("Posicion [%d] borrada\n\nLista modificada:\n", posicion);
    imprimirLista(lista);
}