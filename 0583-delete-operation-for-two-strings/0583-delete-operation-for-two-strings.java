class Solution {
    public int minDistance(String word1, String word2) {
        return solve(word1,word2,0,0);
    }

    int solve(String word1,String word2,int i,int j) {
        if(i>=word1.length()) return word2.length()-j;
        if(j>=word2.length()) return word1.length()-i;
        int ans = Integer.MAX_VALUE;
        if(word1.charAt(i)==word2.charAt(j)) ans = Math.min(ans,solve(word1,word2,i+1,j+1));
        ans = Math.min(ans,1+solve(word1,word2,i+1,j));
        ans = Math.min(ans,1+solve(word1,word2,i,j+1));
        return ans;
    }
}


/*



*/