#include <iostream>
#include <random>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;


// Cria uma lista aleatoria de numeros de tamanho e numero maximo tamanhoDoArray
void CriarListaAleatoria( size_t tamanhoDoArray, vector<int>& randomArray )
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, tamanhoDoArray);

    for (int i = 0; i < 1000; ++i)
    {
        randomArray[i] = dist(gen);
    }

}

void CriarLista( size_t tamanhoDoArray, vector<int>& arrayInicial )
{
    for (int i = 0; i < 1000; ++i)
    {
        arrayInicial[i] = i + 1;
    }
}

vector<int> Inverter(vector<int> &arrayInicial)
{

    vector<int>

    for (int i = 0; i < 1000; ++i)
    {
        arrayInicial[i] = i;
    }
}

int main() {

    size_t tamanhoDoArray = 1000;
    vector<int> arrayInicial(tamanhoDoArray);
    vector<int> arrayFinal(tamanhoDoArray);

    CriarLista(tamanhoDoArray, arrayInicial);
    Inverter(arrayInicial);

    // Print the generated array
    // for (const auto& num : randomArray) {
    //    cout << num << " ";
    // }
    // cout <<endl;

    return 0;
}
