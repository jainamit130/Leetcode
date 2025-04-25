class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> prefix(1);
        for(auto n:nums) prefix.push_back(prefix.back()+n);
        int ans = 0;
        for(auto n:prefix) {
            int valToLookUp = (n%k+k)%k;
            ans+=mp[valToLookUp];
            mp[valToLookUp]++;
        }
        return ans;
    }
};