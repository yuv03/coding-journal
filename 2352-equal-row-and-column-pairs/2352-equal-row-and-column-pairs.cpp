class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        vector<vector<int>> col(grid[0].size());
        int count = 0;

        for(int j=0; j<grid[0].size(); j++){
            for(int i=0; i<grid.size(); i++){
                col[j].push_back(grid[i][j]);
            }
        }


        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<col.size(); j++){
                if(grid[i] == col[j]) count++;
            }
        }
        return count;
    }
};