class Solution {
public:
    int minDays(int n) {
        unordered_map<int,int> cache;
        return dp(n,cache);
    }

    int dp(int n,unordered_map<int,int>& cache){
        if(n==0){
            return 0;
        }

        if(cache.find(n)!=cache.end())
            return cache[n];

        int days=INT_MAX;
        if(n%3==0)
            days=min(days,1+dp(n/3,cache));
        else
            days=min(days,1+dp(n-1,cache));

        if(n%2==0)
            days=min(days,1+dp(n/2,cache));
        else
            days=min(days,1+dp(n-1,cache));

        return cache[n]=days;
    }
};