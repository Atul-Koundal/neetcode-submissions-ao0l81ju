class Solution {
public:
    void dfs(int i,int j,int &area,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }

        if(grid[i][j] == 0 || visited[i][j] == true){
            return;
        }
        visited[i][j] = true;
        area+=1;

        dfs(i + 1,j,area,grid,visited);
        dfs(i - 1,j,area,grid,visited);
        dfs(i,j + 1,area,grid,visited);
        dfs(i,j -1,area,grid,visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int maxArea = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int area = 0;
                    dfs(i,j,area,grid,visited);
                    maxArea = max(area,maxArea);
                }  
            }
        }
        return maxArea;
    }
};