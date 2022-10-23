#include <stdio.h>
#include <stdlib.h>

struct s_contenido
{
    char *nombre;
    int edad;
};
typedef struct s_contenido t_contenido;

struct s_nodo
{
    t_contenido content;
    struct s_nodo *sig;
};
typedef struct s_nodo *t_nodo;

// void leerStrDeArch(FILE *arch, char **arrC, char sep);
// void cargarPila(const char *nomArch, t_nodo *pila);
void cargarArch(const char *nomArch, t_nodo *lista);
void push(t_nodo *pila, t_contenido carga);
t_contenido pop(t_nodo *pila);
void pilaAlista(t_nodo *nodo);
void imprimirR(t_nodo lista);

int main(void)
{
    t_nodo n = NULL;

    // cargarPila("./02.txt", &n);
    cargarArch("./02.txt", &n);
    printf("\nPila del archivo:\n");
    imprimirR(n);

    printf("\nPila a lista\n");
    pilaAlista(&n);
    imprimirR(n);

    return 0;
}

void cargarArch(const char *nomArch, t_nodo *lista)
{
    FILE *arch;
    t_contenido aux;
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

        fscanf(arch, "%d\n", &aux.edad);

        push(lista, aux);

        c = fgetc(arch);
    }

    fclose(arch);
}

void push(t_nodo *pila, t_contenido carga)
{
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->content = carga;
    aux->sig = (*pila);
    (*pila) = aux;
}

t_contenido pop(t_nodo *pila)
{
    t_contenido carga;
    t_nodo aux = *pila;

    carga = aux->content;
    *pila = aux->sig;
    free(aux);

    return carga;
}

void pilaAlista(t_nodo *nodo)
{
    t_nodo aux = NULL;
    t_contenido carga;

    while (*nodo)
    {
        carga = pop(nodo);
        push(&aux, carga);
    }
    *nodo = aux;
}

void imprimirR(t_nodo lista)
{
    if (lista)
    {
        printf("%s,%d\n", lista->content.nombre, lista->content.edad);
        imprimirR(lista->sig);
    }
}

// void leerStrDeArch(FILE *arch, char **arrC, char sep)
// {
//     char c;
//     int i = 0;

//     *(arrC) = malloc(sizeof(char));

//     if (!feof(arch))
//     {
//         c = fgetc(arch);

//         while (!feof(arch) && c != sep)
//         {
//             (*(arrC))[i] = c;
//             i++;
//             *(arrC) = realloc(*(arrC), (i + 1) * sizeof(char));
//             c = fgetc(arch);
//         }
//     }
//     (*(arrC))[i] = '\0';
// }

// void cargarPila(const char *nomArch, t_nodo *pila)
// {
//     FILE *arch;
//     t_contenido carga;

//     arch = fopen(nomArch, "r");

//     while (!feof(arch))
//     {
//         leerStrDeArch(arch, &(carga.nombre), ',');
//         fscanf(arch, "%d\n", &(carga.edad));
//         push(pila, carga);
//     }
// }