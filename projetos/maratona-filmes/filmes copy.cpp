#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Filme {
    int inicio;
    int fim;
    int categoria;
};

bool compara_filme(Filme a, Filme b) {
    return a.fim < b.fim;
}

void main() {
    int n, m;
    cin >> n >> m;
    vector<Filme> filmes(n);
    vector<int> categorias(m);
    
    for (int i = 0; i < m; i++) {
        cin >> categorias[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> filmes[i].inicio >> filmes[i].fim >> filmes[i].categoria;
    }

    sort(filmes.begin(), filmes.end(), compara_filme);

    for (int i = 0; i < n; i++) {
        cout << filmes[i].inicio << " " << filmes[i].fim << " " << filmes[i].categoria << endl;
    }

    int maximo = 0;
    for (int i = 0; i < n; i++) {
        int fim = filmes[i].fim;
        int categoria = filmes[i].categoria;
        int quantidade = 1;

        for (int j = i + 1; j < n; j++) {
            if (filmes[j].inicio >= fim && categorias[categoria - 1] > 0) {
                quantidade++;
                fim = filmes[j].fim;
                categorias[categoria - 1]--;
            }
        }

        if (quantidade > maximo) {
            maximo = quantidade;
        }

        for (int j = 0; j < m; j++) {
            categorias[j] = categorias[j] + quantidade;
        }
    }
    cout << maximo << endl;
}
