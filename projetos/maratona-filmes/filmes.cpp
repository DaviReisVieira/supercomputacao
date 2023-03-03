// Entrada: Um inteiro N representando o número de filmes disponíveis para assistir e N trios de inteiros (H[i], F[i], C[i]), representando a hora de início, a hora de fim e a categoria do i-ésimo filme. Além disso, um inteiro M representando o número de categorias e uma lista de M inteiros representando o número máximo de filmes que podem ser assistidos em cada categoria.

// Saída: Um inteiro representando o número máximo de filmes que podem ser assistidos de acordo com as restrições de horários e número máximo por categoria.

// formato do arquivo 'input.txt':
// N M
// M1 M2 ... Mm
// H1 F1 C1
// H2 F2 C2
// ...
// Hn Fn Cn

// formato do arquivo 'output.txt':
// X

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct filme {
    int inicio;
    int fim;
    int categoria;
};

bool compara_filme(filme a, filme b) {
    return a.fim < b.fim;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<filme> filmes(n);
    vector<int> categorias(m);
    
    for (int i = 0; i < m; i++) {
        cin >> categorias[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> filmes[i].inicio >> filmes[i].fim >> filmes[i].categoria;
    }

    sort(filmes.begin(), filmes.end(), compara_filme);

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
    return 0;
}
