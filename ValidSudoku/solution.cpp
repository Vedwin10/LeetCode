class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row_mp;
            unordered_set<char> col_mp;
            for (int j = 0; j < 9; ++j) {
                if (row_mp.find(board[i][j]) != row_mp.end()) return false;
                if (board[i][j] != '.') row_mp.insert(board[i][j]);
                if (col_mp.find(board[j][i]) != col_mp.end()) return false;
                if (board[j][i] != '.') col_mp.insert(board[j][i]);
            }
        }

        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                unordered_set<char> mp;
                for (int row_small = 0; row_small < 3; ++row_small) {
                    for (int col_small = 0; col_small < 3; ++col_small) {
                        if (mp.find(board[(3*row)+row_small][(3*col)+col_small]) != mp.end()) return false;
                        if (board[(3*row)+row_small][(3*col)+col_small] != '.') 
                            mp.insert(board[(3*row)+row_small][(3*col)+col_small]);
                    }
                }
            }
        }

        return true;
    }
};

// use hashmaps for row, col, and squares. Rows and cols can be checked in one pass, squares can be checked in quad for loop because 3^4 is the same as 9^2