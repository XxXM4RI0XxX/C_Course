#include <stdio.h>

    //Pedir valores al usuario, validar que sean valores entre 1 y 5. Saber cual de los numeros en el arreglo son numeros primos.
void main(){

    int arr [10],lim=1,num,x;


    printf("Ingrese 10 numeros a evaluar:\n");

    do{

        printf("#%d:", lim);
        scanf("%d",&num);
        if(num<1 || num>5){
            printf("Ingrese numero valido...\n");
            continue;
        }

        arr[lim-1]=num;
        lim++;
    }while(lim < 11);

    printf("arreglo:\n");
    for(int i=0; i<10;i++){
        printf("%d | ",arr[i]);
    }
    printf("\n");
    //Reparar esta perre parte >:(
    printf("Numeros primos:\n");
    for(int i=0; i<10;i++){
        x=0;
        for(int j=2; j<arr[i];j++){
            if(arr[i] % j ==0) x++;
            if(!x) printf("Num:%d Pos:%d\n",arr[i],j+1);
        }

    }
}