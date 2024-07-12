class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    bool dfs(int row,int col,vector<vector<int>>& grid){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()){
            return false;
        }

        if(grid[row][col]==1){
            return true;
        }

        bool closed=true;
        grid[row][col]=1;
        for(int i=0;i<dir.size();i++){
            int nr=row+dir[i][0];
            int nc=col+dir[i][1];
            closed&=dfs(nr,nc,grid);
        }
        return closed;
    }
};