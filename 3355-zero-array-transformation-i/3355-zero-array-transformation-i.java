class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] prefix = new int[n+1];
        for(int i=0;i<queries.length;i++) {
            int lowerIndex = queries[i][0];
            int upperIndex = queries[i][1]+1;
            prefix[lowerIndex]--;
            prefix[upperIndex]++;
        }

        for(int i=1;i<prefix.length;i++) {
            if(prefix[i-1]+nums[i-1]>0) return false;
            prefix[i]=prefix[i-1]+prefix[i];
        }

        return true;
    }
}

/*
0   1   2   3
4   3   2   1



1   3
0   2


prefix
0   1   2   3   4
0   0   0   0   0
    -1          +1
-1          +1    

-1  -1  0   1   1


-1  -2  -2  -1  0

3   1   0   0


*/