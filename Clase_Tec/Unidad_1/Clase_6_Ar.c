#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct elem
{
    char *info;
    struct elem *next;
} elem;

elem *raiz = NULL;

int menu()
{
    int x;
    printf("\n1. Agregar palabra\n2. Acomodar palabras\n3. Mostrar palabras\n0. Salir\n");
    scanf("%d", &x);

    return x;

}

void agregarNum()
{
        elem *new;
        char cad [10];
        new = malloc(sizeof(elem));
        printf("\nQue cadena desea ingresar?\n>");
        scanf("%s",cad);
        
        new -> info = strdup(cad);
        new -> next = NULL;

        if(raiz == NULL)  
            raiz = new;
        else
        {
            elem *aux = raiz;
            while (aux -> next != NULL)
                aux = aux -> next;
            aux -> next = new;
        }
}

char acomodarNum()
{
    if(raiz == NULL) printf(">>> Nada para acomodar");
    else
    {
        elem *aux = raiz;

        while (aux -> next != NULL){
            if(strcmp(aux->info,aux->next->info) == 1)
            {
                char *temp = strdup(aux->info);
                aux->info = strdup(aux->next->info);
                aux->next->info = strdup(temp);
                free(temp);
                aux = raiz;
            }
            else
            {
                aux = aux -> next;
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
        elem *elemento = raiz;
        while (elemento != NULL)
        {
            printf("[%s]\n", elemento -> info);
            elemento = elemento -> next;
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