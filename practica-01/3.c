#include <stdio.h>
#define LARGO 100

void leer(char arr[LARGO]);
void reemplazar(char arr[LARGO]);

int main(void)
{
    char arr[LARGO] = {'\0'};

    printf("Ingrese texto: ");
    leer(arr);
    printf("%s\n", arr);

    return 0;
}


void leer(char arr[LARGO])
{
    int i = 0;
    
    for (i = 0; i < LARGO; i++)
    {
        arr[i] = getchar();
        fflush(stdin);
    }
}
