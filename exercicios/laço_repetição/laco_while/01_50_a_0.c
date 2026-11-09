#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Faça um programa que imprima os números de 50 a 0, em ordem decrescente de 6 em 6, usando o laço while.
void main(){
     setlocale(LC_ALL, ".UTF8");
    
     int i = 50;

     while (i >= 0) {
        printf("i: %d\n", i);
        i -= 6;
     }
     
     printf("Fim do programa!\n");
}
