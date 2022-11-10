#include <stdio.h>
#include <stdlib.h>
/**
Para visualizar archivos Binarios
https://hexed.it/
*/
int main()
{
    FILE *arch = fopen("arch.txt", "r");
    int i, r, a, b;
    char c;

    // -------------------------------------
    printf("\n-- Lectura como TEXTO con feof() --");
    printf("\n");
    r = fscanf(arch, "%d,%d\n", &a, &b);
    printf("%d: %d,%d\n", r, a, b);
    while (!feof(arch))
    {
        r = fscanf(arch, "%d,%d\n", &a, &b);
        printf("%d: %d,%d\n", r, a, b);
        // printf("%d,%d\n",a,b);
    }

    // -------------------------------------
    rewind(arch);
    printf("\n-- Lectura como TEXTO evalua retorno EOF --");
    printf("----\n");
    r = fscanf(arch, "%d,%d\n", &a, &b);
    while (r != EOF)
    {
        printf("%d: %d,%d\n", r, a, b);
        // printf("%d,%d\n",a,b);
        r = fscanf(arch, "%d,%d\n", &a, &b);
    }

    // ---------BINARIA----------------------------
    rewind(arch);
    printf("\n-- Lectura como BINARIO con feof()--");
    printf("\n");
    r = fread(&c, 1, 1, arch); // c=fgetc(arch);
    printf("%c", c);
    while (!feof(arch))
    {
        r = fread(&c, 1, 1, arch);
        printf("%c", c);
    }
    // -------------------------------------
    rewind(arch);
    printf("\n-- Lectura como TEXTO evalua retorno 0 --");
    printf("\n");
    r = fread(&c, 1, 1, arch); // sizeof(char)
    while (r != 0)
    {
        printf("%c", c);
        r = fread(&c, 1, 1, arch);
    }

    return 0;
}