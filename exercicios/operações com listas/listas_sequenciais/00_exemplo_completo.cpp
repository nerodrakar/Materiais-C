#include <iostream>
#include <string>

using namespace std;

// Cada registro representa uma pessoa da lista sequencial.
struct listaPessoa {
    string nome;
    int rg;
};


// Função 08: exibir todos os elementos da lista.
void imprimeSequencial(const listaPessoa *lista, int tamanhoLista) {
    if (tamanhoLista == 0) {
        cout << "Lista vazia!\n";
        return;
    }

    for (int i = 0; i < tamanhoLista; i++) {
        cout << i << " - " << lista[i].nome
             << " | RG: " << lista[i].rg << "\n";
    }
}


// Função 01: inserir uma pessoa no início da lista.
void funcao01(listaPessoa *&lista, int *tamanhoLista,
              const string &nome, int rg) {
    listaPessoa *nova = new listaPessoa[*tamanhoLista + 1];

    nova[0] = {nome, rg};  // A nova pessoa ocupa o índice 0.

    for (int i = 0; i < *tamanhoLista; i++) {
        nova[i + 1] = lista[i]; // Antigos elementos avançam uma posição.
    }

    delete[] lista;        // Libera o vetor antigo (aceita nullptr).
    lista = nova;          // *& permite atualizar o ponteiro original.
    (*tamanhoLista)++;     // Atualiza o tamanho fora da função.
}


// Função 02: inserir uma pessoa no final da lista.
void funcao02(listaPessoa *&lista, int *tamanhoLista,
              const string &nome, int rg) {
    listaPessoa *nova = new listaPessoa[*tamanhoLista + 1];

    for (int i = 0; i < *tamanhoLista; i++) {
        nova[i] = lista[i]; // Mantém as posições dos elementos antigos.
    }

    nova[*tamanhoLista] = {nome, rg}; // Ocupa o último índice.

    delete[] lista;
    lista = nova;
    (*tamanhoLista)++;
}


// Função 03: inserir uma pessoa na posição informada.
// Retorna false quando a posição não existe para inserção.
bool funcao03(listaPessoa *&lista, int *tamanhoLista,
              const string &nome, int rg, int posicao) {
    if (posicao < 0 || posicao > *tamanhoLista) {
        return false; // Para inserir, são válidos 0 até tamanhoLista.
    }

    listaPessoa *nova = new listaPessoa[*tamanhoLista + 1];

    for (int i = 0; i < posicao; i++) {
        nova[i] = lista[i]; // Copia os elementos anteriores à posição.
    }

    nova[posicao] = {nome, rg}; // Insere o novo elemento.

    for (int i = posicao; i < *tamanhoLista; i++) {
        nova[i + 1] = lista[i]; // Desloca o restante para a direita.
    }

    delete[] lista;
    lista = nova;
    (*tamanhoLista)++;
    return true;
}


// Função 04: remover a primeira pessoa da lista.
bool funcao04(listaPessoa *&lista, int *tamanhoLista) {
    if (*tamanhoLista == 0) return false; // Não remove de lista vazia.

    int novoTamanho = *tamanhoLista - 1;
    listaPessoa *nova = (novoTamanho > 0)
        ? new listaPessoa[novoTamanho] : nullptr;

    for (int i = 0; i < novoTamanho; i++) {
        nova[i] = lista[i + 1]; // Ignora o índice 0 do vetor antigo.
    }

    delete[] lista;
    lista = nova; // nullptr se a lista ficou vazia.
    *tamanhoLista = novoTamanho;
    return true;
}


// Função 05: remover a última pessoa da lista.
bool funcao05(listaPessoa *&lista, int *tamanhoLista) {
    if (*tamanhoLista == 0) return false;

    int novoTamanho = *tamanhoLista - 1;
    listaPessoa *nova = (novoTamanho > 0)
        ? new listaPessoa[novoTamanho] : nullptr;

    for (int i = 0; i < novoTamanho; i++) {
        nova[i] = lista[i]; // Copia tudo, menos o último elemento.
    }

    delete[] lista;
    lista = nova;
    *tamanhoLista = novoTamanho;
    return true;
}


