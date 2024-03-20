class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeak(nums,0,nums.size()-1);
    }

    int findPeak(vector<int>& nums,int start,int end){
        int mid=(start+end)/2;
        if(mid>0 && nums[mid]<nums[mid-1])
            return findPeak(nums,start,mid-1);
        else if(mid<nums.size()-1 && nums[mid]<nums[mid+1])
            return findPeak(nums,mid+1,end);
        else
            return mid;
        return mid;
    }
};