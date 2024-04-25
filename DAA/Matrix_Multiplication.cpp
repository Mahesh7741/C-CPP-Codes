#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices using Strassen's algorithm
vector<vector<int>> strassenMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    if (n == 1) {
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    // Divide matrices into submatrices
    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate intermediate matrices
    vector<vector<int>> P1 = strassenMultiplication(A11, subtractMatrices(B12, B22));
    vector<vector<int>> P2 = strassenMultiplication(addMatrices(A11, A12), B22);
    vector<vector<int>> P3 = strassenMultiplication(addMatrices(A21, A22), B11);
    vector<vector<int>> P4 = strassenMultiplication(A22, subtractMatrices(B21, B11));
    vector<vector<int>> P5 = strassenMultiplication(addMatrices(A11, A22), addMatrices(B11, B22));
    vector<vector<int>> P6 = strassenMultiplication(subtractMatrices(A12, A22), addMatrices(B21, B22));
    vector<vector<int>> P7 = strassenMultiplication(subtractMatrices(A11, A21), addMatrices(B11, B12));

    // Calculate result matrices
    vector<vector<int>> C11 = addMatrices(subtractMatrices(addMatrices(P5, P4), P2), P6);
    vector<vector<int>> C12 = addMatrices(P1, P2);
    vector<vector<int>> C21 = addMatrices(P3, P4);
    vector<vector<int>> C22 = subtractMatrices(subtractMatrices(addMatrices(P5, P1), P3), P7);

    // Combine result matrices
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + newSize] = C12[i][j];
            result[i + newSize][j] = C21[i][j];
            result[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return result;
}

// Function to print a matrix
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
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << endl;

    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << endl;

    vector<vector<int>> result = strassenMultiplication(A, B);

    cout << "Resultant Matrix:" << endl;
    printMatrix(result);

    return 0;
}
