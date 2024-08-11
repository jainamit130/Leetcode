class Solution {
public:
    int mod=1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> cache(n+1,vector<vector<int>>(51,vector<int>(51,-1))); 
        return solve(nums,0,0,50,cache);
    }

    int solve(vector<int>& nums,int index,int arr1B,int arr2B,vector<vector<vector<int>>> & cache){
        if(index>=nums.size()){
            return 1;
        }

        if(cache[index][arr1B][arr2B]!=-1){
            return cache[index][arr1B][arr2B];
        }

        int ans=0;
        for(int newArr1B=arr1B;newArr1B<=nums[index];newArr1B++){
            int newArr2B=nums[index]-newArr1B;
            if(newArr2B<=arr2B){
                ans=(ans+solve(nums,index+1,newArr1B,newArr2B,cache))%mod;
            }
        }
        return cache[index][arr1B][arr2B]=ans;
    }
};


/*


2   3   2

0-2 

2-0 


arr1 is increasing 


arr2 is decreasing

arr1[i]+arr2[i]==nums[i]


*/