class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int ans = INT_MIN;
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(nums1[i]==nums2[j]) {
                    dp[i][j]=dp[i+1][j+1]+1;
                    ans = max(ans,dp[i][j]);
                }   
            }
        }

        return ans;
    }
};



/*

smaller (nums1 size, nums2 size) = smaller size

0 - smaller size


x   x   x   x   x   x   x   x   x
x   x   x   x
    x   x   x   x
        x   x   x   x
            x   x   x   x
                x   x   x   x
                    x   x   x   x
                        



*/