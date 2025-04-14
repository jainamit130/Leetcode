class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<vector<int>> q;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        q.push({0, 0, 0});
        dist[0][0]=0;
        while (!q.empty()) {
            int cost = q.front()[0];
            int row = q.front()[1];
            int col = q.front()[2];
            int sign = grid[row][col];
            q.pop();
            for (int i = 1; i <= 4; i++) {
                int newRow = row + dir[i - 1][0];
                int newCol = col + dir[i - 1][1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && dist[newRow][newCol]>(i!=sign)+cost) {
                    dist[newRow][newCol]=(i!=sign)+cost;
                    q.push({(i!=sign)+cost, newRow, newCol});
                }
            }
        }
        return dist[m-1][n-1];
    }
};