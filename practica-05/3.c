// WIP el borrarTodasOc me borra cualquier cosa
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

void listaInsertarUltimo(t_nodo *nodo, t_contenido carga);
void borrarValor(t_nodo *nodo, t_contenido carga);
void borrarTodasOc(t_nodo *nodo, t_contenido carga);
void imprimirListaR(t_nodo lista);

int main(void)
{
    t_nodo lista = NULL;
    t_contenido datos;
    int campo, opcion, doc;
    char *ape, *nom;

    datos.nombre = "Mirtha";
    datos.apellido = "Legrand";
    datos.dni = 12345678;
    listaInsertarUltimo(&lista, datos);

    datos.nombre = "Lionel";
    datos.apellido = "Messi";
    datos.dni = 10101010;
    listaInsertarUltimo(&lista, datos);

    datos.nombre = "Diego";
    datos.apellido = "Maradona";
    datos.dni = 98765432;
    listaInsertarUltimo(&lista, datos);

    datos.nombre = "Pepe";
    datos.apellido = "Argento";
    datos.dni = 40195122;
    listaInsertarUltimo(&lista, datos);

    datos.nombre = "Pepe";
    datos.apellido = "Argento";
    datos.dni = 40195122;
    listaInsertarUltimo(&lista, datos);

    imprimirListaR(lista);
    printf("\n");

    // printf("\nMENU\n1. Eliminar por DNI\n2. Eliminar por apellido\n3. Eliminar por nombre\nSu opcion: ");
    // scanf("%d", &campo);

    datos.nombre = "Lionel";
    borrarTodasOc(&lista, datos);

    // borrarTodasOc(&lista, datos);
    // datos.dni = 40195122;
    // datos.nombre = "Messi";
    // borrarValor(&lista, datos);

    imprimirListaR(lista);
    printf("\n");

    return 0;
}

void listaInsertarUltimo(t_nodo *nodo, t_contenido carga)
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
        listaInsertarUltimo(&((*nodo)->sig), carga);
    }
}

void borrarValor(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux = NULL;

    if (*nodo)
    {
        if (((*nodo)->content.dni != carga.dni) && (strcmp((*nodo)->content.apellido, carga.apellido) != 0) && (strcmp((*nodo)->content.nombre, carga.nombre) != 0))
        {
            borrarValor(&(*nodo)->sig, carga);
        }

        else
        {
            aux = (t_nodo)malloc(sizeof(struct s_nodo));
            (*nodo) = (*nodo)->sig;
            free(aux);
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

void borrarTodasOc(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux = NULL;

    if (*nodo)
    {
        if (((*nodo)->content.dni != carga.dni) && (strcmp((*nodo)->content.apellido, carga.apellido) != 0) && (strcmp((*nodo)->content.nombre, carga.nombre) != 0))
        {
            borrarTodasOc(&(*nodo)->sig, carga);
        }

        else
        {
            aux = (t_nodo)malloc(sizeof(struct s_nodo));
            (*nodo) = (*nodo)->sig;
            free(aux);
            borrarTodasOc(nodo, carga);
        }
    }
}

/*
datos.dni = 123;
    listaInsertarUltimo(&lista, datos);

    datos.dni = 456;
    listaInsertarUltimo(&lista, datos);

    datos.dni = 456;
    listaInsertarUltimo(&lista, datos);

    datos.dni = 456;
    listaInsertarUltimo(&lista, datos);

    datos.dni = 789;
    listaInsertarUltimo(&lista, datos);

if (campo == 1)
    {
        printf("\nIngrese DNI a borrar (sin puntos): ");
        scanf("%d", &doc);
        datos.dni = doc;
        printf("\n1. Borrar una ocurrencia\n2. Borrar todas las ocurrencias\nSu opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        borrarValor(&lista, datos);
    }

    else if (campo == 2)
    {
        printf("\nIngrese apellido a borrar: ");
        scanf("%s", ape);
        datos.apellido = ape;
        // printf("\n1. Borrar una ocurrencia\n2. Borrar todas las ocurrencias\nSu opcion: ");
        // scanf("%d", &opcion);
        printf("\n");
        borrarValor(&lista, datos);
    }


*/
