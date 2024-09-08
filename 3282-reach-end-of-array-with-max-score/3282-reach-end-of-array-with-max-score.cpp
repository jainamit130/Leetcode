class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int last=0;
        long long ans=0;
        for(int i=1;i<nums.size() && last<nums.size()-1;i++)
        {
            ans+=nums[last];
            if(nums[last]<nums[i])
            {
                last=i;
            }
        }
        return ans;
    }
};