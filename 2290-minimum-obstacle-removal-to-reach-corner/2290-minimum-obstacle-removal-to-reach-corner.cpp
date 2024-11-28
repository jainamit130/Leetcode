class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = { {1,0}, {0,1}, {-1,0}, {0,-1} };
        vector<vector<int>> visited(m,vector<int>(n,0));
        visited[0][0]=1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        int ans = INT_MAX;
        while(!pq.empty()) {
            int row = pq.top()[1];
            int col = pq.top()[2];
            int obsCount = pq.top()[0];
            pq.pop();
            if(row == m-1 && col == n-1){
                ans = min(ans,obsCount);
            }

            for(int i=0;i<4;i++) {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && visited[newRow][newCol]==0) {
                    pq.push({obsCount + grid[newRow][newCol], newRow, newCol});
                    visited[newRow][newCol]=1;
                }
            }
        }
        return ans;
    }
};