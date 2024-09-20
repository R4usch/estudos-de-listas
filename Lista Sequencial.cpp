/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{

    const int tamanhoDaLista = 10;
    int lista[tamanhoDaLista] = { 3,5,4,5,6,7,8,9,10,11 };
    int currentIndex = 3;


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
        switch (opcao) {
        case 1:
            cout << "Primeiro elemento e: " << lista[0] << endl;
            break;
        case 2:
            cout << "Ultimo elemento e: " << lista[tamanhoDaLista - 1] << endl;
            break;
        case 3:
            cout << "Escolha o elemento: ";
            cin >> elementoEscolhido;
            if (elementoEscolhido < 0 || elementoEscolhido > tamanhoDaLista) {
                cout << "Elemento invalido" << endl;
                break;
            }
            for (int i = elementoEscolhido; i < tamanhoDaLista; i++) {
                cout << "[" << i + 1 << "]" << lista[i] << endl;
            }
            break;
        case 4:
            cout << "Existem " << tamanhoDaLista << " elementos na lista" << endl;
            break;
        case 5:
            cout << "Escolha o elemento: ";
            cin >> elementoEscolhido;

            if (elementoEscolhido < 0) {
                cout << "Elemento invalido" << endl;
                break;
            }
            {
                bool encontrou = false;
                for (int i = 0; i < tamanhoDaLista; i++) {
                    if (lista[i] == -1) {
                        currentIndex = i;
                        encontrou = true;
                    }
                } 

                if (!encontrou) {
                    cout << "A lista encheu!" << endl;
                    break;
                }
            }
            
            if (lista[currentIndex] == -1) {
                lista[currentIndex] = elementoEscolhido;
            }



            break;
        case 6:
            cout << "Escolha o elemento: ";
            cin >> elementoEscolhido;

            if (elementoEscolhido < 0 || elementoEscolhido > 9) {
                cout << "Elemento invalido" << endl;
                break;
            }
            else {
                bool encontrou = false;
                int i = 0;
                for (i = 0; i < tamanhoDaLista; i++) {

                    if (lista[i] == elementoEscolhido) {
                        lista[i] = -1;
                        encontrou = true;
                        break;
                    }
                }
                // Organize a lista
                if (encontrou) {
                    for (int v = i; v < tamanhoDaLista; v++) {
                        bool limpa = false;
                        if (lista[v] == -1) {
                            for (int u = v+1; u < tamanhoDaLista; u++) {
                                cout << u << "/" << v << endl;;
                                if (lista[u] != -1) {
                                    lista[v] = lista[u];
                                    lista[u] = -1;
                                    break;
                                }
                            }
                        }
                        if (limpa) break;
                    }
                }
            }

            break;
        }
    } while (true);

    return 0;
}