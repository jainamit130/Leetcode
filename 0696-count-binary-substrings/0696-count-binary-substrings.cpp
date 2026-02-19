class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = -1, curr = -1, ans = 0;
        vector<int> counts = {s[0]=='0',s[0]=='1'};
        for(int i=1;i<=s.length();i++) {
            if(i<s.length() && s[i]==s[i-1]) counts[s[i]-'0']++;
            else {
                prev = curr;
                curr = counts[s[i-1]-'0'];
                if(prev!=-1) ans += min(prev,curr);
                if(i<s.length()) counts={s[i]=='0',s[i]=='1'};
            }
        }
        return ans;
    }
};



/*

00  1   0   111 000000000   111 0   11  0000    11  0   1   0

x   y   


0   000    111
     00    11
      0    1
*/