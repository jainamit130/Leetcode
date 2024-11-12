class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int mod = 1e9+7;
        int ans = 0;
        unordered_map<int,pair<int,long long>> mp;
        for(auto n:nums) {
            int l = n-1;
            int u = n+1;
            int currTotal = n;
            long long count = 0;
            if(mp.find(l)!=mp.end()){
                currTotal=(currTotal+(mp[l].first+1LL*mp[l].second*n)%mod)%mod;
                count+=mp[l].second;
            }
            if(mp.find(u)!=mp.end()){
                currTotal=(currTotal + (mp[u].first+1LL*mp[u].second*n)%mod)%mod;
                count+=mp[u].second;
            }
            ans = (ans+currTotal)%mod;
            if(mp.find(n)==mp.end()){
                mp[n]={currTotal,count+1};
            } else {
                mp[n]={(mp[n].first+currTotal)%mod,mp[n].second+count+1};
            }
        }
        return ans;
    }
};


/*

1   2   1
        i

1 -> 1,1

1 -> 1,1
2 -> 5,2 



*/