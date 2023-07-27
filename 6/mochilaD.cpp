#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int mochila(int n, int M, const vector<int>& bi, const vector<int>& pi, vector<vector<int>>& V) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= M; ++j) {
           if (j - pi[i-1] < 0)
               V[i][j] = V[i - 1][j];
           else
                V[i][j] = max(V[i - 1][j], bi[i-1] + V[i - 1][j - pi[i-1]]);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }
    return V[n][M];
}
void recomponer( int n, int M, const vector<int>& pi, vector<vector<int>>& V)
{
    int j = M;
    vector<int>x(3, 0);
    for (int i = n; i >= 1; i--)
    {
        if (V[i][j] == V[i - 1][j])
            x[i-1] = 0;
        else
        {
            x[i-1] = 1;
            j = j - pi[i-1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << x[i] << " , "<<pi[i]<<endl;
    }
}

int main() {
    int n = 3;
    int M = 6;
    vector<int> b = { 1, 2, 5 };
    vector<int> p = { 2, 3, 4 };
    vector<vector<int>> V(n+1, vector<int>(M+1, 0));
    int beneficio_optimo = mochila(n, M, b, p, V);
    cout << "El beneficio optimo es: " << beneficio_optimo << endl;
    recomponer(n,M,p,V);

    return 0;
}