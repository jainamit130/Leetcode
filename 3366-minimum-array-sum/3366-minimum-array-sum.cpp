class Solution {
public:
    vector<vector<vector<int>>> cache;
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        cache.resize(101,vector<vector<int>>(101,vector<int>(101,-1)));
        return solve(nums,k,0,op1,op2);
    }

    int solve(vector<int>& nums,int& k,int index,int op1,int op2) {
        if(index>=nums.size()) {
            return 0;
        }

        if(cache[index][op1][op2]!=-1) {
            return cache[index][op1][op2];
        }

        int ans = INT_MAX;
        // Do nothing
        ans = min(ans, nums[index]+ solve(nums,k,index+1,op1,op2));

        // Divide only
        if(op1>0) {
            ans = min(ans, (nums[index]+1) / 2 + solve(nums,k,index+1,op1-1,op2));
        }

        // Subtract Only
        if(op2>0 && nums[index]>=k) {
            ans = min(ans, (nums[index]-k) + solve(nums,k,index+1,op1,op2-1));
        }

        // Divide and then Subtract
        if(op1>0 && op2>0 && ((nums[index]+1)/2)>=k) {
            ans = min(ans, ((nums[index]+1)/2) - k + solve(nums,k,index+1,op1-1,op2-1));
        }

        // Subtract and then Divide
        if(op1>0 && op2>0 && nums[index]>=k) {
            ans = min(ans, (nums[index] - k + 1)/2 + solve(nums,k,index+1,op1-1,op2-1));
        }

        return cache[index][op1][op2]=ans;
    }
};


/*


1. not take => dont perform any operation
2. take => 
    1. divide / 2
    2. subtract k
    3. divide then subtract
    4. subtract then divide




*/