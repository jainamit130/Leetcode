class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        for(auto p:points) {
            mp[p[1]]++;
        }
        int mod = 1e9+7;
        int ans = 0;
        int prefix = 0;
        for(auto [y,count]:mp) {
            if(count==1) continue;
            int p = count*1LL*(count-1)/2;
            ans = (ans + prefix*1LL*p%mod)%mod;
            prefix = (prefix+p)%mod;
        }
        return ans;
    }
};