#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

    typedef struct { //typedef: Estructura con diferentes datos -> typedef struct *Nombre anonimo*{} Nombre_Estructura;
    char name[30];
    char firstLastName[30];
    char secondLastName[30];
    } Nombre;

    Nombre lista[3];

    int i;

    for(i=0;i<3;i++)
    {
        gets(lista[i].name);
        gets(lista[i].firstLastName);
        gets(lista[i].secondLastName);
    }

    for(i=0;i<3;i++)
    {
        printf("%s %s %s",lista[i].name,lista[i].firstLastName,lista[i].secondLastName);
    }

}