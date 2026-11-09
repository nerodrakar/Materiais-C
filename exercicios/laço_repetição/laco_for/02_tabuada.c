#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Faça um programa que mostre a tabuada de um número inteiro informado pelo usuário, usando o laço for.
int main(){
    setlocale(LC_ALL, ".UTF8");

    int numero;
    printf("Digite um número inteiro para ver a tabuada: ");
    scanf("%d", &numero);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}