// WIP

#include <stdio.h>
#define F 10
#define f 10
#define C 20
#define c 20
#define TERM_STR '\0'

void cargarMatText(char mat[F][C]);
void imprimirMatText(char mat[F][C]);
void ordenarMatText(char mat[F][C]);

int main(void)
{
    char mat[F][C] = {'\0'};

    cargarMatText(mat);
    imprimirMatText(mat);

    return 0;
}

void cargarMatText(char mat[F][C])
{
    int i, j;
    char aux;

    printf("Ingrese palabra: ");
    fflush(stdin);
    aux = getchar();
    
    for (i = 0; aux != '\n' && i < F; i++)
    {
        for (j = 0; mat[i][j] != '\n' && j < C; j++)
        {
            mat[i][j] = aux;
            fflush(stdin);
            aux = getchar();
        }
        mat[i][0] = '\0';
        printf("Ingrese palabra: ");
        fflush(stdin);
        aux = getchar();
    }
    mat[i][0] = '\0';
}

/*
void cargarmatriztxt(char matriz[f][c]){
    int fila,col,cont;
    char letra;
    cont=1;
    printf("Ingrese palabra %d: ",cont);
    fflush(stdin);
    letra=getchar();
    for(fila=0;fila<f && letra!='\n';fila++){
        for(col=0;col<c && letra!='\n';col++){
            matriz[fila][col]=letra;
            fflush(stdin);
            letra=getchar();
        }
        matriz[fila][col]='\0';
        cont+=1;
        printf("ingrese palabra %d: ",cont);
        fflush(stdin);
        letra=getchar();
    }
    matriz[fila][0]='\0';
}
*/


void imprimirMatText(char mat[F][C])
{
    int i, j;

    for (i = 0; mat[i][0] != TERM_STR && i < F; i++)
    {
        for (j = 0; mat[i][j] != TERM_STR && j < C; j++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}