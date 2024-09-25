#include <stdio.h>

    /*
    Escribe un programa en que se pida ingresar numeros entre el 1 y el 7. Segun el numero elegido va a representar un dia de la semana.
    */

int main(){

    int dia;

    printf("Ingrese un número entre 1 y 7:\n>>");
    scanf("%d",&dia);
    
    switch (dia)
    {
    case 1: printf("Lunes");
        break;
    case 2: printf("Martes");
        break;
    case 3: printf("Miercoles");
        break;
    case 4: printf("Jueves");
        break;
    case 5: printf("Viernes");
        break;
    case 6: printf("Sabado");
        break;
    case 7: printf("Domingo");
        break;
    default: printf(">>> Número erroneo...");
        break;
    }

    return 0;

}