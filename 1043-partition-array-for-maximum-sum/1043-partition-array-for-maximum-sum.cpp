class Solution {
public:
    vector<int> cache;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        cache.resize(arr.size()+1,-1);
        return solve(arr,0,k);
    }

    int solve(vector<int>& arr,int index,int& k) {
        if(index>=arr.size()) return 0;
        if(cache[index]!=-1) return cache[index];
        int currMax = arr[index];
        int ans = currMax;
        for(int i=index+1;i<=arr.size();i++) {
            if(i-index<=k) {
                ans = max(ans,(currMax * (i-index)) + solve(arr,i,k));
                if(i==arr.size()) break;
                currMax = max(currMax,arr[i]);
            }
        }
        return cache[index]=ans;
    }
};


/*

1   15  7   9   2   5   10




*/