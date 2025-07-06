class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> prefix(m+1,vector<int>(n+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefix[i+1][j+1]=matrix[i][j]+prefix[i][j+1]+prefix[i+1][j]-prefix[i][j];
            }
        } 

        int ans = INT_MIN;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int t=i;t<=m;t++){
                    for(int l=j;l<=n;l++){
                        int sum = prefix[t][l] - prefix[i-1][l] - prefix[t][j-1] + prefix[i-1][j-1];
                        if (sum <= k)
                            ans = max(ans, sum);
                    }
                }
            }
        }
        return ans;
    }
};

/*

1
-8
4
-13


1   -7  3   -10


*/