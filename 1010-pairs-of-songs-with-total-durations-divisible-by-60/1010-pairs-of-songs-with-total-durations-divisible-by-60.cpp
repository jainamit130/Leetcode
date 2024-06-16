class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto t: time){
            ans += mp[(60 - t%60)%60];
            mp[t%60]++;
        }
        return ans;
    }
};