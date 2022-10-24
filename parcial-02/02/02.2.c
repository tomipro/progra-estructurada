#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_contenido
{
    char *nombre;
    char letra;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void push(t_nodo *nodo, t_contenido carga);
t_contenido pop(t_nodo *nodo);
void cargarArch(char const *nomArch, t_nodo *nodo);
void pilaAlista(t_nodo *nodo);
int cumpleCondicion(t_contenido carga);
void imprimirR(t_nodo lista);

int main(void)
{
    t_nodo n = NULL;

    cargarArch("./02.2.txt", &n);
    printf("\nPila original:\n");
    imprimirR(n);

    printf("\nPila pasada a lista filtrada:\n");
    pilaAlista(&n);
    imprimirR(n);

    return 0;
}

void cargarArch(char const *nomArch, t_nodo *nodo)
{
    FILE *arch;
    int i;
    t_contenido aux;

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

        fscanf(arch, "%c\n", &aux.letra);

        push(nodo, aux);

        c = fgetc(arch);
    }

    fclose(arch);
}

void push(t_nodo *nodo, t_contenido carga)
{
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->content = carga;
    aux->sig = (*nodo);
    (*nodo) = aux;
}

int cumpleCondicion(t_contenido carga)
{
    int i, res = 0;
    int cont = 0;

    while (i < strlen(carga.nombre))
    {
        if (carga.nombre[i] == carga.letra)
        {
            cont++;
        }
        i++;
    }

    if (cont > 2)
    {
        res = 1;
    }

    return res;
}

t_contenido pop(t_nodo *nodo)
{
    t_contenido carga;
    t_nodo aux = *nodo;

    carga = aux->content;
    *nodo = aux->sig;
    free(aux);

    return carga;
}

void pilaAlista(t_nodo *nodo)
{
    t_nodo lista = NULL;
    t_contenido carga;

    while (*nodo)
    {
        carga = pop(nodo);
        if (cumpleCondicion(carga))
        {
            push(&lista, carga);
        }
    }

    *nodo = lista;
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%s,%c\n", lista->content.nombre, lista->content.letra);
        imprimirR(lista->sig);
    }
}