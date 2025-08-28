class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,priority_queue<int>> maxHeapMp;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> minHeapMp;
        int n = grid.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i-j>=0) maxHeapMp[i-j].push(grid[i][j]);
                else minHeapMp[i-j].push(grid[i][j]);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i-j>=0) {
                    grid[i][j]=maxHeapMp[i-j].top();
                    maxHeapMp[i-j].pop();
                } else {
                    grid[i][j]=minHeapMp[i-j].top();
                    minHeapMp[i-j].pop();
                } 
            }
        }
        return grid;
    }
};


/*




000  01-1  02-2  03  04

101  110  12-1  13-2  14

20  211  220  23-1  24-2

30  31  321  330  34-1

40  41  42  431  440





*/