class Solution {
public:
    int fixed;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       int target=0;
       for(auto n:nums){
            target+=n;
       }
       if(target%k!=0){
        return false;
       }
       target/=k;
       fixed=target;
       return solve(nums,k,target,0);
    }

    bool solve(vector<int>& nums,int k,int target,int visited){
        if(k==0 && visited==(1<<nums.size())-1){
            return true;
        }

        if(target<0){
            return false;
        }

        bool ans=false;
        for(int i=0;i<nums.size();i++){
            if(visited>>i & 1){
                continue;
            }

            visited=visited|(1<<i);

            if(target-nums[i]==0){
                ans=ans||solve(nums,k-1,fixed,visited);
            } else {
                ans=ans||solve(nums,k,target-nums[i],visited);
            }

            visited=visited&(~(1<<i));

        }
        return ans;
    }
};

/*

4   3   2   3   5   2   1
*   *   *   *   *   *   *

k=0


20/4 = 5
k=4

*/