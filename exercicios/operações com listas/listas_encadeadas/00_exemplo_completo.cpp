#include <iostream>
#include <string>

using namespace std;

// Cada no guarda os dados de uma pessoa e o endereco do proximo no.
struct pessoa {
    string nome;
    int rg;
    pessoa *proximo;
};

// Conta os nos. Lista vazia (nullptr) tem tamanho zero.
int retornaTamanho(const pessoa *inicio) {
    int tamanho = 0;
    const pessoa *atual = inicio;

    while (atual != nullptr) {
        tamanho++;
        atual = atual->proximo;
    }

    return tamanho;
}

// Percorre a lista sem alterar o ponteiro inicial.
void imprimeEncadeada(const pessoa *inicio) {
    if (inicio == nullptr) {
        cout << "Lista vazia!\n";
        return;
    }

    const pessoa *atual = inicio;
    int posicao = 0;

    while (atual != nullptr) {
        cout << posicao << " - " << atual->nome
             << " | RG: " << atual->rg << '\n';
        atual = atual->proximo;
        posicao++;
    }
}

// Funcao 01: insere um no no inicio. O ponteiro inicial muda.
void funcao01(pessoa *&inicio, const string &nome, int rg) {
    pessoa *novo = new pessoa;
    novo->nome = nome;
    novo->rg = rg;
    novo->proximo = inicio;  // Aponta para o primeiro no anterior.
    inicio = novo;           // Atualiza o inicio da lista.
}

// Funcao 02: insere um no no fim. Tambem funciona com lista vazia.
void funcao02(pessoa *&inicio, const string &nome, int rg) {
    pessoa *novo = new pessoa;
    novo->nome = nome;
    novo->rg = rg;
    novo->proximo = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
        return;
    }

    pessoa *atual = inicio;
    while (atual->proximo != nullptr) {
        atual = atual->proximo;
    }
    atual->proximo = novo;  // O antigo ultimo no aponta para o novo.
}

// Funcao 03: insere na posicao indicada (0 ate tamanho, inclusive).
// Retorna false se a posicao nao existir.
bool funcao03(pessoa *&inicio, const string &nome, int rg, int posicao) {
    if (posicao < 0) {
        return false;
    }
    if (posicao == 0) {
        funcao01(inicio, nome, rg);
        return true;
    }

    pessoa *anterior = inicio;
    for (int i = 0; i < posicao - 1 && anterior != nullptr; i++) {
        anterior = anterior->proximo;
    }
    if (anterior == nullptr) { // Posicao alem do fim da lista.
        return false;
    }

    pessoa *novo = new pessoa;
    novo->nome = nome;
    novo->rg = rg;
    novo->proximo = anterior->proximo; // Nao perde o restante da lista.
    anterior->proximo = novo;          // Conecta o anterior ao novo no.
    return true;
}

// Funcao 04: remove o primeiro no e libera sua memoria.
bool funcao04(pessoa *&inicio) {
    if (inicio == nullptr) {
        return false;
    }

    pessoa *remover = inicio;
    inicio = inicio->proximo; // O segundo no passa a ser o primeiro.
    delete remover;
    return true;
}

// Funcao 05: remove o ultimo no e libera sua memoria.
bool funcao05(pessoa *&inicio) {
    if (inicio == nullptr) {
        return false;
    }
    if (inicio->proximo == nullptr) {
        return funcao04(inicio); // Lista com apenas um no.
    }

    pessoa *atual = inicio;
    while (atual->proximo->proximo != nullptr) {
        atual = atual->proximo; // Para no penultimo no.
    }

    delete atual->proximo;     // Apaga o ultimo no.
    atual->proximo = nullptr;  // O penultimo torna-se o ultimo.
    return true;
}

// Funcao 06: remove o no de indice posicao.
bool funcao06(pessoa *&inicio, int posicao) {
    if (posicao < 0 || inicio == nullptr) {
        return false;
    }
    if (posicao == 0) {
        return funcao04(inicio);
    }

    pessoa *anterior = inicio;
    for (int i = 0; i < posicao - 1 && anterior != nullptr; i++) {
        anterior = anterior->proximo;
    }
    if (anterior == nullptr || anterior->proximo == nullptr) {
        return false;
    }

    pessoa *remover = anterior->proximo;
    anterior->proximo = remover->proximo; // Pula o no a ser removido.
    delete remover;
    return true;
}

// Funcao 07: busca linear por RG. Nao modifica a lista.
string funcao07(const pessoa *inicio, int rg) {
    const pessoa *atual = inicio;
    while (atual != nullptr) {
        if (atual->rg == rg) {
            return atual->nome;
        }
        atual = atual->proximo;
    }
    return "Nao encontrado";
}

// Libera todos os nos antes de encerrar o programa.
void limpaLista(pessoa *&inicio) {
    while (inicio != nullptr) {
        funcao04(inicio);
    }
}

void imprimeMenu() {
    cout << "\n=== LISTA ENCADEADA ===\n"
         << "1 - Inserir no inicio\n"
         << "2 - Inserir no fim\n"
         << "3 - Inserir na posicao N\n"
         << "4 - Remover do inicio\n"
         << "5 - Remover do fim\n"
         << "6 - Remover da posicao N\n"
         << "7 - Buscar por RG\n"
         << "8 - Imprimir a lista\n"
         << "9 - Sair\n"
         << "Escolha: ";
}

int main() {
    pessoa *ponteiroEncadeado = nullptr; // Lista inicialmente vazia.
    int opcao;

    while (true) {
        cout << "\nTamanho atual: " << retornaTamanho(ponteiroEncadeado) << '\n';
        imprimeMenu();

        if (!(cin >> opcao) || opcao == 9) {
            break;
        }

        string nome;
        int rg = 0;
        int posicao = 0;
        bool sucesso = true;

        switch (opcao) {
            case 1:
            case 2:
            case 3:
                cout << "Nome: ";
                getline(cin >> ws, nome);  // Aceita nomes com espacos.
                cout << "RG: ";
                cin >> rg;
                if (opcao == 1) {
                    funcao01(ponteiroEncadeado, nome, rg);
                } else if (opcao == 2) {
                    funcao02(ponteiroEncadeado, nome, rg);
                } else {
                    cout << "Posicao (iniciando em 0): ";
                    cin >> posicao;
                    sucesso = funcao03(ponteiroEncadeado, nome, rg, posicao);
                }
                cout << (sucesso ? "Insercao realizada.\n" : "Posicao invalida.\n");
                break;

            case 4:
                cout << (funcao04(ponteiroEncadeado) ? "Removido.\n" : "Lista vazia.\n");
                break;
            case 5:
                cout << (funcao05(ponteiroEncadeado) ? "Removido.\n" : "Lista vazia.\n");
                break;
            case 6:
                cout << "Posicao a remover: ";
                cin >> posicao;
                cout << (funcao06(ponteiroEncadeado, posicao)
                             ? "Removido.\n" : "Posicao invalida.\n");
                break;
            case 7:
                cout << "RG para busca: ";
                cin >> rg;
                cout << "Resultado: " << funcao07(ponteiroEncadeado, rg) << '\n';
                break;
            case 8:
                imprimeEncadeada(ponteiroEncadeado);
                break;
            default:
                cout << "Opcao invalida.\n";
        }

        if (!cin) { // Evita continuar com dados de entrada invalidos.
            break;
        }
    }

    limpaLista(ponteiroEncadeado);
    return 0;
}
