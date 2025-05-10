class Solution {
public:
    vector<int> cache;
    int climbStairs(int n) {
        cache.resize(n+1,-1);
        return solve(n);
    }

    int solve(int n) {
        if(n<=0) return n==0;
        if(cache[n]!=-1) return cache[n];
        int ans = 0;
        ans += solve(n-1) + solve(n-2);
        return cache[n] = ans;
    }
};


/*

Top down

States : just 1 that is n
choices => 1 or 2
O(2^n) => time complexity if done without memoization
O(n) => with memoization

*/