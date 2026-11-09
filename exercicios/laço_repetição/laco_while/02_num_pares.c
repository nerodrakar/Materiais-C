#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Faça um programa que imprima os números pares de 10 até um número informado pelo usuário.
void main(){
     setlocale(LC_ALL, ".UTF8");

     int max, i = 10;

     printf("Digite um número inteiro: ");
     scanf("%d", &max);

     while(i <= max){
        if(i % 2 == 0){
            printf("%d\n", i);
        }
        i++;
     }
     printf("Fim do programa.\n");
}