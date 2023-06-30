#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

void getArray(vector<int>& A, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error: Failed to open the file." << endl;
        return;
    }
    int num;
    while (inputFile >> num) {
        A.push_back(num);
    }

    inputFile.close();
}

int partition(vector<int>& A, int p, int r) {
    int i = p - 1;
    int x = A[r];

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }

    A[r] = A[i + 1];
    A[i + 1] = x;

    return i + 1;
}

void quick_sort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int main() {
    vector<int> A;
    string filename = "numeros.txt";

    getArray(A, filename);

    cout << "Sin ordenar(A): ";
    for (int num : A) {
        cout << num << ", ";
    }

    quick_sort(A, 0, A.size() - 1);

    cout << "\nquicksort(A): ";
    for (int num : A) {
        cout << num << ", ";
    }
    cout << endl;

    return 0;
}
