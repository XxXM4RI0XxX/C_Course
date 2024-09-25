#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_words(const char *);
//Contador de palabras en un texto

void main()
{

    char text[1000]; //Arreglo de tamaño 1000

    printf("Ingrese texto a leer:\n > ");
    fgets(text,sizeof(text),stdin); // fgets: Obtener entrada de usuario que puede contener espacios (char[],tamaño,entrada estandar);

    // FILE *file;
    
    // file = fopen("C.txt","r"); Intento de leer desde un archivo xd

    // if (file == NULL) {
    // perror("Error al abrir el archivo");
    // }

    // if (fgets(text,sizeof(text),file) != NULL) fgets(text,sizeof(file),file);

    int word_count = count_words(text); //Llama a la funcion para contar las palabras
    printf("El texto tiene %d palabras.\n", word_count);

    // fclose(file);

}

int count_words(const char *text)
{
    int count=0; //Cuenta
    int in_word=0; //Verificar si esta dentro de una palabra

    while (*text)//Mientras el apuntador no llegue al caracter nulo '\0'
    {
        if(isspace((unsigned char)*text)) in_word=0; //Sí(El caracter en la posicion '(char sin signo)*text' es espacio[isspace]) >> 'Dentro de palabra' sera falso, y se saltara la suma al contador;
        else if (!in_word) //Entonces Sí('Dentro de palabra' sea falso[Sera negado con ! y se convertira en verdadero; entrando en el ciclo]) >> 'Dentro de palabra' sera verdadero (Con esto sigue siendo verdadero !in_word en el siguiente ciclo), y la cuenta de palabras se sumara +1;
        {
            in_word=1;// 'Dentro de palabra' se hace verdadero
            count++; // Cuenta++;
        }
        text++; //Pasar al siguiente apuntador
    }

    return count;
    
}