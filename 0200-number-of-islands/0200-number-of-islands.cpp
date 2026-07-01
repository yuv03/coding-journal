class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int r = row + delRow[i];
            int c = col + delCol[i];

            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] &&
                grid[r][c] == '1') {
                dfs(r, c, grid, vis);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};