class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0) return;
        int n = nums.size();
        int swaps = 0;
        int index = 0;
        int val = nums[index];
        int count = 0;
        while(swaps<n) {
            int newIndex = (index + k)%n;
            int temp = val;
            val = nums[newIndex];
            nums[newIndex] = temp;
            index = newIndex;
            count+=k;
            if(count%n==0) {
                count=0;
                index=(index+1)%n;
                val=nums[index];
            }
            swaps++;
        }
    }
};

/*
1   2   3   4   5   6


1   2   3   4   1   6

1   2   5   4   1   6






*/