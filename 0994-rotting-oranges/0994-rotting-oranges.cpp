class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int freshOranges = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                    visited[i][j]=1;
                } else {
                    visited[i][j]=0;
                }

                if(grid[i][j]==1) freshOranges++;
            }
        }
        int time = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                vector<int> indexes = q.front();
                int row = indexes[0];
                int col = indexes[1];
                q.pop();
                for(auto d:dir) {
                    int newRow = row+d[0];
                    int newCol = col+d[1];
                    // Mark if the new orange is fresh
                    if(isValid(newRow,newCol,m,n) && visited[newRow][newCol]==0 && grid[newRow][newCol]==1) {
                        visited[newRow][newCol]=1;
                        freshOranges--;
                        q.push({newRow,newCol});
                    }
                }              
            }
            time++;
        }
        if(freshOranges>0) return -1;
        return max(0,time-1);
    }

    bool isValid(int row,int col,int m,int n) {
        if(row>=0 && row<m && col>=0 && col<n) {
            return true;
        }
        return false;
    }
};

