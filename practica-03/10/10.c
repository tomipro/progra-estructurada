#include <stdio.h>
#include <stdlib.h>

struct s_texto
{
    char *txt;
    int longitud;
};
typedef struct s_texto t_texto;

t_texto cargarTexto();
void escribirArchText(const char *nomArch, t_texto texto);

int main(void)
{
    escribirArchText("frases_con_longitud.csv", cargarTexto());

    return 0;
}

t_texto cargarTexto()
{
    t_texto texto;
    texto.longitud = 0;
    int aux;
    texto.txt = malloc(sizeof(char));

    while (aux != '\n')
    {
        texto.longitud++;
        aux = getchar();
        texto.txt = realloc(texto.txt, (texto.longitud * sizeof(char)));
        texto.txt[texto.longitud - 1] = aux;
    }

    texto.txt[texto.longitud - 1] = '\0';

    return texto;
}

void escribirArchText(const char *nomArch, t_texto texto)
{
    FILE *arch;

    arch = fopen(nomArch, "w");

    fprintf(arch, "%d, %s", texto.longitud - 1, texto.txt);

    fclose(arch);
}