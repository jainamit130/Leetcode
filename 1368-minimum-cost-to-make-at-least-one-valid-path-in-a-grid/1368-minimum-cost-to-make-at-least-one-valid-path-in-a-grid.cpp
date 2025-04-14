class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> dirMp = { {1,{0,1}}, {2,{0,-1}}, {3,{1,0}}, {4,{-1,0}} };
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        vector<vector<int>> distance(m,vector<int>(n,m*n));
        auto isValid = [&](int& row,int& col) {
            return row>=0 && row<m && col>=0 && col<n;
        };
        minHeap.push({0,0,0});
        distance[0][0]=0;
        while(!minHeap.empty()) {
            int dist = minHeap.top()[0];
            int row = minHeap.top()[1];
            int col = minHeap.top()[2];
            minHeap.pop();
            for(int i=1;i<=4;i++) {
                int newRow = row+dirMp[i][0];
                int newCol = col+dirMp[i][1];
                int newCost = dist+(grid[row][col]!=i);
                if(isValid(newRow,newCol) && distance[newRow][newCol]>newCost) {
                    distance[newRow][newCol] = newCost;
                    minHeap.push({newCost,newRow,newCol});
                }
            }
        }
        return distance[m-1][n-1];
    }
};

// class Solution {
// public:
//     int m,n;
//     unordered_map<int,vector<int>> dirMp = { {1,{0,1}}, {2,{0,-1}}, {3,{1,0}}, {4,{-1,0}} };
//     int minCost(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         return solve(grid,0,0);
//     }

//     bool isValid(int row,int col) {
//         return row>=0 && row<m && col>=0 && col<n;
//     }

//     int solve(vector<vector<int>>& grid,int row,int col) {
//         if(row==m-1 && col==n-1) return 0;
//         if(!isValid(row,col) || grid[row][col]==-1) return 1e4;
//         int ans = 1e4;
//         // just go
//         int temp = grid[row][col];
//         grid[row][col]=-1;
//         ans = min(ans,solve(grid,row+dirMp[temp][0],col+dirMp[temp][1]));
//         // change
//         for(int i=1;i<=4;i++) {
//             if(temp!=i) ans = min(ans,1+solve(grid,row+dirMp[i][0],col+dirMp[i][1]));
//         }
//         grid[row][col]=temp;
//         return ans;
//     }
// };


/*

Approach:
1. Select minCost via binary Search 
2. Try to change the direction of every arrow 

2^100



*/