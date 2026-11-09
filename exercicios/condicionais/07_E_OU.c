#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Faça um programa que leia 2 números inteiros e imprima se a soma deles estiverem entre 0 e 10 ou se a soma for par
int main(){
    setlocale(LC_ALL, ".UTF8");
    
    int num1, num2, soma;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);
    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    soma = num1 + num2;

    if ((soma >= 0 && soma <= 10) || (soma % 2 == 0)) {
        printf("A soma dos números é %d e atende a condição.\n", soma);
    } else {
        printf("A soma dos números é %d e não atende a condição.\n", soma);
    }

    return 0;
}