#include <iostream>
#include <string>
#include <stdlib.h>
#include <new>

using namespace std;

struct pessoa{
    string nome;
    int rg;

    struct pessoa *proximo;
};

void limpaTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


int retornaTamanho(pessoa *ponteiroEncadeado){
    // Controla o tamanho da lista 
    int tam = 0;

    // Criando ponteiro auxiliar (cursor)
    pessoa *p = ponteiroEncadeado;

    while (p != NULL){
        // Atualiza o cursor
        p = p -> proximo;

        //Incrementa o contador de tamanho
        tam++;
    }

    return tam;
}


void imprimeEncadeada(pessoa *ponteiroEncadeado){
    // Criando ponteiro auxiliar (cursor)
    pessoa *p = ponteiroEncadeado;

    while (p != NULL){
        cout << p -> nome << ", " << p -> rg << "\n";
        // Atualiza o cursor
        p = p -> proximo;
    }
    
}


int main(){
    // Variáveis
    int funcaoDesejada = 1;

    // Criando o inicio da lista encadeada (ponteiro principal)
    pessoa *ponteiroEncadeado;

    // Criando um exemplo 
    pessoa *novoValor = new pessoa;

    novoValor -> nome = "Pedro";
    novoValor -> rg = 123;
    novoValor -> proximo = NULL;

    // Transformar o ponteiro do inicio da lista no novo valor 
    ponteiroEncadeado = novoValor;
    
    // Criando novo valor
    pessoa *novoSegValor = new pessoa;

    novoSegValor -> nome = "Joao";
    novoSegValor -> rg = 456;
    novoSegValor -> proximo = NULL;

    // Apontar o ponteiro do primeiro valor para o segundo
    novoValor -> proximo = novoSegValor;

    while(funcaoDesejada < 9 && funcaoDesejada > 0){
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


        cout << "\nTamanho atual: " << retornaTamanho(ponteiroEncadeado) << "\n";

        // Imprimir a lista 
        imprimeEncadeada(ponteiroEncadeado);
        
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