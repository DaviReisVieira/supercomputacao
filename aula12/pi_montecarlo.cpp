#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>

using namespace std;

int N = 100000;

int main() {
  int sum = 0;
  double x, y;
  double start, end;

  start = omp_get_wtime();
  #pragma omp parallel for private(x, y) reduction(+:sum)
  for (int i = 0; i < N; i++) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    if (x*x + y*y <= 1) sum++;
  }
  end = omp_get_wtime();

  cout << "pi = " << 4.0 * sum / N << endl;
  cout << "time = " << end - start << endl;

  return 0;
}