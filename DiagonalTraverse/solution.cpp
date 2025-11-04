class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        pair<int, int> pos = {0, 0};
        string dir = "up";
        for (int i = 0; i < m*n; ++i) {
            res.push_back(mat[pos.first][pos.second]);
            if (dir == "up" && pos.second == n - 1) {
                pos.first++;
                dir = "down";
            } else if (dir == "up" && pos.first == 0) {
                pos.second++;
                dir = "down";
            } else if (dir == "down" && pos.first == m - 1) {
                pos.second++;
                dir = "up";
            } else if (dir == "down" && pos.second == 0) {
                pos.first++;
                dir = "up";
            } else {
                if (dir == "up") {
                    pos.first--;
                    pos.second++;
                } else {
                    pos.first++;
                    pos.second--;
                }
            }
        }
        return res;
    }
};

// This is my second time doing this problem, and while the first way was very smart and intuitive (below), I find this way
// much more straightforward and easier to understand and come up with if you haven't done this problem before
// keep track of current position and direction
// We can have a for loop going m*n times, 1 for each square
// Inside the for loop, we do these steps:
// 1. Add square to solution
// 2. Check if direction needs readjusting
// 3. Increment to the next position
// Step 1 is obvious. For step 2, we check if we're at a boundary. We have to check certain boundaries before others.
// For example, when switching from up to down, if we're at (i, j) and i == 0, we have to move right and then switch to down.
// But, if we're at the end of the row, we can't go right, so we have to go down. So in our if statement,
// we check if we're at the end of the row first, then check if i == 0, and increment the square accordingly
// Same for both cases of switching from down to up
// For step 3, just move up and right 1 or down and left 1 based on direction


// Intuitive way:
// Essentially, we can see that row+col is equal to some value across each diagonal. If that value is even, we go up-right,
// else, down-left.
// To traverse, we go from i = 0 to i < m * n. We go down-left or up-right aside for these 2 edge cases:
// while going up-right:
// if last column, move down, else if first row, just move right
// while going down-left:
// if last row, move right, else if first column, just move down