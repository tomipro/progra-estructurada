#include <stdio.h>

int main(void)
{
    char arrC[10] = "abcdef";
    int arrI[10] = {21, 244, 66, 7, 0};

    printf("%p\n", arrC);
    printf("%s\n", arrC);

    printf("[0] -> %d\n", &arrC + 0);
    printf("[1] -> %d\n", &arrC + 1);
    printf("[2] -> %d\n", &arrC + 2);

    printf("\narrI -> %d\n", arrI);

    printf("[0] -> %d\n", &arrI + 0);
    printf("[1] -> %d\n", &arrI + 1);
    printf("[2] -> %d\n", *(arrI + 2));

    char c = 'A';
    char *pc = &c;
    char **ppc = &pc;

    return 0;
}