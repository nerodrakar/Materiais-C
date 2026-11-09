#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5

int main(){
    setlocale(LC_ALL, ".UTF8");

    // Definindo Vetores de várias formas: 
    int vetorInt[] = {1, 2, 3, 4, 5}; // Vetor de inteiros sem tamanho definido
    float vatorFloat[3] = {1.1, 2.2, 3.3}; // Vetor de float com tamanho definido
    char vetorChar[TAM] = {'A', 'B'}; // Vetor de char com tamanho definido e constante

    // Modificando valor por atribuição 
    vetorInt[0] = 9; // Atribuindo um novo valor ao primeiro elemento do vetor

    // Modificando valor com variável
    float novoValor = 4.4;
    vatorFloat[1] = novoValor; // Atribuindo um novo valor ao segundo elemento do vetor

    //Modificando valor com usuário
    printf("Digite um valor para o terceiro elemento do vetor de char: ");
    fflush(stdin); // Limpa o buffer do teclado
    scanf("%c", &vetorChar[0]); // Lê um valor do teclado

    // Imprimindo os valores dos vetores
    printf("Vetor de inteiros: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetorInt[i]);
    }

    printf("\nVetor de float: ");
    for (int i = 0; i < 3; i++) {
        printf("%.1f ", vatorFloat[i]);
    }

    printf("\nVetor de char: ");
    for (int i = 0; i < TAM; i++) {
        printf("%c ", vetorChar[i]);
    }
    printf("\n");
    return 0;
}