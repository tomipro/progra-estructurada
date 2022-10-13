#include <stdio.h>
#include <stdlib.h>

struct s_contenido
{
    int valor;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void insertarUltimoEnLista(t_nodo *nodo, t_contenido carga);
void imprimirListaR(t_nodo lista);

int main(void)
{
    t_nodo lista = NULL;
    t_contenido aux;

    aux.valor = 10;
    insertarUltimoEnLista(&lista, aux);

    aux.valor = 20;
    insertarUltimoEnLista(&lista, aux);

    aux.valor = 30;
    insertarUltimoEnLista(&lista, aux);

    imprimirListaR(lista);

    return 0;
}

void insertarUltimoEnLista(t_nodo *nodo, t_contenido carga)
{
    // inserta al final de la lista
    if (*nodo == NULL)
    {
        // creo el nodo
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->content = carga;
        (*nodo)->sig = NULL;
    }

    else
    {
        // llamada a la recursiva si no es null
        insertarUltimoEnLista(&((*nodo)->sig), carga);
    }
}

void imprimirListaR(t_nodo lista)
{
    if (lista != NULL)
    {
        // printf("\n valor = %4d, dirNodo: <%p>, dirSig: <%p>", (lista)->content.valor, lista, (lista)->sig);
        printf("%4d\n", lista->content.valor);
        imprimirListaR(lista->sig); // poner esto arriba del print si quiero imprimir al reves
    }
}
