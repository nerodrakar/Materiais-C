#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, ".UTF8");
    
    // Crie um agoritmo que leia duas notas e moestre o valor absoluto da diferença entre elas.
    float nota1, nota2, diferenca;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    diferenca = abs(nota1 - nota2);

    printf("O valor absoluto da diferença entre %.2f e %.2f é igual a: %.2f\n", nota1, nota2, diferenca);
}