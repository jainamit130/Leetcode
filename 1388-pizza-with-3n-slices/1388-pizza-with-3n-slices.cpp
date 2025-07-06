class Solution {
public:
    vector<vector<vector<int>>> cache;
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        cache.resize(n+1,vector<vector<int>>(n+1,vector<int>(n/3+1,-1)));
        return max(slices[0]+solve(slices,2,n-2,n/3-1),solve(slices,1,n-1,n/3));
    }

    int solve(vector<int>& slices,int start,int end,int size){
        if(size==0)
            return 0;
        
        if(start>end){
            return INT_MIN;
        }

        if(cache[start][end][size]!=-1){
            return cache[start][end][size];
        }

        int ans = 0;
        ans = max(slices[start]+solve(slices,start+2,end,size-1),solve(slices,start+1,end,size));
        return cache[start][end][size]=ans;
    }
};