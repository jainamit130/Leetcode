class Solution {
public:
    int mod = 1e9+7;
    int rearrangeSticks(int n, int k) {
        vector<vector<int>> cache(n+1,vector<int>(k+1,-1));
        return solve(n,k,cache);
    }

    int solve(int n,int k,vector<vector<int>>& cache){
        if(k==n)
            return 1;

        if(k==0 || n==0)
            return 0;

        if(cache[n][k]!=-1)
            return cache[n][k];

        cache[n][k]=(solve(n-1,k-1,cache)+(long)(n-1)*solve(n-1,k,cache))%mod;
        return cache[n][k];
    }
};