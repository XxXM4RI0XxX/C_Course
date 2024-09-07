#include <stdio.h>

#define m 10

int pop(int[]);
void push(int[], int);
int i = -1;
/*
    Arreglo de tamaño fijo que cuenta con 'x' tipo de dato
    Cuenta con dos operaciones:
     push -> meter elementos
     pop -> sacar elementos
    int arr[4];
    []
    []
    []
    []
    push(3);
    []
    []
    []
    [3]
    push(1);
    []
    []
    [1]
    [3]
    push(3);
    []
    [3]
    [1]
    [3]
    push(5);
    [5]
    [3]
    [1]
    [3]
    push(2);
     ! - Overflow (Fuera de tamaño de memoria)
    x = pop();
    []
    [3]
    [1]
    [3]
     x es igual al valor sacado  (En este caso 5)   
    Al hacer pop(); cuando la lista esta vacia
     ! - UnderFlow (Fuera de tamaño de memoria)
*/
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