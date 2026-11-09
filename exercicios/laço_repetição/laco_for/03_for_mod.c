#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Faça um programa que o usuario informe o valor inicial, valor final e o incremento, e mostre os valores de acordo com os dados informados.
int main(){
    setlocale(LC_ALL, ".UTF8");

    int valor_inicial, valor_final, incremento;

    printf("Digite o valor inicial: ");
    scanf("%d", &valor_inicial);

    printf("Digite o valor final: ");
    scanf("%d", &valor_final);

    printf("Digite o incremento: ");
    scanf("%d", &incremento);

    for (int i = valor_inicial; i <= valor_final; i += incremento) {
        printf("%d\n", i);
    }

    return 0;
}