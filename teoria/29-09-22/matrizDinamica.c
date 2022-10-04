#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarMatDin(char ***mat);
void imprimirMatDin(char **mat);
void caso1();
void caso2();

int main(void)
{
    caso2();
    return 0;
}

void caso1()
{
    printf(" C A S O  1 \n");
    int i = 0;
    char *aux = NULL;  // ARREGLO auxiliar
    char **mat = NULL; // MATRIZ

    //- - - - - posicion -> 0 - - - (Con auxiliar) - - - - - - - - - - - - - -
    aux = malloc(sizeof(char) * 8); // asignar memoria al ARREGLO
    strcpy(aux, "Boquita");         // asignar cadena a ARREGLO

    mat = malloc(sizeof(char *) * 1); // asignar memoria a la MATRIZ
    *(mat + 0) = aux;                 // asignar ARREGLO a fila de la MATRIZ
    // printf("%s\n",*(mat+0));         // imprimiR MATRIZ fila 0

    //- - - - - posicion -> 1 - - - (Con auxiliar) - - - - - - - - - - - - - -
    aux = malloc(sizeof(char) * 6); // asignar memoria al ARREGLO
    strcpy(aux, "River");           // asignar cadena a ARREGLO

    mat = realloc(mat, sizeof(char *) * 2); // asignar memoria a la MATRIZ
    *(mat + 1) = aux;                       // asignar ARREGLO a fila de la MATRIZ
    // printf("%s\n",*(mat+1));           // imprimiR MATRIZ fila 1

    //- - - - - posicion -> 3 - - - (Sin auxiliar) - - - - - - - - - - - - - -
    mat = realloc(mat, sizeof(char *) * 3); // asignar memoria a la MATRIZ
    *(mat + 2) = malloc(sizeof(char) * 11); // asignar memoria al ARREGLO
    strcpy(*(mat + 2), "Manchester");       // asignar cadena a ARREGLO
    // printf("%s\n",*(mat+2));           // imprimiR MATRIZ fila 1

    //- - - - - posicion -> 4 - - - (Sin auxiliar) - - - - - - - - - - - - - -
    mat = realloc(mat, sizeof(char *) * 4); // asignar memoria a la MATRIZ
    *(mat + 3) = NULL;                      // INDICA QUE TERMINA LA MATRIZ

    //- - - - - RECORRIDO - - - - - - - - - - - - - - - - - - - - - - - - - -
    printf("  //- - - - - RECORRIDO - - -\n");
    for (i = 0; *(mat + i) != NULL; i++)
    {
        printf("%s\n", *(mat + i));
    }
}

void cargarMatDin(char ***mat)
{
    *mat = malloc(sizeof(char *) * 1);      // asignar memoria a la MATRIZ
    *(*mat + 0) = malloc(sizeof(char) * 8); // asignar memoria al ARREGLO
    strcpy(*(*mat + 0), "Boquita");         // asignar cadena a ARREGLO

    *mat = realloc(*mat, sizeof(char *) * 2); // asignar memoria a la MATRIZ
    *(*mat + 1) = malloc(sizeof(char) * 6);   // asignar memoria al ARREGLO
    strcpy(*(*mat + 1), "River");             // asignar cadena a ARREGLO

    *mat = realloc(*mat, sizeof(char *) * 3); // asignar memoria a la MATRIZ
    *(*mat + 2) = malloc(sizeof(char) * 11);  // asignar memoria al ARREGLO
    strcpy(*(*mat + 2), "Manchester");        // asignar cadena a ARREGLO

    *mat = realloc(*mat, sizeof(char *) * 4); // asignar memoria a la MATRIZ
    *(*mat + 3) = NULL;                       // INDICA QUE TERMINA LA MATRIZ
}

void imprimirMatDin(char **mat)
{
    int i = 0;
    for (i = 0; *(mat + i) != NULL; i++)
    {
        printf("%s\n", *(mat + i));
    }
}

void caso2()
{
    printf(" C A S O  2 \n");

    char **mat = NULL;
    cargarMatDin(&mat);
    printf("  //- - - - - RECORRIDO - - -\n");
    imprimirMatDin(mat);
}
