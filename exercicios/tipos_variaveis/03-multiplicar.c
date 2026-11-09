#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, ".UTF8");
    // Crie um algoritmo que leia 3 numeros de uma só vez e coloque o resultado da multiplicação em uma variável própria, depois exiba o resultado na tela.

    int a, b, c, resultado;

    printf("Digite 3 números inteiros separados por espaço: ");
    scanf("%d %d %d", &a, &b, &c);

    resultado = a * b * c;

    printf("O resultado da multiplicação de %d, %d e %d é: %d\n", a, b, c, resultado);
}