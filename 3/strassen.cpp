#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sum(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    
    return result;
}

vector<vector<int>> subtract(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    
    return result;
}
void split(const vector<vector<int>>& A, vector<vector<int>>& A11, vector<vector<int>>& A12,
           vector<vector<int>>& A21, vector<vector<int>>& A22) {
    int n = A.size();
    int m = n / 2;
    
    A11.resize(m, vector<int>(m, 0));
    A12.resize(m, vector<int>(m, 0));
    A21.resize(m, vector<int>(m, 0));
    A22.resize(m, vector<int>(m, 0));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];
        }
    }
}

vector<vector<int>> combine(const vector<vector<int>>& C11, const vector<vector<int>>& C12,
                            const vector<vector<int>>& C21, const vector<vector<int>>& C22) {
    int n = C11.size();
    int m = 2 * n;
    vector<vector<int>> result(m, vector<int>(m, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + n] = C12[i][j];
            result[i + n][j] = C21[i][j];
            result[i + n][j + n] = C22[i][j];
        }
    }
    
    return result;
}

vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }
    
    vector<vector<int>> A11, A12, A21, A22;
    vector<vector<int>> B11, B12, B21, B22;
    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);
    
    vector<vector<int>> P1 = strassen(sum(A11, A22), sum(B11, B22));
    vector<vector<int>> P2 = strassen(sum(A21, A22), B11);
    vector<vector<int>> P3 = strassen(A11, subtract(B12, B22));
    vector<vector<int>> P4 = strassen(A22, subtract(B21, B11));
    vector<vector<int>> P5 = strassen(sum(A11, A12), B22);
    vector<vector<int>> P6 = strassen(subtract(A21, A11), sum(B11, B12));
    vector<vector<int>> P7 = strassen(subtract(A12, A22), sum(B21, B22));
    
    vector<vector<int>> C11 = subtract(sum(sum(P1, P4), P5), P7);
    vector<vector<int>> C12 = sum(P3, P5);
    vector<vector<int>> C21 = sum(P2, P4);
    vector<vector<int>> C22 = subtract(sum(subtract(P1, P2), P3), P6);
    
    return combine(C11, C12, C21, C22);
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};
    
    vector<vector<int>> B = {{1, 0, 0, 0},
                             {0, 1, 0, 0},
                             {0, 0, 1, 0},
                             {0, 0, 0, 1}};
    
    vector<vector<int>> result = strassen(A, B);
    
    printMatrix(result);
    
    return 0;
}
