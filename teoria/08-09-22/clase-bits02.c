#include <stdio.h>
#include <stdlib.h>
// Ejercicio repaso bit
// ejericio 2.11

void decode(unsigned int val, char arrC[5])
{
    unsigned int mask = 255;
    arrC[0] = (val & (mask << 24)) >> 24; // h -> [h.o.l.a & 1._._._ ]-> h._._._ >>24 => h
    arrC[1] = (val & (mask << 16)) >> 16; // o -> [h.o.l.a & _.1._._ ]-> _.o._._ >>16 => o
    arrC[2] = (val & (mask << 8)) >> 8;   // l -> [h.o.l.a & _._.1._ ]-> _._.l._ >>8 => l
    arrC[3] = val & (mask);               // a -> [h.o.l.a & _._._.1 -> _._._.a >>0 => l
    arrC[4] = '\0';
}

int code(char w, char x, char y, char z)
{
    int val = 0; //    _._._._

    val = w; // h ->  _._._.h            => _._._.h

    val = val << 8; // izq 8 lugares -> _._.h._
    val = val | x;  // o ->  _._.h._ | _._._.o  => _._.h.o

    val = val << 8; // izq 8 lugares -> _.h.o._
    val = val | y;  // l ->  _.h.o._ | _._._.l  => _.h.o.l

    val = val << 8; // izq 8 lugares -> h.o.l._
    val = val | z;  // a ->  h.o.l._ | _._._.a  => h.o.l.a

    return val;
}

int main()
{
    char w, x, y, z;
    char arrC[5];
    unsigned int val;
    w = 'h';
    x = 'o';
    y = 'l';
    z = 'a';

    val = code(w, x, y, z);
    printf("Valor entero que contiene las letras: %d\n", val);

    decode(val, arrC);
    printf("El entero contiene la palabra: %s\n", arrC);

    return 0;
}