class Solution {
    public int numberOfSubstrings(String s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        int ans = 0;
        Map<Integer,Integer> mp = new HashMap();
        while(j<=s.length()) {
            // keep pushing j till not valid
            while(j<s.length() && mp.size()<3) {
                int ch = s.charAt(j)-'a';
                mp.put(ch,mp.getOrDefault(ch,0)+1);
                j++;
            }
            int incCount = n-j+1;
            while(i<j && mp.size()==3) {
                ans+=incCount;
                int ch = s.charAt(i)-'a';
                mp.put(ch,mp.get(ch)-1);
                if(mp.get(ch)==0) mp.remove(ch);
                i++;
            }
            if(j==s.length()) break;
        }
        return ans;
    }
}


/*

all characters in s will be among a,b,c
length of s => 3 if less then return 0


a   b   a   b   c   a   b   b   c
                        i
                                j

inc answer by n-j and try moving i forward
15
4
3
1
*/