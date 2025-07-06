class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> dir = { {0,1}, {0,-1}, {-1,0}, {1,0} };
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        int m = moveTime.size();
        int n = moveTime[0].size();
        moveTime[0][0]=-1;
        while(!pq.empty()) {
            int time = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if(row==m-1 && col==n-1) return time;
            for(auto d:dir) {
                int newRow = d[0]+row;
                int newCol = d[1]+col; 
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && moveTime[newRow][newCol]!=-1) {
                    pq.push({max(time,moveTime[newRow][newCol])+1,newRow,newCol});
                    moveTime[newRow][newCol]=-1;
                }
            }
        }
        return -1;
    }
};