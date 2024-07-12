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
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]=='(' && size){
                size--;
                continue;
            }
            t+=ans[i];
        }
        reverse(t.begin(),t.end());
        return t;
    }
};


/*
(   )   )   (   )   (   (   (   
        i


st: ( ) 

*/