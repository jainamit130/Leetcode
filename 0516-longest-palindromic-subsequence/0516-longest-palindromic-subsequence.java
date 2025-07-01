class Solution {
    int[][] cache;
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        cache = new int[n+1][n+1];
        int[][] lastOccurences = new int[n+1][26];
        for(int i=0;i<26;i++) lastOccurences[0][i]=-1;
        for(int i=0;i<n;i++) {
            Arrays.fill(cache[i],-1);
            for(int j=0;j<26;j++) lastOccurences[i+1][j]=lastOccurences[i][j];
            lastOccurences[i+1][s.charAt(i)-'a']=i;
        }
        return solve(s,0,s.length()-1,lastOccurences);
    }

    int solve(String s,int start,int end,int[][] lastOccurences) {
        if(start>=end) return start==end?1:0;
        if(cache[start][end]!=-1) return cache[start][end];
        int currEnd = lastOccurences[end+1][s.charAt(start)-'a'];
        int ans = (currEnd==start?1:2)+solve(s,start+1,currEnd-1,lastOccurences);
        ans = Math.max(ans,solve(s,start+1,end,lastOccurences));
        return cache[start][end]=ans;
    }
}


/*


take 


*/