class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> cache(n+1,vector<int>(n+1,-1));
        return solve(n,1,0,cache);
    }

    int solve(int n,int curr,int copied,vector<vector<int>>& cache){
        if(curr==n){
            return 0;
        }
        if(curr>n){
            return 1e5;
        }

        if(cache[curr][copied]!=-1){
            return cache[curr][copied];
        }

        int ans=INT_MAX;
        if(copied==0)
            ans=min(ans,1+solve(n,curr,curr,cache));
        else {
            ans=min(ans,1+solve(n,curr+copied,0,cache));
            ans=min(ans,1+solve(n,curr+copied,copied,cache));
        }
        return cache[curr][copied]=ans;
    }
};