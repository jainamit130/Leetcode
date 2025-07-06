class Solution {
    int ans = 0;
    public int reversePairs(int[] nums) {
        int[] sorted = getReversePairsCount(nums,0,nums.length-1);
        return ans;
    }

    int[] getReversePairsCount(int[] nums,int start,int end) {
        if(start>=end) return new int[]{nums[start]};
        int mid = (start+end)/2;
        int[] left = getReversePairsCount(nums,start,mid);
        int[] right = getReversePairsCount(nums,mid+1,end);
        return merge(left,right);
    }

    int[] merge(int[] left,int[] right) {
        int m = left.length,n=right.length;
        int start = 0, end = right.length-1;
        int i=0,j=0;
        while(i<m) {
            while(j<n && left[i] > 2L * right[j]) {
                j++;
            }
            ans+=j;
            i++;
        }
        i=j=0;
        int[] merged = new int[m+n];
        int index = 0;
        while(i<m || j<n) {
            if(i<m && j<n) {
                if(left[i]<=right[j]) { merged[index]=left[i]; i++; }
                else { merged[index]=right[j]; j++; }
            } else if(i<m) { merged[index]=left[i]; i++; } 
            else { merged[index]=right[j]; j++; }
            index++;
        }

        return merged;
    }
}


/*

1   3   2   3   1

ans = 1 + 


1   3                   2   3   1
1       3                   2               3   1
   1    3                               3               1
                                            1   3
1   2   3                   1   3
i                   
                            j    

9/2 => 4.5
7/2 => 3.5
1   2   3   4   5   6   7   8   9   10   
i
j

*/ 