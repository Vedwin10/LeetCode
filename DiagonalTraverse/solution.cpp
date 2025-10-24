class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ret;
        pair<int, int> pos = {0, 0};
        int n = mat[0].size();
        int m = mat.size();
        for (int i = 0; i < m*n; ++i) {
            ret.push_back(mat[pos.first][pos.second]);

            if ((pos.first + pos.second) % 2 == 0) {
                if (pos.second == n-1) pos.first++;
                else if (pos.first == 0) pos.second++;
                else {
                    pos.first--;
                    pos.second++;
                }
            } else {
                if (pos.first == m-1) pos.second++;
                else if (pos.second == 0) pos.first++;
                else {
                    pos.first++;
                    pos.second--;
                }
            }
        }
        return ret;
    }
};

// Essentially, we can see that row+col is equal to some value across each diagonal. If that value is even, we go up-right,
// else, down-left.

// To traverse, we go from i = 0 to i < m * n. We go down-left or up-right aside for these 2 edge cases:
// while going up-right:
// if last column, move down, else if first row, just move right
// while going down-left:
// if last row, move right, else if first column, just move down