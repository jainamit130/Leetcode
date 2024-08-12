// class Solution {
// public:
//     int mod=1e9+7;
//     int countOfPairs(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> cache(n+1,vector<int>(1001,-1)); 
//         int ans=solve(nums,0,0,cache);
//         return cache[0][0];
//     }

//     int solve(vector<int>& nums,int index,int arr1B,vector<vector<int>> & cache){
//         if(index>=nums.size()){
//             return 1;
//         }

//         int arr2B=1000;
//         if(index>0){
//             arr2B=nums[index-1]-arr1B;
//         }

//         if(cache[index][arr1B]!=-1){
//             return cache[index][arr1B];
//         }

//         int ans=0;
//         for(int newArr1B=arr1B;newArr1B<=nums[index];newArr1B++){
//             int newArr2B=nums[index]-newArr1B;
//             if(newArr2B<=arr2B){
//                 ans+=solve(nums,index+1,newArr1B,cache)%mod;
//                 ans=ans%mod;
//             }
//         }
//         return cache[index][arr1B]=ans;
//     }
// };

// class Solution {
// public:
//     int mod=1e9+7;
//     int countOfPairs(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(1001,-1)); 
//         vector<int> base(1001,1);
//         dp[n]=base;
//         for(int index=n-1;index>=0;index--){
//             for(int arr1B=0;arr1B<1001;arr1B++){
//                 int arr2B=1000;
//                 if(index>0){
//                     arr2B=nums[index-1]-arr1B;
//                 }
//                 int ans=0;
//                 for(int newArr1B=arr1B;newArr1B<=nums[index];newArr1B++){
//                     int newArr2B = nums[index]-newArr1B;
//                     if(newArr2B<=arr2B){
//                         ans+=dp[index+1][newArr1B];
//                     }
//                 }
//                 dp[index][arr1B]=ans;
//             }
//         }
//         return dp[0][0];
//     }
// };


class Solution {
public:
    int mod=1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(1001,1); 
        for(int index=n-1;index>=0;index--){
            vector<int> nextDp(1001);
            vector<int> prefix;
            prefix.push_back(0);
            for(int i=0;i<1001;i++){
                prefix.push_back((prefix.back()+dp[i])%mod);
            }
            for(int arr1B=0;arr1B<((index<n-1)?(nums[index+1]+1):(1001));arr1B++){
                int arr2B=1000;
                if(index>0){
                    arr2B=nums[index-1]-arr1B;
                }

                int l=max(nums[index]-arr2B,arr1B);
                int r=nums[index];
                if(l<=r){
                    nextDp[arr1B]=(prefix[r+1]-prefix[l]+mod)%mod;
                }
            }
            dp=nextDp;
        }
        return dp[0];
    }
};

// class Solution {
// public:
//     int mod = 1e9 + 7;
//     int countOfPairs(vector<int>& nums) {
//         const int N = 1001;  
//         int n = nums.size();
//         vector<int> dp(N, 1);  
        
//         for (int index = n - 1; index >= 0; index--) {
//             vector<int> newDp(N, 0); 
//             vector<int> prefix(N, 0); 
            
//             prefix[0] = dp[0];
//             for (int j = 1; j < N; j++) 
//                 prefix[j] = (prefix[j - 1] + dp[j]) % mod;
            
//             for (int arr1B = 0; arr1B <= 1000; arr1B++) {
//                 int arr2B = (index > 0) ? nums[index - 1] - arr1B : 1000;
                
//                 if (arr2B < 0) 
//                     break;
                
//                 int l = max(arr1B, nums[index] - arr2B);
//                 int r = nums[index];
                
//                 if (l <= r)
//                     newDp[arr1B] = (prefix[r] - (l > 0 ? prefix[l - 1] : 0) + mod) % mod;
//             }
//             dp = newDp;
//         }

//         return dp[0];
//     }
// };
