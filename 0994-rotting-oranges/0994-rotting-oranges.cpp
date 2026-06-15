class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<pair<int, int>, int>> q;
        // {{r,c}, t}
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }


        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int t = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;

            int tm = q.front().second;
            q.pop();
            t = max(t, tm);

            for(int i=0; i<4; i++){
                int row = r + delRow[i];
                int col = c + delCol[i];

                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && !vis[row][col]){
                    vis[row][col]=2;
                    q.push({{row,col},tm+1});
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return t;
    }
};