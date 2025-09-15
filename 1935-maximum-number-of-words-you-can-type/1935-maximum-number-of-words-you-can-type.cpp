class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st(brokenLetters.begin(),brokenLetters.end());
        int ans = 0, i = 0; text+=" ";
        while(i<text.length()) {
            if(text[i]==' ') ans++;
            else if(st.find(text[i])!=st.end()) while(i<text.length() && text[i]!=' ') i++;
            i++;
        }
        return ans;
    }
};