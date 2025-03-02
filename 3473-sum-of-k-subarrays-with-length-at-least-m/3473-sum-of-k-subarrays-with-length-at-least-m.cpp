class Solution {
public:
    int cache[2002][2002][2];
    int maxSum(vector<int>& nums, int k, int m) {
        vector<int> prefix(1);
        memset(cache,-1,sizeof(cache));
        for(auto n:nums) prefix.push_back(prefix.back()+n);
        return solve(nums,prefix,m,0,k,0);
    }

    int solve(vector<int>& nums,vector<int>& prefix,int& m,int index,int k,int canContinue) {
        if(index>=nums.size()) return k==0?0:-2*1e8;
        if(cache[index][k][canContinue]!=-1) return cache[index][k][canContinue];
        int ans = INT_MIN;
        if(canContinue) { // we have started the subArray with atlease m elements accounted in the sum
            // keep continuing 1 by 1 each element and add its contibution to the sum
            ans = max(ans,nums[index]+solve(nums,prefix,m,index+1,k,canContinue));
            // End the subarray
            ans = max(ans,solve(nums,prefix,m,index,k,0));
        } else { // we have not started the subarray yet
            if(k==0) return 0;
            // start it
            if(nums.size()-index>=m)
                ans = max(ans,prefix[index+m]-prefix[index]+solve(nums,prefix,m,index+m,k-1,1));
            // Skip it
            ans = max(ans,solve(nums,prefix,m,index+1,k,0));
        }
        return cache[index][k][canContinue]=ans;
    }
};

/*

States => ?
index
k
canContinue


k = 3
m = 3

a   b   c   d   e   f   g   h   i   j   k   
            i
                    j
                                k

Decisions=> 
skip element => index+1,k,canContinue = false

end element => index,k,canContinue = false

continue extending subarray window => add the nums[index] contribution to the already cal sum of elements for this subarray => nums[index] + solve(index+1,k,1);

start subarray => strainght away take sum of m elements into account (using prefix sum)
=> prefix[index+m] - prefix[index] + solve(index+m,k-1,1);

*/