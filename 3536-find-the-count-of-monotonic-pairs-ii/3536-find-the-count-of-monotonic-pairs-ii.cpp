class Solution {
public:
    int mod = 1e9 + 7;
    int countOfPairs(vector<int>& nums) {
        const int N = 2001;  
        int n = nums.size();
        vector<int> dp(N, 1);  
        
        for (int index = n - 1; index >= 0; index--) {
            vector<int> newDp(N, 0); 
            vector<int> prefix(N, 0); 
            
            prefix[0] = dp[0];
            for (int j = 1; j < N; j++) 
                prefix[j] = (prefix[j - 1] + dp[j]) % mod;
            
            for (int arr1B = 0; arr1B <= 2000; arr1B++) {
                int arr2B = (index > 0) ? nums[index - 1] - arr1B : 2000;
                
                if (arr2B < 0) 
                    break;
                
                int l = max(arr1B, nums[index] - arr2B);
                int r = nums[index];
                
                if (l <= r)
                    newDp[arr1B] = (prefix[r] - (l > 0 ? prefix[l - 1] : 0) + mod) % mod;
            }
            dp = newDp;
        }

        return dp[0];
    }
};
