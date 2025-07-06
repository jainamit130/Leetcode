class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) continue;
            vector<vector<int>> cache(nums[i]+1,vector<int>(queries.size()+1,-1));
            int subAns = solve(nums[i],queries,i,0,cache);
            if(subAns == 1001) return -1;
            ans = max(subAns,ans);
        }
        return ans;
    }

    int solve(int num,vector<vector<int>>& queries,int& numsIndex,int index,vector<vector<int>>& cache) {
        if(num==0) return index;
        if(index>=queries.size()) return 1001;
        if(cache[num][index]!=-1) return cache[num][index];
        int ans = 1001;
        int start = queries[index][0];
        int end = queries[index][1];
        int val = queries[index][2];
        ans = min(ans,solve(num,queries,numsIndex,index+1,cache));
        if(start<=numsIndex && numsIndex<=end && num>=val) {
            ans = min(ans,solve(num-val,queries,numsIndex,index+1,cache));
        }
        return cache[num][index]=ans;
    }
};


/*


queries
1   2   3   4   5


nums[i] > vali => may or may not use
        < vali => cannot use
        = vali => defintely use
*/