class Solution {
private:
    void dfs(int n, int m, int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
        vis[row][col]=1;
        int rowFor = row+1;
        int rowBack = row-1;
        int colFor = col +1;
        int colBack = col -1;

        if(col>=0 && col<m && rowBack >=0 && rowBack < n && grid[rowBack][col]=='1' && vis[rowBack][col]==0){
            dfs(n,m,rowBack, col, grid, vis);
        }

        if(col>=0 && col<m && rowFor<n && rowFor >=0 && grid[rowFor][col]=='1' && vis[rowFor][col]==0){
            dfs(n,m,rowFor, col, grid, vis);
        }

        if(row>=0 && row<n &&colBack >=0 && colBack<m && grid[row][colBack]=='1' && vis[row][colBack]==0){
            dfs(n,m,row, colBack, grid, vis);
        }

        if(row>=0 && row<n && colFor >=0 && colFor<m && grid[row][colFor]=='1' && vis[row][colFor]==0){
            dfs(n,m,row, colFor, grid, vis);
        }

        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    dfs(n,m,i, j, grid, vis);
                }
            }
        }
        return count;
    }
};