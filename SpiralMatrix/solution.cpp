class Solution {
public:
    void spiral(pair<int, int>& pos, string dir) {
        if (dir == "up") pos.first--;
        else if (dir == "down") pos.first++;
        else if (dir == "left") pos.second--;
        else if (dir == "right") pos.second++;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        string dir = "right";
        int r_bound = n - 1, l_bound = 0, d_bound = m - 1, u_bound = 0;
        pair<int, int> pos = {0, 0};
        for (int i = 0; i < m*n; ++i) {
            res.push_back(matrix[pos.first][pos.second]);
            if (dir == "right" && pos.second == r_bound) dir = "down";
            else if (dir == "down" && pos.first == d_bound) dir = "left";
            else if (dir == "left" && pos.second == l_bound) {
                ++u_bound;
                --d_bound;
                --r_bound;
                ++l_bound;
                dir = "up";
            } else if (dir == "up" && pos.first == u_bound) dir = "right";
            spiral(pos, dir);
        }
        return res;
    }
};

// We can see the spiral as going in 1 of 4 directions at any given time. Right, down, left, up, that order. 
// We can change the direction every time we hit that direction's respective boundary, and while we're going from left -> up,
// Our spiral starts to shrink, so we can decrement each of the boundaries by one and keep your algorithm going
// We can also have a separate function that will increment the position of the matrix [i, j] based on the direction for us
