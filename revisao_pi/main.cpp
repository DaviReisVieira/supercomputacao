#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bitset>

using namespace std;


int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    int** pesos = new int*[n];
    for(int i = 0;i<n; i++){
        pesos[i] = new int[n];
    }
    for(int i =0; i < n; i ++){
        for(int j = 0; j < n; j++){
            cin >> pesos[i][j];
        }
    }


    vector<int> centros;
    centros.push_back(0);

    int linha = 0;
    int coluna = 0;

    for (int i = 0; i < k-1; i++){
        int maior = 0;
        for(int j = 0; j < n; j++){
            if(find(centros.begin(), centros.end(), j) == centros.end()){
                if(pesos[linha][j] > maior){
                    maior = pesos[linha][j];
                    coluna = j;
                }
            }
        }
        linha = coluna;
        centros.push_back(coluna);
    }

    for(int i = 0; i < k; i++){
        cout << centros[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < n; i++){
        int menor = 9999999;
        int centro = 0;
        for(int j = 0; j < k; j++){
            if(pesos[i][centros[j]] < menor){
                menor = pesos[i][centros[j]];
                centro = centros[j];
            }
        }
        cout << centro << " ";
    }

    cout << endl;
    
    return 0;


 }