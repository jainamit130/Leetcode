class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (i < n-1 && s[i] == s[i + 1]) {
                int cnt = 1;
                char temp = s[i];
                while (i < n-1 && s[i] == s[i + 1]) {
                    cnt++;
                    i++;
                }

                if (cnt >= 2) {
                    ans += string(2, temp); // Add temp twice as a string
                }
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};