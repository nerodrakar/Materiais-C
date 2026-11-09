#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, ".UTF8");

    // Crie um algoritmo que leia 2 notas e mostre a media entre elas.
    float nota1, nota2, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    
    media = (nota1 + nota2) / 2;

    printf("A media entre %.2f e %.2f é igual a: %.2f\n", nota1, nota2, media);

}