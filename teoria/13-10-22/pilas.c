#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    int valor;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void push(t_nodo *pila, int valor);
int pop(t_nodo *pila);
int estaVacia(t_nodo *pila);

int main(void)
{
    t_nodo pila = NULL;
    int val;
    t_nodo dir;

    printf("\nPila antes de agregar: <%p>\n", pila);
    push(&pila, 10);
    push(&pila, 140);
    push(&pila, 18);
    push(&pila, 3);
    printf("\nPila una vez completa: <%p>\n", pila);

    printf("\nHago pop a la pila: \n");
    while (!estaVacia(&pila))
    {
        dir = pila;
        val = pop(&pila);
        printf("\nPila = %4d: <%p>", val, dir);
    }

    printf("\n");

    return 0;
}

void push(t_nodo *pila, int valor)
{
    // apilar: agrego al frente
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->sig = *pila;
    *pila = aux;
}

int pop(t_nodo *pila)
{
    // desapilar: eliminar del frente
    int valor;

    t_nodo aux = *pila;
    valor = aux->valor;
    *pila = aux->sig;
    free(aux);

    return valor;
}

int estaVacia(t_nodo *pila)
{
    return (*pila == NULL);
}