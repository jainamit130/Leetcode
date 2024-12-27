class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            int cost = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            int sign = grid[row][col];
            pq.pop();
            if(row==m-1 && col==n-1) {
                return cost;
            }
            for (int i = 1; i <= 4; i++) {
                int newRow = row + dir[i - 1][0];
                int newCol = col + dir[i - 1][1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && dist[newRow][newCol]>(i!=sign)+cost) {
                    dist[newRow][newCol]=(i!=sign)+cost;
                    pq.push({(i!=sign)+cost, newRow, newCol});
                }
            }
        }
        return 0;
    }
};