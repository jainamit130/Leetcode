class Solution {
    public int bestRotation(int[] nums) {
        int[] pre = new int[nums.length+1];
        for(int i=0;i<nums.length;i++) {
            int start=0,end=0;
            if(nums[i]<=i) {
                start = i-nums[i]+1;
                end = i+1;
            } else {
                pre[nums.length-(nums[i]-i)+1]++;
                pre[nums.length]--;
                end = i+1;
            }
            pre[start]++;
            pre[end]--;
        }
        int ans = 0;
        int val = pre[0];
        int subVal = pre[0];

        for(int i=1;i<nums.length;i++) {
            subVal+=pre[i];
            if(subVal<val) {
                val = subVal;
                ans = i;
            }
        }
        return ans;
    }
}

/*

0   1   2   3   4   0   1   2   3
        1   1   1
            1   1

2   3   1   4   0


0   1   2   3   4

2   3   1   4   0 
3   1   4   0   2  
1   4   0   2   3
4   0   2   3   1
0   2   3   1   4



*/