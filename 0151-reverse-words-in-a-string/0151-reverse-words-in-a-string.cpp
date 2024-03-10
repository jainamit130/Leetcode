class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string t = "";
        int start = -1;
        int flag1 = 0;
        stack<string> st;

        while (i < s.length()) {
            if (s[i] == ' ') {
                if (flag1) {
                    t = s.substr(start, i - start);
                    st.push(t);
                    start = -1;
                    flag1 = 0;
                }
            } else if (s[i] != ' ') {
                if (start == -1)
                    start = i;
                flag1 = 1;
            }

            i++;
        }
        if (s[s.length() - 1] != ' ') {
            st.push(s.substr(start, i - start));
        }

        t = "";
        while (!st.empty()) {
            t += st.top();
            st.pop();
            if (!st.empty())
                t += " ";
        }
        return t;
    }
};