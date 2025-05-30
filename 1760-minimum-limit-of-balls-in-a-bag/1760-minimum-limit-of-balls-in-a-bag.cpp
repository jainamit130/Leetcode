class Solution {
public:
    priority_queue<int> heap;
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1;  
        int end = nums[0];
        for(auto n:nums) {
            heap.push(n);
            end = max(n,end);
        }

        int ans = end;
        // O(n log n)
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(isValid(nums,mid,maxOperations)) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }

    // O(n)
    bool isValid(vector<int>& nums,int penalty,int maxOperations) {
        for(int i=0;i<nums.size() && maxOperations>=0;i++) {
            int currPenalty = nums[i];
            if(currPenalty>penalty) maxOperations-=ceil(currPenalty/(double)penalty)-1;
        }
        return maxOperations>=0;
    }
};

/*

9 -> 2  7
7 -> 2  5
5 -> 2  3

What are the constraints?
nums = [0,0,0]

Binary Search on the ans
Range:
1 to max(nums)

get mid = start+(end-start)/2;

check if we can achieve a ans of mid

x -> mid x-mid
x-mid -> mid x-2*mid


*/