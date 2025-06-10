class Solution {
    public int maxDifference(String s) {
        int n = s.length();
        int maxOdd=0;;
        int minEven=n;
        int[] freq = new int[26];
        for(int i=0;i<n;i++) {
            freq[s.charAt(i)-'a']++;
        }

        for(int i=0;i<26;i++) {
            int count = freq[i];
            if(count==0) continue;
            if(count%2==0) {
                minEven = Math.min(minEven,count);
            } else {
                maxOdd = Math.max(maxOdd,count);
            }
        }
        return maxOdd-minEven;
    }
}