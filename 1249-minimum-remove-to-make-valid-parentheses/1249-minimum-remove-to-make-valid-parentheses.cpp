class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
                ans+=s[i];
            } else if(s[i]==')') {
                if(count>0){
                    count--;
                    ans+=s[i];
                }  
            } else {
                ans+=s[i];
            }
        }

        string t="";
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]=='(' && count){
                count--;
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