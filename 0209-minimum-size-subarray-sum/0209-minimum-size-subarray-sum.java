class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;    
        int[] prefix = new int[n+1];
        for(int i=1;i<n+1;i++) {
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int ans = n+1;
        for(int i=1;i<n+1;i++) {
            // searching for right most index with val <=search 
            int search = prefix[i]-target;
            if(search<0) continue; 
            // Binary Search
            int index = binarySearch(search,i-1,prefix);
            ans = Math.min(ans,i-index);
        } 
        return ans==n+1?0:ans;
    }

    public int binarySearch(int searchVal,int end,int[] prefix) {
        int start=0;
        int ans = 0;
        while(start<=end) {
            int mid = (start+end)/2;
            if(prefix[mid]<=searchVal) {
                ans = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return ans;
    }
}



/*



Approach: Sliding Window
O(n)

0   1   2   3   4   5
2   3   1   2   4   3
                i
                        j


ans = 2
target = 7
windowSum = 7


2nd Approach: Prefix Sum
0   1   2   3   4   5
2   3   1   2   4   3


0   2   5   6   8   12  15

0   1   2   3   4   5   6   
0   2   5   6   8   12  15
                        i   




2 - (-5) >= target
5 - (-2) >= 7 
6 - (-1) >= 7 
8 - (1) >= 7 
12 - (5) >= 7 
15 - (8) >= 7
*/
