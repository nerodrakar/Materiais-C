#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

struct listaPessoa{
    string nome;
    int rg;
};

void limpaTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void imprimeSequencial(listaPessoa *ponteiroSequencial, int tamanhoLista){
    for(int i = 0; i < tamanhoLista; i++){
        cout << i << " - " << ponteiroSequencial[i].nome << " , " << ponteiroSequencial[i].rg << "\n";
    }
}

int main(){
    // Variáveis 
    int funcaoDesejada = 1;
    // Ponteiro para a lista sequencial 
    listaPessoa *ponteiroSequencial;
    // Tamanho da lista
    int tamanhoLista = 0;
    
    // // Exemplo
    // listaPessoa *exemploLista = new listaPessoa[1];
    
    // exemploLista[0].nome = "Baseado ENE";
    // exemploLista[0].rg = 123;
    
    // ponteiroSequencial = exemploLista;
    
    // imprimeSequencial(ponteiroSequencial, 2);
    
    while(funcaoDesejada < 10 && funcaoDesejada > 0){
        cout << "Operações \n";
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
        
        // Lendo a entrada do usuário
        cin >> funcaoDesejada;  
        
        limpaTela();
        
        // Escolhendo a função desejada
        switch(funcaoDesejada){
            case 1:
                cout << "Função escolhida: 1 \n";
                break;
            case 2: 
                cout << "Função escolhida: 2 \n";
                break;
                
        }
    }
}