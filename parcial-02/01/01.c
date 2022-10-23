#include <stdio.h>
#include <stdlib.h>

struct s_refran
{
    char *txt;
    char car;
    int cantidad_caracter;
};
typedef struct s_refran t_refran;

struct s_nodo
{
    t_refran ref;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

void cargarPilaDeArch(const char *nomArch, t_nodo *pila);
void leerStrDeArch(FILE *arch, char **arrC, char sep);
void push(t_nodo *pila, t_refran carga);
void pilaAlista(t_nodo *nodo);
t_refran pop(t_nodo *pila);
int contarCaracter(t_nodo *nodo, char car);
void imprimirRecurs(t_nodo lista);

int main(void)
{
    t_nodo n = NULL;

    cargarPilaDeArch("./refranes.txt", &n);
    pilaAlista(&n);

    printf("%-50s%-10s%-10s\n\n", "Refran", "Caracter", "Cantidad");
    imprimirRecurs(n);

    return 0;
}

void leerStrDeArch(FILE *arch, char **arrC, char sep)
{
    char c;
    int i = 0;

    *(arrC) = malloc(sizeof(char));
    if (!feof(arch))
    {
        c = fgetc(arch);

        while (!feof(arch) && c != sep)
        {
            (*(arrC))[i] = c;
            i++;
            *(arrC) = realloc(*(arrC), (i + 1) * sizeof(char));
            c = fgetc(arch);
        }
    }
    (*(arrC))[i] = '\0';
}

void push(t_nodo *pila, t_refran carga)
{
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->ref = carga;
    aux->sig = (*pila);
    (*pila) = aux;
}

t_refran pop(t_nodo *pila)
{
    t_refran refran;
    t_nodo aux = *pila;
    refran = aux->ref;
    *pila = aux->sig;
    free(aux);

    return refran;
}

void cargarPilaDeArch(const char *nomArch, t_nodo *pila)
{
    FILE *arch;
    t_refran carga = {NULL, 0, 0};

    arch = fopen("./refranes.txt", "r");

    while (!feof(arch))
    {
        leerStrDeArch(arch, &(carga.txt), ',');
        fscanf(arch, "%c\n", &(carga.car));
        push(pila, carga);
    }

    fclose(arch);
}

void pilaAlista(t_nodo *nodo)
{
    t_nodo aux = NULL;
    t_refran carga;

    while (*nodo)
    {
        carga = pop(nodo);
        push(&aux, carga);
    }

    *nodo = aux;
}

void imprimirRecurs(t_nodo lista)
{
    if (lista)
    {
        printf("%-50s%-10c%-10d\n", lista->ref.txt, lista->ref.car, lista->ref.cantidad_caracter);
        imprimirRecurs(lista->sig);
    }
}