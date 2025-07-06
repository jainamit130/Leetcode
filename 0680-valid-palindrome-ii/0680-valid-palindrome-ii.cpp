class Solution {
public:
    bool validPalindrome(string s) {
        return process(s,1)||process(s,0);
    }

    bool process(string s,bool isForward) {
        int n = s.length();
        int i=0;
        int j=n-1;
        while(i<j && s[i]==s[j]) {
            i++;j--;
        }
        if(isForward) i++; else j--;
        while(i<j && s[i]==s[j]) {
            i++;j--;
        }
        return i>=j;            
    }
};



/*


c   b   b   c   c   



a   b   e   c   d   d   c   b   a



*/