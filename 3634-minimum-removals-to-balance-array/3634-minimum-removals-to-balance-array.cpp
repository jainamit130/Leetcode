class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int ans = n;
        while(i<=j && j<n) {
            if((nums[i]*1LL*k)>=nums[j]) j++;
            else i++;
            ans = min(ans,n-(j-i+1));
        }
        return ans+1;
    }
};