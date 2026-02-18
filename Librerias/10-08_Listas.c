#include <stdio.h>
#include <stdlib.h>
#include "Simple_ligada.h"

typedef struct elem
{
    int value;
    struct elem *sig;
} elem;

elem *raiz = NULL;

void meter_ordenar(elem *);
int meter(int, elem *);
int sacar(int);
void ver();

void main()
{
    printf("\t>>>>>>>>>>>>>> LISTAS SIMPLEMENTE LIGADAS <<<<<<<<<<<<<<<\n\n");
    int opt;

    do
    {

        printf("\nMENU\n1) Meter elemento \n2) Sacar elemento\n3) Ordenar elementos\n4) Ver elementos\n0) Salir\n> ");

        scanf("%d", &opt);

        switch (opt)
        {
        case 1:

            printf("Elemento a agregar: ");
            elem *nuevo;
            int valor;

            nuevo = malloc(sizeof(elem));
            nuevo->sig = NULL;

            do
            {
                scanf("%d", &valor);
                if (valor < 1)
                    printf(">>> Valor invalido...\n> ");
            } while (valor < 1);

            nuevo->value = valor;

            printf("Como desea ingresar el valor?\n1) Primero\n2) Ultimo\n3) Ordenado [! Ordena toda la lista !]\n> ");
            scanf("%d", &opt);
            meter(opt, nuevo);

            printf(">> Valor [%d] exitosamente agregado\n", valor);

            break;

        case 2:

            printf("Que valor desea sacar?\n1) Primero\n2) Ultimo\n3) Especifico\n> ");
            scanf("%d", &opt);

            int num = sacar(opt);

            if (num < 0)
                printf(">>> Cola vacia...\n");
            else if (num == 0)
                printf(">>> Valor no encontrado...\n");
            else
                printf(">> Valor [%d] exitosamente retirado\n", num);
            break;
        case 3:
            int ver = order(&raiz);

            if (ver == 0)
                printf(">>> Nothing to order...\n");
            else
                printf(">> Done!\n");
            break;
        case 4:
            print(&raiz);
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

int meter(int opt, elem *nuevo)
{
    switch (opt)
    {
    case 1:
        firstIn(&raiz, &nuevo);
        break;
    case 2:
        lastIn(&raiz, &nuevo);
        break;
    case 3:
        orderIn(&raiz, &nuevo);
        break;
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
            return firstOut(&raiz);
            break;
        case 2:
            return lastOut(&raiz);
            break;
        case 3:
            return orderOut(&raiz);
            break;
        }
    }
}
