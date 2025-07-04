class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.length;
        int windowSum = 0;
        for(int index=0;index<n;index++) {
            if(index==n-k) windowSum = sum;
            sum+=cardPoints[index];
        }
        int ans = 0;
        System.out.println(windowSum + " " + sum);
        int i=0,j=n-k;
        while(j<=n) {
            ans = Math.max(ans,sum-windowSum);
            if(j==n) break;
            windowSum+=cardPoints[j]-cardPoints[i];
            i++;j++;
        }
        return ans;
    }
}

/**/