class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int last2 = nums.back() * nums[n-2];
        int ans = INT_MIN;
        ans = last2 * nums[0]; // - + +
        ans = max(ans,nums[0]*nums[1]*nums.back()); // - - +
        ans = max(ans,last2 * nums[n-3]); // + + +
        ans = max(ans,nums[0]*nums[1]*nums[2]); // - - -
        return ans;
    }
};


// +   +   + => +
// +   +   - => - 
// +   -   - => +
// -   -   - => -


// .   .   .   .   .   .   .  