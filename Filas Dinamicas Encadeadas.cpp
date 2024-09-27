#include <iostream>
#include <string>
using namespace std;

class FilaEncadeadaString {
    class Item {
    public:
        Item* Proximo = nullptr;
        string valor;
    };

private:
    Item* PrimeiroItem = nullptr;

public:
    FilaEncadeadaString() {}
    int tamanho = 0;


    void Adicionar(string texto) {
        Item* novoItem = new Item;
        novoItem->valor = texto;

        if (PrimeiroItem == nullptr) {
            PrimeiroItem = novoItem;
        }
        else {
            Item* currentItem = PrimeiroItem;
            while (currentItem->Proximo != nullptr) {
                currentItem = currentItem->Proximo;
            }
            currentItem->Proximo = novoItem;
        }
        tamanho++;
    }

    string Remover(string texto) {
        if (PrimeiroItem == nullptr) {
            cout << "A lista esta vazia" << endl;
            return "NULL";
        }

        Item* originalItem = PrimeiroItem;

        string resultado;
        resultado = PrimeiroItem->valor;
        if (PrimeiroItem->Proximo == nullptr) {
            PrimeiroItem = nullptr;
            delete originalItem;
            return resultado;
        }

        PrimeiroItem = PrimeiroItem->Proximo;
        delete originalItem;
        
        tamanho--;
        

        return resultado;
    }

    string* Intervalo(int primeiro, int segundo) {
        if (PrimeiroItem == nullptr) {
            cout << "A lista esta vazia" << endl;;
            return 0;
        }
        if (primeiro > tamanho) {
            cout << "Primeiro numero e maior que o tamanho da lista";
            return 0;
        }
        if (segundo > tamanho) {
            cout << "Segundo numero e maior que o tamanho da lista";
            return 0;
        }

        const int size = segundo - primeiro;
        int counter = 0;
        Item* currentItem = PrimeiroItem;
        string* retorno = new string[size];
        do {
            if (counter < primeiro) {
                currentItem = currentItem->Proximo;
                counter++;
            }
            else {
                for (int i = 0; i < size; i++) {
                    //cout << "Opa" << endl;
                    if (currentItem == nullptr) break;
                    retorno[i] = currentItem->valor;
                    currentItem = currentItem->Proximo;
                    
                }
                break;
            }
        } while (true);
        return retorno;
    }

    string Primeiro() {
        if (PrimeiroItem == nullptr) {
            cout << "A lista está vazia";
            return 0;
        }
        else {
            return PrimeiroItem->valor;
        }

    }
    string Ultimo() {
        if (PrimeiroItem == nullptr) {
            cout << "A lista está vazia";
            return "NULL";
        }
        Item* currentItem = PrimeiroItem;
        do {
            if (currentItem->Proximo == nullptr) {
                return currentItem->valor;
            }
            else {
                currentItem = currentItem->Proximo;
            }
        } while (true);
    }
};

int main()
{
    FilaEncadeadaString lista;

    lista.Adicionar("Opa!");
    lista.Adicionar("Tudo bem?");
    lista.Adicionar("E voce?");
    lista.Adicionar("Estou bem");
    lista.Adicionar("Que otimo!");

    do {
        cout << "========================================================" << endl;
        cout << "1)Mostre o primeiro elemento da lista" << endl;
        cout << "2)Mostre o ultimo elemento da lista" << endl;
        cout << "3)Mostre quais elementos sucedem um determinado elemento" << endl;
        cout << "4)Mostre quantos elementos existem na lista" << endl;
        cout << "5)Inclua um elemento na lista" << endl;
        cout << "6)Exclua um elemento da lista" << endl;
        cout << "========================================================" << endl;
        int opcao = 0;

        cout << "Digite o numero: ";
        cin >> opcao;

        int elementoEscolhido = 0;

        string stringSelecionada;
        switch (opcao) {
        case 1:
            cout << "Primeiro elemento e: " << lista.Primeiro() << endl;
            break;
        case 2:
            cout << "Ultimo elemento e: " << lista.Ultimo() << endl;
            break;
        case 3:
            cout << "Escolha o elemento: ";
            cin >> elementoEscolhido;
            {
                string* intervalo = lista.Intervalo(elementoEscolhido, lista.tamanho);
                if (intervalo != 0) {
                    for (int i = 0; i < (lista.tamanho - elementoEscolhido); i++) {
                        cout << "[" << i << "]" << intervalo[i] << endl;
                    }

                }
            }

            break;
        case 4:
            cout << "Existem " << lista.tamanho << " elementos na lista" << endl;
            break;
        case 5:
            cout << "Digite a string: ";
            cin.ignore();
            std::getline(cin, stringSelecionada);
            lista.Adicionar(stringSelecionada);

            break;
        case 6:
            {
                string item = lista.Remover(stringSelecionada);
                cout << "Item removido e: " << item << endl;;
            }

            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }
    } while (true);

    return 0;
}