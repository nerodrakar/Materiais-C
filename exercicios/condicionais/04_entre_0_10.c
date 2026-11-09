#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Faça um programa que leia um número inteiro e imprima se ele está entre 0 e 10
int main(){
    setlocale(LC_ALL, ".UTF8");
    
    int num;
    printf("Digite um número inteiro: ");
    scanf("%d", &num); // Lê o primeiro número inteiro
    
    if (num >= 0 && num <= 10){
        printf("O número está entre 0 e 10");
    }else{
        printf("O numéro não está entre 0 e 10");
    }
}