#include <iostream>

int* gpVect = NULL,
gnCount = 0,
gnMax = 0;
using namespace std;

void Resize();
void Insert(int elem)
{
    if (gnCount == gnMax) Resize();
    gpVect[gnCount++] = elem;
}
void Resize()
{
    const int delta = 100;
    gpVect = (int*)(realloc(gpVect, sizeof(int) * (gnMax + delta)));
    gnMax += delta;         /* The Max has to be increased by delta */
}
int partition(int* A, int p, int r) {
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

void quick_sort(int* A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}
int main()
{
    int x;

    while (cin >> x) {
        Insert(x);
            int median;
            quick_sort(gpVect, 0, gnCount - 1);
            if (gnCount % 2 == 0)
                median = (gpVect[gnCount / 2] + gpVect[gnCount / 2 - 1]) / 2;
            else
                median = (gpVect[gnCount / 2]);
            cout << median << endl;

    }

    return 0;
}