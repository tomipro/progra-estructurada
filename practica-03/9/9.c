#include <stdio.h>
#include <stdlib.h>

char *subcadena(char *p, int i, int n);
char *leerArch(const char *nomArch);

int main(void)
{
    char *str = NULL;
    char *subStr = NULL;
    int i = 8, n = 5;

    str = leerArch("./frase.txt");
    subStr = subcadena(str, i, n);

    printf("Para i = %d y n = %d, se encontro el substring: ", i, n);
    printf("%s", subStr);

    return 0;
}

char *subcadena(char *p, int i, int n)
{
    
}