#include <stdio.h>

//Detectar palabras palindromas (Ignorar espacios)

void main()
{
    char cad[30];

    printf("Ingrese palabra:");
    gets(cad);

    int lenght = 0;
    //Obtener tamaño y quitar espacios
    while (cad[lenght]!=0)
    {
        if(cad[lenght]==' ')
        {
            for(int i = lenght ; i < 30 ;i++)
            {
            cad[i]=cad[i+1];
            }
        } 
        lenght++;
    }

    int val = 0;
    //Verificar si es palindromo
    for (int i=0,f = lenght; i < lenght; i++,f--)
    {
        if(cad[i]==cad[f]){
            printf(">> NO es palindromo");
            val++;
            break;
        }
    }

    if(val==0) printf(">> Es palindromo");
}