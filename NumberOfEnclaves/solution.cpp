class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, pair<int, int> p) {
        queue<pair<int, int>> q;
        q.push({p.first, p.second});
        int ret = 0;
        bool border = false;
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            int i = curr.first;
            int j = curr.second;
            if (visited[i][j]) {
                q.pop();
                continue;
            }
            if (i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1) {
                ret = 0;
                border = true;
            }
            visited[i][j] = true;
            q.pop();
            
            if (i > 0 && !visited[i-1][j] && grid[i-1][j] == 1) q.push({i-1, j});
            if (i < grid.size()-1 && !visited[i+1][j] && grid[i+1][j] == 1) q.push({i+1, j});
            if (j > 0 && !visited[i][j-1] && grid[i][j-1] == 1) q.push({i, j-1});
            if (j < grid[0].size()-1 && !visited[i][j+1] && grid[i][j+1] == 1) q.push({i, j+1});

            if (!border) ++ret;
        }
        return ret;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int enclaves = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    enclaves += bfs(grid, visited, {i, j});
                }
            }
        }

        return enclaves;
    }
};

// basically iterating through the grid and doing bfs to find all enclaves of 1s
// if you come across a 1 that is on the border, that bfs instance is automatically invalid
// bfs will still continue, because that enclave needs to be marked as visited, but the counter of land cells will stay 0
