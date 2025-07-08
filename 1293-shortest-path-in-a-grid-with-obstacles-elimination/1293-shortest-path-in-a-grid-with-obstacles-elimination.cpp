class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> dir = { {0,1}, {1,0}, {-1,0}, {0,-1} };
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<vector<int>>> visited(m,vector<vector<int>>(n,vector<int>(k+1)));
        pq.push({0,0,0,k});
        visited[0][0][k]=1;
        while(!pq.empty()) {
            int steps = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            int canRemoveWall = pq.top()[3];
            pq.pop();
            if(row==m-1 && col==n-1) return steps;
            for(auto d:dir) {
                int newRow = d[0] + row;
                int newCol = d[1] + col;
                if(newRow<0 || newRow>=m || newCol<0 || newCol>=n) continue;
                if(visited[newRow][newCol][canRemoveWall]==0) {
                    visited[newRow][newCol][canRemoveWall]=1;
                    if(canRemoveWall>0 || (canRemoveWall==0 && grid[newRow][newCol]==0))
                        pq.push({steps+1,newRow,newCol,canRemoveWall-(grid[newRow][newCol]==1)});
                }
            }
        }
        return -1;
    }
};