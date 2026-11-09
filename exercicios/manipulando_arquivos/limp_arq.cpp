#include <iostream>
#include <fstream> // Biblioteca para manipulação de arquivos

using namespace std;

int main() {
    ofstream arquivoDeSaida;

    // Abrindo o arquivo para escrita, sobrescrevendo o conteúdo existente
    arquivoDeSaida.open("arquivo.txt");

    arquivoDeSaida << ""; // Escrevendo uma string vazia para limpar o conteúdo do arquivo
    arquivoDeSaida.close(); // Fechando o arquivo
    return 0;
}