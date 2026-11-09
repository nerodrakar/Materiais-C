#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Faça um programa que leia 2 números inteiros e imprima se algum for par
int main(){
    setlocale(LC_ALL, ".UTF8");
    
    int num1, num2;
    printf("Digite dois número inteiro: ");
    scanf("%d %d", &num1, &num2); 
    
    if (num1 % 2 == 0 && num2 % 2 == 0){
        printf("Os números %d e %d são pares! \n", num1, num2);
    }else if (num1 % 2 == 0){
        printf("Somente %d é par! \n", num1);
    }else if (num2 % 2 == 0){
        printf("Somente %d é par! \n", num2);
    }else{
        printf("Nenhum numero é par! \n");
    }
}