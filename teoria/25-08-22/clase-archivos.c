#include <stdio.h>
#include <string.h>

int main(void)
{
    int c = 0;
    int res = 0;

    FILE *arch;
    arch = fopen("/Users/tomasprodan/Documents/progra-estructurada/teoria/25-08-22/arch.txt", "r");

    if (arch != NULL)
    {
        c = fgetc(arch);

        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(arch);
        }

        printf("EOF = %d\n", c);
        printf("EOF = %d\n", EOF);
        fclose(arch);
    }

    else
    {
        res = -1;
    }

    return res;
}
