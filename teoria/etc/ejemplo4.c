#include <stdio.h>
#include <stdlib.h>

typedef struct valor
{
    int edad;
    char *nombre;
    char *sexo;
} data;

typedef struct nodo
{
    data valor;
    struct nodo *sig;
} * tnodo;

void cargaLista(tnodo *nodo, data valor)
{
    if (*nodo == NULL)
    {
        *nodo = malloc(sizeof(struct nodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }
    else
    {
        cargaLista(&((*nodo)->sig), valor);
    }
}

void cargaArch(const char *archivo, tnodo *lista)
{
    FILE *arch;
    arch = fopen(archivo, "r");
    if (arch != NULL)
    {

        int i;
        char r = fgetc(arch);
        while (r != EOF)
        {
            data aux;
            aux.nombre = malloc(1);

            for (i = 0; r != ','; i++)
            {
                aux.nombre[i] = r;
                aux.nombre = realloc(aux.nombre, i + 2);
                r = fgetc(arch);
            }
            aux.nombre[i] = 0;
            
            fscanf(arch, "%d,", &aux.edad);

            aux.sexo = malloc(1);
            r = fgetc(arch);
            for (i = 0; r != '\n'; i++)
            {
                aux.sexo[i] = r;
                aux.sexo = realloc(aux.sexo, i + 2);
                r = fgetc(arch);
            }
            aux.sexo[i] = 0;

            cargaLista(lista, aux);
            
            r = fgetc(arch);
        }
    }
    fclose(arch);
}

void imprimir(tnodo lista)
{
    if (lista != NULL)
    {
        // rintf(".2.");
        printf("%s, %d, %s\n", lista->valor.nombre, lista->valor.edad, lista->valor.sexo);
        imprimir(lista->sig);
    }
}

int main()
{
    tnodo lista = NULL;
    
    cargaArch("./ejemplo4.txt", &lista);
    imprimir(lista);


    return 0;
}
