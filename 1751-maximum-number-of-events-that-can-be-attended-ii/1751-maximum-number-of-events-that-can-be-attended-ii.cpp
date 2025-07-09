class Solution {
public:
    vector<vector<int>> cache;
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        cache.resize(events.size()+1,vector<int>(k+1,-1));
        return solve(0,k,events);
    }

    int solve(int index,int k,vector<vector<int>>& events) {
        if(index>=events.size()) return k>=0 ? 0:INT_MIN;
        if(k==0) return 0;
        if(k<0) return INT_MIN;
        if(cache[index][k]!=-1) return cache[index][k];
        int ans = 0;
        ans = max(ans,solve(index+1,k,events));
        int upperBound = events[index][1];
        int val = events[index][2];
        int nextIndex = upper_bound(events.begin()+index+1,events.end(),upperBound,[](int val, const std::vector<int>& v) {
            return val < v[0];
        })-events.begin();
        ans = max(ans,val+solve(nextIndex,k-1,events));
        return cache[index][k]=ans;
    }
};

/*

sort based on event values




*/