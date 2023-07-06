#include <iostream>
#include <random>
#include <vector>
#include <chrono>

// Impotando somente o necessario
using std::vector;
using std::cout;
using std::endl;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

#define DEBUG    false
#define DEBUG_1  false
#define DEBUG_2  false

vector<int> tamanhoDoArray = {10, 100, 1000, 10000, 50000, 60000};
//vector<int> tamanhoDoArray = {10};

void CriarLista( int tamanhoDoArray, vector<int>& arrayInicial )
{
    for (int i = 0; i < tamanhoDoArray; i++)
    {
        arrayInicial[i] = i + 1;
    }
}

void Inverter(const vector<int> &arrayInicial, vector<int> &arrayFinal, int tamanhoDoArray )
{
    vector<int> Y(arrayInicial.begin(), arrayInicial.end());
    vector<vector<int>> Y_intermediarios(tamanhoDoArray);

    // "Decida" 
    for (int i = 0; i < tamanhoDoArray; i++)
    {
        if (DEBUG_1)
        {
            for (const auto &num : Y)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        
        int X = Y.front();
        Y_intermediarios[i].push_back(X);
        Y.erase(Y.begin());
    }

    // "Subida"
    for (int i = tamanhoDoArray - 1; i > 0; i--)
    {
        if (DEBUG_1)
        {
            for (const auto &num : Y_intermediarios[i])
            {
                cout << num << " ";
            }
            cout << endl;
        }

        Y_intermediarios[i - 1].insert(
            Y_intermediarios[i - 1].begin(),
            Y_intermediarios[i].begin(),
            Y_intermediarios[i].end());
    }

    if (DEBUG_1)
    {
        for (const auto &num : Y_intermediarios[0])
        {
            cout << num << " ";
        }
        cout << endl;
    }

    // Resultado final esta em Y0
    arrayFinal = Y_intermediarios[0];
}

void InverterOtimizado(const vector<int> &arrayInicial, vector<int> &arrayFinal, int tamanhoDoArray)
{
    // aux(ListaAux, L, arrayFinal[Y])
    vector<int> L(arrayInicial.begin(), arrayInicial.end());
    vector<int> ListaAux;

    // "Subida"
    for (int i = tamanhoDoArray; i > 0; i--)
    {
        // Adiciona o primeiro elemento da lista inicial na lista auxiliar
        // ListaAux.push_back(L.front());
        ListaAux.insert(ListaAux.begin(), L.front());

        // Retira o primeiro elemento da lista
        L.erase(L.begin());

        if ( DEBUG_2 )
        {
            for (const auto &num : ListaAux)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    // aux(ListaAux, L, arrayFinal[Y])
    arrayFinal = ListaAux;
}

int main() {

    cout << "\n| Trabalho 4 de Inteligencia Artificial" << endl;
    cout << "| Aluno: Lucas Araujo Pena - 130056162" << endl;
    cout << "| Analise de desempenho de algoritmos de inversao." << endl;
    cout << "---------------------------------------------------\n" << endl;

    vector<int> arrayInicial;
    vector<int> arrayFinal;

    cout << "> Calculando tempo de execucao para a Inversao 1..." << endl;
    for (size_t i = 0; i < tamanhoDoArray.size(); i++)
    {

        arrayInicial.resize(tamanhoDoArray[i]);
        arrayFinal.resize(tamanhoDoArray[i]);

        // Comeca o Timer
        auto start = std::chrono::high_resolution_clock::now();

        CriarLista(tamanhoDoArray[i], arrayInicial);
        Inverter(arrayInicial, arrayFinal, tamanhoDoArray[i]);

        // Para o Timer
        auto end = std::chrono::high_resolution_clock::now();

        // Calcula a duracao da funcao
        std::chrono::duration<double> duration = end - start;

        if( DEBUG )
        {
            cout << endl;
            // Print the generated array
            for (const auto &num : arrayInicial)
            {
                cout << num << " ";
            }
            cout << endl;

            // Print the generated array
            for (const auto &num : arrayFinal)
            {
                cout << num << " ";
            }
            cout << endl;
        }

        // Mostra a duracao da execusao
        cout << "\n> Tempo de execucao para " << tamanhoDoArray[i] <<" elementos: " << duration.count() * 1000.0 << " milisegundos" << endl;
    }

    cout << "\n---------------------------------------------------" << endl;

    cout << "\n> Calculando tempo de execucao para a Inversao 2..." << endl;
    for (size_t i = 0; i < tamanhoDoArray.size(); i++)
    {

        arrayInicial.resize(tamanhoDoArray[i]);
        arrayFinal.resize(tamanhoDoArray[i]);

        // Comeca o Timer
        auto start = std::chrono::high_resolution_clock::now();

        CriarLista(tamanhoDoArray[i], arrayInicial);
        InverterOtimizado(arrayInicial, arrayFinal, tamanhoDoArray[i]);

        // Para o Timer
        auto end = std::chrono::high_resolution_clock::now();

        // Calcula a duracao da funcao
        std::chrono::duration<double> duration = end - start;

        if (DEBUG)
        {
            cout << endl;
            // Print the generated array
            for (const auto &num : arrayInicial)
            {
                cout << num << " ";
            }
            cout << endl;

            // Print the generated array
            for (const auto &num : arrayFinal)
            {
                cout << num << " ";
            }
            cout << endl;
        }

        // Mostra a duracao da execusao
        cout << "\n> Tempo de execucao para " << tamanhoDoArray[i] << " elementos: " << duration.count() * 1000.0 << " milisegundos" << endl;
    }

    return 0;
}
