class Solution {
public:
    string shortestPalindrome(string s) {
        string p=s;
        reverse(p.begin(),p.end());
        string rev=p;
        p+=s;
        vector<int> lps(p.length());
        computeLPS(p,lps);
        int len=lps.back();
        while(len){
            rev.pop_back();
            len--;
        }
        return rev+s;
    }

    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0; 
        
        lps[0] = 0; 
        
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; 
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};


/*

a   a   c   e   c   a   a   a
i   

a   a   a   c   e   c   a   a
j


a   b   c   d
i

d   c   b   a
            j


*/