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

void funcao01(listaPessoa *&ponteiroSequencial, int *tamanhoLista, string nome, int rg){

    if(*tamanhoLista == 0){
        listaPessoa *novaListaSeq = new listaPessoa[1];

        novaListaSeq[0].nome = nome;
        novaListaSeq[0].rg = rg;

        ponteiroSequencial = novaListaSeq;

    } else {
        // Caso a lista já tenha membros, criamos uma nova lista com TAM+1
        listaPessoa *novaListaSeq = new listaPessoa[*tamanhoLista+1];

        // Insere o primeiro novo elemento
        novaListaSeq[0].nome = nome;
        novaListaSeq[0].rg = rg;

        // Passando os elementos do vetor antigo para o novo
        for(int i = 0; i < *tamanhoLista; i++){
            novaListaSeq[i+1].nome = ponteiroSequencial[i].nome;
            novaListaSeq[i+1].rg = ponteiroSequencial[i].rg;
        }

        // Atualizar o ponteiro para a lista nova 
        ponteiroSequencial = novaListaSeq;
    }        
    
    // Aumenta o tamanho da lista 
    *tamanhoLista = *tamanhoLista + 1;
}

void funcao02(listaPessoa *&ponteiroSequencial, int *tamanhoLista, string nome, int rg){
    // Cria uma lista com um tamanho maior 
    listaPessoa *novaListaSeq = new listaPessoa[*tamanhoLista+1];

    // Passando os elementos do vetor antigo para o novo com a ultima posição vazia
    for(int i = 0; i < *tamanhoLista; i++){
        novaListaSeq[i].nome = ponteiroSequencial[i].nome;
        novaListaSeq[i].rg = ponteiroSequencial[i].rg;
    }

    // Posicionar o ultimo elemento
    novaListaSeq[*tamanhoLista].nome = nome;
    novaListaSeq[*tamanhoLista].rg = rg;

    // Atualizar o ponteiro para a lista nova 
    ponteiroSequencial = novaListaSeq;

    // Aumenta o tamanho da lista 
    *tamanhoLista = *tamanhoLista + 1;
}

void funcao03(listaPessoa *&ponteiroSequencial, int *tamanhoLista, string nome, int rg, int posicao){
    // Cria uma lista com um tamanho maior 
    listaPessoa *novaListaSeq = new listaPessoa[*tamanhoLista+1];

    // Passa os elementos da lista antiga para a nova até chegar a posicao escolhida
    for(int i = 0; i < posicao; i++){
    novaListaSeq[i].nome = ponteiroSequencial[i].nome;
    novaListaSeq[i].rg = ponteiroSequencial[i].rg;
    }

    // Adiciona o novo elemento na posiçao correta 
    novaListaSeq[posicao].nome = nome;
    novaListaSeq[posicao].rg = rg;    

    // Coloca o resto dos valores antigos 
    for(int j = posicao + 1; j < *tamanhoLista + 1; j++){
        novaListaSeq[j].nome = ponteiroSequencial[j-1].nome;
        novaListaSeq[j].rg = ponteiroSequencial[j-1].rg;   
    }

    // Atualizar o ponteiro para a lista nova 
    ponteiroSequencial = novaListaSeq;

    // Aumenta o tamanho da lista 
    *tamanhoLista = *tamanhoLista + 1;
}



int main(){
    // Variáveis 
    int funcaoDesejada = 1;
    listaPessoa *ponteiroSequencial;    // Ponteiro para a lista sequencial 
    int tamanhoLista = 0;              // Tamanho da lista
    
    // // Exemplo
    // listaPessoa *exemploLista = new listaPessoa[1];
    
    // exemploLista[0].nome = "Baseado ENE";
    // exemploLista[0].rg = 123;
    
    // ponteiroSequencial = exemploLista;
    
    while(funcaoDesejada < 10 && funcaoDesejada > 0){
        // Imprime a lista completa 
        cout << "\n";
        imprimeSequencial(ponteiroSequencial, tamanhoLista);
        cout << "\n";

        cout << "Operações \n";
        cout << "1 - Insercao de node no inicio da lista\n";
        cout << "2 - Insercao de um node no fim do lista\n";
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

        // Variáveis usadas na operação  
        string nome;
        int rg, posicao;
        
        // Escolhendo a função desejada
        switch(funcaoDesejada){
            case 1:
                cout << "Funcao escolhida: 1 - Insercao de node no inicio da lista \n";

                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                funcao01(ponteiroSequencial, &tamanhoLista, nome, rg);

                break;
            case 2: 
                cout << "Funcao escolhida: 2 - Insercao de um node no fim do lista\n";
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                if(tamanhoLista == 0){
                    funcao01(ponteiroSequencial, &tamanhoLista, nome, rg);    // Se a lista for vazia usamos a função de criação inicial
                } else{
                    funcao02(ponteiroSequencial, &tamanhoLista, nome, rg);
                }

                break;
            
            case 3:
                cout << "Funcao escolhida: 3 - Insercao de um node na posicao N\n";
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;
                cout << "Digite a posicao: ";
                cin >> posicao;

                if(posicao == 0){
                    funcao01(ponteiroSequencial, &tamanhoLista, nome, rg);    // Se estiver adicionando na posicão inicial
                } else if(posicao == tamanhoLista){
                    funcao02(ponteiroSequencial, &tamanhoLista, nome, rg);    // Se escolher adicionar ao final da lista
                } else {
                    funcao03(ponteiroSequencial, &tamanhoLista, nome, rg, posicao);   // Adiciona em uma posicao específica
                }
                
                break;
        }
    }
}