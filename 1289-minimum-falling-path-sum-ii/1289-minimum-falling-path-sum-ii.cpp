// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,INT_MAX));
//         return dfs(0,grid,-1,dp);
//     }

//     int dfs(int row,vector<vector<int>>& grid,int prevCol,vector<vector<int>>& dp){
//         if(row>=grid.size()){
//             return 0;
//         }

//         if(dp[row][prevCol+1]!=INT_MAX){
//             return dp[row][prevCol+1];
//         }

//         int result=INT_MAX;
//         for(int col=0;col<grid[0].size();col++){
//             if(prevCol==col)
//                 continue;
//             result=min(result,grid[row][col]+dfs(row+1,grid,col,dp));
//         }
//         return dp[row][prevCol+1]=result;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int fm = 0, sm = 0, pos = -1;
        for (auto i = 0; i < arr.size(); ++i) {
            auto fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1;
            for (auto j = 0; j < arr[i].size(); ++j) {
                auto mn = j != pos ? fm : sm;
                if (arr[i][j] + mn < fm2) {
                    sm2 = fm2;
                    fm2 = arr[i][j] + mn;
                    pos2 = j;
                } else sm2 = min(sm2, arr[i][j] + mn);
            }
            fm = fm2, sm = sm2, pos = pos2;
        }
        return fm;
    }
};

// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int pos=-1;
//         int ans=0;
//         for(int i=0;i<grid.size();i++){
//             priority_queue<pair<int,int>> pq;
//             for(int j=0;j<grid[0].size();j++){
//                 if(pq.size()<2)
//                     pq.push({grid[i][j],j});
//                 else {
//                     if(pq.top().first>grid[i][j]){
//                         pq.pop();
//                         pq.push({grid[i][j],j});
//                     }
//                 }
//             }
//             priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1;
//             while(!pq.empty()){
//                 pq1.push(pq.top());
//                 pq.pop();
//             }
//             if(pos==pq1.top().second)
//                 pq1.pop();
//             ans+=pq1.top().first;
//             pos=pq1.top().second;
//         }
//         return ans;
//     }
// };


/*

*   *   *   *   *
-   -   -   -   -
*   *   *   *   *



*/