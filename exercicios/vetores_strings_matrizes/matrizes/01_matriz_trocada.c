#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, ".UTF8");
    
    // Preencha uma matriz 2x2 lendo valores do usuario e depois troque os valores entre a primeira e segunda linha
    int matriz[2][2]; 
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Digite o valor da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Troca de valores entre a primeira e segunda linha
    int aux[2];
    for (int j = 0; j < 2; j++){
        aux[j] = matriz[0][j];
        matriz[0][j] = matriz[1][j];
        matriz[1][j] = aux[j];
    }
    
    printf("Valores da Matriz:\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
    