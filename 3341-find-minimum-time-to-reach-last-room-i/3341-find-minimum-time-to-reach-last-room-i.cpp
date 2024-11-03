class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> shortestTime(m,vector<int>(n,INT_MAX));
        pq.push({0, 0, 0});
        shortestTime[0][0] = 0;
        while (!pq.empty()) {
            int row = pq.top()[1];
            int col = pq.top()[2];
            int time = pq.top()[0];
            pq.pop();
            if (row == m - 1 && col == n - 1) {
                return time;
            }
            for (int i = 0; i < dir.size(); i++) {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if (newRow < m && newRow >= 0 && newCol < n && newCol >= 0) {
                    int timeToArrive = max(moveTime[newRow][newCol], time) + 1;
                    if(timeToArrive<shortestTime[newRow][newCol]) {
                        shortestTime[newRow][newCol]= timeToArrive;
                        pq.push({timeToArrive,newRow, newCol});
                    }
                }
            }
        }
        return 0;
    }
};