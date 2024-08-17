class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int streak=0;
        if(k==1){
            ans.push_back(nums[0]);
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]-1){
                streak++;
            } else {
                streak=0;
            }
            if(i>=k-1){
                if(streak>=k-1){
                    ans.push_back(nums[i]);
                } else {
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};