class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            // binary Search
            int index = upper_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            if(k-index>nums.size()-i) {
                ans.push_back(nums[i]);
                continue;
            }
            while(!ans.empty() && ans.back()>nums[i]){
                ans.pop_back();
            }
            ans.push_back(nums[i]);
            while(ans.size()>k){
                ans.pop_back();
            }
        }
        return ans;
    }
};