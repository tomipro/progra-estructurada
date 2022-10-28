#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_frase
{
    char *fr;
    int limite;
    int valido;
};
typedef struct s_frase t_frase;

struct s_nodo
{
    t_frase frase;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void cargarArch(const char *nomArch, t_nodo *nodo);
void insertarPrimero(t_nodo *nodo, t_frase carga);
int contarCar(char *frase);
void imprimirR(t_nodo lista);

int main(void)
{
    t_nodo lista = NULL;

    printf("%-75s%-10s%-8s", "Frase", "Limite", "Validez\n\n");
    cargarArch("./05.txt", &lista);
    imprimirR(lista);

    return 0;
}

void cargarArch(const char *nomArch, t_nodo *nodo)
{
    FILE *arch;
    t_frase aux;
    int i, c;

    arch = fopen(nomArch, "r");

    while (!feof(arch))
    {
        aux.fr = malloc(sizeof(char));

        c = fgetc(arch);
        for (i = 0; c != ';'; i++)
        {
            aux.fr[i] = c;
            aux.fr = realloc(aux.fr, i + 2);
            c = fgetc(arch);
        }
        aux.fr[i] = 0;

        fscanf(arch, "%d\n", &aux.limite);

        if (contarCar(aux.fr) <= aux.limite)
        {
            aux.valido = 1;
        }

        else
        {
            aux.valido = 0;
        }

        insertarPrimero(nodo, aux);
    }
}

void insertarPrimero(t_nodo *nodo, t_frase carga)
{
    t_nodo aux;

    if (!*nodo)
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->sig = (*nodo);
        aux->frase = carga;
        (*nodo) = aux;
    }

    else
    {
        insertarPrimero(&((*nodo)->sig), carga);
    }
}

int contarCar(char *frase)
{
    if (*frase == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + contarCar(frase + 1);
    }
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%-75s%-10d%-8d\n", lista->frase.fr, lista->frase.limite, lista->frase.valido);
        imprimirR(lista->sig);
    }
}