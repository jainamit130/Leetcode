class Solution {
public:
    int m;
    int n;
    bool isValid(int row,int col){
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    vector<vector<int>> cases={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int row,int col,vector<vector<int>>& grid,queue<vector<int>>& q,set<pair<int,int>>& visited){
        if(!isValid(row,col) || visited.find({row,col})!=visited.end() || grid[row][col] == 0){
            return;
        }
        q.push({row,col});
        visited.insert({row,col});
        for(int i=0;i<cases.size();i++){
            int nrow=cases[i][0]+row;
            int ncol=cases[i][1]+col;
            dfs(nrow,ncol,grid,q,visited);
        }    
        return;
    }

    int bfs(vector<vector<int>>& grid,queue<vector<int>>& q,set<pair<int,int>>& visited){
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size){
                int row=q.front()[0];
                int col=q.front()[1];
                q.pop();
                size--;
                for(int i=0;i<cases.size();i++){
                    int nrow=cases[i][0]+row;
                    int ncol=cases[i][1]+col;
                    if(!isValid(nrow,ncol) || visited.find({nrow,ncol})!=visited.end())
                        continue;
                    if(grid[nrow][ncol]==1){
                        return level; 
                    }
                    visited.insert({nrow,ncol});
                    q.push({nrow,ncol});
                }
            }
            level++;
        }
        return level;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        //dfs
        queue<vector<int>> q;
        set<pair<int,int>> visited;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,q,visited);
                    return bfs(grid,q,visited);
                }
            }
        }   
        return 0;
    }
};



/*

0   1
1   0



0   1   0
0   0   0
0   0   1



1   1   1   1   1
1   0   0   0   1
1   0   1   0   1
1   0   0   0   1
1   1   1   1   1




*/