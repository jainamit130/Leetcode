class Solution {
public:
    int ans = INT_MAX;
    
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> freq(n);
        for(int i = 0; i < n; i++) {
            vector<int> currColFreq(10);
            for(int j = 0; j < m; j++) {
                currColFreq[grid[j][i]]++;
            }
            freq[i] = currColFreq;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(11, -1));
        dfs(freq, m, 0, 10, 0, dp);
        return ans;
    }

    void dfs(vector<vector<int>>& freq, int m, int index, int prev, int operations, vector<vector<int>>& dp) {
        if(index >= freq.size()) {
            ans = min(operations, ans);
            return;
        }

        if(dp[index][prev] != -1 && operations >= dp[index][prev]) {
            return;
        }

        for(int i = 0; i < 10; i++) {
            if(i != prev) {
                dfs(freq, m, index + 1, i, operations + m - freq[index][i], dp);
            }
        }
        dp[index][prev] = min(operations, dp[index][prev] != -1 ? dp[index][prev] : INT_MAX);
    }
};





// class Solution {
// public:
//     int ans=INT_MAX;
//     int minimumOperations(vector<vector<int>>& grid) {
//         vector<vector<pair<int,int>>> firstSecondChoice(grid[0].size());
//         for(int i=0;i<grid[0].size();i++){
//             unordered_map<int,int> mp;
//             priority_queue<pair<int,int>> pq;
//             for(int j=0;j<grid.size();j++){
//                 mp[grid[j][i]]++;
//             }
//             for(int k=0;k<=9;k++){
//                 pq.push({mp[k],k});
//             }
//             while(!pq.empty() && firstSecondChoice[i].size()<=2){
//                 firstSecondChoice[i].push_back({pq.top().second,pq.top().first});
//                 pq.pop();
//             }
//         }
//         dfs(firstSecondChoice,0,-1,grid[0].size(),0);
//         return ans;
//     }

//     void dfs(vector<vector<pair<int,int>>>& firstSecondChoice,int index,int prev,int size,int operations){
//         if(index>=firstSecondChoice.size()){
//             ans=min(ans,operations);
//             return;
//         }

//             dfs(firstSecondChoice,index+1,firstSecondChoice[index][0].first,size,operations+(size-firstSecondChoice[index][0].second));
//             dfs(firstSecondChoice,index+1,firstSecondChoice[index][1].first,size,operations+(size-firstSecondChoice[index][1].second));
//         return;
//     }
// };


/*

1   1   1

0   0   0

0   
0
1
1



*/