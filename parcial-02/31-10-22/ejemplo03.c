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

void encolar(t_nodo *nodo, t_registro carga);
void cargarArch(t_nodo *nodo);

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

        encolar(nodo, aux);

        c = fgetc(arch);
    }

    fclose(arch);
}

void encolar(t_nodo *nodo, t_registro carga)
{
    if (!*nodo)
    {
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->dato = carga;
        (*nodo)->sig = NULL;
    }
    else
    {
        encolar(&(*nodo)->sig, carga);
    }
}

t_datos desencolarAarregloD(t_nodo *cola)
{
    t_datos ret;
    t_nodo aux;

    ret.len = 0;
    ret.fila = malloc(sizeof(t_registro));

    while (*cola)
    {
        aux = *cola;
        *cola = (*cola)->sig;

        ret.fila = realloc(ret.fila, sizeof(t_registro) * (ret.len + 1));
        ret.fila[ret.len] = aux->dato;
        ret.len++;

        free(aux);
    }

    return ret;
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

int main(void)
{
    t_nodo cola = NULL;
    t_datos dato;

    cargarArch(&cola);
    // printQueue(cola);

    dato = desencolarAarregloD(&cola);
    mostrarTabla(dato);


    return 0;
}

/*
cargar en una cola y pasar a arr
*/