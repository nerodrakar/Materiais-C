#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Faça um programa que leia 3 numeros inteiros e diga se os três são maiores que 10
int main(){
    setlocale(LC_ALL, ".UTF8");
    
    int num1, num2, num3;
    printf("Digite três número inteiro: ");
    scanf("%d %d %d", &num1, &num2, &num3); // Lê o primeiro número inteiro
    
    if (num1 > 10 && num2 > 10 && num3 > 10){
        printf("Todos os numeros são maiores que 10. \n");
    }else if (num1 > 10 || num2 > 10 || num3 > 10){
        printf("Pelo menos um número é maior que 10. \n");
    }else{
        printf("Nenhum numero é maior que 10. \n");
    }
    
    return 0;
}