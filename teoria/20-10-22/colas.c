#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    int valor;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

struct s_cola
{
    t_nodo frente;
    t_nodo final;
};
typedef struct s_cola t_cola;

int desencolar(t_nodo *nodo);
void encolar(t_nodo *nodo, int valor);

int main(void)
{
    int val;
    t_nodo cola = NULL;
    t_nodo dir;

    encolar(&cola, 2);
    encolar(&cola, 7);
    encolar(&cola, 9);
    encolar(&cola, 1);
    encolar(&cola, -3);

    printf("Cola insertada:\n");

    while (cola)
    {
        dir = cola;
        val = desencolar(&cola);
        printf("%8d <%8p>\n", val, dir);
    }

    return 0;
}

void encolar(t_nodo *nodo, int valor)
{
    if (!*nodo)
    {
        (*nodo) = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }

    else
    {
        encolar(&(*nodo)->sig, valor);
    }
}

int desencolar(t_nodo *nodo)
{
    t_nodo aux = NULL;
    int valor = 0;

    if (*nodo)
    {
        aux = *nodo;
        valor = (*nodo)->valor;
        *nodo = (*nodo)->sig;
        free(aux);
        aux = NULL;
    }

    return valor;
}