#include <iostream>
#include <vector>
using namespace std;

int maxCoinsHelper(vector<int>& coins, int start, int end) {
    if (start > end)
        return 0;

    int mid = (start + end) / 2;
    int maxCoins = 1;
    int remainingAmount = coins[mid];

    // Verificar hacia la izquierda desde el punto medio
    for (int i = mid - 1; i >= start; i--) {
        if (coins[i] <= remainingAmount) {
            maxCoins++;
            remainingAmount = coins[i];
        } else {
            break;
        }
    }

    // Verificar hacia la derecha desde el punto medio
    remainingAmount = coins[mid];
    for (int i = mid + 1; i <= end; i++) {
        if (coins[i] <= remainingAmount) {
            maxCoins++;
            remainingAmount = coins[i];
        } else {
            break;
        }
    }

    // Calcular el máximo de monedas utilizando "divide y vencerás"
    int maxLeft = maxCoinsHelper(coins, start, mid - 1);
    int maxRight = maxCoinsHelper(coins, mid + 1, end);

    return max(maxCoins, max(maxLeft, maxRight));
}

int maxCoins(vector<int>& coins) {
    int n = coins.size();
    return maxCoinsHelper(coins, 0, n - 1);
}

int main() {
    int t;
    cin >> t; // Número de casos de prueba

    while (t--) {
        int n;
        cin >> n; // Número de diferentes tipos de monedas

        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i]; // Valores de cada tipo de moneda
        }

        int result = maxCoins(coins);
        cout << result << endl;
    }

    return 0;
}