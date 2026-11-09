#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Crie um algoritmo que imprima os numeros pares de 10 a 20 usando for, while e do while.
int main(){
     setlocale(LC_ALL, ".UTF8");

    // Usando for
    printf("Usando for:\n");
    for (int i = 10; i <= 20; i ++){
        if (i % 2 == 0){
            printf("%d\n", i);
        }
    }

    // Usando while
    printf("Usando while:\n");
    int j = 10;
    while (j <= 20){
        if (j % 2 == 0){
            printf("%d\n", j);
        }
        j++;
    }

    // Usando do while
    printf("Usando do while:\n");
    int k = 10;
    do{
        if (k % 2 == 0){
            printf("%d\n", k);
        }
        k++;
    } while (k <= 20);

    return 0;
}