class Solution {
    public boolean isPalindrome(String str) {
        int i=0,j=str.length()-1;
        String s = str.toLowerCase();
        while(i<j) {
            while(i<j && !(('a'<=s.charAt(i) && s.charAt(i)<='z') || ('0'<=s.charAt(i) && s.charAt(i)<='9'))) i++;
            while(i<j && !(('a'<=s.charAt(j) && s.charAt(j)<='z') || ('0'<=s.charAt(j) && s.charAt(j)<='9'))) j--;
            if(i>=j) break;
            if(s.charAt(i)!=s.charAt(j)) return false;
            i++;j--;
        }
        return true;
    }
}