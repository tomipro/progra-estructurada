#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    struct s_nodo *izq;
    struct s_nodo *der;
    int dato;
};
typedef struct s_nodo *t_nodo;

void insertarEnArbol(t_nodo *nodo, int carga);
void imprimirPostorden(t_nodo nodo);
t_nodo borrarNodo(t_nodo raiz, int dato);
t_nodo nodoValorMin(t_nodo nodo);

void insertarEnArbol(t_nodo *nodo, int carga)
{
    t_nodo aux;

    if (!*nodo)
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->der = NULL;
        aux->izq = NULL;
        aux->dato = carga;
        (*nodo) = aux;
    }

    else
    {
        if (carga > (*nodo)->dato)
        {
            insertarEnArbol(&((*nodo)->der), carga);
        }

        else
        {
            insertarEnArbol(&((*nodo)->izq), carga);
        }
    }
}

void imprimirPostorden(t_nodo nodo)
{
    if (nodo)
    {
        imprimirPostorden(nodo->izq);
        imprimirPostorden(nodo->der);
        printf("%d ", nodo->dato);
    }
}

t_nodo borrarNodo(t_nodo raiz, int dato)
{
    if (raiz == NULL)
    {
        return raiz;
    }

    raiz->izq = borrarNodo(raiz->izq, dato);
    raiz->der = borrarNodo(raiz->der, dato);

    if (raiz->dato == dato)
    {
        if (raiz->izq == NULL)
        {
            t_nodo temp = raiz->der;
            free(raiz);
            return temp;
        }
        else if (raiz->der == NULL)
        {
            t_nodo temp = raiz->izq;
            free(raiz);
            return temp;
        }

        t_nodo temp = nodoValorMin(raiz->der);
        raiz->dato = temp->dato;
        raiz->der = borrarNodo(raiz->der, temp->dato);
    }
    return raiz;
}

t_nodo nodoValorMin(t_nodo nodo)
{
    t_nodo actual = nodo;

    while (actual && actual->izq != NULL)
        actual = actual->izq;

    return actual;
}

int main(void)
{
    t_nodo arbol = NULL;
    insertarEnArbol(&arbol, 3);
    insertarEnArbol(&arbol, 6);
    insertarEnArbol(&arbol, 1);
    insertarEnArbol(&arbol, 13);
    insertarEnArbol(&arbol, 10);
    insertarEnArbol(&arbol, 9);
    insertarEnArbol(&arbol, 4);
    insertarEnArbol(&arbol, 32);
    insertarEnArbol(&arbol, 11);
    insertarEnArbol(&arbol, 10);

    printf("\n\nArbol postorden\n");
    imprimirPostorden(arbol);

    int num = 4;
    borrarNodo(arbol, num);
    printf("\n\nArbol postorden, nodo borrado: %d\n", num);
    imprimirPostorden(arbol);
    printf("\n");

    return 0;
}