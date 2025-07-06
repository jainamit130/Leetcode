class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> copyNums1(nums1.begin(),nums1.end());
        sort(copyNums1.begin(),copyNums1.end());
        long long absDiff=0;
        for(int i=0;i<n;i++)
            absDiff+=abs(nums1[i]-nums2[i]);
        long long ans=absDiff;
        for(int i=0;i<n;i++){
            int currentDiff=abs(nums1[i]-nums2[i]);
            int closestSmallerToCurrentArr2Element = lowerBound(copyNums1,nums2[i]);
            int closestLargerToCurrentArr2Element = upperBound(copyNums1,nums2[i]);
            int newDiff=min(abs(closestSmallerToCurrentArr2Element-nums2[i]),abs(closestLargerToCurrentArr2Element-nums2[i]));
            long long currentAns=absDiff-currentDiff+newDiff;
            ans=min(ans,currentAns);
        }
        return ans%((int)1e9+7);
    }

    int lowerBound(vector<int>& nums,int e){
        long long ans = INT_MAX;
        int beg = 0, end = nums.size() - 1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(nums[mid] <= e) {
                ans = nums[mid];
                beg = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }

        int upperBound(vector<int>& nums,int e){
        long long ans = INT_MAX;
        int beg = 0, end = nums.size() - 1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(nums[mid] >= e) {
                ans = nums[mid];
                end = mid - 1;
            }
            else beg = mid + 1;
        }
        return ans;
    }
};