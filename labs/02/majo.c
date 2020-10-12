#include <stdio.h>

int main(){

    int var = 0;
    int *i = &var;
    int var2 = 0;
    int *sum = &var2;
    int arreglo [100];
    for (;*i<100;(*i)++){
        printf("aqui: %d\n", arreglo[*i]);
        (*sum) += arreglo[*i];
    }
    printf("Suma: %d\n", *sum);
    return 0;
}