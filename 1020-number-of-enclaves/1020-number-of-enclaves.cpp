class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // first and last column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0) {
                vis[i][0] = 1;
                q.push({i, 0});
            }

            if (grid[i][n - 1] == 1 && vis[i][n - 1] == 0) {
                vis[i][n - 1] = 1;
                q.push({i, n-1});
            }
        }

        // first and last row
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && vis[0][j] == 0) {
                vis[0][j] = 1;
                q.push({0, j});
            }

            if (grid[m - 1][j] == 1 && vis[m - 1][j] == 0) {
                vis[m - 1][j] = 1;
                q.push({m-1, j});
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                }
            }
            q.pop();
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && vis[i][j]==0) count++;
            }
        }

        return count;
    }
};