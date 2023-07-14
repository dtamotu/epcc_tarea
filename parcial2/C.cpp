#include <iostream>
#include <vector>

using namespace std;

void withdraw( vector<int> coins,int n){
    int Biggest = coins[0];
    int coin = 1;
    for (int i = 1; i < n; i++) {
        if (Biggest + coins[i] < coins[i+1]) {
           Biggest += coins[i];
           coin++;
        }
    }
    //se cuenta a la moneda mayor
    coin+=1;
    cout<<coin<<endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        } 
        withdraw(coins,n-1);
    }

    return 0;
}
