class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int maxi=0;
        for(auto n:nums){
            maxi=max(n,maxi);
        }
        vector<int> mp(nums.size()+maxi);
        for(auto n:nums){
            mp[n]++;
        }
        int ans=0;
        for(int i=0;i<maxi+nums.size();i++){
            if(mp[i]>1){
                ans+=mp[i]-1;
                mp[i+1]+=(mp[i]-1);
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        int ans=0;
//        for(int i=1;i<nums.size();i++){
//             if(nums[i]<=nums[i-1]){
//                 ans+=(nums[i-1]+1)-nums[i];
//                 nums[i]=nums[i-1]+1;
//             }
//        } 
//        return ans;
//     }
// };




/*

3   2   1   2   1   7

1   1   2   2   3   7

1   2   3   4   5   7

*/