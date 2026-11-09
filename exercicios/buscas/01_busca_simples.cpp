#include <iostream>
using namespace std;

int main()
{
    int vetor[5] = {17, 23, 15, 42, 8};
    int valorProcurado = 42;
    int posicao;
    
    for(int i = 0; i < 5; i++){
        if(vetor[i] == valorProcurado){
            posicao = i;
            break;
        }
    }

    if (valorProcurado == vetor[posicao]){
        printf("Valor %d encontrado na posicao %d\n", valorProcurado, posicao);
    } else {
        printf("Valor %d nao encontrado\n", valorProcurado);
    }

    return 0;
}