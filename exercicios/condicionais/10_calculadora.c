#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Faça um programa de calculadora usando o switch case, que leia dois números e mostre as opções de soma, subtração, multiplicação e divisão. O usuário deve escolher a operação desejada e o programa deve exibir o resultado correspondente.
int main(){
    setlocale(LC_ALL, ".UTF8");

    int num1, num2, resultado, opcao;

    printf("Digite dois numeros: ");
    scanf("%d %d", &num1, &num2);

    printf("Escolha a operação desejada:\n");
    printf("1. Soma\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
  
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            resultado = num1 + num2;
            printf("O resultado da soma é: %d\n", resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("O resultado da subtração é: %d\n", resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("O resultado da multiplicação é: %d\n", resultado);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}