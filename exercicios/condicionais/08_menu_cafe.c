#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, ".UTF8");

    printf("Bem-vindo ao menu de café!\n");
    printf("Escolha uma opção:\n");
    printf("1. Café Expresso\n");
    printf("2. Café com Leite\n");
    printf("3. Cappuccino\n");
    printf("4. Sair\n");

    int opcao;
    printf("Digite o número da opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Você escolheu Café Expresso.\n");
            break;
        case 2:
            printf("Você escolheu Café com Leite.\n");
            break;
        case 3:
            printf("Você escolheu Cappuccino.\n");
            break;
        case 4:
            printf("Saindo do menu. Até logo!\n");
            break;
        default:
            printf("Opção inválida. Por favor, escolha uma opção válida.\n");
            break;
    }