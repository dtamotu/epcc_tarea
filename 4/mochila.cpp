#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// Función que resuelve el problema de la mochila con objetos fraccionables

float fobjetivo(vector<pair<float, float>>& candidatos, float M)
{
    //float M = M_;
    float valor_total = 0.0;
    vector<pair<float,float>> sol;
    for (auto obj : candidatos) {
        if (M == 0) {
            // Si se ha llenado la mochila, detenemos el proceso
            //cout << " 0 ";
            sol.push_back({ 0, obj.second });
            break;
        }
        else if (obj.first <= M) {
            // Agregamos el objeto completo a la mochila
            //cout << " " << 1;
            valor_total += obj.second;
            sol.push_back({1, obj.second });
            M -= obj.first;
        }
        else {
            // Agregamos una fracción del objeto a la mochila
            valor_total += (M / obj.first)*(obj.second);
            sol.push_back({ M/ obj.first, obj.second});
            //cout << " " << M/obj.first;
            M = 0.0;
        }

    }
    cout << "Solucion (";
    for (auto i : sol)
    {
        cout << "\t" << i.first;
    }
    cout << ")"<<endl;
    cout << "Beneficio total = ";
    for (auto i : sol)
    {
        cout << "\t" << i.second<<"*"<<i.first<<" + ";
    }
    cout << ") = " << valor_total <<endl;

    return valor_total;

}
bool cmp1(const pair<float, float>& a, const pair<float, float>& b) {
    return a.second < b.second;
}
bool cmp2(const pair<float, float>& a, const pair<float, float>& b) {
    return a.first > b.first;
}
bool cmp3(const pair<float, float>& a, const pair<float, float>& b) {
    float v1 = a.second / a.first;
    float v2 = b.second / b.first;
    return v1 < v2;
}
float mochila(int n, float M, vector<float> &p, vector<float> &b) {
    vector<pair<float, float>> c1, c2, c3;
    for (int i = 0; i < n; i++) {
        // Calculamos el valor por unidad de los objetos
        c1.push_back({ p[i],b[i] });
        c2.push_back({ p[i],b[i] });
        c3.push_back({ p[i],b[i] });
    }
    // Criterio 1 (prioriza el objeto con más benficio)
    // Criterio 2 (prioriza los objetos menos pesado)
    // Criterio 3 (mejor coste por unidad de peso)
    sort(c1.rbegin(), c1.rend(), cmp1);
    sort(c2.rbegin(), c2.rend(), cmp2);
    sort(c3.rbegin(), c3.rend(), cmp3);

    float s1, s2, s3;
    s1 = fobjetivo(c1,M);
    s2 = fobjetivo(c2,M);
    s3 = fobjetivo(c3,M);

    cout << "3er criterio suele ser la optima ";
    return max(max(s1,s2),s3);
}

int main() {
    // Definimos las variables
    int n = 3;
    float M = 20;
    vector<float> p = { 18, 15, 10 };
    vector<float> b = { 25, 24, 15 };
    float max_valor = mochila(n,M,p,b); // Llamamos a la función que resuelve el problema de la mochila con objetos fraccionables
    cout << max_valor << endl<< endl;

    int n1 = 4;
    float M1 = 10;
    vector<float> p1 = { 10, 3, 3, 4};
    vector<float> b1 = { 10, 9, 9, 9};
    float max_valor1 = mochila(n1,M1,p1,b1); // Llamamos a la función que resuelve el problema de la mochila con objetos fraccionables
    cout << max_valor1 << endl<< endl;
    int n2 = 4;
    float M2 = 10;
    vector<float> p2 = { 10, 3, 3, 4};
    vector<float> b2 = { 10, 1, 1, 1};
    float max_valor2 = mochila(n2,M2,p2,b2); // Llamamos a la función que resuelve el problema de la mochila con objetos fraccionables
    cout << max_valor2 << endl<< endl;
    return 0;
}