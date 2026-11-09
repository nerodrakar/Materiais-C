#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Faça um programa que mostre a soma de dois numeros entre 5 e 10, apenas quando ambos forem maiores que 5 e menores que 10.
void main(){
     setlocale(LC_ALL, ".UTF8");

    int num1 = 0;
    int num2 = 0;

    while (!(num1 > 5 && num1 < 10) || !(num2 > 5 && num2 < 10)) {
        printf("Digite o primeiro numero (entre 5 e 10): ");
        scanf("%d", &num1);
        printf("Digite o segundo numero (entre 5 e 10): ");
        scanf("%d", &num2);

        if (!(num1 > 5 && num1 < 10 && num2 > 5 && num2 < 10)) {
            printf("Os numeros devem ser maiores que 5 e menores que 10. Tente novamente.\n");
        }
    }
    printf("A soma dos numeros e: %d\n", num1 + num2);
}