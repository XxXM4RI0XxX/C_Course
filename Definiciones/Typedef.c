#include <stdio.h>

typedef char user[25]; //Definir un nuevo tipo de dato simple

struct User //Definir un nuevo tipo de dato con atributos
{
    char name[25];
    char password[12];
    int id;
};

typedef struct //Ahorrarnos el escribir 'struct' cada que utilizamos el nuevo tipo de dato
{
    char name[25];
    char password[50];
}UserA;

void main()
{
    /*
    typedef, palabra reservada para darle a un tipo de dato una "etiqueta":
    typedef *tipo_dato* *nombre_dato*;

    struct, es como crear un objeto:
    struct *nombre_dato*
    {
      *atributos*
    };
    */

    user usuario1 = "Jose";

    struct User usuario2 = {"Juan", "Juan13", 12345};
    struct User usuario3 = {"Juana", "Juana12", 54321};

    UserA usuarioA = {"Miguel","Miguel27"};

    printf("Name: %s\nPass: %d\nID: %d",usuario2.name,usuario2.password,usuario2.id);

}