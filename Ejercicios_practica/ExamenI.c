#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct nodo
{
    int *info;
    struct nodo *sig;
} nodo;

nodo *raiz = NULL;

int menu()
{
    int x;
    printf("\n1. Agregar numero\n2. Acomodar numeros\n3. Mostrar numeros\n0. Salir\n");
    scanf("%d", &x);

    return x;

}

void agregarNum()
{
        nodo *new;
        int num;
        new = malloc(sizeof(nodo));
        printf("\nQue numero desea ingresar?\n>");
        scanf("%d", &num);
        
        new -> info = num;
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

char acomodarNum()
{
    if(raiz == NULL) printf(">>> Nada para acomodar");
    else
    {
        nodo *aux = raiz;

        while (aux -> sig != NULL){
            if((aux->info > aux->sig->info))
            {
                char *temp = aux->info;
                aux->info = aux->sig->info;
                aux->sig->info = temp;
                aux = raiz;
            }
            else
            {
                aux = aux -> sig;
            }
        }
    }
}

void PilaPrint()
{
    
    if (raiz == NULL)
    {
        printf("\n>> La pila esta vacia\n");
    }
    else
    {
        nodo *elemento = raiz;
        while (elemento != NULL)
        {
            printf("[%d]\n", elemento -> info);
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
    case 2: int num = acomodarNum();
    if(num==-1) printf("\nPila vacia...");
    else 
    {
            PilaPrint();
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