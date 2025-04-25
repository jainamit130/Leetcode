class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int runningCount = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        long long ans = 0;
        for(auto n:nums) {
            if(n%modulo==k) runningCount=(runningCount+1)%modulo;
            int valToLookUp = (runningCount-k+modulo)%modulo;
            ans+=mp[valToLookUp];
            mp[runningCount]++;
        }
        return ans;
    }
};