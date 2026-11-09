#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Faça um programa que joga 3 dados de seis lados aleatórios e exibe o resultado de cada dado e a soma total dos três dados.
int main() {
    setlocale(LC_ALL, ".UTF8");

    srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo atual
    
    int dado1 = rand() % 6 + 1; // Gera um número aleatório entre 1 e 6 para o primeiro dado
    int dado2 = rand() % 6 + 1; // Gera um número aleatório entre 1 e 6 para o segundo dado 
    int dado3 = rand() % 6 + 1; // Gera um número aleatório entre 1 e 6 para o terceiro dado

    int soma_total = dado1 + dado2 + dado3; // Calcula a soma total dos três dados

    printf("Resultado do dado 1: %d\n", dado1);
    printf("Resultado do dado 2: %d\n", dado2);
    printf("Resultado do dado 3: %d\n", dado3);
    printf("Soma total: %d\n", soma_total);

    return 0;
}
