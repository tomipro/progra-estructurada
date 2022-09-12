#include <stdio.h>

#define T 50
#define N 10

struct s_personas
{
    int dni;
    char nombre[T];
    char pais[T];
};
typedef struct s_personas t_personas;

void cargarTabla(t_personas personas[N], char nomArch[T]);
void imprimirTabla(t_personas personas[N]);

int main(void)
{
    t_personas personas[N] = {0};

    cargarTabla(personas, "./personas.txt");
    imprimirTabla(personas);

    return 0;
}

void cargarTabla(t_personas personas[N], char nomArch[T])
{
    FILE *arch;
    int r, i = 0;

    arch = fopen(nomArch, "r");

    r = fscanf(arch, "%d, %[^,], %[^\n]", &personas[i].dni, personas[i].nombre, personas[i].pais);

    for (i = 1; r != EOF && i < N; i++)
    {
        r = fscanf(arch, "%d, %[^,], %[^\n]", &personas[i].dni, personas[i].nombre, personas[i].pais);
    }

    fclose(arch);
}

void imprimirTabla(t_personas personas[N])
{
    int i;

    printf("\n%-15s %-15s %-5s", "Documento", "Nombre", "Pais\n");
    printf("==========================================\n");
    for (i = 0; i < N && personas[i].dni != 0; i++)
    {
        printf("%-15d %-15s %-5s\n", personas[i].dni, personas[i].nombre, personas[i].pais);
    }
    printf("\n");
}
