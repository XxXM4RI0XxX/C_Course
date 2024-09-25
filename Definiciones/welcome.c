#include <stdio.h>
//Definir constantes
#define SEMESTRE 3.5;
#define NOMBRE "Jose";
//Definir variables
float dinero = 127.33;
char pollo = 'P';

void main(){

    int ola = 14; //Declarar variable
    float adios = 15;
    double sum = ola-adios;
    printf("%d\n",ola);
    ola+=adios;

    printf("Welcome\n");//Imprimir texto en consola
    printf("%d - %f = %f\n",ola,adios,sum);
    //comment xd
   
    /*
    comment block
    */

   //Secuencias de escape
   printf("Nu\n\0lo olo87wdytf789\n");//Canela todo el texto que haya despues de Nulo
   printf("Retro\bceso\n");//Aplica un... retroceso en el texto?
   printf("Tabu\tlador\n");//Tabula xd
   printf("Salto de>\n<linea\n");//Salta la linea :o
   printf("Salto de \f pagina\n");// ??
   printf("Retorno de\r carro carro ca\rrro?\n");// FF
   printf("Poner \"comillas\" | Poner ¿Signo de interrogacion?\? | Poner \\ barra \\ invertida\n");//Para mostrar signos reservados (" \ ?)

   char cadena [30];
   scanf("%s", &cadena);
   printf("%s", cadena);
}