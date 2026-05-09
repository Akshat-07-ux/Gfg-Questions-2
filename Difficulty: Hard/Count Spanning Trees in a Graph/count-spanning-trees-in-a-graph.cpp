#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSpanTree(int n, vector<vector<int>>& edges) {
        // A graph with 1 vertex has exactly 1 spanning tree (0 edges).
        if (n <= 1) return 1;

        // 1. Construct the Laplacian Matrix (L = D - A)
        vector<vector<double>> laplacian(n, vector<double>(n, 0.0));

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Adjacency parts (-1 for edges)
            laplacian[u][v] -= 1;
            laplacian[v][u] -= 1;
            
            // Degree parts (+1 on diagonal)
            laplacian[u][u] += 1;
            laplacian[v][v] += 1;
        }

        // 2. Create the reduced matrix (remove the last row and column)
        int size = n - 1;
        vector<vector<double>> matrix(size, vector<double>(size));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = laplacian[i][j];
            }
        }

        // 3. Calculate the determinant using Gaussian Elimination
        return (int)round(calculateDeterminant(matrix, size));
    }

private:
    double calculateDeterminant(vector<vector<double>>& matrix, int n) {
        double det = 1.0;
        for (int i = 0; i < n; i++) {
            // Pivot selection
            int pivot = i;
            for (int j = i + 1; j < n; j++) {
                if (abs(matrix[j][i]) > abs(matrix[pivot][i])) pivot = j;
            }

            if (abs(matrix[pivot][i]) < 1e-9) return 0; // Singular matrix

            swap(matrix[i], matrix[pivot]);
            if (i != pivot) det *= -1;

            det *= matrix[i][i];

            for (int j = i + 1; j < n; j++) {
                double factor = matrix[j][i] / matrix[i][i];
                for (int k = i + 1; k < n; k++) {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }
        return det;
    }
};