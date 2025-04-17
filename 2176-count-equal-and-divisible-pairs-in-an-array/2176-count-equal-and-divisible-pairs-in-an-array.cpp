class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto n:nums) {
            if(n%k==0) {
                ans+=mp[n];
                mp[n]++;
            }
        }
        return ans;
    }
};