class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][0]+1<grid[0][1] && grid[0][0]+1<grid[1][0]){
            return -1;
        }
        vector<vector<int>> dir = { {1,0}, {-1,0}, {0,1}, {0,-1} };
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        int m = grid.size();
        int n = grid[0].size();
        while(!pq.empty()) {
            int time= pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if(row == m-1 && col == n-1) {
                return time;
            }

            for(auto d:dir) {
                int newRow = d[0] + row;
                int newCol = d[1] + col;
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]!=-1) {
                    int diff = grid[newRow][newCol] - time;
                    int newTime = diff<1?time+1:grid[newRow][newCol];
                    if(diff>=2 && diff%2==0){
                        newTime++;
                    }
                    pq.push({newTime,newRow,newCol});
                    grid[newRow][newCol] = -1;
                } 
            }
        }
        return -1;
    }
};


/*

0   38   86   76
1   90   75   49
87  29   42   76
92  48   82   0
85  7    36   81



*/