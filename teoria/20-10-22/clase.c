#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_nodo
{
    int valor;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void insertarEnListaPrimero(t_nodo *nodo, int valor);
void insertarEnListaPorPos(t_nodo *nodo, int pos, int valor);
void eliminarEnListaPorValorTodos(t_nodo *nodo, int valor);
void imprimir(t_nodo lista);

int main(void)
{
    t_nodo lista = NULL;

    insertarEnListaPrimero(&lista, 10);
    insertarEnListaPrimero(&lista, 10);
    insertarEnListaPrimero(&lista, 10);
    insertarEnListaPrimero(&lista, 20);
    insertarEnListaPrimero(&lista, 30);
    insertarEnListaPrimero(&lista, 40);

    printf("Lista original: ");
    imprimir(lista);
    printf("\n");

    printf("Lista con valor insertado por valor: ");
    insertarEnListaPorPos(&lista, 2, 55);
    imprimir(lista);
    printf("\n");
    
    printf("Lista con valor borrado: ");
    eliminarEnListaPorValorTodos(&lista, 10);
    imprimir(lista);
    printf("\n");

    return 0;
}

void insertarEnListaPrimero(t_nodo *nodo, int valor)
{
    t_nodo aux;

    if (!*nodo)
    {
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }

    else
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->sig = (*nodo);
        aux->valor = valor;
        (*nodo) = aux;
    }
}

void insertarEnListaPorPos(t_nodo *nodo, int pos, int valor)
{
    if (pos == 0 || !*nodo)
    {
        t_nodo aux;

        if (!*nodo)
        {
            *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
            (*nodo)->valor = valor;
            (*nodo)->sig = NULL;
        }

        else
        {
            aux = (t_nodo)malloc(sizeof(struct s_nodo));
            aux->sig = (*nodo);
            aux->valor = valor;
            (*nodo) = aux;
        }
    }

    else if (pos > 0)
    {
        insertarEnListaPorPos(&((*nodo)->sig), pos - 1, valor);
    }
}

void imprimir(t_nodo lista)
{
    if (lista)
    {
        printf("%d ", lista->valor);
        imprimir(lista->sig);
    }
}

void eliminarEnListaPorValorTodos(t_nodo *nodo, int valor)
{
    t_nodo aux = NULL;

    if (*nodo)
    {
        if ((*nodo)->valor != valor)
        {
            eliminarEnListaPorValorTodos(&(*nodo)->sig, valor);
        }

        else
        {
            aux = (*nodo);
            *nodo = (*nodo)->sig;
            free(aux);
            eliminarEnListaPorValorTodos(nodo, valor); // saco esto si no quiero borrar todas ocurrencias de ese valor
        }
    }
}