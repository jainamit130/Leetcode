class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> prefix;
        prefix.push_back(0);
        for(auto n:nums) {
            prefix.push_back(prefix.back()+n);
        }
        int ans = 0;
        for(auto n:prefix) {
            int valToLookUp = n<k?n%k:n-k;
            if(mp.find(valToLookUp)!=mp.end()) ans+=mp[valToLookUp];
            mp[n%5]++;
        }
        return ans;
    }
};