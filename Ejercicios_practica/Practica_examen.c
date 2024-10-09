#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    var *nodoV;
    ope *nodoO;
}nodo;

typedef struct var
{
    char *val;
    var *sig;
}var;

typedef struct ope
{
    char *val;
    ope *sig;
}ope;

var *raizV = NULL;
ope *raizO = NULL;

void main()
{
    char ec[100];
    int op;
    printf("Ingrese ecuacion a evaluar:\n> ");
    gets(ec);

    printf("1) Prefijo\n2) Posfijo 3) Calcular");
    scanf("%d",op);

    switch (op)
    {
    case 1:
        prefijo(strdup(ec));
        break;
    case 2:
        posfijo(strdup(ec));
        break;
    case 3:

        break;
    default: printf("Nope...");
        break;
    }
}

char prefijo(char ec)
{

}

char posfijo(char ec)
{
    nodo *nodoMain;
    nodoMain = malloc(sizeof(nodo));
    raizV = malloc(sizeof(var));
    raizO = malloc(sizeof(ope));
    nodoMain->nodoO->sig = NULL;
    nodoMain->nodoV->sig = NULL;

    push('(', *nodoMain, 0);
}

void push(char elem,int type)
{
    if(type==0) // Variables
    {
       if(raizV == NULL)  
            raizV->val = elem;
        else
        {
            var *aux = raizV;
            while (aux -> sig != NULL)
                aux = aux -> sig;
            aux -> sig = ;
        } 
    }
    else // Operadores
    {

    }
}