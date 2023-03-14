#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bitset>

using namespace std;

struct Filme {
    int id;
    int inicio;
    int fim;
    int categoria;
    std::bitset<24> horario;
};

struct Categoria {
    int id;
    int quantidade;
};

struct Maratona {
    std::bitset<24> disponibilidade;
    std::vector<Filme> filmes;
};

bool compara_filme(Filme a, Filme b) {
    return a.fim < b.fim;
}

std::bitset<24> gera_horario(int inicio, int fim) {
    std::bitset<24> horario;

    if (inicio == fim) {
        horario.set(inicio);
        return horario;
    }
    
    for (int i = inicio; i < fim; i++) {
        horario.set(i);
    }

    return horario;
}

void heuristica_gulosa(vector<Filme> &filmes, vector<Categoria> &categorias, Maratona &maratona) {
    int maximo = 0;
    int size_of_filmes = filmes.size();
    int size_of_categorias = categorias.size();

    for 

    cout << maximo << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Filme> filmes(n);
    vector<Categoria> categorias(m);
    Maratona maratona;
    
    for (int i = 0; i < m; i++) {
        cin >> categorias[i].quantidade;
        categorias[i].id = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int inicio, fim, categoria;
        cin >> inicio >> fim >> categoria;

        if (inicio > fim) {
            if (fim == 0){
                fim = 24;
            } else {
                continue;
            }
        }

        Filme filme;
        filme.id = i + 1;
        filme.inicio = inicio;
        filme.fim = fim;
        filme.categoria = categoria;
        filme.horario = gera_horario(inicio, fim);

        filmes.push_back(filme);
    }

    sort(filmes.begin(), filmes.end(), compara_filme);

    int size_of_filmes = filmes.size();

    heuristica_gulosa(filmes, categorias, maratona);

    return 0;

}
