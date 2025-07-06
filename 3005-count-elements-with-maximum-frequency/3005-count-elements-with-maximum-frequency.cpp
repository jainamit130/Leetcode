class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto& [nums,count]:mp){
            if(maxi<count){
                maxi=count;
                ans=0;
            }
            if(maxi==count){
                ans+=count;
            }
        }
        return ans;
    }
};