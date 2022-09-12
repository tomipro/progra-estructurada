// WIP
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
    t_personas personas[N];

    cargarTabla(personas, "./personas.txt");
    imprimirTabla(personas);

    return 0;
}

void cargarTabla(t_personas personas[N], char nomArch[T])
{
    FILE *arch;
    int r, i = 0;

    arch = fopen(nomArch, "r");

    r = fscanf(arch, "%d, %[^,]s, %[^\n]s\n", &personas[i].dni, personas[i].nombre, personas[i].pais);
    while ((r != EOF) && (i < N))
    {
        r = fscanf(arch, "%d, %[^,]s, %[^\n]s\n", &personas[i].dni, personas[i].nombre, personas[i].pais);
        personas[i].pais = '\0';
        i++;
    }

    fclose(arch);
}

void imprimirTabla(t_personas personas[N])
{
    int i, j;

    printf("%-10s %15s %10s", "Documento", "Nombre", "Pais\n");
    printf("==========================================================\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%-10d %15s %10s\n", personas[i].dni, personas[i].nombre, personas[i].pais);
        }
    }
    printf("\n");
}
