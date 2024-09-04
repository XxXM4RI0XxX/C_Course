#include <stdio.h>

//Detectar palabras palindromas (Ignorar espacios)

void main()
{
    char cad[30];

    printf("Ingrese palabra:");
    gets(cad);

    int lenght = 0;
    //Obtener tamaño
    while (cad[lenght]!=0)
    {
        lenght++;
    }
    //Verificar si es palindromo
    for (int i=0,f = lenght; i < lenght; i++,f--)
    {
        if(cad[i]==' ')i++;
        if(cad[f]==' ')f--;
        if(cad[i]==cad[f]){
            printf(">>> es palindromo");
        }
        else printf("no Es palindromo");
    }
}