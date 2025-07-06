class Solution {
public:
    typedef long long ll;
    ll maximumTotalCost(vector<int>& nums) { 
        ll sub = nums[0]; 
        ll add = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            ll t=max(add,sub);
            sub = add - nums[i];
            add = t + nums[i];
        }
        
        return max(add, sub);
    }
};

// class Solution {
// public:
//     typedef long long ll;
//     ll maximumTotalCost(vector<int>& nums) {
//         vector<vector<ll>> cache(nums.size(),vector<ll>(2,-1e15));
//         return solve(nums,0,0,0,cache);
//     }

//     ll solve(vector<int>& nums,int index,int isStart,int sign,vector<vector<ll>>& cache){
//         if(index>=nums.size())
//             return 0ll;

//         if(cache[index][sign]!=-1e15)
//             return cache[index][sign];

//         int mul=-1;
//         if(!sign)
//             mul=1;

//         if(isStart==0){
//             cache[index][sign]=max(cache[index][sign],nums[index]+solve(nums,index+1,1,1,cache));
//         } else {
//             cache[index][sign]=max(cache[index][sign],(mul*nums[index])+solve(nums,index+1,1,!sign,cache));
//             cache[index][sign]=max(cache[index][sign],solve(nums,index,0,0,cache));
//         }
//         return cache[index][sign];
//     }
// };