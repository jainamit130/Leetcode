class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]==0) continue;
            vector<vector<int>> cache(nums[i]+1,vector<int>(queries.size()+1,-1));
            int subAns = solve(nums[i], i, 0, queries,cache);
            if(subAns==1001) return -1;
            ans = max(subAns,ans);
        }
        return ans;
    }

    int solve(int num, int& numIndex, int index, vector<vector<int>>& queries,vector<vector<int>>& cache) {
        if(num==0) return index;
        if(index>=queries.size()) return 1001;
        if(cache[num][index]!=-1) return cache[num][index];
        int ans = 1001;
        int start = queries[index][0];
        int end = queries[index][1];
        int val = queries[index][2];
        ans = min(ans,solve(num,numIndex,index+1,queries,cache));
        if (start <= numIndex && numIndex <= end && val<=num) {
            ans = min(ans,solve(num-val,numIndex,index+1,queries,cache));
        }
        return cache[num][index]=ans;
    }
};

/*
0   1   2
2   0   2


0   2   1

if nums[i]>val then can do decrement if nums[i]<val then cannot do the decrement
min val
max val

if 2 values are equal then i should decide the same out come for them
i can skip the query for a index
or i can apply the query for a index

*/