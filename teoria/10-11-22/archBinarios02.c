#include <stdio.h>
#include <stdlib.h>
#define T 10
/**
Para visualizar archivos Binarios
https://hexed.it/
*/

struct sVenTar
{                      // 33 byte
    int codVen;        //  4 byte
    char mesVenta[25]; // 25 byte
    int canTar;        //  4 byte
};
typedef struct sVenTar tVenTar;

int cerrarArchivo(FILE *fp);
FILE *abrirArchivo(char nombre[30], char modo[3]);
int escribirArchivo(FILE *fichero);
int leerArchivo(FILE *fichero);

int main()
{
    FILE *fichero;
    char nomArch[30] = "ventasTarjetas.dat";
    char modo[4] = "w+b";

    fichero = abrirArchivo(nomArch, modo);
    escribirArchivo(fichero);
    rewind(fichero);
    leerArchivo(fichero);
    cerrarArchivo(fichero);

    printf("\n");
    printf("------- %lu -------", sizeof(tVenTar));

    return 0;
}
FILE *abrirArchivo(char nombre[30], char modo[3])
{
    FILE *fichero = fopen(nombre, modo);
    printf("Fichero: %s -> ", nombre);
    if (fichero)
        printf("creado (ABIERTO)\n");
    else
        printf("Error (NO ABIERTO)\n");

    return fichero;
}

int cerrarArchivo(FILE *fichero)
{
    int res = 0;
    if (!fclose(fichero))
        printf("\nFichero cerrado\n");
    else
    {
        printf("\nError: fichero NO CERRADO\n");
        res = 1;
    }
    return res;
}

int escribirArchivo(FILE *fichero)
{
    /** cargar el arreglo de tVenTar con datos validos*/
    tVenTar venTar[T] = {{1, "Enero", 91},
                         {1, "Febrero", 60},
                         {1, "Marzo", 60},
                         {3, "Febrero", 60},
                         {6, "Marzo", 76},
                         {1, "Enero", 90},
                         {7, "Febrero", 60},
                         {7, "Marzo", 62},
                         {8, "Febrero", 60},
                         {8, "Marzo", 96}};

    int i;

    printf("Escribiendo cantidades:\n\n");
    for (i = 0; i < T; i++)
    {
        printf("%d\t%s\t%d\t\n", venTar[i].codVen, venTar[i].mesVenta, venTar[i].canTar);

        fwrite(&venTar[i], sizeof(tVenTar), 1, fichero);
    }
    // fwrite( venTar, sizeof(tVenTar), T, fichero );
    return 0;
}
int leerArchivo(FILE *fichero)
{
    int i;
    tVenTar leer[T] = {0};
    printf("\nLeyendo los datos del fichero \n");
    i = 0;
    fread(&leer[i], sizeof(tVenTar), 1, fichero);
    while (!feof(fichero))
    {
        printf("%d\t%s\t%d\t\n", leer[i].codVen, leer[i].mesVenta, leer[i].canTar);
        i++;
        fread(&leer[i], sizeof(tVenTar), 1, fichero);
    }

    /**
    //sin feof, utilizando el retorno de bytes leidos de fread (el count)

    res=fread( &leer[i], sizeof(tVenTar), 1, fichero );
    while(res!=0 ) {
        printf("%d\t%s\t%d\t\n", leer[i].codVen,leer[i].mesVenta,leer[i].canTar);
        i++;
        res=fread( &leer[i], sizeof(tVenTar), 1, fichero );
    }
    */
    return 0;
}

// en listas (y sus derivados) no podemos escribir/leer todo de un saque 
// ya que todo se encuentra disperso en la memoria