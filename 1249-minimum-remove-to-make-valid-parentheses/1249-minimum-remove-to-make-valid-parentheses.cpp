class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
                ans+=s[i];
            } else if(s[i]==')') {
                if(!st.empty()){
                    st.pop();
                    ans+=s[i];
                }  
            } else {
                ans+=s[i];
            }
        }

        int size=st.size();
        string t="";
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='(' && size){
                size--;
                continue;
            }
            t+=ans[i];
        }
        return t;
    }
};


/*




*/