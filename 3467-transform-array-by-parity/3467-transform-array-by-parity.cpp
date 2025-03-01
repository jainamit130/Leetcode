class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int count1 = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]%2!=0) {
                count1++;
            }
        }

        for(int i=nums.size()-1;i>=0 && count1>0;i--) {
            ans[i]=1;
            count1--;
        }
        return ans;
    }
};