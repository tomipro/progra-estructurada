#include <stdio.h>
#include <stdlib.h>

#define T 10
/**
Para visualizar archivos Binarios
https://hexed.it/
*/

/**

  CREA UN ARCHIVO BINARIO Y PERMITE ESCRIBIR el
  CONTENIDO DE UN ARREGLO EN EL ARCHIVO.
  LUEGO SE LEE EL ARCHIVO Y SE IMPRIME EL ARREGLO.
  COMANDOS
        fopen
        fwrite
        rewind
        fread
        fclose

        MODOS DE APERTURA
                          rb
                          wb
                          w+b
                          r+b


size_t fwrite ( const void * restrict buffer, size_t size, size_t count, FILE * restrict stream ) ;
       fwrite (       fuentedeDatos         ,       size ,   count     ,      archivo           ) ;

size_t fread  ( void * restrict buffer, size_t size, size_t count, FILE * restrict stream ) ;
        fread (      destinodeDatos   ,       size ,   count     ,      archivo           ) ;
*/

FILE *abrirArchivo(char nomArch[T], char modo[]);
int escribirArchivo(FILE *fp, int datosFuente[T]);
int leerArchivo(FILE *fp, int datosDestino[T]);
int cargarVector(char arr[]);
int imprimirVector(int arr[T]);
int cerrarArchivo(FILE *fp);

int main()
{
    int datosFuente[T] = {25, 12, 45, 345, 512, 345, 654, 287, 567, 124}; // 4*T=40
    int datosDestino[T] = {0};

    /** ########################    DEFINE VARIABLES     ###########################  */
    FILE *fp;                        // DECLARACION de un puntero al archivo
    char nomArch[11] = "prueba.dat"; // DECLARACION nombre del archivo

    /** ##############     ABRIR ARCHIVO DE ESCRITURA Y BINARIO    ##################  */
    fp = abrirArchivo(nomArch, "w+b"); // ABRIR  el archivo de (W+b):escritura / lectura Binario

    /** ##############     ESCRIBE ARCHIVO                         ##################  */
    printf("Escribiendo en el archivo las cantidades:\n\n");
    imprimirVector(datosFuente);      // Imprimir el vactor para ver el pantalla lo que se cargará en e archivo
    escribirArchivo(fp, datosFuente); // ESCRIBE en archivo el contenido de datosFuente*

    /** ##############   COLOCAR PUNTERO DEL DESCRIPTOR AL INICIO   ##################  */
    rewind(fp); // vuelve el puntero del archivo al inicio

    /** ##############     LEER ARCHIVO                            ##################  */
    printf("\n\n\nLeyendo los datos del archivo :\n\n");
    leerArchivo(fp, datosDestino);
    imprimirVector(datosDestino);
    printf("\n");

    /** ##############     CERRAR ARCHIVO                          ##################  */
    cerrarArchivo(fp); // SIEMPRE se debe cerrar el archivo

    return 0;
}

FILE *abrirArchivo(char nomArch[T], char modo[])
{
    /** ABRE el descriptor de un archivo y en un modo determinado*/
    return fopen(nomArch, modo);
}

int escribirArchivo(FILE *fp, int datos[T])
{
    // int escribirArchivo(FILE* fp,  int* datos)
    /** escribe en un archivo binario (pasado el puntero del descriptor por parámetro)
          el contenido leido de un arreglo (pasado por parametro)

         Parametros "fwrite"
         1) datos: puntero de los Valores a leer (¡es la fuente de datos!!)
         2) Tamanio en byte de cada elemento a escribir
         3) cantidad de elementos a escribir
         4) puntero del archivo a escribir (¡es el destino de los datos!!)

                  // 40
                 //  4               10
     */

    fwrite(datos, sizeof(int), T, fp); // fwrite: permite escribir archivos

    /**
        int i;
        for (i=0;i<T;i++){
            fwrite( &(datos[i]), sizeof( int), 1, fp );
        }
    */
    return 0;
}
int leerArchivo(FILE *fp, int datos[T])
{
    /** leer en un archivo binario (pasado el puntero del descriptor por parámetro)
        y escribir el contenido en un arreglo (pasado por parametro)

        Parametros
        1) datos: puntero de los Valores a escribir (¡es el destino de los datos!!)
        2) Tamanio en byte de cada elemento a leer
        3) cantidad de elementos a leer
        4) puntero del fichero a leer (¡es la fuente de datos!!)

    */
    fread(datos, sizeof(int), T, fp); // fread: Permite leer archivos

    return 0;
}

int imprimirVector(int arr[T])
{
    int i;
    for (i = 0; i < T; i++)
        printf("%d\t", arr[i]);

    return 0;
}

int cerrarArchivo(FILE *fp)
{
    fclose(fp); // CIERRA el descriptor de un archivo
    return 0;
}