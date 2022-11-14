// WIP
#include <stdio.h>
#include <stdlib.h>

struct s_dato
{
    char *nombre;
    int *notas;
    char estado;
};
typedef struct s_dato t_dato;

struct s_nodo
{
    t_dato content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void imprimirListaR(t_nodo lista);
void push(t_nodo *nodo, t_dato contenido);
t_dato pop(t_nodo *nodo);
void desapilarAlista(t_nodo *pila, t_nodo *lista);
void cargarArch(const char *nomArch, t_nodo *nodo);

int main(void)
{
    t_nodo pila = NULL;
    t_nodo lista = NULL;

    cargarArch("./03.txt", &pila);
    imprimirListaR(pila);

    return 0;
}

void cargarArch(const char *nomArch, t_nodo *nodo)
{
    FILE *arch;
    t_dato aux;

    int i;

    arch = fopen(nomArch, "r");

    char c = fgetc(arch);
    while (!feof(arch))
    {
        aux.nombre = malloc(sizeof(char));

        for (i = 0; c != ','; i++)
        {
            aux.nombre[i] = c;
            aux.nombre = realloc(aux.nombre, i + 2);
            c = fgetc(arch);
        }
        aux.nombre[i] = 0;

        aux.notas = malloc(sizeof(int));
        fscanf(arch, "%d,%d,%d,%d\n", &aux.notas[0], &aux.notas[1], &aux.notas[2], &aux.notas[3]);
        aux.notas[4] = -1;

        push(nodo, aux);

        c = fgetc(arch);
    }
}

void imprimirListaR(t_nodo lista)
{
    if (lista)
    {
        printf("%-40s%-10d%d,%d,%d%6d\n", lista->content.nombre, lista->content.notas[0], lista->content.notas[1], lista->content.notas[2], lista->content.notas[3], lista->content.estado);
        imprimirListaR(lista->sig);
    }
}

void push(t_nodo *nodo, t_dato contenido)
{
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));

    aux->content = contenido;
    aux->sig = (*nodo);
    (*nodo) = aux;
}