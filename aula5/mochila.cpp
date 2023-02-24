#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct item {
    int id;
    int peso;
    int valor;
};

bool compara(item a, item b) {
    return a.valor > b.valor;
}

void mais_pesado(vector<item> itens, int N, int W) {
    sort(itens.begin(), itens.end(), compara);
        
        int peso = 0;
        int valor = 0;
        vector<int> selecionados;
        for (int i = 0; i < N; i++) {
            if (peso + itens[i].peso <= W) {
                peso += itens[i].peso;
                valor += itens[i].valor;
                selecionados.push_back(itens[i].id);
            }
        }
        cout << peso << " " << valor << " " << 0 << endl;

        for (int i = 0; i < int (selecionados.size()); i++) {
            cout << selecionados[i] << " ";
        }

        cout << endl;
}

bool compara_leve(item a, item b) {
    return a.peso < b.peso;
}

void mais_leve(vector<item> itens, int N, int W) {
    sort(itens.begin(), itens.end(), compara_leve);
        
        int peso = 0;
        int valor = 0;
        vector<int> selecionados;
        for (int i = 0; i < N; i++) {
            if (peso + itens[i].peso <= W) {
                peso += itens[i].peso;
                valor += itens[i].valor;
                selecionados.push_back(itens[i].id);
            }
        }
        cout << peso << " " << valor << " " << 0 << endl;

        for (int i = 0; i < int (selecionados.size()); i++) {
            cout << selecionados[i] << " ";
        }

        cout << endl;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<item> itens(N);
    for (int i = 0; i < N; i++) {
        itens[i].id = i;
        cin >> itens[i].peso >> itens[i].valor;
    }

    cout << "Mais pesado:" << endl;
    mais_pesado(itens, N, W);
    cout << "Mais leve:" << endl;
    mais_leve(itens, N, W);

    return 0;
}

