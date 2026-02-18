#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int value;
    struct elem *sig;
    struct elem *ant;
} elem;

elem *raiz = NULL;

void meter_ordenar(elem *);
int sacar(int);
void ver();

void main()
{
    printf("\t>>>>>>>>>>>>>> LISTAS DOBLEMENTE LIGADAS <<<<<<<<<<<<<<<\n\n");
    int opt;

    do
    {

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
            nuevo->ant = NULL;

            do
            {
                scanf("%d", &valor);
                if (valor < 1)
                    printf(">>> Valor invalido...\n> ");
            } while (valor < 1);

            nuevo->value = valor;

            meter_ordenar(nuevo);
            break;
        case 2:
            int opt;
            printf("Que valor desea sacar?\n1) Primero\n2) Ultimo\n3) Especifico\n> ");
            scanf("%d", &opt);

            int num = sacar(opt);

            if (num < 0)
                printf(">>> Cola vacia...\n");
            else if (num == 0)
                printf(">>> Valor no encontrado...");
            else
                printf("Elemento sacado: %d\n", num);

            break;
        case 3:
            ver();
            break;
        default:
        {
            printf("Bai :>");
            opt = 0;
        }
        break;
        }

    } while (opt != 0);
}

void meter_ordenar(elem *elemento)
{
    if (raiz == NULL)
        raiz = elemento;
    else
    {
        if (raiz->value > elemento->value)
        {
            elem *aux = raiz;
            raiz = elemento;
            raiz->sig = elemento;
            elemento->ant = raiz;
        }
        else
        {
            elem *aux = raiz, *aux2;

            while (aux->sig != NULL)
            {
                if (elemento->value < aux->sig->value && elemento->value > aux->ant->value)
                {
                    elemento->sig = aux->sig;
                    aux->sig = elemento;
                    elemento->ant = aux;
                    if(elemento->sig != NULL)
                    {
                        elemento->sig->ant = elemento;
                    }
                    break;
                }
                aux = aux->sig;
            }

            if (elemento->sig == NULL)
                aux->sig = elemento;
        }
    }
}

int sacar(int opt)
{
    if (raiz == NULL)
        return -1;
    else
    {
        elem *aux = raiz;
        int val;

        switch (opt)
        {
        case 1:
            val = raiz->value;
            raiz = raiz->sig;
            free(aux);
            return val;
        case 2:
            while (aux->sig != NULL)
                aux = aux->sig;
            val = aux->value;
            aux = NULL;
            return val;
        case 3:
            int num;
            printf("Valor: ");
            scanf("%d", &num);
            elem *auxA;

            if (raiz->value == num)
            {
                aux = raiz->sig;
                free(raiz);
                raiz = aux;
                return num;
            }
            else
            {
                
            }
        }
    }
}

void ver()
{

    if (raiz == NULL)
        printf(">>> Cola vacia...\n");
    else
    {
        elem *aux = raiz;

        while (aux != NULL)
        {
            printf("[%d] ", aux->value);
            aux = aux->sig;
        }

        printf("\n");

        free(aux);
    }
}