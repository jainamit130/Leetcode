class Solution {
public:
    int longestPalindrome(string s, string t) {
        int ans = 0;
        for(int i=0;i<=s.length();i++) {
            for(int j=i;j<=s.length();j++) {
                string fromS = "";
                for(int k=i;k<=j && k<s.length();k++) {
                    fromS += s[k];
                }
                for(int m=0;m<=t.length();m++) {
                    for(int n=m;n<=t.length();n++) {
                        string fromT = "";
                        for(int o=m;o<=n && o<t.length();o++) {
                            fromT += t[o];
                        }
                        string conc = fromS+fromT;
                        if(isPalindrome(conc)) ans = max(ans,(int)conc.length());
                    }
                }
            }
        }
        return ans;
    }

    bool isPalindrome(string p) {
        for(int i=0;i<p.length()/2;i++) {
            if(p[i]!=p[p.length()-1-i]) {
                return false;
            }
        }
        return true;
    }
};


/*


1   2   
        3   4   3   2   1




*/