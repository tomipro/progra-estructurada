// WIP
#include <stdio.h>

#define NA 15
#define NM 15

typedef struct
{
    char nombre[100];
    int legajo, materias[30];
} t_alumno;

typedef struct
{
    char nombre[100];
    int codigo;
} t_materia;

typedef struct
{
    int legajo_alumno;
    int cod_materia, nota;
} t_nota;

void funcion01(t_alumno alumno[NA], char nomArch[50]);

int main(void)
{
    t_alumno alumno[NA] = {0};

    funcion01(alumno, "./alumnos.txt");

    return 0;
}

void funcion01(t_alumno alumno[NA], char nomArch[50])
{
    // nombre alumno, legajo, y materias
    int i = 0, j = 0;
    FILE *arch;

    arch = fopen(nomArch, "w");

    printf("Ingrese legajo del alumno: ");
    scanf("%d", &alumno[i].legajo);

    while ((i < NA) && (alumno[i].legajo != 0))
    {
        fflush(stdin);
        printf("Ingrese nombre del alumno: ");
        scanf("%[^\n]s", alumno[i].nombre);
        fflush(stdin);
        fprintf(arch, "%d, %s, ", alumno[i].legajo, alumno[i].nombre);

        printf("Ingrese materia del alumno [%d]: ", j);
        scanf("%d", &alumno[i].materias[j]);

        j = 1;
        while ((j < 30))
        {
            printf("Ingrese materia del alumno [%d]: ", j);
            scanf("%d", &alumno[i].materias[j]);
            if (j == 0)
            {
                fprintf(arch, "%d", &alumno[i].materias[j]);
            }

            else if (j > 0)
            {
                fprintf(arch, ",%d", &alumno[i].materias[j]);
            }

            else if (alumno[i].materias[j] == 0)
            {
                fprintf(arch, "\n");
            }
            j++;
        }

        i++;

        if (i < NA)
        {
            printf("Ingrese legajo del alumno: ");
            scanf("%d", &alumno[i].legajo);
        }
    }

    fclose(arch);
}