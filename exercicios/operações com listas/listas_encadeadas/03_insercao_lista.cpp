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

    // Verifica se a lista esta vazia
    if(ponteiroEncadeado -> nome == ""){
        return 0;
    }

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


void funcao01(pessoa *&ponteiroEncadeado, string nome, int rg){
    // Criando uma nova lista 
    pessoa *novoValor = new pessoa;
    novoValor -> nome = nome;
    novoValor -> rg = rg;

    // Verifica se a lista está vazia
    if(ponteiroEncadeado -> nome == ""){
        novoValor -> proximo = NULL;
    } else {
        novoValor -> proximo = ponteiroEncadeado;
    }

    // Atualiza o início da lista 
    ponteiroEncadeado = novoValor;
}


void funcao02(pessoa *&ponteiroEncadeado, string nome, int rg){
    // Criando uma nova lista 
    pessoa *novoValor = new pessoa;
    novoValor -> nome = nome;
    novoValor -> rg = rg; 
    novoValor -> proximo = NULL;

    pessoa *p = ponteiroEncadeado;

    while (p != NULL){
        // Quando chegar no ultimo elemento faz ele apontar para o novo valor 
        if(p -> proximo == NULL){
            p -> proximo = novoValor;
            
            return;
        }

        // Atualiza o cursor
        p = p -> proximo;
    }

}


void funcao03(pessoa *&ponteiroEncadeado, string nome, int rg, int posicao){
    // Criando uma nova lista 
    pessoa *novoValor = new pessoa;
    novoValor -> nome = nome;
    novoValor -> rg = rg; 
    novoValor -> proximo = NULL;

    pessoa *p = ponteiroEncadeado;
    
    // Navegar até uma posição antes da posição desejada 
    int i =0;
    while(i <= posicao){
        
        if(i == posicao - 1){
            // Criar um auxiliar 
            pessoa *aux = new pessoa; 
            aux -> proximo = p -> proximo;    // Armazena a posicao do proximo valor
            
            // Adiciona o novo valor na posicao desejada
            p -> proximo = novoValor;
            
            // Faz o novo valor apontar para o proximo
            novoValor -> proximo = aux -> proximo;

            free(aux); 
        }

        // Atualiza o cursor
        p = p -> proximo;

        i++;
    }
}


int main(){
    // Variáveis
    int funcaoDesejada = 1;

    // Criando o inicio da lista encadeada (ponteiro principal)
    pessoa *ponteiroEncadeado = new pessoa;
    ponteiroEncadeado -> nome = "";
    ponteiroEncadeado -> rg = 0;
    ponteiroEncadeado -> proximo = NULL;

    // // Criando um exemplo 
    // pessoa *novoValor = new pessoa;

    // novoValor -> nome = "Pedro";
    // novoValor -> rg = 123;
    // novoValor -> proximo = NULL;

    // // Transformar o ponteiro do inicio da lista no novo valor 
    // ponteiroEncadeado = novoValor;
    
    // // Criando novo valor
    // pessoa *novoSegValor = new pessoa;

    // novoSegValor -> nome = "Joao";
    // novoSegValor -> rg = 456;
    // novoSegValor -> proximo = NULL;

    // // Apontar o ponteiro do primeiro valor para o segundo
    // novoValor -> proximo = novoSegValor;

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
        cout << "\nTamanho atual: " << retornaTamanho(ponteiroEncadeado) << "\n";

        // Imprimir a lista 
        if(retornaTamanho(ponteiroEncadeado) == 0){
            cout << "Lista vazia!\n";
        } else {
            imprimeEncadeada(ponteiroEncadeado); 
        }      
        cout << "\nEscolha um numero e pressione ENTER \n"; 

        
        cin >> funcaoDesejada;
        
        limpaTela();

        // Variáveis 
        string nome;
        int rg, posicao;

        switch (funcaoDesejada){
            case 1:
                cout << "Funcao escolhida: 1 - Insercao de node no inicio da lista\n";
                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                funcao01(ponteiroEncadeado, nome, rg);

                break;
            case 2:
                cout << "Funcao escolhida: 2 - Insercao de um node no fim do lista \n";
                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(retornaTamanho(ponteiroEncadeado) == 0){
                    funcao01(ponteiroEncadeado, nome, rg);
                } else {
                    funcao02(ponteiroEncadeado, nome, rg);
                }

                break;
            
            case 3: 
                cout << "Funcao escolhida: 3 - Insercao de um node na posicao N\n";
                cout << "Digite a posicao: ";
                cin >> posicao;
                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(posicao == 0){
                    funcao01(ponteiroEncadeado, nome, rg);
                } else if(posicao == retornaTamanho(ponteiroEncadeado) -1 ) {
                    funcao02(ponteiroEncadeado, nome, rg);
                } else {
                    funcao03(ponteiroEncadeado, nome, rg, posicao);
                }

                break;
        }

    }
}