class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for(auto n:nums) {
            if(n==0) {
                count=0;
            } else {
                count++;
                ans = max(ans,count);
            }
        }
        return ans;
    }
};