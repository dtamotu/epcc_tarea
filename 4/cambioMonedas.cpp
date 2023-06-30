#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> cambioDeMonedas(int cantidad, const vector<int>& denominaciones) {

    vector<int> solucion(denominaciones.size(), 0);
    for (int i = denominaciones.size() - 1; i >= 0; --i) {
        while (cantidad >= denominaciones[i]) {
            cantidad -= denominaciones[i];
            ++solucion[i];
        }
    }

    return solucion;
}

void printSolucion(int cantidad, const vector<int>& denominaciones, const vector<string>& nombres) {
    vector<int> solucion = cambioDeMonedas(cantidad, denominaciones);
    int total=0;
    cout << "Solucion:" << endl;
    for (int i = denominaciones.size()-1; i>=0; i--) {
        if(solucion[i]==0)
            continue;
        if (solucion[i]>1) {
            cout << solucion[i]<<" Monedas "<<nombres[i] << "; ";
            total=total+solucion[i];
        } else
        {
            cout << solucion[i]<<" Moneda"<<nombres[i] <<  "; ";
            total=total+solucion[i];
        }

    }
    cout << "Total " <<total<<" monedas"<< endl;
}

int main() {
    float  cantidadf;
    int cantidad;
    cout << "Ingrese la cantidad de dinero: ";
    cin >> cantidadf;
    cantidad=(int)(cantidadf*100);

    vector<int> denominaciones{1, 2, 5, 10, 20, 50, 100, 200};
    vector<string> nombres{" de 1 cE o ", " de 2 cE", " de 5 cE", " de 10 cE", " de 20 cE", " de 50 cE", " de 1 E", " de 2 E"};

    printSolucion(cantidad, denominaciones, nombres);

    return 0;
}