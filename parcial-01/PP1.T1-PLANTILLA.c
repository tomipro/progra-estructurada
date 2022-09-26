// TEMA-01- PLANTILLA
#include <stdio.h>
#include <string.h>
#define TD 100 // tama�o arreglo de datos
#define TT 1   // tama�o arreglo de titulo
#define TC 30  // tama�o de las cadenas

struct s_titu
{
	char art[TC], can[TC], pre[TC], cod[TC];
};
typedef struct s_titu t_titu;
struct s_dato
{
	char nomArt[TC];
	int cantidad;
	float precio;
	int codigo;
};
typedef struct s_dato t_dato;

int decodAnio(unsigned long int fecha);

void cargarArr(char nomArch[], t_dato ad[TD], t_titu at[1])
{
	int i = 0, r;
	FILE *arch;

	arch = fopen(nomArch, "r");

	r = fscanf(arch, "%[^,],%[^,],%[^,],%[^\n]\n", at[i].art, at[i].can, at[i].pre, at[i].cod);

	for (i = 1; !feof(arch); i++)
	{
		r = fscanf(arch, "%[^,],%d,%f,%d\n", ad[i].nomArt, &ad[i].cantidad, &ad[i].precio, &ad[i].codigo);
	}

	ad[i].codigo = 0;
}
void imprimirArr(t_dato ad[TD], t_titu at[1])
{
	int i = 0;

	printf("%20s%10s%10s%13s\n", at[i].art, at[i].can, at[i].pre, at[i].cod);
	for (i = 1; ad[i].codigo != 0; i++)
	{
		printf("%20s%10d%10.3f%13d\n", ad[i].nomArt, ad[i].cantidad, ad[i].precio, ad[i].codigo);
	}
}

void ordenarArr(t_dato ad[TD])
{
	int i, j;
	t_dato aux;

	for (i = 0; ad[i].codigo != 0; i++)
	{
		for (j = i + 1; ad[j].codigo != 0; j++)
		{
			if (strlen(ad[i].nomArt) > strlen(ad[j].nomArt))
			{
				aux = ad[i];
				ad[i] = ad[j];
				ad[j] = aux;
			}
		}
	}
}

void imprimirRegistroXFecha(t_dato ad[TD], int anio, int mes, int dia)
{
	int i, j;

	printf("Para el a�o: %d - - - - - - - - - - - - - - - - - - - - -\n", anio);
	for (i = 0; ad[i].codigo != 0; i++)
	{
		if (anio == (decodAnio(ad[i].codigo)))
		{
			printf("%20s%10d%10.3f%13d\n", ad[i].nomArt, ad[i].cantidad, ad[i].precio, ad[i].codigo);
		}
	}
}

int decodAnio(unsigned long int fecha)
{
	return (fecha >> 25);
}

int main()
{

	t_titu arrTitulo[1]; // Arreglo de un solo elemento
	t_dato arrDatos[TD];

	cargarArr("pp1.t1.txt", arrDatos, arrTitulo);
	printf("\nTABLA ORIGINAL * * * * * * * * * * * * * * * * * * * *\n");

	imprimirArr(arrDatos, arrTitulo);

	ordenarArr(arrDatos);
	printf("\nTABLA ORDENADA * * * * * * * * * * * * * * * * * * * *\n");
	imprimirArr(arrDatos, arrTitulo);

	printf("\nBUSQUEDA POR FECHA * * * * * * * * * * * * * * * * * *\n");
	imprimirRegistroXFecha(arrDatos, 22, 3, 18);
	imprimirRegistroXFecha(arrDatos, 21, 4, 3);
	imprimirRegistroXFecha(arrDatos, 21, 3, 3);
	return 0;
}

/*
void generarFechas(){
//int fechaT1[3]={22,03,18}; //	T1  738787331
//int fechaT2[3]={18,06,28}; //	T2   29364832
//     768152163
//int fechaT1[3]={21,04,3};  // T1  704741380
//int fechaT2[3]={21,03,03}; //	T2    3151152
//     707892532
//int fechaT1[3]={17,12,20}; //	T1  571080716
//int fechaT2[3]={22,10,12}; //	T2   12588704
//     583669420
//int fechaT1[3]={21,04,3};  //	T1  704741380
//int fechaT2[3]={21,03,03}; // T2    3151152
//     707892532
int fechaT1[3]={20,2,28};    //	T1  672006146
int fechaT2[3]={22,03,18}; //	T2   18880048
							 //     690886194
int res[3]={0};
int valorT1 = codeT1(fechaT1);
int valorT2 = codeT2(fechaT2);
int valor   = valorT1 | valorT2;

printf("T1: %d\n",valorT1);
printf("T2: %d\n",valorT2);
printf("VALOR: %d\n",valor);
decodeT1(valor,res);
printf("T1: %d/%d/%d\n",res[0],res[1],res[2]);
decodeT2(valor,res);
printf("T2: %d/%d/%d\n",res[0],res[1],res[2]);

}

int main() {
generarFechas();

return 0;
}
	*/
