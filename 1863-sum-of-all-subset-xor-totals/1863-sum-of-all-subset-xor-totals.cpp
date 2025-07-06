class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ors=0;
        for(auto n:nums)
            ors=ors|n;
        return ors<<nums.size()-1;
    }
};

// class Solution {
// public:
//     int ans=0;
//     int subsetXORSum(vector<int>& nums) {
//         takeItOrLeaveIt(nums,0,0);
//         return ans;
//     }

//     void takeItOrLeaveIt(vector<int>& nums,int index,int currXor){
//         if(index>=nums.size()){
//             ans+=currXor;
//             return;
//         }

//         //take it
//         takeItOrLeaveIt(nums,index+1,currXor^nums[index]);
//         //leave it
//         takeItOrLeaveIt(nums,index+1,currXor);
//         return;
//     }
// };