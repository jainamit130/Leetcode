class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> prefix(1);
        long long ans = 0;
        int start = 0;
        for(int i=0;i<nums.size();i++) {
            // binary search 
            int count = getCountOfSubarrayUsingBinarySearch(start,prefix,i+1,prefix.back()+nums[i],k);
            ans += count;
            prefix.push_back(prefix.back()+nums[i]);
        }
        return ans;
    }

    int getCountOfSubarrayUsingBinarySearch(int& start,vector<long long>& prefix,int upperIndex,long long val,long long k) {
        int end = prefix.size()-1;
        int count = 0;
        while(start<=end) {
            int mid = start+(end-start)/2;
            long long score = (val-prefix[mid])*1LL*(upperIndex-mid);
            if(score<k) {
                count = upperIndex-mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return count;
    }
};


/*

k = 17
    0   1   2   3   4
    2   1   4   3   5
0   2   3   7   10  15   
0   1   2   3   4   5   


ans = 1 + 2 + 2 + 2 + 2

2
1
2,1
4
1,4
3
4,3
5


*/