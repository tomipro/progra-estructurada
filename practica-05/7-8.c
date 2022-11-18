#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    struct s_nodo *izq;
    struct s_nodo *der;
    int dato;
};
typedef struct s_nodo *t_nodo;

void insertarEnArbol(t_nodo *nodo, int dato);
void imprimirPreOrden(t_nodo nodo);
void imprimirInorden(t_nodo nodo);
void imprimirPostorden(t_nodo nodo);
int altura(t_nodo nodo);
void imprimirNivel(t_nodo root, int nivel);
void imprimirOrdenNivel(t_nodo root);

void insertarEnArbol(t_nodo *nodo, int dato)
{
    t_nodo aux;

    if (!*nodo)
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->der = NULL;
        aux->izq = NULL;
        aux->dato = dato;
        (*nodo) = aux;
    }

    else
    {
        if (dato > (*nodo)->dato)
        {
            insertarEnArbol(&((*nodo)->der), dato);
        }

        else
        {
            insertarEnArbol(&((*nodo)->izq), dato);
        }
    }
}

void imprimirPreOrden(t_nodo nodo)
{
    if (nodo)
    {
        printf("%d\n", nodo->dato);
        imprimirPreOrden(nodo->izq);
        imprimirPreOrden(nodo->der);
    }
}

void imprimirInorden(t_nodo nodo)
{
    if (nodo)
    {
        imprimirInorden(nodo->izq);
        printf("%d\n", nodo->dato);
        imprimirInorden(nodo->der);
    }
}

void imprimirPostorden(t_nodo nodo)
{
    if (nodo)
    {
        imprimirPostorden(nodo->izq);
        imprimirPostorden(nodo->der);
        printf("%d\n", nodo->dato);
    }
}

int altura(t_nodo nodo)
{
    int alturaIzq;
    int alturaDer;

    if (!nodo)
    {
        return 0;
    }

    else
    {
        alturaIzq = altura(nodo->izq);
        alturaDer = altura(nodo->der);

        if (alturaIzq > alturaDer)
        {
            return (alturaIzq + 1);
        }

        else
        {
            return (alturaDer + 1);
        }
    }
}

void imprimirNivel(t_nodo root, int nivel)
{
    if (!root)
    {
        return;
    }
    
    if (nivel == 1)
    {
        printf("%-5d ", root->dato);
    }

    else if (nivel > 1)
    {
        imprimirNivel(root->izq, nivel - 1);
        imprimirNivel(root->der, nivel - 1);
    }
}

void imprimirOrdenNivel(t_nodo root)
{
    int alt = altura(root);
    int i;

    for (i = 1; i <= alt; i++)
    {
        imprimirNivel(root, i);
        printf("\n\n");
    }
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

    printf("\nArbol preorden\n");
    imprimirPreOrden(arbol);

    printf("\n\nArbol inorden\n");
    imprimirInorden(arbol);

    printf("\n\nArbol postorden\n");
    imprimirPostorden(arbol);

    printf("\n\nArbol por niveles (leer de derecha a izquierda)\n");
    imprimirOrdenNivel(arbol);

    return 0;
}

