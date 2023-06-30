#include <iostream>

using namespace std;

double potencia(double x, int n) {
    if (n == 0) {
        return 1;
    }
    double temp = potencia(x, n / 2);
    if (n % 2 == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}

int main() {
    double a = 2.0;
    int n = 8;
    cout <<a<<"^("<<n <<")="<<potencia(a, n) <<"."<< endl; 
    return 0;
}
