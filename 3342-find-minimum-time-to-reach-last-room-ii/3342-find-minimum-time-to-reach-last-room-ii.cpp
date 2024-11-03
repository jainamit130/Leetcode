
        class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> dir={ {0,1}, {1,0} , {0,-1}, {-1,0} };    
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> earliestTime(m,vector<int>(n,INT_MAX));
        pq.push({0,0,0,1});
        earliestTime[0][0]=0;
        while(!pq.empty()){
            int time = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            int travelTime = pq.top()[3];
            pq.pop();
            if(row == m-1 && col == n-1){
                return time;
            }

            for(int i=0;i<dir.size();i++){
                int newRow = row+dir[i][0];
                int newCol = col+dir[i][1];
                if(newRow<m && newRow>=0 && newCol<n && newCol>=0){
                    int timeToArrive = max(time,moveTime[newRow][newCol])+1;
                    if(travelTime==2){
                        timeToArrive++;
                    }
                    if(timeToArrive<earliestTime[newRow][newCol]){
                        earliestTime[newRow][newCol] = timeToArrive;
                        pq.push({timeToArrive,newRow,newCol,travelTime==1?2:1});
                    }
                }
            }
        }
        return -1;
    }
};


