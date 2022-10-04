#include <stdio.h>
#include <stdlib.h>

char *cargarStrDin1();
void cargarStrDin2(char **pCadena);
void escribirArch(const char *nomArch, char *cadena);
void imprimirArch(const char *nomArch);

int main(void)
{
    char *str = NULL;

    // str = cargarStrDin1();
    cargarStrDin2(&str);

    escribirArch("./frase.txt", str);
    imprimirArch("./frase.txt");

    return 0;
}

char *cargarStrDin1()
{
    int i = 0;
    int c;
    char *p = malloc(sizeof(char));

    while (c != '\n')
    {
        i++;
        c = getchar();
        p = realloc(p, i * sizeof(char));
        p[i - 1] = c;
    }

    return p;
}

void cargarStrDin2(char **pCadena)
{
    *pCadena = (char *)malloc(sizeof(char));
    int i = 0;
    int c;

    if (*pCadena != NULL)
    {
        c = getchar();

        while (c != '\n')
        {
            *((*pCadena) + i) = c;
            i++;
            *pCadena = (char *)realloc((*pCadena), sizeof(char) * (i + 1));
            c = getchar();
        }
        *((*pCadena) + i) = '\0';
    }
}

void escribirArch(const char *nomArch, char *cadena)
{
    FILE *arch;

    arch = fopen(nomArch, "w");

    fprintf(arch, "%s", cadena);

    fclose(arch);
}

void imprimirArch(const char *nomArch)
{
    FILE *arch;
    int r;
    char *aux;

    arch = fopen(nomArch, "r");
    fscanf(arch, "%c", aux);
    fclose(arch);

    printf("%s\n", aux);
}