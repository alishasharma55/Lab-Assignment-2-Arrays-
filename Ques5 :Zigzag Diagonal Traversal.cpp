#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    int matrix[20][20];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Zigzag Diagonal Traversal: ";

    for (int diagonal = 0; diagonal <= n + m - 2; diagonal++) {

        if (diagonal % 2 == 0) {
            int row = min(diagonal, n - 1);
            int col = diagonal - row;

            while (row >= 0 && col < m) {
                cout << matrix[row][col] << " ";
                row--;
                col++;
            }
        }
        else {
            int col = min(diagonal, m - 1);
            int row = diagonal - col;

            while (col >= 0 && row < n) {
                cout << matrix[row][col] << " ";
                row++;
                col--;
            }
        }
    }

    return 0;
}
