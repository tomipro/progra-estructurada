/** 02 Bit */

#include <stdio.h>
#include <stdlib.h>

#define MASK 123

void convert(char *var, char *ope, int num);
void convertU(char *var, char *ope, unsigned int num);

int main()
{
    // int i=0;

    int a = 5;      /** binario: 0000000000000101  es el valor 5 en decimal*/
    int b = a << 3; /** binario: 0000000000101000, o 40 en decimal */
    int c = b >> 3; /** binario: 0000000000000101, se retrocede al valor 5 original */

    int x = -5;
    int y = x << 3; /** binario: 1111111111110000 */
    int z = y >> 3; /** binario: 1111111111111110 */

    unsigned int ur = 5;
    unsigned int us = ur << 3;
    unsigned int ut = us >> 3;

    unsigned int ux = -5;
    unsigned int uy = ux << 3; /** binario: 1111111111110000 */
    unsigned int uz = uy >> 3; /** binario: 0001111111111110 */

    printf("\n\n\n");
    printf("En una variable signed cuando su valor es positivo \nshift por izquierda agrega 0 \nshift por derecha agrega 0 ");
    printf("\n");

    // unsigned int mask;
    printf("\n\n%s%7s%13s%20s ", "VAR", "OPER", "DECIMAL", "BINARIO");
    convert("a", "", a);
    convert("b", "a << 3", b);
    convert("c", "b >> 3", c);

    printf("\n\n\n");
    printf("En una variable signed cuando su valor es negativo\nshift por izquierda agrega 1 \nshift por derecha agrega 0 ");
    printf("\n");

    printf("\n\n%s%7s%13s%20s ", "VAR", "OPER", "DECIMAL", "BINARIO");
    convert("x", "", x);
    convert("y", "x << 3", y);
    convert("z", "y>>3", z);

    printf("\n\n\n");
    printf("En una variable UNsigned cuando su valor es positivo \nshift por izquierda agrega 0 \nshift por derecha agrega 0 ");
    printf("\n");

    printf("\n\n%s%7s%13s%20s ", "VAR", "OPER", "DECIMAL", "BINARIO");
    convertU("ur", "", ur);
    convertU("us", "ur<<3", us);
    convertU("ut", "us>>3", ut);

    printf("\n\n\n");
    printf("En una variable UNsigned cuando su valor es negativo \nshift por izquierda agrega 0 \nshift por derecha agrega 0 ");
    printf("\n");

    printf("\n\n%s%7s%13s%20s ", "VAR", "OPER", "DECIMAL", "BINARIO");
    convertU("ux", "", ux);
    convertU("uy", "ux<<3", uy);
    convertU("uz", "uy>>3", uz);

    printf("\n\n\n");
    printf("En una variable UNsigned y su negado ");
    unsigned int uzz = 0;
    printf("\n\n%s%7s%13s%20s ", "VAR", "OPER", "DECIMAL", "BINARIO");
    convertU("uzz", "", uzz);
    convertU("uzz", "~uzz", ~uzz);

    printf("\n\n\n");

    printf("Libro: Kernighan, B. W., & Ritchie, D. M. (1991). \nEl lenguaje de programación C. Pearson Educación -  Pag 45.\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Right shifting an unsigned quantity always fits the vacated bits with zero.\n");
    printf("Right shifting a signed quantity will fill with bit signs[arithmetic shift]\n");
    printf("on some machines and with 0-bits (``logical shift'') on others.\n");

    return 0;
}

void convert(char *var, char *ope, int num)
{
    /** convierte a binario e imprime (bit  bit) un numero decimal "signed"  */

    unsigned int mask = 1 << 31; /** coloca el uno en el bit más significativo (a la izquierda)*/
    int i;
    printf("\n%2s= %6s =%12d : ", var, ope, num);
    for (i = 0; i < 32; i++)
    {
        printf("%d", (num & (mask >> i)) != 0);
        // printf("%d",(5&(2147483648))!=0);
        // printf("%d",( 0 )!=0);
        // printf("%d", 0 );
    }
}

void convertU(char *var, char *ope, unsigned int num)
{
    /** convierte a binario e imprime (bit  bit) un numero decimal "unsigned"  */

    unsigned int mask = 1 << 31; /** coloca el uno en el bit más significativo (a la izquierda)*/
    int i;

    printf("\n%2s= %6s =%12u : ", var, ope, num);
    for (i = 0; i < 32; i++)
    {
        printf("%d", (num & (mask >> i)) != 0);
    }
}