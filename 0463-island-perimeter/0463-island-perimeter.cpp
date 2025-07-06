class Solution {
public:
    int ans=0;
    int islandPerimeter(vector<vector<int>>& grid) {
        int flag=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid,int row,int col){
        // cout<<row<<" "<<col<<" "<<ans<<endl;
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]==0){
            ans++;
           return; 
        }

        if(grid[row][col]==-1)
            return;
            
        grid[row][col]=-1;
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
        return;
    }
};