#include <stdio.h>
#include <stdlib.h>

char *leerArch(const char *nomArch);
char *subcadena(char *p, int i, int n);

int main(void)
{
    char *str = NULL;
    char *subStr = NULL;
    int i = 8, n = 5;

    str = leerArch("./frase.txt");
    subStr = subcadena(str, i, n);

    printf("Para i = %d y n = %d, se encontro el substring: ", i, n);
    printf("%s\n", subStr);

    return 0;
}

char *leerArch(const char *nomArch)
{
    char *strArch = malloc(sizeof(char));
    int i = 0, c;

    FILE *arch = fopen(nomArch, "r");

    while (!feof(arch))
    {
        i++;
        c = fgetc(arch);
        strArch = realloc(strArch, i * sizeof(char));
        strArch[i - 1] = c;
    }
    strArch[i - 1] = '\0';

    fclose(arch);

    return strArch;
}

char *subcadena(char *p, int i, int n)
{
    int j = 0;
    char *subStr = malloc(sizeof(char));

    p += i;

    if (n > 0)
    {
        while (j < n)
        {
            *(subStr + j) = *p;
            p++;
            j++;
        }
    }

    else
    {
        while (j > n)
        {
            *(subStr - j) = *p;
            p--;
            j--;
        }
    }

    return subStr;
}