class Solution {
public:
    vector<vector<int>> dir={{0,1},{-1,0},{0,-1},{1,0}};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int state=1;
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    dfs(grid1,grid2,i,j,state);
                    if(state==1) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int row,int col,int& ans){
        if(row<0 || row>=grid2.size() || col<0 || col>=grid2[0].size()){
            return;
        }

        if(grid2[row][col]!=1){
            return;
        }

        if(grid1[row][col]!=1){
            ans=0;
        }
      
        grid2[row][col]=2;
        for(auto d:dir){
            int newR=row+d[0];
            int newC=col+d[1];
            dfs(grid1,grid2,newR,newC,ans);
        }
        return; 
    }
};


/*
1   0   1   0   1   0
0   1   1   1   0   1
1   0   0   0   1   1
1   0   0   0   1   0
1   1   1   1   1   0




0   1   1   1   1   1
1   1   0   1   1   1
1   0   0   1   0   1
1   1   1   1   1   1   
1   0   0   1   0   0









*/