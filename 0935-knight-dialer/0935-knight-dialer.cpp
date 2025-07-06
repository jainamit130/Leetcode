class Solution {
public:
    vector<vector<int>> adj = {
        {4,6},
        {6,8},
        {7,9},
        {8,4},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };
    int m = 4,n = 3;
    int mod = 1e9+7;
    vector<vector<int>> cache;
    int knightDialer(int len) {
        int ans = 0;
        cache.resize(10,vector<int>(len,-1));
        for(int i=0;i<10;i++) {
            ans = (ans + dp(i,len-1))%mod;
        }
        return ans;
    }

    int dp(int dial,int len) {
        if(len==0) return 1;
        if(cache[dial][len]!=-1) return cache[dial][len];
        int ans = 0;
        for(auto neigh:adj[dial]) {
            ans = (ans + dp(neigh,len-1))%mod;
        }
        return cache[dial][len]=ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> dialar = { {1,2,3}, {4,5,6}, {7,8,9}, {-1,0,-1} };
//     vector<vector<int>> dir = { {-2,1}, {-2,-1}, {2,-1}, {2,1}, {1,2}, {-1,2}, {1,-2}, {-1,-2} };
//     int m = 4,n = 3;
//     int mod = 1e9+7;
//     vector<vector<vector<int>>> cache;
//     int knightDialer(int len) {
//         int ans = 0;
//         cache.resize(m+1,vector<vector<int>>(n+1,vector<int>(len,-1)));
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++) {
//                 if(dialar[i][j]!=-1) {
//                     ans = (ans + dp(i,j,len-1))%mod;
//                 }
//             }
//         }
//         return ans;
//     }

//     bool isValid(int row,int col) {
//         return row>=0 && col>=0 && row<m && col<n && dialar[row][col]!=-1;
//     }

//     int dp(int row,int col,int len) {
//         if(len==0) return 1;
//         if(cache[row][col][len]!=-1) return cache[row][col][len];
//         int ans = 0;
//         for(auto d:dir) {
//             int newRow = d[0] + row;
//             int newCol = d[1] + col;
//             if(isValid(newRow,newCol)) {
//                 ans = (ans + dp(newRow,newCol,len-1))%mod;
//             }
//         }
//         return cache[row][col][len]=ans;
//     }
// };