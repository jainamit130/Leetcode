class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(auto n:nums2){
            int start=0;
            int end=nums1.size()-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(nums1[mid]>n)
                    end=mid-1;
                else if(nums1[mid]<n)
                    start=mid+1;
                else
                    return n;
            }
        }
        return -1;
    }
};