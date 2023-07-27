#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int cambiomonedas(int n, int P, const vector<int>& Ci, vector<vector<int>>& D) {


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= P; ++j) {
            if (i - 1 == 0)
            {
                D[i - 1][j] = 1 + D[i - 1][j - Ci[i - 1]];
            }
            else
            {
                if (j - Ci[i - 1] < 0)
                    D[i - 1][j] = D[i - 1-1][j];
                else
                    D[i - 1][j] = min(D[i - 1-1][j], 1 + D[i - 1][j - Ci[i - 1]]);
            }

        }
    }
       for (int i = 0; i < n; i++) {
        for (int j = 0; j <= P; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    } 

    return D[n-1][P];
}
void recomponer(int n, int P, const vector<int>& Ci, vector<vector<int>>& D)
{
    int i = n;
    int j = P;
    vector<int>x(n, 0);
    for (;i != 0&&j!=0;)
    {
        if (D[i-1][j] == D[i - 1-1][j])
            i=i- 1;
        else
        {
            x[i-1] = x[i-1]+1;
            j = j - Ci[i-1];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << x[i] << " , " << Ci[i] << endl;
    }

}

int main() {
    int n = 3;
    int P = 8;
    vector<int> c = { 1, 4, 6 };
    vector<vector<int>> D(n, vector<int>(P + 1, 0));

    cambiomonedas(n, P, c, D);
    //int beneficio_optimo = mochila(n, M, b, p, V);
    //cout << "El beneficio optimo es: " << beneficio_optimo << endl;
    recomponer(n, P, c, D);

    return 0;
}
