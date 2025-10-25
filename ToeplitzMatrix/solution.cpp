class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // from 0 to m-1
        // (n-m)+1 diagonals

        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        // checking diagonals below main diagonal
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }

        // checking diagonals above main diagonal
        for (int i = 0; i < m; ++i) {
            int num = matrix[i][0];
            for (int j = 0; j < m; ++j) {
                if ((j+i) >= m || j >= n) break;
                if (num != matrix[j+i][j]) return false;
                num = matrix[j+i][j];
            }
        }

        for (int i = 1; i < n; ++i) {
            int num = matrix[0][i];
            for (int j = 0; j < m; ++j) {
                if (j >= m || (j+i) >= n) break;
                if (num != matrix[j][j+i]) return false;
                num = matrix[j][j+i];
            }
        }

        return true;
    }
};