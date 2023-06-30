#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void cargar(vector<int>& sortedArray, const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error: Failed to open the file." << endl;
        return;
    }

    int num;
    while (inputFile >> num) {
        cout<<num<<" ";
        sortedArray.push_back(num);
    }
    cout<<endl;
    inputFile.close();
}

int binarySearch(const vector<int>& sortedArray, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedArray[mid] == target) {
            return mid;
        } else if (sortedArray[mid] < target) {
            return binarySearch(sortedArray, target, mid + 1, right);
        } else {
            return binarySearch(sortedArray, target, left, mid - 1);
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> sortedArray;
    string filename = "numeros.txt";

    cargar(sortedArray, filename);

    int buscado = 20; // The number to search for
    int result = binarySearch(sortedArray, buscado, 0, sortedArray.size() - 1);

    if (result != -1) {
        cout << "El #" << buscado << " fue encontrado en la pos  " << result << endl;
    } else {
        cout << "The target " << buscado << " no fue encontrado." << endl;
    }

    return 0;
}
