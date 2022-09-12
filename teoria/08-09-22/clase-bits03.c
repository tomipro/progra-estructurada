#include <stdio.h>
#include <math.h>
//                 |    |
// 11034 -> 0010101 1000 11010    21/08/26

// aa/mm/dd
// dd -> 00101
// mm -> 0000
// aa ->
// dd =   // 31-> cinco   bit
// mm =   // 12-> cuatro bit
// aa =   // 99-> siete bit

void imprimeBinC(unsigned char c);
void imprimeBinI(unsigned int n);
int mes(unsigned int n);

int main()
{
    unsigned char c;
    unsigned int n;
    c = 129;
    imprimeBinC(c);
    printf("\n");
    n = 46934;
    imprimeBinI(n);
    printf("\n-------------------------------------\n");
    unsigned int fechaNum = 11034;
    printf("%d\n", mes(fechaNum));

    return 0;
}

void imprimeBinC(unsigned char c)
{
    unsigned char mask = 1;
    int i = 7;
    printf("%d: ", c);
    while (i >= 0)
    {

        if ((c & (mask << i)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        i--;
    }
}

void imprimeBinI(unsigned int n)
{
    unsigned char mask = 1;
    int i = 31;
    printf("%d: ", n);
    while (i >= 0)
    {

        if ((n & (mask << i)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        i--;
    }
}

// 11034 -> 0010101 1000 11010    // ->21/08/26
//   		0000000 0000 01111    // 15
//          0000000 1111 00000    // 15<<5
//          0000000 1000 00000

int mes(unsigned int n)
{
    int res;
    unsigned mask = pow(2, 4) - 1; // 15
    res = (n & (mask << 5)) >> 5;
    return res;
}