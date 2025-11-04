class Solution {
public:
    void increment(pair<int, int>& pos, string dir) {
        if (dir == "right") pos.second++;
        else if (dir == "left") pos.second--;
        else if (dir == "down") pos.first++;
        else if (dir == "up") pos.first--;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int r_bound = n - 1, l_bound = 0, d_bound = n - 1, u_bound = 0;
        pair<int, int> pos = {0, 0};
        string dir = "right";
        for (int i = 1; i <= n*n; ++i) {
            res[pos.first][pos.second] = i;
            if (dir == "right" && pos.second == r_bound) dir = "down";
            else if (dir == "down" && pos.first == d_bound) dir = "left";
            else if (dir == "left" && pos.second == l_bound) {
                --r_bound;
                --d_bound;
                ++u_bound;
                ++l_bound;
                dir = "up";
            } else if (dir == "up" && pos.first == u_bound) dir = "right";
            increment(pos, dir);
        }
        return res;
    }
};

// Spiral Matrix algorithm but instead of pushing back the element to a vector, we insert i into our resulting matrix
