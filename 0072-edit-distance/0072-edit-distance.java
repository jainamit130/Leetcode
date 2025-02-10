class Solution {
    public int minDistance(String word1, String word2) {
        return solve(word1,word2,0,0);
    }

    int solve(String word1,String word2,int index1,int index2) {
        if(index2==word2.length()) {
            return word1.length()-index1; // Return remaining operations as to be deleted
        }

        if(index1==word1.length()) {
            return word2.length()-index2; // Return reamining operations as to be inserted
        }
    // initialiazing with max val of all removals and all insertions = word1.length()+word2.length()
        int ans = word1.length()+word2.length();  
        if(word1.charAt(index1)!=word2.charAt(index2)) {
            // Replce char to word2[index2] only if they are different
            ans = Math.min(ans,1+solve(word1,word2,index1+1,index2+1));
            // Insert a char to word2[index2] and move forward only index2 for the next recursion
            ans = Math.min(ans,1+solve(word1,word2,index1,index2+1));
            // Delete a char only move forward index 1 this time
            ans = Math.min(ans,1+solve(word1,word2,index1+1,index2));
        } else {
            ans = Math.min(ans,solve(word1,word2,index1+1,index2+1));
        }
        return ans;
    }
}


/*

dp approach
States: currWord = word1 (intially)

1. Replace a char
2. Delete a char

*/