//PP2-TEMA-02- SOLUCION
#include <stdio.h>
#include <stdlib.h>

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


t_datos cargarDatos(){
	t_datos datos;
	// AQUI EL CODIGO
	FILE*arch;
	// arch=fopen("./datos.csv","r");
	if (arch!=NULL){
		char r=fgetc(arch);
		datos.fila=malloc(sizeof(t_registro));
		int i=0;
		int j;
		while (r!=EOF){
			(datos.fila[i]).loc=malloc(sizeof(char));
			for(j=0; r!=',';j++){
				(datos.fila[i]).loc[j]=r;
				(datos.fila[i]).loc=realloc((datos.fila[i]).loc,sizeof(char)*(j+2));
				r=fgetc(arch);
			} 
			(datos.fila[i]).loc[j]=0;
			fscanf(arch,"%f,%d,%d\n",&((datos.fila[i]).sup),&((datos.fila[i]).pob),&((datos.fila[i]).anio));
			r=fgetc(arch);

			datos.fila=realloc(datos.fila,sizeof(t_registro)*(i+2));
			i++;
		}
		datos.len=i;
	}fclose(arch);
	
	return datos;
}
	
void mostrarTabla(t_datos datos){
	// AQUI EL CODIGO
	for (int i=0;i<datos.len;i++){
		printf("\n%15s %10.2f %10d %5d",datos.fila[i].loc,datos.fila[i].sup,datos.fila[i].pob,datos.fila[i].anio);
	}
	
	
}

void insertOrd(t_nodo*nodo,t_registro valor){
	
	
	if (*nodo==NULL){
		*nodo=malloc(sizeof(struct s_nodo));
		(*nodo)->dato=valor;
		(*nodo)->sig=NULL;
	}
	else{
		
		if ((*nodo)->dato.sup > valor.sup){
			t_nodo aux=malloc(sizeof(struct s_nodo));
			//printf("\n%f  ---- %f",(*nodo)->dato.sup,valor.sup);
			aux->dato=(*nodo)->dato;
			aux->sig=(*nodo)->sig;
			(*nodo)->dato=valor;
			(*nodo)->sig=aux;
		}
		else{
			insertOrd(&((*nodo)->sig),valor);
		}
	}
}
	
t_nodo filtrarDatos(t_datos d,int anio,int pob){ 
	t_nodo lst=NULL;
	// AQUI EL CODIGO
	for (int i=0; i<d.len;i++){
		if(d.fila[i].anio==anio && d.fila[i].pob>=pob){
			//printf("\n%15s %10.2f %10d %5d",d.fila[i].loc,d.fila[i].sup,d.fila[i].pob,d.fila[i].anio);
			insertOrd(&lst,d.fila[i]);
		}
	}
	
	
	
	return lst;
}
void mostrarLst(t_nodo lst){
	// AQUI EL CODIGO
	if (lst!=NULL){
		printf("\n%15s %10.2f %10d %5d",lst->dato.loc,lst->dato.sup,lst->dato.pob,lst->dato.anio);
		mostrarLst(lst->sig);
	}
	

}

int main(){
	t_nodo lst=NULL;
	t_datos datos;
	datos=cargarDatos();                   // 1)
	printf("\n= = = ARREGLO DINAMICO CON LOS DATOS = = = =\n");
	mostrarTabla(datos); 
	// 2)
	lst=filtrarDatos(datos,2010,10000);   // 3)
	printf("\n= = = = LISTA FILTRADA Y ORDENADA = = = = =\n");
	mostrarLst(lst);	                   // 4)
	return 0;
}
	

	

