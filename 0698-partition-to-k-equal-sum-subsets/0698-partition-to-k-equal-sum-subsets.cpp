class Solution {
public:
    int real;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target=0;
        for(auto n:nums){
            target+=n;
        }
        if(target%k!=0){
            return false;
        }
        target/=k;
        real=target;
        unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>> cache; 
        return solve(nums,0,target,k,0,cache);
    }

    bool solve(vector<int>& nums,int index,int target,int k,int visited,unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>>& cache){
        if(k==0 && visited==(1 << nums.size()) - 1){
            return true;
        }

        if(index>=nums.size() || k<0 || target<0 || (visited >> index) & 1){
            return false;
        }

        if(cache.find(index)!=cache.end() && cache[index].find(k)!=cache[index].end() && cache[index][k].find(target)!=cache[index][k].end() && cache[index][k][target].find(visited)!=cache[index][k][target].end()){
            return cache[index][k][target][visited];
        }

        bool ans=false;
        visited=visited|(1<<index);
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]==0){
                ans=ans||solve(nums,i+1,real,k-1,visited,cache);
            }
            else {
                ans=ans||solve(nums,i+1,target-nums[i],k,visited,cache);
            }
        }
        visited=visited&(~(1<<index));
        return cache[index][k][target][visited]=ans;
    }
};


/*

4   3   2   3   5   2   1
i

4

4   3

4   3   2

4   3   2   3



  



*/