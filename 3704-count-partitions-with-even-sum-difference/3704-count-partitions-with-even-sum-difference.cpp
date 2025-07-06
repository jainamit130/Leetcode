class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int right = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        for(auto n:nums) {
            left+=n;
            right-=n;
            if(abs(left-right)%2==0) count++;
        }
        return count;
    }
};