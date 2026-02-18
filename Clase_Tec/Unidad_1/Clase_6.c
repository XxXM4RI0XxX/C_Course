#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct elem
{
    int info;
    struct elem *next;
} elem;


elem *raiz = NULL;

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

        elem *new;
        
        new = malloc(sizeof(elem));
        new -> info = x;
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

int pop()
{

    if(raiz == NULL) 
    {
        return -1;
    }
    else if(raiz -> next == NULL)
    {
        int num = raiz -> info;
        raiz = NULL;
        return num;
    }
    else
    {
        int num;
        elem *aux = raiz;
        while(aux->next->next != NULL) {
        aux = aux -> next;
        }
        num = aux -> next -> info;
        aux -> next = NULL;
        
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
        elem *elemento = raiz;
        while (elemento != NULL)
        {
            printf("[%d]", elemento -> info);
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