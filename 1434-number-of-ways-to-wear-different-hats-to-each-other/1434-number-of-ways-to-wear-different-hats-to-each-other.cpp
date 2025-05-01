class Solution {
public:
    int mod = 1e9+7;
    int n=0;
    vector<vector<int>> cache;
    int numberWays(vector<vector<int>>& hatss) {
        vector<vector<int>> hats(41);
        n=hatss.size();
        cache.resize(41,vector<int>(2050,-1));
        for(int index=0;index<hatss.size();index++) {
            for(auto hat:hatss[index]) {
                hats[hat].push_back(index);
            }
        }

        return solve(hats,1,0);
    }

    int solve(vector<vector<int>>& hats,int index,int assignment) {
        if(index>=41) return  assignment == (1 << n) - 1 ? 1 : 0;
        if(cache[index][assignment]!=-1) return cache[index][assignment];
        int ans = 0;
        for(auto person:hats[index]) {
            if((assignment&(1<<person))==0) {
                ans=(ans+solve(hats,index+1,assignment|(1<<person)))%mod;
            }
        }
        ans=(ans+solve(hats,index+1,assignment))%mod;
        return cache[index][assignment]=ans;
    }
};