#include <iostream>
#include <string>
#include <stdlib.h>
#include <new>

using namespace std;

void limpaTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    // Variáveis
    int funcaoDesejada = 1;
    
    while(funcaoDesejada <10 && funcaoDesejada >0){
        cout << "1 - Insercao de node no inicio da lista\n";
        cout << "2 - Insercao de um node no fim do lista \n";
        cout << "3 - Insercao de um node na posicao N \n";
        cout << "4 - Retirar um node do inicio da lista \n";
        cout << "5 - Retirar um node no fim da lista \n";
        cout << "6 - Retirar um node na posicao N \n"; 
        cout << "7 - Procurar um node com campo RG \n";
        cout << "8 - Imprimir a Lista \n";
        cout << "9 - Sair do sistema \n";
        cout << "\nEscolha um numero e pressione ENTER \n"; 

        cin >> funcaoDesejada;
        
        limpaTela();

        switch (funcaoDesejada){
            case 1:
            cout << "Funcao escolhida: 1 - Insercao de node no inicio da lista\n";
                break;
            case 2:
                cout << "Funcao escolhida: 2 - Insercao de um node no fim do lista \n";
                break;
        }

    }
}