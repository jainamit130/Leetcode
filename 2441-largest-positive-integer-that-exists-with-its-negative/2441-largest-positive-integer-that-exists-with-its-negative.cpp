class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=INT_MIN;
        for(auto n:nums){
            if(mp.find(-n)!=mp.end())
                ans=max(ans,abs(n));
            mp[n]++;
        }
        if(ans==INT_MIN)
            return -1;
        return ans;
    }
};