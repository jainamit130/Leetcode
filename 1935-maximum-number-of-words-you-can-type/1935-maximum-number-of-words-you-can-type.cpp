class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for(auto& ch: brokenLetters) st.insert(ch);
        int ans = 0;
        string word = "";
        int i = 0;
        text+=" ";
        while(i<text.length()) {
            if(text[i]==' ') {
                ans++;
                word = "";
            }
            else if(st.find(text[i])!=st.end()) {
                word = "";
                while(i<text.length() && text[i]!=' ') i++;
            } else {
                word += text[i]; 
            }
            i++;
        }
        return ans;
    }
};