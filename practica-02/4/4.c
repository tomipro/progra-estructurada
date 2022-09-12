#include <stdio.h>

#define N 10
#define T 50

struct s_personas
{
    int dni;
    char nombre[T];
    char pais[T];
};
typedef struct s_personas t_personas;

void cargarArch(t_personas arrPersonas[N], char nomArch[T]);

int main(void)
{
    t_personas arrPersonas[N];

    cargarArch(arrPersonas, "./personas.txt");

    return 0;
}

void cargarArch(t_personas arrPersonas[N], char nomArch[T])
{
    FILE *arch;
    int i = 0;

    arch = fopen(nomArch, "w");

    printf("Ingrese DNI (sin puntos): ");
    scanf("%d", &arrPersonas[i].dni);

    while ((i < N) && ((arrPersonas[i].dni > 0)))
    {
        fflush(stdin);
        printf("Ingrese nombre: ");
        scanf("%[^\n]s", arrPersonas[i].nombre);
        fflush(stdin);
        printf("Ingrese pais: ");
        scanf("%[^\n]s", arrPersonas[i].pais);
        fprintf(arch, "%d, %s, %s\n", arrPersonas[i].dni, arrPersonas[i].nombre, arrPersonas[i].pais);

        i++;

        if (i < N)
        {
            printf("Ingrese DNI (sin puntos): ");
            scanf("%d", &arrPersonas[i].dni);
        }
    }

    fclose(arch);
}
