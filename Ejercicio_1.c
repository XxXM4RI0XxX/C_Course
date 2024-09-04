#include <stdio.h>
    /*
    Realice un programa que determine cual es la nota final de un alumno en una materia teniendo en cuenta que la nota final es el promedio de 2 examenes. (obtener el promedio de los 2 examenes)
    */
int main(){

    float ex1 , ex2;

    printf("Ingrese nota primer examen: ");
    scanf("%f",&ex1);
    printf("Ingrese nota segundo examen: ");
    scanf("%f",&ex2);

    float prom = (ex1+ex2)/2;

    printf("%f es el promedio final",prom);

    return 0;
}