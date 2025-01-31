class Solution {
public:
    vector<vector<int>> dir = { {0,1}, {0,-1}, {-1,0}, {1,0} };
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int label = 2;
        int ans = 0;
        // precompute area and update grid
        unordered_map<int,int> areaMp;
        for(int row=0;row<m;row++) {
            for(int col=0;col<n;col++) {
                if(grid[row][col]) ans = max(ans,1);
                for(int k=0;k<4;k++) {
                    int newRow = row+dir[k][0];
                    int newCol = col+dir[k][1];
                    if(isValid(newRow,newCol,m,n) && grid[newRow][newCol]==1) {
                        int area = dfs(grid,newRow,newCol,label);
                        ans = max(area,ans);
                        if(area>0) areaMp[label]=area;
                        label++;
                    }
                }
            }
        }

        for(int row=0;row<m;row++) {
            for(int col=0;col<n;col++) {
                int area = grid[row][col]?0:1;
                unordered_set<int> visited;
                for(int k=0;k<4;k++) {
                    int newRow = row+dir[k][0];
                    int newCol = col+dir[k][1];
                    if(!isValid(newRow,newCol,m,n)) continue;
                    int label = grid[newRow][newCol];
                    if(visited.find(label)==visited.end()) {
                        area+=areaMp[label];
                        visited.insert(label);
                    }
                }
                ans = max(area,ans);
            }
        }
        return ans;
    }

    bool isValid(int row,int col,int m,int n) {
        return (row>=0 && row<m && col>=0 && col<n);
    }

    int dfs(vector<vector<int>>& grid,int row,int col,int& label) {
        if(!isValid(row,col,grid.size(),grid[0].size()) || grid[row][col]!=1) {
            return 0;
        } 
        grid[row][col] = label;
        int ans = 1;
        for(int i=0;i<4;i++) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            if(!isValid(newRow,newCol,grid.size(),grid[0].size()) || grid[newRow][newCol]!=1) continue;
            ans = 1+dfs(grid,newRow,newCol,label);
        }
        return ans;
    }
};