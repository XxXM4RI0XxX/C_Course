#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo
{
    int info;
    struct nodo *sig;
} nodo;


nodo *raiz = NULL;

int menu()
{
    int x;
    printf("\n1. Push\n2. Pop\n3. Mostrar\n0. Salir\n");
    scanf("%d", &x);

    return x;

}

void agregarNum()
{

        int x;
        printf("\nQue numero desea ingresar?\n>");
        scanf("%d", &x);

        nodo *new;
        
        new = malloc(sizeof(nodo));
        new -> info = x;
        new -> sig = NULL;

        if(raiz == NULL)  
            raiz = new;
        else
        {
            nodo *aux = raiz;
            while (aux -> sig != NULL)
                aux = aux -> sig;
            aux -> sig = new;
        }
}

int pop()
{

    if(raiz == NULL) 
    {
        return -1;
    }
    else if(raiz -> sig == NULL)
    {
        int num = raiz -> info;
        raiz = NULL;
        return num;
    }
    else
    {
        int num;
        nodo *aux = raiz;
        while(aux->sig->sig != NULL) {
        aux = aux -> sig;
        }
        num = aux -> sig -> info;
        aux -> sig = NULL;
        
        return num;
    }
}

void PilaPrint()
{
    
    if (raiz == NULL)
    {
        printf("\n--La pila esta vacia\n");
    }
    else
    {
        nodo *elemento = raiz;
        while (elemento != NULL)
        {
            printf("[%d]", elemento -> info);
            elemento = elemento -> sig;
        }
    }

    printf("\n");
}

int main()
{
int x;
do{
    x=menu();
    switch (x)
    {
    case 1: agregarNum();
        PilaPrint();
        break;
    case 2: int num = pop();
    if(num==-1) printf("\nPila vacia...");
    else 
    {
        printf("Num. ob: %d\n",num);
            PilaPrint(1);
    }
        break;
    case 3: PilaPrint();
        break;
    case 0: 
    printf("Sayonara..."); 
    x=0;
        break;
    default: printf("Nope...");
        break;
    }
}while(x!=0);


    return 0;
}