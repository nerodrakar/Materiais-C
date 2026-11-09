#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Faça um programa que leia dois números inteiros e imprima na tela se a soma deles é maior/igual a 10 ou menor que 10.

int main(){
    setlocale(LC_ALL, ".UTF8");

    int num1, num2, soma;

    scanf("%d", &num1); // Lê o primeiro número inteiro
    scanf("%d", &num2); // Lê o segundo número inteiro

    soma = num1 + num2;

    if (soma >= 10){
        printf("%d + %d = %d, que é maior ou igual a 10.\n", num1, num2, soma);
    } else {
        printf("%d + %d = %d, que é menor que 10.\n", num1, num2, soma);
    }
    return 0;
}