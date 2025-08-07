class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int diagonal = 0;
        int n= fruits.size();
        for(int i=0;i<n;i++){
            diagonal+= fruits[i][i];
        }     

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        dp[0][n-1] = fruits[0][n-1];
        for(int i=1;i<n;i++) {
            for(int j = n-1; j>i ; j--) {
                int maxVal = max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
                if(maxVal!=-1){
                    dp[i][j] = fruits[i][j] + maxVal;
                }
            }
        }
        int i=n-1,j=n-1;
        dp[i][j] = max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});

        vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
        dp1[n-1][0] = fruits[n-1][0];
        for(int j=1;j<n;j++) {
            for(int i = n-1; i>j ; i--) {
                int maxVal = max({dp1[i-1][j-1], dp1[i][j-1], dp1[i+1][j-1]});
                if(maxVal!=-1){
                    dp1[i][j] = fruits[i][j] + maxVal;
                }
            }
        }
        dp1[i][j] = max({dp1[i-1][j-1], dp1[i][j-1], dp1[i+1][j-1]});

        return diagonal + dp[n-1][n-1] + dp1[n-1][n-1];
    }
};


/*

1. Sum up the main diagonal

Formula
1. bottom left: dp[i][j]=fruits[i][j] +max(dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1])
2. top right: dp[i][j]=fruits[i][j] + max(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])



*/