class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return divideAndConquer(nums,0,nums.size()-1);
    }

    int divideAndConquer(vector<int>& nums,int start,int end) {
        if(start==end) return nums[start];
        int mid = start+(end-start)/2;
        int firstEnd,secondStart;
        firstEnd = mid;
        secondStart = mid+1;
        if(nums[mid]==nums[mid+1]) {
            firstEnd = mid-1;
            secondStart = mid+2;
        }
        if((end-secondStart+1)%2!=0) return divideAndConquer(nums,secondStart,end);
        return divideAndConquer(nums,start,firstEnd);
    }
};