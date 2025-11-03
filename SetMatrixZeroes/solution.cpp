class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int, int>> s;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    s.insert({i, j});
                }
            }
        }

        for (const auto& ele : s) {
            matrix[ele.first] = vector<int>(n, 0);
            for (int i = 0; i < m; ++i) matrix[i][ele.second] = 0;
        }
    }
};

// We can first traverse the matrix and store the location of all the original zeroes using a set
// Note: sets are good for storing pair<int, int> because they don't require a hashing function, unordered_set wouldn't work here
// Then we can traverse the set and set each row i and each col j equal to 0 for each pair [i, j] in the set.