// Função 06: remover a pessoa da posição informada.
bool funcao06(listaPessoa *&lista, int *tamanhoLista, int posicao) {
    if (*tamanhoLista == 0 ||
        posicao < 0 || posicao >= *tamanhoLista) {
        return false; // Para remover, índices válidos: 0 a tamanho-1.
    }

    int novoTamanho = *tamanhoLista - 1;
    listaPessoa *nova = (novoTamanho > 0)
        ? new listaPessoa[novoTamanho] : nullptr;

    for (int i = 0; i < novoTamanho; i++) {
        // Antes da posição: mesmo índice. Depois: pula um índice antigo.
        nova[i] = (i < posicao) ? lista[i] : lista[i + 1];
    }

    delete[] lista;
    lista = nova;
    *tamanhoLista = novoTamanho;
    return true;
}


// Função 07: buscar a primeira pessoa com o RG informado.
string funcao07(const listaPessoa *lista, int tamanhoLista, int rg) {
    for (int i = 0; i < tamanhoLista; i++) {
        if (lista[i].rg == rg) {
            return lista[i].nome; // Encontrou: encerra a busca.
        }
    }
    return "Não encontrado!";
}


// Auxiliar do menu: lê nome (inclusive com espaços) e RG.
bool lerPessoa(string &nome, int &rg) {
    cout << "Nome: ";
    if (!getline(cin >> ws, nome)) return false;
    cout << "RG: ";
    return static_cast<bool>(cin >> rg);
}


int main() {
    listaPessoa *ponteiroSequencial = nullptr; // Lista começa vazia.
    int tamanhoLista = 0;
    int opcao = 0;

    while (true) {
        cout << "\n=== OPERACOES COM LISTAS SEQUENCIAIS ===\n"
             << "1 - Inserir no inicio\n"
             << "2 - Inserir no fim\n"
             << "3 - Inserir na posicao N\n"
             << "4 - Remover do inicio\n"
             << "5 - Remover do fim\n"
             << "6 - Remover da posicao N\n"
             << "7 - Buscar por RG\n"
             << "8 - Imprimir lista\n"
             << "9 - Sair\n"
             << "Opcao: ";

        if (!(cin >> opcao)) break; // Encerra se a leitura falhar.
        if (opcao == 9) break;

        string nome;
        int rg = 0;
        int posicao = 0;

        switch (opcao) {
            case 1:
            case 2:
            case 3:
                if (!lerPessoa(nome, rg)) {
                    cout << "Dados invalidos.\n";
                    break;
                }
                if (opcao == 1) {
                    funcao01(ponteiroSequencial, &tamanhoLista, nome, rg);
                } else if (opcao == 2) {
                    funcao02(ponteiroSequencial, &tamanhoLista, nome, rg);
                } else {
                    cout << "Posicao de insercao: ";
                    if (!(cin >> posicao) ||
                        !funcao03(ponteiroSequencial, &tamanhoLista,
                                  nome, rg, posicao)) {
                        cout << "Posicao invalida.\n";
                    }
                }
                break;
            case 4:
                if (!funcao04(ponteiroSequencial, &tamanhoLista)) {
                    cout << "Lista vazia!\n";
                }
                break;
            case 5:
                if (!funcao05(ponteiroSequencial, &tamanhoLista)) {
                    cout << "Lista vazia!\n";
                }
                break;
            case 6:
                cout << "Posicao para remocao: ";
                if (!(cin >> posicao) ||
                    !funcao06(ponteiroSequencial, &tamanhoLista, posicao)) {
                    cout << "Posicao invalida ou lista vazia.\n";
                }
                break;
            case 7:
                cout << "RG procurado: ";
                if (cin >> rg) {
                    cout << funcao07(ponteiroSequencial, tamanhoLista, rg)
                         << "\n";
                }
                break;
            case 8:
                imprimeSequencial(ponteiroSequencial, tamanhoLista);
                break;
            default:
                cout << "Opcao invalida.\n";
                break;
        }
    }

    delete[] ponteiroSequencial; // Libera a última alocação.
    return 0;
}
