class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto n:nums) {
            mini = min(n,mini);
        }
        return mini;
    }
};