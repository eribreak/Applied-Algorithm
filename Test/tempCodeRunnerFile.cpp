#include <iostream>
#include <vector>

using namespace std;

void readMatrix(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (int j = 0; j < n; j++) {
            cin >> row[j];
        }
        matrix.push_back(row);
    }
}

int sumOddRowsAndCols(const vector<vector<int>>& matrix) {
    int sum = 0;
    int n = matrix.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                if (j % 2 == 0 && !visited[i][j]) {
                    sum += matrix[i][j];
                    visited[i][j] = true;
                }
            }
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix;
    readMatrix(matrix, n);

    int sum = sumOddRowsAndCols(matrix);
    cout << sum << endl;

    return 0;
}
