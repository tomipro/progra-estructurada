#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_producto
{
    char *art;
    int cant;
    float precio;
    unsigned long int codigo;
};
typedef struct s_producto t_producto;

void cargarArchDin(const char *nomArch);

int main(void)
{
    // t_producto productos;

    cargarArchDin("./ejemplo1.txt");
    // printf("%s\n", productos);

    return 0;
}

void cargarArchDin(const char *nomArch)
{
    // FILE *arch;
    // int i, j = 0, c, r;
    // int caracter;
    // t_producto producto;
    // t_producto *arreglo = malloc(sizeof(struct s_producto));

    // arch = fopen(nomArch, "r");
    // caracter = fgetc(arch);

    t_producto *arreglo = NULL;
    FILE *arch = fopen("./ejemplo1.txt", "r");
    arreglo = malloc(sizeof(struct s_producto));
    t_producto prod1;
    int caracter = fgetc(arch);
    int i, j = 0, c;

    while (caracter != EOF)
    {
        i = 0;
        // char* arregloDinamico = NULL;
        prod1.art = NULL;
        prod1.art = malloc(sizeof(char));
        while (caracter != ',')
        {
            *(prod1.art + i) = caracter;
            i++;
            prod1.art = realloc(prod1.art, (i + 1) * sizeof(char));
            caracter = fgetc(arch);
        }
        *(prod1.art + i) = '\0';

        // strcpy(prod1.nombre,arregloDinamico);

        c = fscanf(arch, "%d,%f,%ld\n", &prod1.cant, &prod1.precio, &prod1.codigo);
        *(arreglo + j) = prod1;
        j++;
        
        caracter = fgetc(arch);

        // txtArch = realloc(txtArch, i * sizeof(char));
        // txtArch[i - 1] = c;
    }
    // txtArch[i - 1] = '\0';

    fclose(arch);

    // printf("%s", arreglo[j].art);
    // printf("ARTICULO    CANTIDAD    PRECIO  CODIGO\n");

    for (int j = 0; j < 4; j++)
    {
        printf("%s,%d,%.1f,%ld\n", arreglo[j].art, arreglo[j].cant, arreglo[j].precio, arreglo[j].codigo);
    }
}