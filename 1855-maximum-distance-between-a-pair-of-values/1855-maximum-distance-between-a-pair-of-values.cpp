class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i=0;i<nums1.size();i++) {
            // binary search in nums2 in range i to its end
            int start = i;
            int end = nums2.size()-1;
            while(start<=end) {
                int mid = (start + end)/2;
                if(nums2[mid]>=nums1[i]) {
                    // update ans 
                    ans = max(ans,mid-i);
                    start = mid + 1;
                } else {
                    end = mid-1;
                }
            }
        }
        return ans;
    }
};