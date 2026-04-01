class Solution {
public:
    void dfs(int i ,int j,vector<vector<char>>&grid,vector<vector<bool>>&visited){
        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || j<0 || i >=m ||j>=n){
            return;
        }
        if(grid[i][j] == '0' || visited[i][j] == true){
            return;
        }

        visited[i][j] = true;

        dfs(i+1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i - 1,j,grid,visited);
        dfs(i,j - 1,grid,visited);



    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};