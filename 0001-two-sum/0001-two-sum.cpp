class Solution {
public:
    map<int,int> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end())
                return {mp[nums[i]],i};
            else {
                mp[target-nums[i]]=i;
            }
        }
        return {};
    }
};