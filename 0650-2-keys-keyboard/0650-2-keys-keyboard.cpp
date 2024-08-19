class Solution {
public:
    int minSteps(int n) {
        return solve(n,1,0);
    }

    int solve(int n,int curr,int copied){
        if(curr==n){
            return 0;
        }
        if(curr>n){
            return 1e5;
        }
        int ans=INT_MAX;
        if(copied==0)
            ans=min(ans,1+solve(n,curr,curr));
        else {
            ans=min(ans,1+solve(n,curr+copied,0));
            ans=min(ans,1+solve(n,curr+copied,copied));
        }
        return ans;
    }
};