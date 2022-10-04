#include <stdio.h>
#include <stdlib.h>

void cargarStrDin(char **miStr);
char *cargarStrDin2(char *miStr);

int main(void)
{
    char *miStr = NULL;

    printf("Ingrese frase: ");
    cargarStrDin(&miStr);

    if (miStr != NULL)
    {
        printf("%s\n", miStr);
        free(miStr);
    }

    return 0;
}

void cargarStrDin(char **miStr)
{
    *miStr = (char *)malloc(sizeof(char));
    int i = 0;
    int c;

    if (*miStr != NULL)
    {
        c = getchar();

        while (c != '\n')
        {
            *((*miStr) + i) = c;
            i++;
            *miStr = (char *)realloc((*miStr), sizeof(char) * (i + 1));
            c = getchar();
        }
        *((*miStr) + i) = '\0';
    }
}
