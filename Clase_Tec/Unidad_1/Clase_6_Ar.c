#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct nodo
{
    char *info;
    struct nodo *sig;
} nodo;

nodo *raiz = NULL;

int menu()
{
    int x;
    printf("\n1. Agregar palabra\n2. Acomodar palabras\n3. Mostrar palabras\n0. Salir\n");
    scanf("%d", &x);

    return x;

}

void agregarNum()
{
        nodo *new;
        char cad [10];
        new = malloc(sizeof(nodo));
        printf("\nQue cadena desea ingresar?\n>");
        scanf("%s",cad);
        
        new -> info = strdup(cad);
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
            if(strcmp(aux->info,aux->sig->info) == 1)
            {
                char *temp = strdup(aux->info);
                aux->info = strdup(aux->sig->info);
                aux->sig->info = strdup(temp);
                free(temp);
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
            printf("[%s]\n", elemento -> info);
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
        printf("Cadena ob: %d\n",num);
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