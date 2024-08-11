class Solution {
public:
    int mod=1e9+7;
    int countOfPairs(vector<int>& nums) {
        vector<vector<vector<int>>> cache(nums.size()+1,vector<vector<int>>(52,vector<int>(52,-1)));
        return solve(nums,0,0,51,cache); // nums, last element of arr1, last element of arr2
    }

    // arr1 is increasing and arr2 is decreasing
    int solve(vector<int>& nums,int index,int arr1B,int arr2B,vector<vector<vector<int>>>& cache){
        if(index>=nums.size()){
            return 1;
        }

        if(cache[index][arr1B][arr2B]!=-1){
            return cache[index][arr1B][arr2B];
        }

        cache[index][arr1B][arr2B]=0;
        for(int i=0;i<=nums[index];i++){
            if(i>=arr1B && (nums[index]-i)<=arr2B)
                cache[index][arr1B][arr2B]=(cache[index][arr1B][arr2B]+solve(nums,index+1,i,nums[index]-i,cache))%mod;
        }
        return cache[index][arr1B][arr2B];
    }
};


/*

2   3   2



*/