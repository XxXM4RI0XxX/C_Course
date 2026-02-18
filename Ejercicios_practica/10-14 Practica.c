#include <stdio.h>
#include <stdlib.h>

#define size 100

typedef struct celda_info
{
    char nombre[size];
    unsigned int id;
    float cal_sen;
    struct ope_info *op;
}celda_info;

typedef struct ope_info
{
    char nombre[size];
    unsigned int prioridad;
    unsigned int ult_comp;
}ope_info;

void main()
{
    
}