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

            elem ola;

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
            raiz->sig = aux;
            aux->ant = elemento;
        }
        else
        {
            elem *aux = raiz;

            while (aux != NULL)
            {
                if (aux != raiz && aux->ant->value < elemento->value && aux->value > elemento->value)
                {
                    elemento->sig = aux;
                    elemento->ant = aux->ant;
                    aux->ant = elemento;
                    elemento->ant->sig = elemento;
                }
                if (elemento->ant == NULL && aux->sig == NULL)
                {
                    aux->sig = elemento;
                    elemento->ant = aux;
                }
                aux = aux->sig;
            }
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
            if (raiz->sig == NULL)
                raiz = NULL;
            else
            {
                raiz = raiz->sig;
                raiz->ant = NULL;
            }
            free(aux);
            return val;
        case 2:
            if (raiz->sig == NULL)
                return sacar(1);
            else
            {
                while(aux->sig != NULL)
                    aux = aux->sig;
                
                val = aux->value;
                aux = aux->ant;
                aux->sig = NULL;
                aux = aux->sig;
                free(aux);
                
                return val;
            }
        case 3:
            int num;
            printf("Valor: ");
            scanf("%d", &num);
            elem *aux2;

            if (raiz->value == num)
                sacar(1);
            else
            {
                while (aux->value != num && aux->sig != NULL)
                    aux = aux->sig;

                if (aux->value == num)
                {
                    if (aux->sig == NULL)
                        sacar(2);
                    else
                    {   
                        num = aux->value;
                        aux2 = aux->ant;
                        aux2->sig = aux->sig;
                        aux->ant = aux2;
                        free(aux);
                        return num;
                    }
                }
                else
                    return 0;
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