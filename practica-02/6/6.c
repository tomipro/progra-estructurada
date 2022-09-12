#include <stdio.h>
#include <string.h>

#define N 10
#define T 50

struct s_personas
{
    int dni;
    char nombre[T];
    char pais[T];
};
typedef struct s_personas t_personas;

void cargarTabla(t_personas personas[N], char nomArch[T]);
void ordenarTabla(t_personas personas[N], int col);
void imprimirTabla(t_personas personas[N]);
int opciones();

int main(void)
{
    t_personas personas[N] = {0};
    int opcion;

    cargarTabla(personas, "./personas.txt");

    opcion = opciones();

    if (opcion > 0 && opcion < 4)
    {
        ordenarTabla(personas, opcion);
        imprimirTabla(personas);
    }

    else
    {
        printf("Saliendo del programa...\n");
    }

    return 0;
}

void cargarTabla(t_personas personas[N], char nomArch[T])
{
    FILE *arch;
    int i, r = 0;

    arch = fopen(nomArch, "r");

    r = fscanf(arch, "%d, %[^,], %[^\n]", &personas[i].dni, personas[i].nombre, personas[i].pais);
    for (i = 1; i < N && r != EOF; i++)
    {
        r = fscanf(arch, "%d, %[^,], %[^\n]", &personas[i].dni, personas[i].nombre, personas[i].pais);
    }

    fclose(arch);
}

void ordenarTabla(t_personas personas[N], int col)
{
    int i, j, aux;
    char auxStr[T];

    for (i = 0; i < N && personas[i].dni != 0; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if ((col == 1) && (personas[i].nombre[0] < personas[j].nombre[0]) || (col == 2) && (personas[i].dni < personas[j].dni) || (col == 3) && (personas[i].pais[0] < personas[j].pais[0]))
            {
                aux = personas[i].dni;
                personas[i].dni = personas[j].dni;
                personas[j].dni = aux;

                strcpy(auxStr, personas[i].nombre);
                strcpy(personas[i].nombre, personas[j].nombre);
                strcpy(personas[j].nombre, auxStr);

                strcpy(auxStr, personas[i].pais);
                strcpy(personas[i].pais, personas[j].pais);
                strcpy(personas[j].pais, auxStr);
            }
        }
    }
}

void imprimirTabla(t_personas personas[N])
{
    int i;

    printf("\n%-15s %-15s %-5s", "Documento", "Nombre", "Pais");
    printf("\n==========================================\n\n");

    for (i = 0; personas[i].dni != 0; i++)
    {
        printf("%-15d %-15s %-5s\n", personas[i].dni, personas[i].nombre, personas[i].pais);
    }
    printf("\n");
}

int opciones()
{
    int opcion;

    printf("\n1 - Ver listado ordenado por nombre");
    printf("\n2 - Ver listado ordenado por documento");
    printf("\n3 - Ver listado ordenado por pais");
    printf("\n4 - Salir del programa\n\n");

    scanf("%d", &opcion);

    return opcion;
}
