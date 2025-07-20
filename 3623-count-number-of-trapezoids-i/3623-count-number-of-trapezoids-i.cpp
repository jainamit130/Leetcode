class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        for(auto p:points) {
            mp[p[1]]++;
        }
        int mod = 1e9+7;
        long long ans = 0;

        long long prefix = 0;
        for(auto [y,count]:mp) {
            if(count==1) continue;
            int p = count*1LL*(count-1)/2;
            ans = (ans + prefix*p%mod)%mod;
            prefix = (prefix+p)%mod;
        }
        return (int)ans;
    }
};


/*

p1
p2
p3

p1 * p2 + p1 * p3 + p2 * p3

*/