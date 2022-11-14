//PP2-TEMA-02- SOLUCION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_dato{          // ESTRUCTURA para almacenar una FILA
	char* loc;          // localidad (areglo DINAMICO de char)
	float sup;          // superficie
	int pob;            // poblacion
	int anio;           // anio del censo
};
typedef struct s_dato t_registro;

struct s_datos{         // ESTRUCTURA para almacenar los datos del ARCHIVO
	t_registro* fila;   // Arreglo DINAMICO de t_registro 
	int len;            // Almacenar el largo del arreglo fila
};
typedef struct s_datos t_datos;

struct s_nodo{       	// ESTRUCTURA para el NODO de la LISTA
	t_registro dato; 	// Informacion del nodo del tipo t_registro
	struct s_nodo* sig; // puntero al siguiente
};
typedef struct s_nodo* t_nodo;

void insertarPrimero(t_nodo *nodo, t_registro carga);
void insertarOrdenado(t_nodo *nodo, t_registro carga);

void cargarArch(t_nodo *nodo, int orden)
{
	FILE *arch;
	t_registro aux;
	int i, c;
	
	arch = fopen("datos.csv", "r");
	
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
		
		if (orden == 0)
		{
			insertarPrimero(nodo, aux);
		}
		
		else if (orden == 1)
		{
			insertarOrdenado(nodo, aux);
		}
	}
	
	fclose(arch);
}

void insertarPrimero(t_nodo *nodo, t_registro carga)
{
	t_nodo aux;
	
	if (!*nodo)
	{
		aux = (t_nodo)malloc(sizeof(struct s_nodo));
		aux->dato = carga;
		aux->sig = (*nodo);
		(*nodo) = aux;
	}
	
	else
	{
		insertarPrimero(&((*nodo)->sig), carga);
	}
}
	
void mostrarLst(t_nodo lst){
	if (lst)
	{
		printf("%17s%8.2f%8d%6d\n", lst->dato.loc, lst->dato.sup, lst->dato.pob, lst->dato.anio);
		mostrarLst(lst->sig);
	}
}

void insertarOrdenado(t_nodo *nodo, t_registro carga)
{
	t_nodo aux;
	
	if (!*nodo || ((*nodo)->dato.sup > carga.sup))
	{
		aux = (t_nodo)malloc(sizeof(struct s_nodo));
		aux->dato = carga;
		aux->sig = (*nodo);
		(*nodo) = aux;
	}
	
	else
	{
		insertarOrdenado(&((*nodo)->sig), carga);
	}
}

void filtrar(t_nodo *nodo, int anio, int pob)
{
	t_nodo aux;
	
	if (*nodo)
	{
		if ((*nodo)->dato.anio == anio && (*nodo)->dato.pob >= pob)
		{
			filtrar(&((*nodo)->sig), anio, pob);
		}
		
		else
		{
			aux = (*nodo);
			(*nodo) = (*nodo)->sig;
			free(aux);
			filtrar(nodo, anio, pob);
		}
	}
}
	
	
int main(){
	t_nodo lst=NULL;
	t_nodo lstOrdenada = NULL;
	
	printf("\n= = = ARREGLO DINAMICO CON LOS DATOS = = = =\n");
	cargarArch(&lst, 0);
	mostrarLst(lst);

	printf("\n= = = = LISTA FILTRADA Y ORDENADA = = = = =\n");

	cargarArch(&lstOrdenada, 1);
	filtrar(&lstOrdenada, 2010, 300000);
	mostrarLst(lstOrdenada);
	
	return 0;
}
	

	
/*
void mostrarTabla(t_datos datos){
	// AQUI EL CODIGO
	
	
}

t_nodo filtrarDatos(t_datos d,int anio,int pob){ 
	t_nodo lst=NULL;
	// AQUI EL CODIGO
	
	
	
	return lst;
}
	

t_datos cargarDatos(){
	t_datos datos;
	t_registro registros;
	FILE *arch;
	int i, c;
	t_nodo aux;
	
	arch = fopen("datos.csv", "r");
	
	datos = (t_datos)malloc(sizeof(struct s_datos));
	while (!feof(arch))
	{
	registros.loc = malloc(sizeof(char));
	c = fgetc(arch);
	
	for (i = 0; c != ','; i++)
	{
	registros.loc[i] = c;
	registros.loc = realloc(registros.loc, i + 2);
	c = fgetc(arch);
	}
	registros.loc = 0;
	
	fscanf(arch, "%f,%d,%d\n", &registros.sup, &registros.pob, &registros.anio);
	
	}
	
	
	fclose(arch);
	
	
	return datos;
}
*/
