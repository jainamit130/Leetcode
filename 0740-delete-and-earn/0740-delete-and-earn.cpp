class Solution {
public:
    vector<vector<int>> cache;
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> numsToFreq;
        for(auto n:nums) {
            numsToFreq[n]++;
        }

        vector<pair<int,int>> vecs;
        for(auto [key,freq]:numsToFreq) {
            vecs.push_back({key,freq});
        }
        sort(vecs.begin(),vecs.end());
        cache.resize(vecs.size()+1,vector<int>(vecs.back().first+2,-1));
        return solve(vecs,0,-1);
    }

    int solve(vector<pair<int,int>>& vec,int index,int lastTaken) {
        if(index>=vec.size())  {
            return 0;
        } 
        if(cache[index][lastTaken+1]!=-1) return cache[index][lastTaken+1];
        int ans = 0;
        if(lastTaken+1!=vec[index].first) {
            ans = max(ans,vec[index].second*vec[index].first+solve(vec,index+1,vec[index].first));
        }
        ans = max(ans,solve(vec,index+1,lastTaken));
        return cache[index][lastTaken+1]=ans;
    }
};

/*

27 + 15 + 14 + 4 + 


*/