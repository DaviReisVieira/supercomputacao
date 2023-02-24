#include <iostream>

using namespace std;

int quadrado(int& x);

int main() {
    int a = 10;
    // endereço de a
    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    int b = quadrado(a);
    cout << "a = " << a << endl;

    cout << "b = " << b << endl;
    return 0;
}

int quadrado(int& x) {
    // endereço de x
    cout << "x = " << x << endl;
    cout << "&x = " << &x << endl;
    x = x * x;
    return x;
}