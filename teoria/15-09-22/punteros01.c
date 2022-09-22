#include <stdio.h>

// int main(void)
// {
//     char car = 'A';
//     char *pc = NULL;

//     printf("%c\n", car);
//     printf("%p\n", pc);
//     printf("%c\n", *pc);

//     return 0;
// }

// int main(void)
// {
//     char car = 'A';
//     char *pCar = NULL;

//     printf("\n car   = %4c", car);
//     printf("\n car   = %4p\n\n", &car);

//     pCar = &car;

//     printf("pCar   = %4p\n", pCar);
//     printf("pCar   = %4c\n\n", *pCar);

//     return 0;
// }

int fun1(int n);
void fun2(int *n);

int main(void)
{
    int num = -1;

    // num = fun1(num);
    fun2(&num);

    printf("%d\n", num);

    return 0;
}

int fun1(int n)
{
    return n + 10;
}

void fun2(int *n)
{
    *n = *n +10; 
}