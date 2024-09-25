#include <stdio.h>
#include <stdlib.h>

/*
Que es un pointer?

Primero, entendamos la memoria:
 | Direc  | Val |
 | 0x1000 | 0x4 | int x = 4; La dirreccion 0x1000 (x) de la memoria, tiene asignado el valor '4'
 | 0x1004 | 0x7 | int *pX = &x; El apuntador px apunta hacia la direccion de x, y se le asigna ese valor

 Los pointers sirven para no estar guardando datos en variables cada 3 segundos, si no referencia el valor que ya existe
 en alguna parte de la memoria; si es que ese valor no va a ser modificado.
*/

typedef struct
{
    int x;
    int y;
}Point;

int main()
{
    int q = 4; // Entero(int) llamdo q(q) tiene un valor de(=) 4(4);
    int *aQ = &q; // Entero(int) apuntador(*) llamado apuntador_a_q(aQ) tiene el valor de(=) la direccion(&) de q(q);
    int h = *aQ; //Entero(int) llamado h(h) tiene el valor de(=) el valor apuntado(*) por qX(qX);

    Point p1;
    p1.x=3;
    p1.y=2;

    printf("p1: (%d,%d)\n",p1.x,p1.y);//Imprime el valor de la estructura Point

    Point *p2;
    p2 = &p1; //Se le asigna la direccion en la memoria de p1 a p2; (p2 esta apuntando(&) a p1)

    // p2.x=7; Marca error! Los apuntadores no tienen valores, simplemente apuntan hacia la direccion de un valor en la memoria, y pueden cambiar ese valor al que apuntan.
    p2->x=5; //p2->x == p1.x, El valor .x de la direccion hacia donde apunta p2, se le asigna el valor de 9
    p2->y=4;

    printf("p1: (%d,%d)\n",p2->x,p2->y);//Imprime el valor hacia el que apunta p2

    Point *p3;
    p3 = malloc(sizeof(Point));//Malloc, reserva una direccion en la memoria, del tamaño de Point, y p3 apuntara a esa direccion reservada.

    p3->x=5;
    p3->y=10;

    printf("p3: (%d,%d)\n",p3->x,p3->y);

    (*p3).x=2;
    (*p3).y=4;
    //(*p3).x == p3->x; Es lo mismo, pero con diferente sintaxis
    //Funciona primero (obteniendo la direccion a la que apunta p3) . y despues accediendo al valor de la direccion.\

    printf("p3: (%d,%d)\n",(*p3).x,(*p3).y); //Es exactamente la misma funcion, pero las -> son mas bonitas :3
}