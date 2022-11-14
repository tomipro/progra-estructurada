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
	int contador = 0;

    FILE* arch=fopen("datos.csv","r");
    t_registro storage = {NULL,0.0,0,0};

    datos.fila = malloc(sizeof(t_registro));

    //datos = malloc(sizeof(t_datos);
    while(!feof(arch)){
        strDin(arch,&(storage.loc)); //recolecto datos de archivo
        fscanf(arch,"%f,%d,%d\n",&(storage.sup),&(storage.pob),&(storage.anio));

        datos.fila[contador] = storage; // guardo en din
        //printf("%i\n",datos.fila[contador].pob);

        datos.len = contador;
        contador++; //aumento el contador

        datos.fila= realloc(datos.fila,sizeof(t_registro)*(contador+1)); // redefino el tamaño del arr din
    }

    fclose(arch);

	return datos;
}
void strDin(FILE* arch,char** palabra){
    char r;
    int i=0;
    (*palabra)=malloc(sizeof(char));
    r=fgetc(arch);
    while(r!=','){
        ((*palabra))[i]=r;
        i++;
        (*palabra)=realloc((*palabra),sizeof(char)*(i+1));
        r=fgetc(arch);

    }
    ((*palabra))[i]='\0';
}

void mostrarTabla(t_datos datos){
	int i = 0;
	while(i<datos.len){
        printf("%15s - %.2f - %i - %i\n",datos.fila[i].loc ,datos.fila[i].sup ,datos.fila[i].pob ,datos.fila[i].anio);
        i++;
	}
}

t_nodo filtrarDatos(t_datos d,int anio,int pob){
	t_nodo lst=NULL;
	int i=0;
    while(i<d.len){
        d.fila[i].loc;
        if(d.fila[i].anio == anio && d.fila[i].pob > pob){
            insertar_ordenado(&lst,d.fila[i]);
        }
        i++;
	}
	return lst;
}
void insertar_ordenado(t_nodo* nodo,t_registro valor){
    if(*nodo == NULL){
        (*nodo) = malloc(sizeof(struct s_nodo));
        (*nodo)->dato = valor;
        (*nodo)->sig = NULL;
    }
    else{
        if(valor.sup < (*nodo)->dato.sup){
            t_nodo aux = malloc(sizeof(struct s_nodo));
            aux->dato = valor;
            aux->sig = (*nodo);
            (*nodo)=aux;
        }
        else{
            insertar_ordenado(&((*nodo)->sig),valor);
        }
    }
}
void mostrarLst(t_nodo lst){
    if(lst!=NULL){
        t_registro aux = lst->dato;
        printf("%15s - %.2f - %i - %i\n",aux.loc ,aux.sup ,aux.pob ,aux.anio);
        mostrarLst(lst->sig);
    }

}

int main(){
	t_nodo lst=NULL;
	t_datos datos;
	datos=cargarDatos();                   // 1)
	printf("\n= = = ARREGLO DINAMICO CON LOS DATOS = = = =\n");
	mostrarTabla(datos);                   // 2)
	lst=filtrarDatos(datos,2010,300000);   // 3)
	printf("\n= = = = LISTA FILTRADA Y ORDENADA = = = = =\n");
	mostrarLst(lst);	                   // 4)
	return 0;
}




