#include <stdio.h>
#include <stdlib.h>
#include "Doble_ligada.h"

typedef struct elem
{
    int value;
    struct elem *sig;
    struct elem *ant;
} elem;

elem *raiz = NULL;

void meter(int, elem *);
int sacar(int);

void main()
{
    printf("\t>>>>>>>>>>>>>> LISTAS DOBLEMENTE LIGADAS <<<<<<<<<<<<<<<\n\n");
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
            nuevo->ant = NULL;

            do
            {
                scanf("%d", &valor);
                if (valor < 1)  
                    printf(">>> Valor invalido...\n> ");
            } while (valor < 1);

            nuevo->value = valor;

            printf("Como desea agregar el nuevo valor?\n1) Primero\n2) Ulitmo\n3) Ordenado\n> ");
            scanf("%d", &opt);

            meter(opt, nuevo);
            break;
        case 2:
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
            int check = order(&raiz);

            if(check == 1)
                printf(">>Done!\n");
            else
                printf(">>>Nada para ordenar...\n");
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

void meter(int opt, elem *nuevo)
{
    switch(opt)
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
        case 2:
            return lastOut(&raiz);
        case 3:
            return orderOut(&raiz);
        }
    }
}