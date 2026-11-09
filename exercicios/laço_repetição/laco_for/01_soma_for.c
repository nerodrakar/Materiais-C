#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Faça um programa que mostre a soma de todos os numeros de 0 a 10, adicionando o valor atual de i numa variável soma a cada repetição do laço for.
int main(){
     setlocale(LC_ALL, ".UTF8");

     int soma;
     printf("Digite o valor inicial da soma: ");
     scanf("%d", &soma);

     for (int i = 0; i <= 10; i++) {
      printf("i: %d (soma: %d)\n", i, soma);
        soma += i;
     }
     printf("Soma final: %d\n", soma);

     return 0;
}