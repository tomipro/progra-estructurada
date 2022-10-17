#include <stdio.h>
#include <stdlib.h>

unsigned int contar_vocales(char *texto);
int esVocal(char c);

int main(void)
{
    char *texto = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut porttitor ultricies pulvinar. Nulla facilisi. Pellentesque placerat sed lorem quis molestie. Maecenas ut fringilla ante, vitae commodo leo. Aenean non scelerisque mauris, at aliquam elit. Suspendisse diam leo, euismod eu sagittis ut, finibus at magna. Praesent sit amet dapibus mi. Donec.";

    printf("\nTexto:\n%s\n", texto);

    printf("\nCantidad de vocales en el texto: %d\n", contar_vocales(texto));

    return 0;
}

int esVocal(char c)
{
    return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'));
}

unsigned int contar_vocales(char *texto)
{
    int cant = 0;

    if (*texto && *texto != '\0')
    {
        if (esVocal(*texto))
        {
            cant = 1 + contar_vocales(texto + 1);
        }

        else
        {
            cant = contar_vocales(texto + 1);
        }
    }

    return cant;
}