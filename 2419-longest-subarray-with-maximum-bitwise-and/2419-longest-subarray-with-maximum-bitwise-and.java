class Solution {
    public int longestSubarray(int[] nums) {
        int k = Arrays.stream(nums).max().getAsInt();
        int ans = 1;
        int count = 0;
        for(int i=0;i<=nums.length;i++) {
            if(i<nums.length && nums[i]==k) count++;
            else {
                ans = Math.max(ans,count);
                count=0;
            }
        }
        return ans;
    }
}