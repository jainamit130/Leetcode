class Solution {
    public int maxFrequency(int[] nums, int k) {
        int copyK = k;
        Arrays.sort(nums);
        int i = nums.length-1; int j = i;
        int diff = 0;
        int ans = 0;
        while(i>=0) {
            int subAns = i-j;
            while(j>=0 && (nums[i]-nums[j])<=k) {
                k-=nums[i]-nums[j];
                subAns++;
                j--;
            }
            ans = Math.max(ans,subAns);
            if(j==-1) return ans;
            i--;
            k=Math.min(k+nums[i+1]-nums[i],copyK);
        }
        return ans;
    }
}


/*

2

15 -> 3
14 -> 2
12 -> 2
10 -> 2
8 -> 3

k = 0

    1   4   8   10  12  14  15
            i
j   

k = 3

    3   6   9
        i
    j

*/