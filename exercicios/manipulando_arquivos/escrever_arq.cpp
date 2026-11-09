#include <iostream>
#include <stdio.h>
#include <fstream> // Biblioteca para manipulação de arquivos

using namespace std;

int main(){
    // Função para criar o ojeto de arquivo e escrever nele
    ofstream arquivoDeSaida;

    // Abrindo o arquivo para escrita
    arquivoDeSaida.open("arquivo.txt", std::ios_base::app); // Abre o arquivo "arquivo.txt"

    // Escrevendo no arquivo
    arquivoDeSaida << "Olá, mundo!"; // Escreve "Olá, mundo!" no arquivo

    // Fechando o arquivo
    arquivoDeSaida.close(); // Fecha o arquivo

    return 0;
}
