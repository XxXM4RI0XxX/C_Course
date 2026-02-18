#include <stdio.h>
#include <stdlib.h>

#define M 4

int arr[M] = {3,7,12,14}, end, ind;

void sacar();
void ver();

void main()
{
    end = 1;
    ind = 2;
    int ax = 0;
    ver();
    do{
    _sleep(900);
    sacar();
    ax++;
    }while(ax != 8);
}

void sacar()
{
    if(ind < M && ind != end)
    {
        arr[ind++] = 0;
    }
    else
    {
        if(ind == M)
            ind = 0;
        if(ind != end)
            arr[ind++] = 0;
        else{
            if(ind == 0 && arr[ind] != 0)
            {
            arr[ind] = 0;
            }
            else{
            ind = end = 0;
            if(ind == 0 && end == 0)
            {
                printf(">>> Cola vacia\n");
                arr[0] = 7;
                arr[1] = 10;
                arr[2] = 3;
                arr[3] = 8;
                ind = 1;
                end = 0;
            }
            }
        }
    }
    ver();

}

void ver()
{
    for(int i = 0; i < M; i++)
        printf("[%d] ",arr[i]);

    printf("\n");
}