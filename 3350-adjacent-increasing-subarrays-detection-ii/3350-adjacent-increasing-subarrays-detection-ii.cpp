class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n= nums.size();
        vector<int> incSizes(n,1);
        int i=n-2;
        int ans = 0;
        while(i>=0){
            if(nums[i]<nums[i+1]) {
                incSizes[i] = incSizes[i+1]+1;
            } 
            ans = max(ans,incSizes[i]/2);
            i--;
        } 

        for(int i=0;i<n;i++) {
            if(incSizes[i]+i<n) {
                ans=max(ans,min(incSizes[i],incSizes[incSizes[i]+i]));
            }
        } 
        return ans;
    }
};