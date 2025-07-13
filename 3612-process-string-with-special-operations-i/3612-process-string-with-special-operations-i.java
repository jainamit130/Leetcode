class Solution {
    public String processStr(String s) {
        StringBuilder ans = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if(ch>='a' && ch<='z') {
                ans.append(ch);
            } else if(ch=='*' && ans.length()>0) {
                ans.deleteCharAt(ans.length()-1);
            } else if(ch=='#') {
                ans.append(ans);
            } else if(ch=='%') {
                ans.reverse();
            }
        }
        return ans.toString();
    }
}