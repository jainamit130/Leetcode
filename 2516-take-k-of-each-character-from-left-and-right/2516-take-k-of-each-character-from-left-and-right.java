class Solution {
    public int takeCharacters(String s, int k) {
        int n = s.length();
        int[] total = new int[3];
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<n;i++) {
            total[s.charAt(i)-'a']++;
        }
        int flag = 1;
        for(int t=0;t<3;t++) {
            if(total[t]<k) {
                flag=0;
            }
        }
        if(flag == 0) {
            return -1;
        }

        int i=0,j=0;
        int[] curr = new int[3];
        while(j<s.length()) {
            while(j<s.length() && isValid(k,curr,total)) {
                curr[s.charAt(j)-'a']++;
                ans = Math.min(ans,s.length()-(j-i));
                j++;
            }
            while(i<j && !isValid(k,curr,total)) {
                curr[s.charAt(i)-'a']--;
                i++;
            }
            ans = Math.min(ans,s.length()-(j-i));
        }
        return ans;
    }

    public boolean isValid(int k,int[] curr,int[] total) {
        int flag = 1;
        for(int i=0;i<3;i++) {
            if(total[i]-curr[i]<k) {
                flag = 0;
            }
        }
        return flag==1;
    }
}

/*

        i
                            j
a   a   b   a   a   a   a   c   a   a   b   c




*/