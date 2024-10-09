#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int *pe;
    int tam;
    int f;
    printf("Elem vector:");
    scanf("%i",&tam);
    pe=malloc(tam*sizeof(int));//malloc: reserva memoria para la variable especificada
    for (f = 0; f < tam; f++)
    {
        printf("Ingrese el elemento:");
        scanf("%i", &pe[f]);
    }
    printf("Contenido del vector dinamico:");
    for(f=0;f<tam;f++)
    {
        printf("%i ", pe[f]);
    }
    free(pe);
    getch();

    return 0;
}