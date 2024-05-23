class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> treason(2001,-1);
        return solve(nums,k,0,treason);
    }

    int solve(vector<int>& nums, int k,int index,vector<int>& treason){
        if(index>=nums.size())
            return 0;

        int ans=0;
        //skip
        ans+=solve(nums,k,index+1,treason);
        //take
        if(treason[nums[index]]==-1){
            int less = max(0,nums[index]-k);
            int more = nums[index]+k;
            treason[less]++;
            treason[more]++;
            ans+=1+solve(nums,k,index+1,treason);
            treason[less]--;
            treason[more]--;
        }
        return ans;
    }
};



/*


2   3   4   6
    i

4
2




*/