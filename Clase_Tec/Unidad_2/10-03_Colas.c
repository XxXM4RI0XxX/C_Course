#include <stdio.h>
#include <stdlib.h>

int M=5, ind, end;
int arre[5] = {0};

void meter(int);
void recorrer();
void ver();
void sacar();

int main(){

int opt;

do{

    printf("\nMENU\n1) Meter elemento \n2) Sacar elemento\n3) Ver elementos\n0) Salir\n>");

    scanf("%d", &opt);

    ind = end = 0;

    switch (opt)
    {
    case 1:
        printf("Elemento a meter:\n> ");
        int elem;
        scanf("%d", &elem);
        meter(elem);
        break;
    case 2:
        recorrer();
        break;
    case 3:
        ver();
        break;
    default: printf("Nope...");
    }

} while (opt != 0);

    return 0;
}

void meter(int elem)
{
    
    if(end<M)
    {
        arre[end] = elem;
        end++;
    }
    else
    {
        if(ind == 0)
        {
            printf("Cola llena xd");
        }
        else
        {

        }
    }
}

void recorrer()
{
    int aux;
    if(ind > 0 && ind != end)
    {
        aux = arre[ind++];
    }
    else
    {
        if (ind == end && ind != 0)
            ind = end = 0;
        
        if (ind == 0) printf("Cola vacia xd");
    }
}

void ver()
{

    for(int i = 0; i < M; i++)
    {
        printf("[%d] ",arre[i]);
    }

}

void sacar()
{

    

}