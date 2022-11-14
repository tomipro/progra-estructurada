// RPP2-TEMA-01 - PLANTILLA
#include <stdio.h>
#include <stdlib.h>

struct s_dato
{			   // ESTRUCTURA para almacenar una FILA
	char *loc; // localidad (arreglo DINAMICO de char)
	float sup; // superficie
	int pob;   // poblacion
	int anio;  // anio del censo
};
typedef struct s_dato t_registro;

struct s_nodo
{						// ESTRUCTURA para el NODO de la PILA o LISTA
	t_registro fila;	// Informacion del nodo del tipo t_registro
	struct s_nodo *sig; // puntero al siguiente
};
typedef struct s_nodo *t_nodo;

void insertarOrdenado(t_nodo *nodo, t_registro carga);
t_registro pop(t_nodo *nodo);
void push(t_nodo *nodo, t_registro carga);
void mostrarPila(t_nodo *pila);

void cargarDatos(t_nodo *lista, char *nomArch)
{
	// CODIFICAR AQU�
	FILE *arch;
	int i, c;
	t_registro aux;

	arch = fopen(nomArch, "r");

	while (!feof(arch))
	{
		aux.loc = malloc(sizeof(char));
		c = fgetc(arch);

		for (i = 0; c != ','; i++)
		{
			aux.loc[i] = c;
			aux.loc = realloc(aux.loc, i + 2);
			c = fgetc(arch);
		}
		aux.loc[i] = 0;

		fscanf(arch, "%f,%d,%d\n", &aux.sup, &aux.pob, &aux.anio);

		insertarOrdenado(lista, aux);
	}

	fclose(arch);
}

void insertarOrdenado(t_nodo *nodo, t_registro carga)
{
	t_nodo aux;

	if (!*nodo || ((*nodo)->fila.sup) > carga.sup)
	{
		aux = (t_nodo)malloc(sizeof(struct s_nodo));
		aux->fila = carga;
		aux->sig = (*nodo);
		(*nodo) = aux;
	}

	else
	{
		insertarOrdenado(&((*nodo)->sig), carga);
	}
}

void mostrarPila(t_nodo *pila)
{
	// CODIFICAR AQU�
	t_registro registro;

	while (*pila)
	{
		registro = pop(pila);
		printf("%15s%8.2f%9d%7d\n", registro.loc, registro.sup, registro.pob, registro.anio);
	}
}

void filtrarDatos(t_nodo *lst, t_nodo *pila, int anio, int pobinf, int pobsup)
{
	// CODIFICAR AQU�
	t_registro registros;

	if (*lst)
	{
		if (((*lst)->fila.anio) == anio && ((*lst)->fila.pob) > pobinf && ((*lst)->fila.pob) < pobsup)
		{
			registros = pop(lst);
			push(pila, registros);
		}
		filtrarDatos(&((*lst)->sig), pila, anio, pobinf, pobsup);
	}
}

void push(t_nodo *nodo, t_registro carga)
{
	t_nodo aux;

	aux = (t_nodo)malloc(sizeof(struct s_nodo));
	aux->fila = carga;
	aux->sig = (*nodo);
	(*nodo) = aux;
}

t_registro pop(t_nodo *nodo)
{
	t_registro registro;
	t_nodo aux;

	aux = (*nodo);
	registro = aux->fila;
	(*nodo) = aux->sig;
	free(aux);

	return registro;
}
void mostrarLst(t_nodo lst)
{
	// CODIFICAR AQU�
	if (lst)
	{
		printf("%15s%8.2f%9d%7d\n", lst->fila.loc, lst->fila.sup, lst->fila.pob, lst->fila.anio);
		mostrarLst(lst->sig);
	}
}

int main()
{
	t_nodo pila = NULL;
	t_nodo lst = NULL;

	printf("\n= = = = = T E M A - 1 (R O J O) = = = = = =\n");
	cargarDatos(&lst, "datos.csv"); // 1)
	printf("\n= = = LISTA CON LOS DATOS ORDENADOS = = = =\n");
	mostrarLst(lst); // 2)

	printf("\n= = = = PILA FILTRADA = = = = = = = = = =\n");
	filtrarDatos(&lst, &pila, 2010, 200000, 600000); // 3)
	mostrarPila(&pila);								 // 4)

	return 0;
}
