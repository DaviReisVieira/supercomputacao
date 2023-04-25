#include <iostream>
#include <string>
#include <omp.h>

using namespace std;

int main() {
    long int N = 100000000000000000000;
    double pi = 0.0;
    double denominador = 1.0;
    double sinal = 1.0;

    cout << "Number of threads: " << omp_get_num_threads() << endl;

    # pragma omp parallel
    for (int i = 0; i < N; i++) {
        pi += sinal / denominador;
        sinal *= -1.0;
        denominador += 2.0;
    }
    pi *= 4.0;
    cout << pi << endl;
    return 0;
}