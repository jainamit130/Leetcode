class Solution {
    public:
    double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(101, vector<double>(101, 0.0));
    dp[0][0] = poured;

    for(int r = 0; r < query_row; r++) {
        for(int c = 0; c <= r; c++) {
            double overflow = max(0.0, (dp[r][c] - 1.0) / 2.0);
            dp[r+1][c] += overflow;
            dp[r+1][c+1] += overflow;
        }
    }

    return min(1.0, dp[query_row][query_glass]);
}

};

// class Solution {
// public:
//     vector<vector<double>> arr;
//     double champagneTower(int poured, int query_row, int query_glass) {
//         arr.resize(101,vector<double>(101));
//         solve(poured,0,0,query_row,query_glass);
//         return arr[query_row][query_glass];
//     }

//     void solve(double poured,int row,int col,int query_row, int query_glass) {
//         if(poured<=0) return;
//         if(row>query_row || col>query_row) return;
//         if(row==query_row && query_glass==col) {
//             arr[row][col] = min(poured,1.0);
//             return;
//         }
//         arr[row][col]+=poured;
//         solve(max(0.0,(poured-1.0)/2.0),row+1,col,query_row,query_glass);
//         solve(max(0.0,(poured-1.0)/2.0),row+1,col+1,query_row,query_glass);
//         return;
//     }
// };