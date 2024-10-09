#include <stdio.h>
//Matriz
void main(){

    int var [5][10], a=1;

    for(int i=0; i<5 ;i++){
        printf("\n");
        for(int j=0; j<10 ;j++){
            var[i][j]=a++;
            printf("%d\t", var[i][j]);
            
        }
    }

}