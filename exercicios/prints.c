#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, ".UTF8");
    printf("Teste de variáveis\n");

    int a = 10;
    int b = 3;
    // Valores inteiros
    printf("Valores inteiros:\n");
    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);
    printf("Soma: %d\n", a + b);
    printf("Subtração: %d\n", a - b);
    printf("Multiplicação: %d\n", a * b);
    printf("\n");

    // Valores reais
    float c = 10.0;
    float d = 3.0;
    printf("Valores reais:\n");
    printf("Valor de c: %.2f\n", c);
    printf("Valor de d: %.2f\n", d);
    printf("Soma: %.2f\n", c + d);
    printf("Subtração: %.2f\n", c - d);
    printf("Multiplicação: %.2f\n", c * d);
    printf("\n");

    // Valores char
    printf("Valores char:\n");
    char letras = 'S';
    printf("Valor de e: %c\n", letras);
    printf("\n");

    printf("Valores string:\n");
    char nome[] = "Alice";
    printf("Valor de nome: %s\n", nome);
    printf("\n");

    // Entrada de dados
    printf("Inserindo valores:\n");
    printf("Digite um valor: ");
    scanf("%d", &a);
    printf("O valor digitado foi: %d\n", a);
    printf("Digite uma letra: ");
    scanf(" %c", &letras);
    printf("A letra digitada foi: %c\n", letras);
    printf("Digite um nome: ");
    scanf("%s", nome);
    printf("O nome digitado foi: %s\n", nome);
}