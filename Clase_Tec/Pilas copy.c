#include <stdio.h>

#define m 10

int pop(int[]);
void push(int[], int);
int i = -1;

typedef struct
{
    int info;
    nodo *sig;
}nodo; //Estructura con un entero 'info' y un nodo apuntador 'sig'

nodo *raiz = NULL;//Nodo raiz

void pushDin(int x)
{
    //Zelda == Nodo;

    /*
    PRIMER NODO: Es el padre de todos los nodos, el nodo raiz, siempre se inicializa en NULO.
    */

   nodo *nuevo, *aux; //Dos nodos apuntadores
   nuevo = malloc(sizeof(nodo)); // Se le asgina un espacio en la memoria al apuntador 'nuevo' del tamaño de 'nodo'
   nuevo -> info = x; //El valor 'info' de la direccion hacia la que apunta 'nuevo' es igual a x
   if (raiz == NULL) //Si el nodo raiz esta vacio, significa que no hay ningun valor guardado, por que el nuevo valor se le asginara al nodo raiz
   {
    raiz = nuevo; //Al nodo 'raiz' se le asginan los valores del nodo 'nuevo'
    nuevo -> sig = NULL; //Se declara que el apuntador 'sig' de 'nuevo' no apunte a nada, para evitar errores.
   } // Si el nodo 'raiz' ya cuenta con un valor...
   while(aux->sig != NULL) aux = aux -> sig; // Mientras el apuntador 'sig' del nodo 'aux' apunte hacia una direccion,
   // el nodo 'aux' tendra los valores de ese nodo hacia el que apunta 'sig', pero... sig no apunta a nada wtf
   aux -> sig = nuevo;
    nuevo -> sig = NULL;
    

}

void main()
{

    int pila[m] = {0,0,0,0,0,0,0,0,0,0};
    int op, num;
    do{
    printf("Desea:\n1) Push\n2) Pop\n> ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        if(i<m)
        {
        printf("Valor a meter: ");
        scanf("%d", &num);
        push(pila,num);
        }
        else printf(">>> Overflow...\n");
        break;
    case 2:
        num = pop(pila);
        if(num>=0) printf("Valor sacado: %d\n", num);
        else printf(">>> Pila vacia :v...\n");
        break;
    case -1: 
        printf("Bai :>\n");
        break;
    default:
    printf(">>>Nope\n");
        break;
    }
    }while(op!=-1);
}

int pop(int arr[])
{
    int x;
    if(i>=0)
    {
        x = arr[i];
        arr[i]=0;
        i--;

        return x;
    }
    else return -1;
}

void push(int arr[], int num)
{
    arr[++i]=num;
}