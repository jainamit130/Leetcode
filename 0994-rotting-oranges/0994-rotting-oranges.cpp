class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int good=0;
        queue<pair<int,int>> q;
        int time=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    good++;
                }
            }
        }
        if(good==0)
            return 0;
        while(!q.empty()){
            int size=q.size();
            while(size){
                auto [row,col]=q.front();
                q.pop();
                size--;
                if(!valid(row,col,m,n))
                    continue;
                if(grid[row][col]==0 || grid[row][col]==-1)
                    continue;
                // cout<<row<<" "<<col<<" "<<time<<endl;
                if(grid[row][col]==1)
                    good--;
                grid[row][col]=-1;
                q.push({row+1,col});
                q.push({row,col+1});
                q.push({row,col-1});
                q.push({row-1,col});
            }
            time++;
            if(good==0)
                break;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        if(good==0)
            return time;  
        return -1;
    }

    bool valid(int r,int c,int m,int n){
        if(r<0 || r>=m || c<0 || c>=n)
            return false;
        return true;
    }
};


/*
queue =  01 0-1 -10

-1   -1   1
0   1   1
1   0   1

*/