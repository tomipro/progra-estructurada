#include <stdio.h>

struct s_carta
{
    int numero, valor;
    char palo;
};
typedef struct s_carta t_carta;

t_carta *ordenarCartas(t_carta *c1, t_carta *c2, t_carta *c3);

int main(void)
{
    t_carta c1 = {7, 11, 'B'};
    t_carta c2 = {3, 5, 'C'};
    t_carta c3 = {1, 1, 'E'};

    return 0;
}

t_carta *ordenarCartas(t_carta *c1, t_carta *c2, t_carta *c3)
{
    t_carta *aux;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if ((c1->valor > c2->valor && c2->valor > c3->valor) || (c1->valor > c2->valor && c2->valor < c3->valor) || (c1->valor < c2->valor && c2->valor > c3->valor))
            {
                *aux = c1[i];
                c1[i] = c1[j];

            }
        }
    }
}

/*
t_carta:

int numero: es el numero de la carta que me toca, entre 1 y 12

int valor: es valor designado que se le da a una carta, de 1 a 14, 1 vale mas (ancho de espada)
           y 14 es el que menos vale (4 de cualquier palo)

char palo: un caracter que se le asigna una carta segun su palo
           'O' = Oro, 'E' = Espada, 'B' = Bastos, 'C' = Copa


Orden de cartas segun su valor:

{1, 1, 'E'}

{1, 2, 'B'}

{7, 3, 'E'}

{7, 4, 'O'}

{3, 5, 'O'}
{3, 5, 'C'}
{3, 5, 'E'}
{3, 5, 'B'}

{2, 6, 'O'}
{2, 6, 'C'}
{2, 6, 'E'}
{2, 6, 'B'}

{1, 7, 'O'}
{1, 7, 'C'}

{12, 8, 'O'}
{12, 8, 'C'}
{12, 8, 'E'}
{12, 8, 'B'}

{11, 9, 'O'}
{11, 9, 'C'}
{11, 9, 'E'}
{11, 9, 'B'}

{10, 10, 'O'}
{10, 10, 'C'}
{10, 10, 'E'}
{10, 10, 'B'}

{7, 11, 'C'}
{7, 11, 'B'}

{6, 12, 'O'}
{6, 12, 'C'}
{6, 12, 'E'}
{6, 12, 'B'}

{5, 13, 'O'}
{5, 13, 'C'}
{5, 13, 'E'}
{5, 13, 'B'}

{4, 14, 'O'}
{4, 14, 'C'}
{4, 14, 'E'}
{4, 14, 'B'}


c1 c2 c3

c1 > c2 && c2 > c3
c1 > c2 && c3 > c2

c2 > c1 && c1 > c3
c2 > c1 && c3 > c1

c3 > c1 && c1 > c2
c3 > c1 && c2 > c2

c3 > c2 && c2 > c1
c3 > c2 && c1 > c2




*/
