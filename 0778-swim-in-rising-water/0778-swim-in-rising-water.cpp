class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} }; 
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        grid[0][0]=-1;
        while(!pq.empty()) {
            int time = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if(row==grid.size()-1 && col==grid.size()-1){
                return time;
            }
            for(int i=0;i<dir.size();i++) {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid.size() && grid[newRow][newCol]!=-1){
                    pq.push({max(time,grid[newRow][newCol]),newRow,newCol});
                    grid[newRow][newCol]=-1;
                }
            }
        }
        return 0;
    }
};