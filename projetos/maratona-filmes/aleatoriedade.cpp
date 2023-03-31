#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <random>
#include <chrono>
#include <map>

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


void aleatoriedade(vector<Categoria> &categorias, Maratona &maratona, map<int, vector<Filme>> filmes_por_horario){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::binomial_distribution<int> distribution (1, 0.75);
    distribution(generator);

    bitset<24> mochila_cheia(0xFFFFFF);

    for (int i = 1; i <= 24; i++){
        if (maratona.disponibilidade == mochila_cheia){
            break;
        }

        if (filmes_por_horario[i].size() == 0){
            continue;
        }

        Filme filme_escolhido;

        srand(time(NULL));
        if (distribution(generator)){
            for (int j = 0; j < static_cast<int>(filmes_por_horario[i].size()); j++){
                if ((!(maratona.disponibilidade & filmes_por_horario[i][j].horario).any()) && (categorias[filmes_por_horario[i][j].categoria - 1].quantidade > 0)){
                    filme_escolhido = filmes_por_horario[i][j];
                    break;
                }

                filme_escolhido.id = -1;
            }
        } else {
            vector<Filme> filmes_disponiveis_no_horario;

            for (int j = 1; j < static_cast<int>(filmes_por_horario[i].size()); j++){
                if ((!(maratona.disponibilidade & filmes_por_horario[i][j].horario).any()) && (categorias[filmes_por_horario[i][j].categoria - 1].quantidade > 0)){
                    filmes_disponiveis_no_horario.push_back(filmes_por_horario[i][j]);
                }
            }

            if (filmes_disponiveis_no_horario.size() == 0){
                continue;
            }

            filme_escolhido = filmes_disponiveis_no_horario[rand() % filmes_disponiveis_no_horario.size()];
        }

        if (filme_escolhido.id == -1){
            continue;
        }

        maratona.disponibilidade |= filme_escolhido.horario;
        maratona.filmes.push_back(filme_escolhido);
        categorias[filme_escolhido.categoria - 1].quantidade--;        
    }

    cout << maratona.filmes.size() << endl;

    for (int i = 0; i < static_cast<int>(maratona.filmes.size()); i++){
        cout << maratona.filmes[i].id << " " << maratona.filmes[i].inicio << " " << maratona.filmes[i].fim << " " << maratona.filmes[i].categoria << endl;
    }

    cout << endl;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<Filme> filmes;
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
            } else if (inicio == -1 || fim == -1) {
                continue;
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

    // for (int i = 0; i < size_of_f    ilmes; i++) {
    //     cout << filmes[i].id << " " << filmes[i].inicio << " " << filmes[i].fim << endl;
    // }

    map<int, vector<Filme>> filmes_por_horario;
    
    for (int i = 0; i < size_of_filmes; i++) {
        filmes_por_horario[filmes[i].fim].push_back(filmes[i]);
    }

    aleatoriedade(categorias, maratona, filmes_por_horario);

    return 0;

}
