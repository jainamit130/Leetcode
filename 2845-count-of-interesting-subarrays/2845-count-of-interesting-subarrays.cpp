class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {        
        unordered_map<long long,long long> mp;
        long long ans = 0, prefix = 0, n = nums.size();
        mp[0]++;
        for(int i=0;i<n;i++) {
            if(nums[i]%mod==k) 
                prefix++;
            prefix%=mod;
            if(mp.find((prefix-k+mod)%mod)!=mp.end())
                ans+=mp[(prefix-k+mod)%mod];
            mp[prefix]++;
        }
        return ans;
    }
};