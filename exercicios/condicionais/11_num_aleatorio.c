#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ".UTF8");
    
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo atual

    int num_aleatorio = rand() % 10; // Gera um número aleatório entre 0 e 9
    printf("Número aleatório gerado: %d\n", num_aleatorio);

    return 0;
}