class Solution {
public:
    int mod=1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> cache(n+1,vector<int>(51,-1)); 
        int ans=solve(nums,0,0,cache);
        return cache[0][0];
    }

    int solve(vector<int>& nums,int index,int arr1B,vector<vector<int>> & cache){
        if(index>=nums.size()){
            return 1;
        }

        int arr2B=50;
        if(index>0){
            arr2B=nums[index-1]-arr1B;
        }

        if(cache[index][arr1B]!=-1){
            return cache[index][arr1B];
        }

        int ans=0;
        for(int newArr1B=arr1B;newArr1B<=nums[index];newArr1B++){
            int newArr2B=nums[index]-newArr1B;
            if(newArr2B<=arr2B){
                ans+=solve(nums,index+1,newArr1B,cache)%mod;
                ans=ans%mod;
            }
        }
        return cache[index][arr1B]=ans;
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