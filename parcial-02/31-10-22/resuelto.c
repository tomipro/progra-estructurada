// PP2-TEMA-02- SOLUCION
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

struct s_datos
{                     // ESTRUCTURA para almacenar los datos del ARCHIVO
    t_registro *fila; // Arreglo DINAMICO de t_registro
    int len;          // Almacenar el largo del arreglo fila
};
typedef struct s_datos t_datos;

struct s_nodo
{                       // ESTRUCTURA para el NODO de la LISTA
    t_registro dato;    // Informacion del nodo del tipo t_registro
    struct s_nodo *sig; // puntero al siguiente
};
typedef struct s_nodo *t_nodo;

void insertarOrdenado(t_nodo *nodo, t_registro carga);

t_datos cargarDatos()
{
    t_datos datos;
    // AQUI EL CODIGO
    FILE *arch;
    int i = 0, j, c;

    arch = fopen("./datos.csv", "r");
    datos.fila = malloc(sizeof(t_registro));
    c = fgetc(arch);

    while (!feof(arch))
    {
        (datos.fila)[i].loc = malloc(sizeof(char));

        for (j = 0; c != ','; j++)
        {
            (datos.fila)[i].loc[j] = c;
            (datos.fila)[i].loc = realloc((datos.fila)[i].loc, j + 2);
            c = fgetc(arch);
        }
        (datos.fila)[i].loc[j] = 0;

        fscanf(arch, "%f,%d,%d\n", &(datos.fila)[i].sup, &(datos.fila)[i].pob, &(datos.fila)[i].anio);
        c = fgetc(arch);

        datos.fila = realloc(datos.fila, sizeof(t_registro) * (i + 2));

        i++;
    }

    datos.len = i;

    fclose(arch);

    return datos;
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

t_nodo filtrarDatos(t_datos d, int anio, int pob)
{
    t_nodo lst = NULL;
    // AQUI EL CODIGO
    int i;

    for (i = 0; i < d.len; i++)
    {
        if (d.fila[i].anio == anio && d.fila[i].pob > pob)
        {
            insertarOrdenado(&lst, d.fila[i]);
        }
    }

    return lst;
}

void insertarOrdenado(t_nodo *nodo, t_registro carga)
{
    t_nodo aux;

    if (!*nodo || (*nodo)->dato.sup >= carga.sup)
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->dato = carga;
        aux->sig = (*nodo);
        (*nodo) = aux;
    }

    else
    {
        insertarOrdenado(&(*nodo)->sig, carga);
    }
}

void mostrarLst(t_nodo lst)
{
    // AQUI EL CODIGO
    if (lst)
    {
        printf("%-17s%7.2f%8d%7d\n", lst->dato.loc, lst->dato.sup, lst->dato.pob, lst->dato.anio);
        mostrarLst(lst->sig);
    }
}

int main()
{
    t_nodo lst = NULL;
    t_datos datos;
    datos = cargarDatos(); // 1)
    printf("\n= = = ARREGLO DINAMICO CON LOS DATOS = = = =\n");
    mostrarTabla(datos);
    // 2)
    lst = filtrarDatos(datos, 2010, 300000); // 3)
    printf("\n= = = = LISTA FILTRADA Y ORDENADA = = = = =\n");
    mostrarLst(lst); // 4)
    return 0;
}
