class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        for(auto p:points) {
            mp[p[1]]++;
        }
        int mod = 1e9+7;
        long long ans = 0;

        vector<long long> pairs;
        for(auto [y,count]:mp) {
            if(count>1) pairs.push_back(count*1LL*(count-1)/2);
        }
        long long prefix = 0;
        for(auto p:pairs) {
            ans = (ans + prefix*p%mod)%mod;
            prefix = (prefix+p)%mod;
        }
        return (int)ans;
    }
};


/*





*/