//Recursive Approach Without Memoization
// class Solution {
// public:
//     int maxLen=1;
//     int ans=0;
//     int findNumberOfLIS(vector<int>& nums) {
//         solve(nums,0,0,INT_MIN);
//         return ans;
//     }

//     void solve(vector<int>& nums,int index,int currCount,int prev){
//         if(index>=nums.size()){
//             if(maxLen<currCount){
//                 maxLen=currCount;
//                 ans=1;
//             } else if(maxLen==currCount)
//                 ans++;
//             return;
//         }

//         //skip
//         solve(nums,index+1,currCount,prev);
//         //take
//         if(nums[index]>prev)
//             solve(nums,index+1,currCount+1,nums[index]);
//         return;
//     }
// };


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int globalMaxLen=1,ansCount=0;
        vector<pair<int,int>> dp(nums.size());
        for(int i=nums.size()-1;i>=0;i--){    
            int maxLen=1,maxCount=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    auto [len,count]=dp[j];
                    if((1+len)>maxLen){
                        maxLen=len+1;
                        maxCount=count;
                    } else if((1+len)==maxLen){
                        maxCount+=count;
                    }
                }
            }
            if(maxLen>globalMaxLen){
                globalMaxLen=maxLen;
                ansCount=maxCount;
            } else if(globalMaxLen==maxLen){
                ansCount+=maxCount;
            }
            dp[i]={maxLen,maxCount};
        }
        return ansCount;
    }
};