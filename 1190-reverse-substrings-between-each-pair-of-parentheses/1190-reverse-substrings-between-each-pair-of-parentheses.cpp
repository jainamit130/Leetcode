class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string word="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(word);
                word="";
            } else if(s[i]==')') {
               reverse(word.begin(),word.end());
               word=st.top()+word;
               st.pop();
            } else {
                word+=s[i];
            }
        }
        return word;
    }
};



/*

(   e   d   (   e   t   (   o   c   )   )   e   l   )
                                                i

st: 
""
edocteel


word= 


*/