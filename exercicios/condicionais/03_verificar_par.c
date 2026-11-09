#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Faça um programa que leia um número inteiro e informe se ele é par ou impar
int main(){
    setlocale(LC_ALL, ".UTF8");
    
    int num;
    printf("Digite um número inteiro: ");
    scanf("%d", &num); // Lê o primeiro número inteiro
    
    if (num % 2 == 0){
        printf("O número %d é par! \n", num);
    }else{
        printf("O número %d é impar! \n", num);
    }
}