#include <iostream>
#include <fstream> // Biblioteca para manipulação de arquivos

using namespace std;

int main() {
    ifstream arquivo("arquivo.txt"); // Abre o arquivo para leitura

    string textoLido;

    for (string linha; getline(arquivo, linha);) { // Lê o arquivo linha por linha
        textoLido += linha + "\n"; // Adiciona a linha lida ao textoLido
    }
    cout << textoLido; // Imprime o conteúdo lido do arquivo
}