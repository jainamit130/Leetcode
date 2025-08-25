class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,nums[0]),suffix(n,nums.back()),ans(n);
        for(int i=1,j=n-2;i<n;i++,j--) {
            prefix[i] = max(prefix[i-1],nums[i]);
            suffix[j] = min(suffix[j+1],nums[j]);
        }
        
        ans[n-1] = prefix[n-1];
        for(int i=n-2;i>=0;i--) {
            ans[i] = prefix[i];
            if(prefix[i]>suffix[i+1]) ans[i] = ans[i+1];
        }
        return ans;
    }
};