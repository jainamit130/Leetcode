class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.length());
        int len = 0;
        int i = 0, j = 1;
        while (j < s.length()) {
            if (s[i] == s[j]) {
                lps[j] = ++len;
                j++;
                i++;
            } else {
                while (s[i] != s[j] && i != 0) {
                    len = lps[i - 1];
                    i = lps[i - 1];
                }
                if (s[i] != s[j]) {
                    len = 0;
                    j++;
                } else
                    continue;
            }
        }
        len = lps.back();
        if (len == 0)
            return "";
        return s.substr(s.length() - 1 - len + 1, len);
    }
};