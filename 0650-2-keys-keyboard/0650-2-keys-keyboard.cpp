class Solution {
public:
    vector<vector<vector<int>>> cache;
    int minSteps(int n) {
        cache.resize(n+n+1,vector<vector<int>>(n+n+1,vector<int>(2,-1)));
        return solve(n,1,0,1);
    }

    int solve(int& n,int count,int copyCount,int canCopy) {
        if(n==count) return 0;
        if(count>n) return 1001;
        if(cache[count][copyCount][canCopy]!=-1) return cache[count][copyCount][canCopy];
        int ans = 1001;
        if(copyCount>0) ans = min(ans,1+solve(n,count+copyCount,copyCount,1));
        if(canCopy) ans = min(ans,1+solve(n,count,count,0));
        return cache[count][copyCount][canCopy]=ans;
    } 
};


/*




*/