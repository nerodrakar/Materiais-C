#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 3

int main(){
    setlocale(LC_ALL, ".UTF8");

    // Crie um algoritmo que leia 3 valores para um vetor de 3 posições, calcule a média e imprima o resultado.
    int vetornum[TAM];
    float soma = 0.0;
    
    for (int i = 0; i < TAM; i++){
        printf("\nDiginte o número para a posição [%d]: ", i);
        scanf("%d", &vetornum[i]);
    }
    
    fflush(stdin);
    
    printf("\nVetor completo: ");
    for (int i = 0; i < TAM; i++){
        printf("%d ", vetornum[i]);
        soma += vetornum[i];
        
    }
    
    printf("\nMedia: %.1f", soma / TAM);
   
}