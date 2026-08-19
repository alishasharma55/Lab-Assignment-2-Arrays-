#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int matrix[20][20];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int sparse[100][3];
    int k = 1;

    sparse[0][0] = rows;
    sparse[0][1] = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k - 1;

    cout << "\nSparse Matrix:\n";
    for (int i = 0; i < k; i++) {
        cout << sparse[i][0] << " "
             << sparse[i][1] << " "
             << sparse[i][2] << endl;
    }

    int transpose[100][3];

    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = sparse[0][2];

    int t = 1;

    for (int col = 0; col < cols; col++) {
        for (int i = 1; i < k; i++) {
            if (sparse[i][1] == col) {
                transpose[t][0] = sparse[i][1];
                transpose[t][1] = sparse[i][0];
                transpose[t][2] = sparse[i][2];
                t++;
            }
        }
    }

    cout << "\nTranspose of Sparse Matrix:\n";
    for (int i = 0; i < t; i++) {
        cout << transpose[i][0] << " "
             << transpose[i][1] << " "
             << transpose[i][2] << endl;
    }

    return 0;
}
