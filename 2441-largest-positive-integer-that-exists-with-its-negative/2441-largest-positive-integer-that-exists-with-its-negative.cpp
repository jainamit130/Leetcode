class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
        }
        int ans=INT_MIN;
        for(auto n:nums){
            mp[n]--;
            if(mp[n]==0)
                mp.erase(n);
            if(mp.find(-n)!=mp.end())
                ans=max(ans,abs(n));
        }
        if(ans==INT_MIN)
            return -1;
        return ans;
    }
};