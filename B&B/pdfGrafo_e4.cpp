#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Nodo {
    int nivel;
    int DistanciaTotal;
    vector<int> Ruta;
    vector<bool> Visitado;
};

const int INF = numeric_limits<int>::max();

// Matriz de distancias
vector<vector<int>> distancias = {
        {0, 3, 10, 11, 7},
        {3, 0, 8, 12, 9},
        {10, 8, 0, 9, 4},
        {11, 12, 9, 0, 5},
        {7, 9, 4, 5, 0}
};

int numCiudades = distancias.size();

int CalcularCotaInferior(const Nodo &nodo) {
    int cotaInferior = 0;
    vector<int> distanciasMinimas(numCiudades, INF);

    for (int i = 0; i < numCiudades; i++) {
        if (!nodo.Visitado[i]) {
            for (int j = 0; j < numCiudades; j++) {
                if (i != j && !nodo.Visitado[j]) {
                    distanciasMinimas[i] = min(distanciasMinimas[i], distancias[i][j]);
                }
            }
        }
        cotaInferior += distanciasMinimas[i];
    }

    return cotaInferior + nodo.DistanciaTotal;
}

void RamificacionYPoda() {
    Nodo Raiz;
    Raiz.nivel = 0;
    Raiz.DistanciaTotal = 0;
    Raiz.Ruta.push_back(0);
    Raiz.Visitado.assign(numCiudades, false);
    Raiz.Visitado[0] = true;

    int CostoMinimo = INF;
    vector<int> RutaMinima;

    vector<Nodo> NodosActivos;
    NodosActivos.push_back(Raiz);

    while (!NodosActivos.empty()) {
        Nodo NodoActual = NodosActivos.back();
        NodosActivos.pop_back();

        if (NodoActual.nivel == (numCiudades - 1)) {
            NodoActual.Ruta.push_back(0);
            if (NodoActual.DistanciaTotal + distancias[NodoActual.Ruta[numCiudades - 2]][0] < CostoMinimo) {
                CostoMinimo = NodoActual.DistanciaTotal + distancias[NodoActual.Ruta[numCiudades - 2]][0];
                RutaMinima = NodoActual.Ruta;
            }
        } else {
            for (int i = 1; i < numCiudades; i++) {
                if (!NodoActual.Visitado[i]) {
                    Nodo NuevoNodo = NodoActual;
                    NuevoNodo.nivel = NodoActual.nivel + 1;
                    NuevoNodo.Ruta.push_back(i);
                    NuevoNodo.DistanciaTotal = NodoActual.DistanciaTotal + distancias[NodoActual.Ruta[NodoActual.nivel]][i];
                    NuevoNodo.Visitado[i] = true;

                    if (NuevoNodo.DistanciaTotal + CalcularCotaInferior(NuevoNodo) < CostoMinimo )
                        NodosActivos.push_back(NuevoNodo);
                    
                }
            }
        }
    }

    cout << "Costo minimo: " << CostoMinimo << "\n";
    cout << "Camino: ";
    for (int Ciudad : RutaMinima) {
        cout << (char)('A' + Ciudad) << " ";
    }
    cout << "\n";
}

int main() {
    RamificacionYPoda();
    return 0;
}
