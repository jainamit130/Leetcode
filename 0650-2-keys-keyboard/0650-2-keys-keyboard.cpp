class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> cache(n+1,vector<int>(n+1,-1));
        return solve(n,1,0,cache);
    }

    int solve(int& n,int count,int copyCount,vector<vector<int>>& cache) {
        if(n==count) return 0;
        if(count>n) return 1001;
        if(cache[count][copyCount]!=-1) return cache[count][copyCount]; 
        int ans = 1001;
        if(copyCount==0) ans = min(ans,1+solve(n,count,count,cache));
        else {
            ans = min(ans,1+solve(n,count+copyCount,0,cache));
            ans = min(ans,1+solve(n,count+copyCount,copyCount,cache));
        }
        return cache[count][copyCount]=ans;
    } 
};


/*




*/