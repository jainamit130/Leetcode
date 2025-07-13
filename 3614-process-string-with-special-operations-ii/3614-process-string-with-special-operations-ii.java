class Solution {
    public char processStr(String s, long k) {
        long len = 0;
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if(ch>='a' && ch<='z') len++;
            else if(ch=='*' && len>0) len--;
            else if(ch=='#') len+=len;
        }
        if(k>=len) return '.';
        for(char ch='a'; ch<='z';ch++) {
            long currLen = len;
            long pos = k;
            for(int i=s.length()-1;i>=0;i--) {
                char sc = s.charAt(i);
                if(sc>='a' && sc<='z') {
                    currLen--;
                    if(currLen == pos && sc==ch) return ch;
                } else if(sc=='*' && currLen>0) {
                    currLen++; 
                    if(pos==currLen-1) break;
                } else if(sc=='#') {
                    currLen/=2;
                    if(currLen<=pos) pos-=currLen;
                } else if(sc=='%') {
                    pos = currLen-pos-1;
                }
            }
        }
        return '.';
    }
}


/*


q   e   *   v   k   g



q   v   k   g

*/ 