#include <stdio.h>
#include <stdlib.h>

struct s_dato
{              // ESTRUCTURA para almacenar una FILA
    char *loc; // localidad (areglo DINAMICO de char)
    float sup; // superficie
    int pob;   // poblacion
    int anio;  // anio del censo
};
typedef struct s_dato t_registro;

struct s_nodo
{                       // ESTRUCTURA para el NODO de la LISTA
    t_registro dato;    // Informacion del nodo del tipo t_registro
    struct s_nodo *sig; // puntero al siguiente
};
typedef struct s_nodo *t_nodo;

struct s_datos
{                     // ESTRUCTURA para almacenar los datos del ARCHIVO
    t_registro *fila; // Arreglo DINAMICO de t_registro
    int len;          // Almacenar el largo del arreglo fila
};
typedef struct s_datos t_datos;

void insertarOrdenado(t_nodo *nodo, t_registro carga);
void push(t_nodo *nodo, t_registro carga);
t_registro pop(t_nodo *nodo);
t_datos desapilarAarregloD(t_nodo *pila);

void cargarArch(t_nodo *nodo)
{
    FILE *arch;
    t_registro aux;
    int i, c;

    arch = fopen("./datos.csv", "r");

    c = fgetc(arch);
    while (!feof(arch))
    {
        aux.loc = malloc(sizeof(char));

        for (i = 0; c != ','; i++)
        {
            aux.loc[i] = c;
            aux.loc = realloc(aux.loc, i + 2);
            c = fgetc(arch);
        }
        aux.loc[i] = 0;

        fscanf(arch, "%f,%d,%d\n", &aux.sup, &aux.pob, &aux.anio);

        push(nodo, aux);

        c = fgetc(arch);
    }

    fclose(arch);
}

void push(t_nodo *nodo, t_registro carga)
{
    t_nodo aux;

    aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->dato = carga;
    aux->sig = (*nodo);
    (*nodo) = aux;
}

t_datos desapilarAarregloD(t_nodo *pila)
{
    t_datos datos;
    t_nodo aux;
    int i = 0;

    datos.fila = malloc(sizeof(t_registro));
    datos.len = 0;

    while (*pila)
    {
        aux = *pila;
        *pila = (*pila)->sig;

        datos.fila[i] = aux->dato;
        datos.fila = realloc(datos.fila, sizeof(t_registro) * (i + 2));
        datos.len++;

        free(aux);
        i++;
    }

    return datos;
}

void sortAndFilter(t_datos *datos)
{
    int i, j;
    t_registro aux;

    for (i = 0; i < datos->len - 1; i++)
    {
        for (j = 0; j < datos->len - i - 1; j++)
        {
            if (datos->fila[j].sup > datos->fila[j + 1].sup)
            {
                aux = datos->fila[j];
                datos->fila[j] = datos->fila[j + 1];
                datos->fila[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < datos->len; i++)
    {
        if (datos->fila[i].anio != 2010)
        {
            for (j = i; j < datos->len - 1; j++)
            {
                datos->fila[j] = datos->fila[j + 1];
            }
            datos->len--;
            i--;
        }
    }
}

void mostrarTabla(t_datos datos)
{
    // AQUI EL CODIGO
    int i;

    for (i = 0; i < datos.len; i++)
    {
        printf("%-17s%7.2f%8d%7d\n", datos.fila[i].loc, datos.fila[i].sup, datos.fila[i].pob, datos.fila[i].anio);
    }
}

// t_nodo filtrarDatos(t_datos d, int anio, int pob)
// {
//     t_nodo lst = NULL;
//     // AQUI EL CODIGO

//     return lst;
// }

void mostrarPila(t_nodo lst)
{
    // AQUI EL CODIGO
    if (lst)
    {
        mostrarPila(lst->sig);
        printf("%-17s%7.2f%8d%7d\n", lst->dato.loc, lst->dato.sup, lst->dato.pob, lst->dato.anio);
    }
}

int main()
{
    t_nodo pila = NULL;
    t_datos datos;

    printf("\n= = = PILA CARGADA CON LOS DATOS = = = =\n");
    cargarArch(&pila);
    mostrarPila(pila);

    printf("\n= = = ARREGLO DINAMICO CON LOS DATOS = = = =\n");
    datos = desapilarAarregloD(&pila); // 1)
    mostrarTabla(datos);

    printf("\n= = = ARREGLO DINAMICO ORDENADO Y FILTRADO = = = =\n");
    sortAndFilter(&datos); // 3)
    mostrarTabla(datos);

    // printf("\n= = = = ARREGLO DINAMICO FILTRADA Y ORDENADA = = = = =\n");
    // lst = filtrarDatos(datos, 2010, 300000); // 3)
    // mostrarLst(lst); // 4)

    return 0;
}
