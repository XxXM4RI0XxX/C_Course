#include <stdio.h>
#include <stdlib.h>

#define M 4

int ind, end, arr[M];

void meter(int);
int sacar();
void recorrer();
void ver();

void main(){
printf("\t>>>>>>>>>>>>>> COLA FIJA <<<<<<<<<<<<<<<\n\n");
int opt;

ind = end = 0;

do{

    printf("\nMENU\n1) Meter elemento \n2) Sacar elemento\n3) Ver elementos\n0) Salir\n>");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        printf("Elemento a agregar: ");
        int elem;

        do{
        scanf("%d", &elem);
        if(elem < 1) printf(">>> Valor invalido...\n> ");
        }while(elem < 1);

        meter(elem);
        break;
    case 2:
        int num = sacar();

        if(num < 0) printf(">>> Cola vacia...\n");
        else printf("Elemento sacado: %d\n", num);

        break;
    case 3:
        ver();
        break;
    default: 
    {
    printf("Bai :>");
    opt=0;
    }
        break;
    }

} while (opt != 0);

}

void meter(int x)
{
    if(end < M)
    {
        while(ind > 0) recorrer();
        arr[end++] = x;
    }
    else
    {
        if(ind == 0)
        printf(">>> Cola llena...\n");
        else
        {
            while(ind > 0) recorrer();
            arr[end++] = x;
        }
    }
}

int sacar()
{
    if(end > 0)
    {
        printf("1) FIFO\n2) LIFO\n> ");
        int opt;
        scanf("%d", &opt);
        switch(opt){
            case 1:
            int num = arr[ind];

            arr[ind++] = 0;

            while(ind > 0) recorrer();

             return num;
            break;
            case 2:

            break;
        }
    }
    else return -1;
}

void recorrer()
{

        for(int i = ind--; i < M; i++)
        {
            arr[i-1] = arr[i];
        }
        arr[M-1] = 0;
        end--;

}

void ver()
{
    for(int i = 0; i < M; i++)
        printf("[%d] ",arr[i]);

    printf("\n");
}