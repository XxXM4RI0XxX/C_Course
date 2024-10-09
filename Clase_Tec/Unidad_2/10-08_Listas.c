#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int value;
    struct elem *sig;
}elem;

elem *raiz = NULL;

void meter_ordenar(elem *);
int sacar();
void ver();

void main()
{
    printf("\t>>>>>>>>>>>>>> LISTAS SIMPLEMENTE LIGADAS <<<<<<<<<<<<<<<\n\n");
    int opt;
    
    
    do{

    printf("\nMENU\n1) Meter elemento \n2) Sacar elemento\n3) Ver elementos\n0) Salir\n> ");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        printf("Elemento a agregar: ");
        elem *nuevo;
        int valor;

        nuevo = malloc(sizeof(elem));
        nuevo->sig = NULL;

        do{
        scanf("%d", &valor);
        if(valor < 1) printf(">>> Valor invalido...\n> ");
        }while(valor < 1);

        nuevo->value = valor;

        meter_ordenar(nuevo);
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

void meter_ordenar(elem *elemento)
{
    if(raiz == NULL) raiz = elemento;
    else
    {
        if(raiz->value > elemento->value)
        {
            elem *aux = raiz;
            raiz = elemento;
            raiz->sig = aux;
        }
        else
        {
            elem *aux = raiz, *aux2;
            while(aux->sig != NULL)
            {
                if(elemento->value < aux->sig->value)
                {
                    aux2 = aux->sig;
                    aux->sig = elemento;
                    aux->sig->sig = aux2;
                }
                aux = aux->sig;
            }
            if(elemento->value > aux->value) aux->sig = elemento;
        }
    }
}

int sacar()
{
    if(raiz == NULL) return -1;
    else
    {
        elem *aux = raiz;
        int val = raiz->value;
        raiz = raiz->sig;
        free(aux);
        return val;
    }
}

void ver()
{

    if(raiz == NULL) printf(">>> Cola vacia...\n");
    else
    {
    elem *aux = raiz;

    while(aux != NULL)
    {
        printf("[%d] ",aux->value);
        aux = aux->sig;
    }

    printf("\n");

    free(aux);
    }
}