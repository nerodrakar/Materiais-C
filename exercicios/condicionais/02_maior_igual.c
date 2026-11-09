#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Faça um programa que leia dois números inteirios e imprima na tela qual é o maior deles ou se são iguais.
int main(){
    setlocale(LC_ALL, ".UTF8");
    
    int num1, num2;
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1); // Lê o primeiro número inteiro
    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2); // Lê o segundo número inteiro

    if (num1 > num2){
        printf("O maior número é %d \n", num1);
    }else if (num2 > num1){
        printf("O maior número é %d \n", num2);
    }else{
        printf("Os números são iguais \n");
    }
}