#include <stdio.h>
#include <stdlib.h>

struct sNodo
{
    int valor;
    struct sNodo *sig;
};
typedef struct sNodo *tNodo;

void insertarEnListaUltimo(tNodo *nodo, int valor);
void insertarEnListaPrimero(tNodo *nodo, int valor);
void eliminarEnListaPorValor(tNodo *nodo, int valor);
void imprimirListaR(tNodo lista);

int main(void)
{
    unsigned int n, c;
    tNodo lista = NULL;

    printf("\n              L I S T A S \n");
    printf("Agrega valores a lista [10, 20, 30]");
    printf("\n=======================================================================\n");
    insertarEnListaUltimo(&lista, 10);
    insertarEnListaUltimo(&lista, 20);
    insertarEnListaUltimo(&lista, 30);
    imprimirListaR(lista);

    printf("\n=======================================================================\n");
    printf("Inserta adelante el 114 y luego el 7\n");
    insertarEnListaPrimero(&lista, 114);
    insertarEnListaPrimero(&lista, 7);
    imprimirListaR(lista);

    printf("\n=======================================================================\n");
    printf("De la lista anterior se elimina 114\n");
    eliminarEnListaPorValor(&lista, 114);
    imprimirListaR(lista);

    return 0;
}

void insertarEnListaUltimo(tNodo *nodo, int valor)
{
    // inserta al final de la lista

    if (*nodo == NULL)
    {
        *nodo = (tNodo)malloc(sizeof(struct sNodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }

    else
    {
        insertarEnListaUltimo(&((*nodo)->sig), valor);
    }
}

void insertarEnListaPrimero(tNodo *nodo, int valor)
{
    tNodo aux;

    if (*nodo == NULL)
    {
        *nodo = (tNodo)malloc(sizeof(struct sNodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }

    else
    {
        aux = (tNodo)malloc(sizeof(struct sNodo));
        aux->sig = (*nodo);
        aux->valor = valor;
        (*nodo) = aux;
    }
}

void eliminarEnListaPorValor(tNodo *nodo, int valor)
{
    tNodo aux = NULL;

    if (*nodo != NULL)
    {
        if ((*nodo)->valor != valor)
        {
            eliminarEnListaPorValor(&(*nodo)->sig, valor);
        }

        else // entonces encontre el valor
        {
            aux = *(nodo);
            *nodo = (*nodo)->sig;
            free(aux);
        }
    }
}

void imprimirListaR(tNodo lista)
{
    if (lista != NULL)
    {
        printf("\n valor = %4d, dirNodo: <%p>, dirSig: <%p>", (lista)->valor, lista, (lista)->sig);
        imprimirListaR(lista->sig); // poner esto arriba del print si quiero imprimir al reves
    }
}
