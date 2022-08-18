/**
01C-operadores
*/
#include <stdio.h>
#include <stdlib.h>
/**

    ENTRADA SALIDA  -> http://lsi.vc.ehu.es/asignaturas/FdIc/labs/a1/htm/stdio.html
    OPERADORES      -> http://lsi.vc.ehu.es/asignaturas/FdIc/labs/a1/htm/oper.html
    ASCII           -> http://lsi.vc.ehu.es/asignaturas/FdIc/labs/a1/htm/asciis.html

*/

int main()
{
    int inc;             /** para usar como incremento*/
    int a, b;            /**Lo usaremos para probar operaciones logicas*/
    int num1, num2, res; /** usamos res "por resultado"*/
    double num3 = 9.8, num4 = 7.3, res2;
    num1 = 20;
    num2 = 10;

    /** - - - -  - - - - - - - - - - - - - - -  - - - - -  - - - - - - */
    printf("OPERADORES Aritmeticos - \n");
    res = num1 + num2;
    printf("(+)SUMA     -> %d + %d = %d\n", num1, num2, res);
    res = num1 - num2;
    printf("(-)RESTA    -> %d - %d = %d\n", num1, num2, res);
    res = num1 * num2;
    printf("(*)PRODUCTO -> %d * %d = %d\n", num1, num2, res);
    res2 = num3 * num2;
    printf("(*)PRODUCTO -> %lf * %d = %lf\n", num3, num2, res2);
    num2 = 9;
    res = num1 / num2;
    printf("(/)DIVISION -> %d / %d = %d\n", num1, num2, res);
    // printf("\tSi los numeros son enteros, el resultado de\n\tla operacion sera en enteros");
    // printf("\tSi uno de numeros es float o double, el resultado\n\tde la operacion sera en float o double\n");
    res2 = num3 / num4;
    printf("(/)DIVISION -> %lf / %lf = %lf\n", num3, num4, res2);
    res = num1 % num2;
    printf("(%%)RESTO    -> %d  %% %d = %d\n", num1, num2, res); /** OJO ! el operador es % "se coloca %% para que imprmia uno solo (pr ser caracter especial"*/

    /** - - - -  - - - - - - - - - - - - - - -  - - - - -  - - - - - - */
    printf("\nOPERADORES LOGICOS - \n\t(0):Falso (1):Verdadero \n\t[Todo lo distinto a (0) es Verdadero]\n");

    printf("\nOPERADORES LOGICOS DE COMPARACION -\n");

    res = num1 > num2;
    printf("(>)  MAYOR        -> %d > %d  -> %d\n", num1, num2, res);
    res = num1 >= num2;
    printf("(>=) MAYOR IGUAL  -> %d >= %d -> %d\n", num1, num2, res);
    res = num1 < num2;
    printf("(<)  MENOR        -> %d < %d  -> %d\n", num1, num2, res);
    res = num1 <= num2;
    printf("(<=) MENOR IGUAL  -> %d <= %d -> %d\n", num1, num2, res);
    res = num1 == num2;
    printf("(==) IGUAL        -> %d == %d -> %d\n", num1, num2, res);
    res = num1 != num2;
    printf("(!=) DISTINTO     -> %d != %d -> %d\n", num1, num2, res);

    /** - - - -  - - - - - - - - - - - - - - -  - - - - -  - - - - - - */
    printf("\nOPERADORES LOGICOS <AND (&&)> <OR(||)> <NOT (!)> -\n");

    printf("%-5s %-5s %-10s %-10s %4s %4s\n", "a", "b", "a && b", "a || b", "!a", "!b");
    printf("...  ...  ..........  ........    .....  .....\n");
    a = 1;
    b = 1;
    printf("%-5d %-7d %-10d %-8d %4d %4d\n", a, b, a && b, a || b, !a, !b);
    a = 1;
    b = 0;
    printf("%-5d %-7d %-10d %-8d %4d %4d\n", a, b, a && b, a || b, !a, !b);
    a = 0;
    b = 1;
    printf("%-5d %-7d %-10d %-8d %4d %4d\n", a, b, a && b, a || b, !a, !b);
    a = 0;
    b = 0;
    printf("%-5d %-7d %-10d %-8d %4d %4d\n", a, b, a && b, a || b, !a, !b);

    /** - - - -  - - - - - - - - - - - - - - -  - - - - -  - - - - - - */
    printf("\nASIGNACIONES, INCREMENTOS, DECREMENTOs\n");
    inc = 5;
    a = 10;
    printf("(=)   ASIGNACION  -> a = %d;\n", a);
    a += inc;
    printf("(+=)  INCREMENTO  -> a += %d; // a toma el valor %d\n", inc, a);
    a -= inc;
    printf("(-=)  DECREMENTO  -> a -= %d; // a toma el valor %d\n", inc, a);

    a++; // equivalente a=a+1;
    printf("(++)  INCREMENTO de a uno -> a++ // a toma el valor %d\n", a);
    a--;
    printf("(--)  DECREMENTO de a uno -> a-- // a toma el valor %d\n", a);

    /** - - - -  - - - - - - - - - - - - - - -  - - - - -  - - - - - - */

    printf("\nCONVERSION (CASTING) -\n");

    num3 = 3.1418;
    printf("Si num3 es %lf;\n", num3);
    printf("Si (int)num3 es %d;\n", (int)num3);

    num1 = 20;
    printf("Si num1 es %d;\n", num1);
    printf("Si (double)num1 es %lf;\n", (double)num1);

    return 0;
    
}