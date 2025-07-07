class Solution {
public:
    vector<vector<int>> cache;
    int minCost(int n, vector<int>& cuts) {
        vector<int> newCuts = {0};
        sort(cuts.begin(),cuts.end());
        for(int i=0;i<cuts.size();i++) newCuts.push_back(cuts[i]);
        newCuts.push_back(n);
        n = newCuts.size()+2;
        cache.resize(n+1,vector<int>(n+1,-1));
        return solve(newCuts,0,newCuts.size()-1);
    }

    int solve(vector<int>& cuts,int left,int right) {
        if(right-left==1) return 0;
        if(cache[left][right]!=-1) return cache[left][right];
        int ans = INT_MAX;
        for(int i=left+1;i<right;i++) {
            ans = min(ans,cuts[right]-cuts[left]+solve(cuts,left,i)+solve(cuts,i,right));
        }
        return cache[left][right]=ans;
    }
};