#include <stdio.h>
//Cuantas vocales hay?
void main(){

    printf("Dame una frase:");
    char cad [30];
    gets(cad);
    int voc = 0;
    for(int i =0; i<30 ; i++){

        switch (cad[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': voc++;
            break;
        default:
            break;
        }
    }

    printf("Hubo %d vocales", voc);

}