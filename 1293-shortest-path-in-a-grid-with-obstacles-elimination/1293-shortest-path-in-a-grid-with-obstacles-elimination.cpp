class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<vector<int>>> visited(m,vector<vector<int>>(n,vector<int>(k+1,0)));
        q.push({0,0,0,0});
        visited[0][0][0]=1;
        int steps = 0;
        while(!q.empty()) {
                int operations = q.front()[0];
                int row = q.front()[1];
                int col = q.front()[2];
                int steps = q.front()[3];
                q.pop();
                if(row==m-1 && col==n-1) {
                    return steps;
                }
                for(auto d:dir) {
                    int newRow = row + d[0];
                    int newCol = col + d[1];
                    if(isValid(newRow,newCol,m,n)) {
                        int newOperations = operations + grid[newRow][newCol];
                        if(newOperations<=k && visited[newRow][newCol][newOperations]==0) {
                            visited[newRow][newCol][newOperations]=1;
                            q.push({newOperations,newRow,newCol,steps+1});
                        } 
                    }
                }
        }   
        return -1;
    }

    bool isValid(int row,int col,int m,int n) {
        return row>=0 && row<m && col>=0 && col<n;
    }
};

/*


0   1   0   0   0   1   0   0   
0   1   0   1   0   1   0   1
0   0   0   1   0   0   1   0


*/